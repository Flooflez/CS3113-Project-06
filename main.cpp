/**
* Author: Maximilian Ta
* Assignment: Platformer
* Date due: 2023-12-02, 11:59pm
* I pledge that I have completed this assignment without
* collaborating with anyone else, in conformance with the
* NYU School of Engineering Policies and Procedures on
* Academic Misconduct.
*
* Original File created by Sebastián Romero Cruz
**/

#define GL_SILENCE_DEPRECATION
#define GL_GLEXT_PROTOTYPES 1
#define FIXED_TIMESTEP 0.0166666f
#define LEVEL_WIDTH 50
#define LEVEL_HEIGHT 10
#define LEVEL_LEFT_EDGE 5.0f

#ifdef _WINDOWS
#include <GL/glew.h>
#endif

#include <SDL_mixer.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "ShaderProgram.h"
#include "cmath"
#include <ctime>
#include <vector>
#include "Entity.h"
#include "Map.h"
#include "Utility.h"
#include "Scene.h"
#include "LevelA.h"
#include "Menu.h"
#include "Win.h"
#include "Effects.h"
#include "Jumpscare.h"

// ————— CONSTANTS ————— //
const int   WINDOW_WIDTH    = 640,
            WINDOW_HEIGHT   = 480;

const float BG_RED      = 0.01f,
            BG_BLUE     = 0.01f,
            BG_GREEN    = 0.01f,
            BG_OPACITY  = 1.0f;

const int   VIEWPORT_X = 0,
            VIEWPORT_Y = 0,
            VIEWPORT_WIDTH = WINDOW_WIDTH,
            VIEWPORT_HEIGHT = WINDOW_HEIGHT;

const char  V_LIT_SHADER_PATH[] = "shaders/vertex_lit.glsl",
            F_LIT_SHADER_PATH[] = "shaders/fragment_lit.glsl";

const char  V_SHADER_PATH[] = "shaders/vertex_textured.glsl",
            F_SHADER_PATH[] = "shaders/fragment_textured.glsl";

const char  FONT_FILEPATH[] = "assets/fonts/font1.png";

const float MILLISECONDS_IN_SECOND = 1000.0;

// ————— GLOBAL VARIABLES ————— //
Scene*  g_current_scene;
int g_current_scene_index = 0;
Menu* g_menu;
LevelA* g_level_a;
Win* g_win_scene;

SDL_Window* g_display_window;
bool g_game_is_running = true;
bool g_game_over = false;
bool g_game_win = false;
bool g_game_start = false;
std::string g_display_message = "hewoo world!";

ShaderProgram g_shader_program;
glm::mat4 g_view_matrix, g_projection_matrix;

float g_previous_ticks  = 0.0f;
float g_accumulator     = 0.0f;

GLuint g_text_texture_id;

Scene* g_levels[3];

int g_score = 0;

Effects *g_effects;
Jumpscare* g_jumpscare;

//glm::vec3 g_spawn_point = glm::vec3(48.0f, -48.0f, 0.0f);
glm::vec3 g_spawn_point = glm::vec3(37.0f, -28.0f, 0.0f);


void switch_shader(const char v_path[], const char f_path[]) {
    g_shader_program.load(v_path, f_path);
    Utility::set_shader_program(&g_shader_program);

    g_view_matrix = glm::mat4(1.0f);
    g_projection_matrix = glm::ortho(-5.0f, 5.0f, -3.75f, 3.75f, -1.0f, 1.0f);

    g_shader_program.set_projection_matrix(g_projection_matrix);
    g_shader_program.set_view_matrix(g_view_matrix);

    glUseProgram(g_shader_program.get_program_id());
}



void switch_to_scene(Scene* scene)
{
    g_current_scene = scene;
    g_current_scene->m_score = g_score;
    g_current_scene->initialise();
}

void initialise()
{
    // ————— VIDEO ————— //
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    g_display_window = SDL_CreateWindow("Stomp on 'em!",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH, WINDOW_HEIGHT,
        SDL_WINDOW_OPENGL);

    SDL_GLContext context = SDL_GL_CreateContext(g_display_window);
    SDL_GL_MakeCurrent(g_display_window, context);

#ifdef _WINDOWS
    glewInit();
#endif

    // ————— GENERAL ————— //
    glViewport(VIEWPORT_X, VIEWPORT_Y, VIEWPORT_WIDTH, VIEWPORT_HEIGHT);

    switch_shader(V_SHADER_PATH, F_SHADER_PATH);

    glClearColor(BG_RED, BG_GREEN, BG_BLUE, BG_OPACITY);

    // ————— LEVEL SETUP ————— //

    g_menu = new Menu();
    g_level_a = new LevelA();
    g_win_scene = new Win();

    g_levels[0] = g_menu;
    g_levels[1] = g_level_a;
    g_levels[2] = g_win_scene;


    // Start at menu
    switch_to_scene(g_levels[0]);
    g_levels[1]->set_spawn(g_spawn_point);

    //Mix_PlayMusic(Mix_LoadMUS("assets/audio/slight_better_song.wav"), -1);
    Mix_VolumeMusic(3.0f);

    

    // ————— BLENDING ————— //
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // ----- TEXT ----- //
    g_text_texture_id = Utility::load_texture(FONT_FILEPATH);

    g_effects = new Effects(g_projection_matrix, g_view_matrix);
    g_jumpscare = new Jumpscare();
    g_jumpscare->initialise();
}

void process_input()
{
    g_current_scene->m_state.player->set_movement(glm::vec3(0.0f));

    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        // ————— KEYSTROKES ————— //
        switch (event.type) {
            // ————— END GAME ————— //
        case SDL_QUIT:
        case SDL_WINDOWEVENT_CLOSE:
            g_game_is_running = false;
            break;

        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
            case SDLK_q:
                // Quit the game with a keystroke
                g_game_is_running = false;
                break;

            case SDLK_SPACE:
                // ————— JUMPING ————— //
                if (g_current_scene->m_state.player->m_collided_bottom)
                {
                    g_current_scene->m_state.player->m_is_jumping = true;
                    Mix_PlayChannel(-1, g_current_scene->m_state.jump_sfx, 0);
                    Mix_Volume(-1, MIX_MAX_VOLUME / 15);
                }
                break;
            case SDLK_RETURN:
                //start game
                if (!g_game_start) {
                    g_game_start = true;
                    
                    switch_shader(V_LIT_SHADER_PATH, F_LIT_SHADER_PATH);
                    
                    g_current_scene->m_state.next_scene_id = 1;
                }
                break;
            default:
                break;
            }

        default:
            break;
        }
    }

    // ————— KEY HOLD ————— //
    const Uint8* key_state = SDL_GetKeyboardState(NULL);

    if (key_state[SDL_SCANCODE_LEFT])
    {
        g_current_scene->m_state.player->move_left();
        int dir = g_current_scene->m_state.player->LEFT;
        g_current_scene->m_state.player->m_animation_indices = g_current_scene->m_state.player->m_walking[dir];
        g_current_scene->m_state.player->set_facing(dir);
    }
    else if (key_state[SDL_SCANCODE_RIGHT])
    {
        g_current_scene->m_state.player->move_right();
        int dir = g_current_scene->m_state.player->RIGHT;
        g_current_scene->m_state.player->m_animation_indices = g_current_scene->m_state.player->m_walking[dir];
        g_current_scene->m_state.player->set_facing(dir);
    }
    else if (key_state[SDL_SCANCODE_UP])
    {
        g_current_scene->m_state.player->move_up();
        //g_current_scene->m_state.player->m_animation_indices = g_current_scene->m_state.player->m_walking[g_current_scene->m_state.player->UP];
    }
    else if (key_state[SDL_SCANCODE_DOWN])
    {
        g_current_scene->m_state.player->move_down();
        //g_current_scene->m_state.player->m_animation_indices = g_current_scene->m_state.player->m_walking[g_current_scene->m_state.player->DOWN];
    }

    if (key_state[SDL_SCANCODE_LSHIFT]) { //sprint
        g_current_scene->m_state.player->set_sprint(true);
    }
    else {
        g_current_scene->m_state.player->set_sprint(false);
    }
}

void update()
{
    // ————— DELTA TIME / FIXED TIME STEP CALCULATION ————— //
    float ticks = (float)SDL_GetTicks() / MILLISECONDS_IN_SECOND;
    float delta_time = ticks - g_previous_ticks;
    g_previous_ticks = ticks;

    delta_time += g_accumulator;

    if (delta_time < FIXED_TIMESTEP)
    {
        g_accumulator = delta_time;
        return;
    }

    while (delta_time >= FIXED_TIMESTEP) {
        // ————— UPDATING THE SCENE (i.e. map, character, enemies...) ————— //
        g_current_scene->update(FIXED_TIMESTEP);
        g_score = g_current_scene->m_score; //update score

        if (!g_current_scene->m_state.player->get_active()) {

            if (g_jumpscare->finished_playing()) {
                switch_to_scene(g_levels[g_current_scene_index]);
                g_jumpscare->reset();
                g_effects->update(delta_time, 0);
            }
            else {
                if (g_jumpscare->started_playing()) {
                    g_effects->update(delta_time, 1);
                }
                else {
                    switch (g_current_scene->m_state.player->get_killer())
                    {
                    case 0:
                        g_jumpscare->play_jump(g_current_scene->m_state.player->get_position());
                        break;
                    case 1:
                        g_jumpscare->play_stalk(g_current_scene->m_state.player->get_position());
                        break;
                    case 2:
                        g_jumpscare->play_follow(g_current_scene->m_state.player->get_position());
                        break;
                    }
                    
                    g_effects->start(BLACK, 0);
                }
                
            }
            
        }
        else {
            float tint_opacity = -0.01f * g_current_scene->m_state.player->get_sprint_time() + 0.1f;
            if (tint_opacity < 0) {
                tint_opacity = 0;
            }
            else {
                g_effects->start(TINT, 0);
            }
            g_effects->update(delta_time, tint_opacity);
        }

        g_jumpscare->update(delta_time);

        delta_time -= FIXED_TIMESTEP;
    }

    g_accumulator = delta_time;


    // ————— PLAYER CAMERA ————— //
    g_view_matrix = glm::mat4(1.0f);

    g_view_matrix = glm::translate(g_view_matrix, glm::vec3(-g_current_scene->m_state.player->get_position().x, -g_current_scene->get_state().player->get_position().y, 0));

}

void render()
{
    g_shader_program.set_view_matrix(g_view_matrix);
    g_shader_program.set_light_pos(g_current_scene->m_state.player->get_position());


    glClear(GL_COLOR_BUFFER_BIT);

    // ————— RENDERING THE SCENE (i.e. map, character, enemies...) ————— //
    g_current_scene->render(&g_shader_program);

    // ----- TEXT ----- //
    //float draw_x = g_current_scene->m_state.player->get_position().x;
    //float draw_y = g_current_scene->m_state.player->get_position().y + 2.0f;

    //Utility::draw_text(g_text_texture_id, g_display_message, 0.4f, -0.1f, glm::vec3(draw_x, draw_y, 0));
    
    g_effects->render();

    g_jumpscare->render(&g_shader_program);

    SDL_GL_SwapWindow(g_display_window);
}

void shutdown()
{
    SDL_Quit();

    // ————— DELETING LEVEL A DATA (i.e. map, character, enemies...) ————— //
    delete g_level_a;
}

// ————— GAME LOOP ————— //
int main(int argc, char* argv[])
{
    initialise();

    while (g_game_is_running)
    {
        process_input();
        update();

        if (g_current_scene->m_state.next_scene_id >= 0) {
            g_current_scene_index = g_current_scene->m_state.next_scene_id;
            switch_to_scene(g_levels[g_current_scene_index]);
        }

        render();
    }

    shutdown();
    return 0;
}
