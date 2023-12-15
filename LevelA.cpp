/**
* Author: Maximilian Ta
* Assignment: The Caves (Final Project)
* Date due: 2023-12-15, 11:59pm
* I pledge that I have completed this assignment without
* collaborating with anyone else, in conformance with the
* NYU School of Engineering Policies and Procedures on
* Academic Misconduct.
*
* Original File created by Sebastián Romero Cruz
**/

#include "LevelA.h"
#include "Utility.h"

#define LEVEL_WIDTH 50
#define LEVEL_HEIGHT 50

unsigned int LEVELA_DATA[] =
{
    0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0,
    4, 2, 3, 1, 3, 2, 2, 2,14, 1, 3, 3,12, 1, 3, 1, 3,12, 2, 2, 3, 2, 3, 1, 1, 2, 7, 4, 2, 3, 1, 3, 1, 2, 1, 2, 1, 2, 2, 2, 1, 2, 1, 1, 3, 3, 2, 3, 3, 7,
    4, 3, 9,10, 3, 9,10, 1,13, 2,14, 3,13, 3,12,13, 1,13,14, 2, 1, 9, 6, 6,10, 3, 7, 4, 3, 9, 6, 6, 6, 6, 6,10, 3, 9,10, 2, 3, 1, 2, 1, 2, 2, 1, 1, 1, 7,
    4, 1, 8,11,14, 8,11, 3, 3, 3,12, 1, 2, 3,14,12, 3, 2, 3, 1, 1, 7, 0, 0, 4, 2, 7, 4, 2, 7, 0, 5, 5, 5, 5, 4, 3, 7, 4, 1, 2, 1, 2, 9,10, 2, 3, 2, 1, 7,
    4, 2, 2, 2, 3, 3, 3,12, 9, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 4, 2, 7, 4, 2, 7, 4, 2, 3, 1, 3, 7, 6, 0, 4, 1, 1, 3, 3, 7, 4, 3, 2, 1, 1, 7,
    4,12, 3, 1, 2, 1, 2, 2, 7, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 4, 1, 7, 4, 3, 7, 0, 6, 6,10, 1, 7, 0, 0, 4, 2, 3, 9, 6, 0, 0, 6,10, 1, 3, 7,
    4, 3, 1, 2, 1, 2, 2, 3, 7, 4, 1, 2, 3, 3,12, 2, 1, 1,12, 2, 2, 3, 7, 0, 4, 3, 8,11, 2, 8, 5, 5, 5,11, 2, 7, 0, 0, 4, 1, 3, 8, 5, 0, 0, 5,11, 3, 1, 7,
    4, 2, 9, 6,10, 3, 9, 6, 0, 4, 2, 9,10, 2,14, 1,14, 3,14, 3,14, 3, 7, 0, 4, 1, 1, 3, 1, 3, 1, 1, 1, 3, 1, 7, 0, 0, 4, 2, 3, 1, 1, 7, 4, 1, 1, 2, 3, 7,
    4, 3, 7, 0, 4,12, 8, 5, 5,11, 1, 7, 4, 3,14, 3,12,13,13,12,12, 3, 7, 0, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 4, 2, 2, 1, 2, 8,11, 1, 2, 2, 3, 7,
    4, 1, 7, 0, 4, 3, 2, 1, 3, 2, 3, 7, 4, 1, 1, 2,14, 2, 1, 2, 2, 3, 7, 0, 5, 5, 5, 5, 5, 5, 5, 0, 0, 5, 5, 5, 5, 0, 4, 1, 3, 2, 3, 3, 2, 1, 2, 1, 1, 7,
    4, 1, 7, 0, 4, 2, 9, 6, 6, 6, 6, 0, 4, 2,13, 2,13, 3,14,12,13,14, 7, 4, 3, 2, 3, 1,12, 1, 2, 8,11, 1, 3, 1, 2, 7, 4, 2, 3, 1, 1, 1, 3, 1, 2, 1, 1, 7,
    4, 1, 7, 0, 4, 3, 8, 5, 5, 5, 5, 0, 4, 2,12, 2, 3, 2, 3, 2, 2, 2, 7, 4,13,14,12, 1, 3, 3, 3,14, 1, 1, 9,10, 2, 7, 0, 6, 6, 6,10, 1, 3, 9, 6, 6, 6, 0,
    4, 3, 8, 5,11, 2, 2, 3, 2, 2, 2, 7, 4, 1,14,13, 2,12,12,13,14,13, 7, 4, 1, 3,14, 2, 9,10, 3,13, 1, 9, 0,11, 3, 7, 0, 0, 5, 5,11, 2, 3, 8, 5, 5, 0, 0,
    4, 3, 2, 1, 3, 2, 9, 6, 6,10, 2, 7, 4, 3, 3, 1, 3, 1,13,12, 1, 3, 7, 4, 2, 1,12, 2, 8,11, 3,12, 1, 7, 4, 2, 2, 8, 0, 4, 3, 2, 1, 1, 2, 1, 1, 1, 7, 0,
    0, 6, 6, 6,10,14, 8, 5, 5,11, 3, 7, 4, 1, 3,13,12, 1, 2, 1, 2,13, 8,11, 3,14,14, 2, 3, 2, 1, 1, 1, 8,11, 3, 2, 1, 7, 4, 2, 9,10, 1, 2, 9,10, 3, 7, 0,
    0, 5, 5, 5,11, 2, 3, 1, 2, 3, 2, 8, 5, 6, 6, 6, 6, 6, 6, 6, 6,10, 2, 3, 3,13, 3, 1, 2,14, 2,12,13,14, 2, 9,10, 2, 7, 4, 1, 8,11, 2, 1, 8,11, 1, 7, 0,
    4, 1, 2, 3, 3, 3, 9, 6, 6, 6,10, 3, 3, 8, 5, 5, 5, 5, 5, 5, 5,11, 1,12, 2, 2, 3,13, 2,14, 3, 1, 3, 1, 1, 7, 4, 2, 7, 4, 3, 1, 3, 3, 3, 3, 1, 3, 7, 0,
    4, 1, 9,10, 2, 3, 8, 5, 5, 5,11, 3, 2, 2, 2,14, 2, 2, 2, 2, 2, 2, 2, 9, 6,10, 3,12, 2,13,14,13,14, 2, 3, 8,11, 3, 7, 4, 2, 2, 9, 6, 6,10, 1, 2, 7, 0,
    4, 2, 8,11, 3, 2,13, 2, 3, 3, 2, 2,13, 2, 3,12, 3, 2, 9,10, 1,14, 1, 7, 0, 4, 3,13, 3, 9, 6, 6, 6,10,13, 2, 2, 2, 7, 4, 1, 3, 7, 0, 0, 4, 3, 2, 7, 0,
    4, 3, 3, 1, 9, 6, 6,10, 2, 9, 6, 6, 6,10, 2,13, 3,14, 8,11, 2,13, 3, 8, 5,11, 1,12, 3, 8, 5, 5, 5,11,14,13, 2,13, 7, 4, 2, 2, 7, 0, 0, 4, 1, 2, 7, 0,
    0, 6,10, 1, 7, 0, 0, 4, 3, 8, 5, 5, 5,11, 2,14, 1,13, 2, 1, 1, 1, 3, 3, 2,12, 3,13, 2, 3,13, 3, 3, 1, 1,13, 3, 2, 7, 4, 3, 1, 8, 5, 5,11, 3, 1, 7, 0,
    0, 5,11, 2, 8, 5, 0, 4, 3, 2, 2, 2, 1, 1, 3, 1, 2,14, 2, 9, 6, 6,10, 1, 1, 1, 3,14, 3, 3,13, 2, 9,10, 1, 3, 3, 2, 7, 4, 3, 2, 2, 3, 2, 2, 1, 1, 7, 0,
    4, 2, 2, 2, 3, 3, 7, 4, 1, 9,10, 3, 9, 6, 6,10, 2,12, 2, 8, 5, 5,11, 1,13, 9, 6, 6,10, 2,13, 1, 8,11, 3, 9,10, 2, 7, 4, 1, 9,10, 3, 2, 9,10, 1, 7, 0,
    4, 2, 1, 1, 3, 2, 7, 4, 2, 7, 4, 2, 8, 5, 5,11, 2,13, 3, 1, 1, 2, 3, 1,13, 8, 5, 5,11, 3, 1, 1, 3, 1, 3, 7, 4, 3, 7, 4, 3, 8,11, 1, 1, 8,11, 2, 7, 0,
    4, 3, 3, 2, 3, 1, 8,11, 3, 7, 4, 2, 2, 1, 3, 1, 3, 1, 9,10, 1,13,12,14,12, 2, 3, 1, 3, 2, 9,10, 3,14, 2, 8,11, 3, 7, 4, 3, 2, 3, 3, 3, 2, 1, 1, 7, 0,
    4, 1, 3, 3, 2, 1, 2, 1, 3, 7, 4, 2, 9, 6, 6, 6,10, 1, 8,11, 3, 3, 1, 2, 2, 3,14,12,13, 1, 8, 4, 1,13, 3, 2, 2, 3, 7, 0, 6, 6, 6, 6, 6, 6,10, 3, 7, 0,
    0, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 6, 0, 0, 0, 0, 4, 1, 2, 2, 2, 9, 6, 6, 6, 6, 6, 6,10, 3, 2, 7, 6, 6, 6, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 7, 0,
    0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 6, 6, 6, 6, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,11, 3, 7, 0,
    4, 2, 2, 2, 3, 2, 1, 3, 2, 2, 2, 1, 1, 3, 3, 1, 7, 0, 5, 0, 4, 2, 1, 1, 1, 3, 1, 3, 2, 7, 4, 3, 2, 2, 3, 1, 1, 2, 1, 1, 1, 1, 1, 2, 2, 2, 1, 2, 7, 0,
    4, 2, 3, 2, 3, 9, 6, 6, 6, 6,10, 2, 9, 6,10, 3, 7, 4, 2, 7, 0, 6,10, 1, 9, 6, 6,10, 2, 7, 4, 1, 9, 6, 6, 6,10, 1, 9, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0,
    4, 2, 3, 3, 2, 7, 0, 0, 0, 0, 4, 2, 7, 0, 4, 3, 8,11, 2, 8, 5, 0, 4, 3, 7, 0, 5,11, 1, 7, 4, 1, 7, 0, 5, 5,11, 1, 8, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    4, 3, 3, 2, 1, 7, 0, 0, 0, 0,11, 2, 8, 5, 4, 1, 2, 2, 2, 2, 3, 7, 4, 1, 7, 4, 3, 1, 3, 8,11, 3, 7, 4, 1, 1, 2, 2, 2, 1, 1, 7, 0, 0, 0, 0, 0, 0, 0, 0,
    4, 3, 1, 1, 1, 7, 0, 0, 0, 4, 2, 2, 3, 2, 7,10, 2, 9, 6,10, 3, 7, 4, 2, 7, 0, 6, 6,10, 1, 1, 1, 7, 4, 2, 3, 2, 1, 3, 1, 3, 7, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 6, 6, 6, 6, 0, 0, 0, 0, 4, 1, 9,10, 3, 8,11, 2, 8, 5,11, 2, 8,11, 3, 7, 0, 5, 0, 4, 2, 9, 6, 0, 4, 1, 1, 3, 3, 1, 2, 1, 7, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 5, 5, 5,11, 2, 7, 4, 1, 1, 1, 1, 2, 3, 3, 1, 3, 1, 1, 7, 4, 2, 7, 4, 2, 7, 0, 0, 4, 1, 1, 3, 1, 2, 1, 3, 7, 0, 5, 5, 5, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 4, 1, 1, 1, 1, 2, 7, 0,10, 1, 9, 6,10, 1, 9, 6, 6, 6, 6, 5,11, 2, 7, 4, 1, 7, 0, 0, 4, 1, 2, 2, 3, 1, 2, 2, 7, 4, 1, 3, 2, 7, 0, 0, 0,
    0, 0, 0, 0, 0, 4, 1, 9, 6,10, 3, 8, 5,11, 1, 7, 0, 4, 2, 8, 5, 5, 0, 4, 1, 1, 2, 7,11, 1, 7, 0, 0, 4, 2, 3, 1, 3, 2, 1, 3, 7, 4, 2, 3, 2, 8, 5, 5, 0,
    0, 5, 5, 5, 5,11, 3, 7, 0, 4, 2, 1, 3, 1, 1, 7, 0, 4, 3, 2, 2, 3, 7, 4, 2, 9, 6, 4, 3, 1, 7, 0, 0, 0, 6, 6, 6, 6, 6, 6, 6, 0, 4, 1, 2, 1, 2, 1, 2, 7,
    4, 1, 3, 3, 1, 2, 2, 7, 0, 4, 1, 9, 6,10, 3, 8, 5,11, 1, 9,10, 2, 8,11, 2, 8, 5,11, 3, 9, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 0, 4, 1, 1, 1, 9,10, 1, 7,
    0, 6, 6, 6, 6,10, 2, 7, 0, 4, 2, 7, 0, 4, 1, 2, 2, 1, 3, 7, 4, 3, 3, 3, 2, 2, 3, 1, 2, 7, 0, 0, 0, 0, 0, 0, 4, 1, 2, 2, 3, 7, 4, 1, 2, 2, 7, 4, 1, 7,
    0, 0, 0, 0, 0, 4, 2, 7, 0, 0, 6, 0, 0, 0, 6, 6, 6, 6, 6, 0, 0, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 4, 2, 9, 6, 6, 0, 4, 3, 1, 1, 7, 4, 3, 7,
    0, 0, 0, 0, 0, 4, 3, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 4, 1, 7, 0, 0, 0, 4, 2, 3, 2, 7, 4, 3, 7,
    0, 0, 0, 0, 0, 4, 3, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 2, 3, 3, 1, 1, 1, 3, 1, 1, 3, 2, 1, 2, 1, 2, 7, 0, 0, 4, 1, 7, 0, 0, 0, 4, 2, 1, 3, 7, 4, 1, 7,
    0, 0, 0, 0, 0, 4, 2, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 3, 2, 3, 3, 3, 1, 1, 1, 1, 3, 3, 1, 1, 1, 1, 7, 0, 0, 4, 1, 7, 0, 0, 0, 4, 1, 3, 1, 7, 4, 2, 7,
    0, 5, 5, 5, 5,11, 1, 8, 5, 5, 5, 5, 5, 5, 5, 5, 5,11, 2, 3, 3, 3, 2, 3, 2, 1, 1, 3, 3, 1, 2, 1, 3, 8, 5, 5,11, 1, 8, 5, 5, 5,11, 2, 3, 1, 7, 4, 1, 7,
    4, 1, 1, 2, 3, 2, 1, 1, 3, 1, 2, 2, 2, 3, 2, 3, 3, 1, 3, 1, 3, 2, 2, 1, 2, 2, 1, 2, 1, 1, 2, 1, 1, 3, 2, 1, 1, 3, 2, 2, 1, 3, 1, 3, 2, 1, 7, 4, 1, 7,
    0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,10, 3, 2, 1, 1, 3, 3, 3, 3, 3, 1, 3, 3, 1, 1, 2, 9, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 4, 3, 7,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 2, 2, 2, 2, 1, 1, 2, 3, 1, 2, 2, 1, 1, 2, 2, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 3, 7,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 2, 3, 1, 1, 3, 3, 1, 2, 2, 1, 1, 3, 2, 1, 1, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 2, 7,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0,
};

LevelA::~LevelA()
{
    delete [] m_state.enemies;
    delete [] m_state.spawnpoints;
    delete    m_state.player;
    delete    m_state.map;
    Mix_FreeMusic(m_state.bgm);
}

void LevelA::initialise()
{
    GLuint map_texture_id = Utility::load_texture("assets/images/platforms.png");
    m_state.map = new Map(LEVEL_WIDTH, LEVEL_HEIGHT, LEVELA_DATA, map_texture_id, 1.0f, 15, 1);
    
    // Code from main.cpp's initialise()

    // Existing
    m_state.player = new Player();
    m_state.player->set_position(m_spawn);
    m_state.player->set_movement(glm::vec3(0.0f));
    m_state.player->set_speed(1.25f);
    m_state.player->m_texture_id = Utility::load_texture("assets/images/player.png");
    
    // Walking
    m_state.player->m_walking[m_state.player->LEFT]  = new int[4] { 1, 5, 9,  13 };
    m_state.player->m_walking[m_state.player->RIGHT] = new int[4] { 3, 7, 11, 15 };

    m_state.player->m_animation_indices = m_state.player->m_walking[m_state.player->RIGHT];
    m_state.player->m_animation_frames = 4;
    m_state.player->m_animation_index  = 0;
    m_state.player->m_animation_time   = 0.0f;
    m_state.player->m_animation_cols   = 4;
    m_state.player->m_animation_rows   = 4;
    m_state.player->set_height(0.8f);
    m_state.player->set_width(0.3f);
    
    // Jumping
    m_state.player->m_jumping_power = 5.0f;
    
    /**
     Enemies' stuff */

    m_state.enemies = new Enemy[ENEMY_COUNT];

    const int    LEFT = 0, RIGHT = 1, UP = 2,DOWN = 3;

    m_state.enemies[0].m_walking[LEFT] = new int[4] { 1, 5, 9, 13 };
    m_state.enemies[0].m_walking[RIGHT] = new int[4] { 3, 7, 11, 15 };
    m_state.enemies[0].m_animation_indices = m_state.enemies[0].m_walking[RIGHT];
    m_state.enemies[0].m_animation_frames = 4;
    m_state.enemies[0].m_animation_index = 0;
    m_state.enemies[0].m_animation_time = 0.0f;
    m_state.enemies[0].m_animation_cols = 4;
    m_state.enemies[0].m_animation_rows = 4;

    m_state.enemies[0].set_ai_type(JUMP);
    m_state.enemies[0].set_ai_state(IDLE);
    m_state.enemies[0].m_texture_id = Utility::load_texture("assets/images/jump_monster.png");
    m_state.enemies[0].set_position(glm::vec3(31.0f, -45.0f, 0.0f));
    m_state.enemies[0].set_speed(3.25f);
    m_state.enemies[0].set_width(0.3f);
    m_state.enemies[0].set_height(0.8f);

    m_state.enemies[1].m_walking[LEFT] = new int[1] { 3 };
    m_state.enemies[1].m_walking[RIGHT] = new int[1] { 1};
    m_state.enemies[1].m_animation_indices = m_state.enemies[1].m_walking[RIGHT];
    m_state.enemies[1].m_animation_frames = 1;
    m_state.enemies[1].m_animation_index = 0;
    m_state.enemies[1].m_animation_time = 0.0f;
    m_state.enemies[1].m_animation_cols = 4;
    m_state.enemies[1].m_animation_rows = 1;

    m_state.enemies[1].set_ai_type(STALK);
    m_state.enemies[1].set_ai_state(IDLE);
    m_state.enemies[1].m_texture_id = Utility::load_texture("assets/images/stalk_monster.png");
    m_state.enemies[1].set_position(glm::vec3(25.0f, -45.0f, 0.0f));
    m_state.enemies[1].set_speed(7.5f);
    m_state.enemies[1].set_width(0.3f);
    m_state.enemies[1].set_height(0.8f);
    m_state.enemies[1].deactivate();
    m_state.enemies[1].set_patrol_area(glm::vec4(33.0f, -41.0f, 17.0f, -49.0f));

    m_state.enemies[2].m_walking[LEFT] = new int[4] { 1, 5, 9, 13 };
    m_state.enemies[2].m_walking[RIGHT] = new int[4] { 3, 7, 11, 15 };
    m_state.enemies[2].m_animation_indices = m_state.enemies[2].m_walking[RIGHT];
    m_state.enemies[2].m_animation_frames = 4;
    m_state.enemies[2].m_animation_index = 0;
    m_state.enemies[2].m_animation_time = 0.0f;
    m_state.enemies[2].m_animation_cols = 4;
    m_state.enemies[2].m_animation_rows = 4;

    m_state.enemies[2].set_ai_type(JUMP);
    m_state.enemies[2].set_ai_state(IDLE);
    m_state.enemies[2].m_texture_id = Utility::load_texture("assets/images/jump_monster.png");
    m_state.enemies[2].set_position(glm::vec3(2.0f, -45.0f, 0.0f));
    m_state.enemies[2].set_speed(3.25f);
    m_state.enemies[2].set_width(0.3f);
    m_state.enemies[2].set_height(0.8f);

    m_state.enemies[3].m_walking[LEFT] = new int[4] { 1, 5, 9, 13 };
    m_state.enemies[3].m_walking[RIGHT] = new int[4] { 3, 7, 11, 15 };
    m_state.enemies[3].m_animation_indices = m_state.enemies[3].m_walking[RIGHT];
    m_state.enemies[3].m_animation_frames = 4;
    m_state.enemies[3].m_animation_index = 0;
    m_state.enemies[3].m_animation_time = 0.0f;
    m_state.enemies[3].m_animation_cols = 4;
    m_state.enemies[3].m_animation_rows = 4;

    m_state.enemies[3].set_ai_type(JUMP);
    m_state.enemies[3].set_ai_state(IDLE);
    m_state.enemies[3].m_texture_id = Utility::load_texture("assets/images/jump_monster.png");
    m_state.enemies[3].set_position(glm::vec3(10.0f, -35.0f, 0.0f));
    m_state.enemies[3].set_speed(3.25f);
    m_state.enemies[3].set_width(0.3f);
    m_state.enemies[3].set_height(0.8f);
    
    m_state.enemies[4].m_walking[LEFT] = new int[4] { 1, 5, 9, 13 };
    m_state.enemies[4].m_walking[RIGHT] = new int[4] { 3, 7, 11, 15 };
    m_state.enemies[4].m_animation_indices = m_state.enemies[4].m_walking[LEFT];
    m_state.enemies[4].m_animation_frames = 4;
    m_state.enemies[4].m_animation_index = 0;
    m_state.enemies[4].m_animation_time = 0.0f;
    m_state.enemies[4].m_animation_cols = 4;
    m_state.enemies[4].m_animation_rows = 4;

    m_state.enemies[4].set_ai_type(JUMP);
    m_state.enemies[4].set_ai_state(IDLE);
    m_state.enemies[4].m_texture_id = Utility::load_texture("assets/images/jump_monster.png");
    m_state.enemies[4].set_position(glm::vec3(18.0f, -34.0f, 0.0f));
    m_state.enemies[4].set_speed(3.25f);
    m_state.enemies[4].set_width(0.3f);
    m_state.enemies[4].set_height(0.8f);

    m_state.enemies[5].m_walking[LEFT] = new int[1] { 3 };
    m_state.enemies[5].m_walking[RIGHT] = new int[1] { 1};
    m_state.enemies[5].m_walking[UP] = new int[1] { 2};
    m_state.enemies[5].m_walking[DOWN] = new int[1] { 0};
    m_state.enemies[5].m_animation_indices = m_state.enemies[5].m_walking[RIGHT];
    m_state.enemies[5].m_animation_frames = 1;
    m_state.enemies[5].m_animation_index = 0;
    m_state.enemies[5].m_animation_time = 0.0f;
    m_state.enemies[5].m_animation_cols = 4;
    m_state.enemies[5].m_animation_rows = 1;

    m_state.enemies[5].set_ai_type(STALK);
    m_state.enemies[5].set_ai_state(IDLE);
    m_state.enemies[5].m_texture_id = Utility::load_texture("assets/images/stalk_monster.png");
    m_state.enemies[5].set_position(glm::vec3(18.0f, -31.0f, 0.0f));
    m_state.enemies[5].set_speed(7.5f);
    m_state.enemies[5].set_width(0.3f);
    m_state.enemies[5].set_height(0.8f);
    m_state.enemies[5].deactivate();
    m_state.enemies[5].set_patrol_area(glm::vec4(32.0f, -27.0f, 9.0f, -40.0f));

    m_state.enemies[6].m_walking[LEFT] = new int[2] { 0,1 };
    m_state.enemies[6].m_walking[RIGHT] = new int[2] { 2,3};
    m_state.enemies[6].m_animation_indices = m_state.enemies[6].m_walking[RIGHT];
    m_state.enemies[6].m_animation_frames = 2;
    m_state.enemies[6].m_animation_index = 0;
    m_state.enemies[6].m_animation_time = 0.0f;
    m_state.enemies[6].m_animation_cols = 2;
    m_state.enemies[6].m_animation_rows = 2;

    m_state.enemies[6].set_ai_type(FOLLOW);
    m_state.enemies[6].set_ai_state(IDLE);
    m_state.enemies[6].m_texture_id = Utility::load_texture("assets/images/chase_monster.png");
    m_state.enemies[6].set_position(glm::vec3(47.0f, -26.0f, 0.0f));
    m_state.enemies[6].set_speed(1.0f);
    m_state.enemies[6].set_width(0.8f);
    m_state.enemies[6].set_height(0.8f);
    m_state.enemies[6].deactivate();
    m_state.enemies[6].set_patrol_area(glm::vec4(49.0f, 0.0f,34.0f, -26.0f));

    m_state.enemies[7].m_walking[LEFT] = new int[4] { 1, 5, 9, 13 };
    m_state.enemies[7].m_walking[RIGHT] = new int[4] { 3, 7, 11, 15 };
    m_state.enemies[7].m_animation_indices = m_state.enemies[7].m_walking[LEFT];
    m_state.enemies[7].m_animation_frames = 4;
    m_state.enemies[7].m_animation_index = 0;
    m_state.enemies[7].m_animation_time = 0.0f;
    m_state.enemies[7].m_animation_cols = 4;
    m_state.enemies[7].m_animation_rows = 4;

    m_state.enemies[7].set_ai_type(JUMP);
    m_state.enemies[7].set_ai_state(IDLE);
    m_state.enemies[7].m_texture_id = Utility::load_texture("assets/images/jump_monster.png");
    m_state.enemies[7].set_position(glm::vec3(36.0f, -3.25f, 0.0f));
    m_state.enemies[7].set_speed(2.75f);
    m_state.enemies[7].set_width(0.3f);
    m_state.enemies[7].set_height(0.7f);

    m_state.enemies[8].m_walking[LEFT] = new int[1] { 3 };
    m_state.enemies[8].m_walking[RIGHT] = new int[1] { 1};
    m_state.enemies[8].m_walking[UP] = new int[1] { 2};
    m_state.enemies[8].m_walking[DOWN] = new int[1] { 0};
    m_state.enemies[8].m_animation_indices = m_state.enemies[8].m_walking[RIGHT];
    m_state.enemies[8].m_animation_frames = 1;
    m_state.enemies[8].m_animation_index = 0;
    m_state.enemies[8].m_animation_time = 0.0f;
    m_state.enemies[8].m_animation_cols = 4;
    m_state.enemies[8].m_animation_rows = 1;

    m_state.enemies[8].set_ai_type(STALK);
    m_state.enemies[8].set_ai_state(IDLE);
    m_state.enemies[8].m_texture_id = Utility::load_texture("assets/images/stalk_monster.png");
    m_state.enemies[8].set_position(glm::vec3(17.0f, -11.0f, 0.0f));
    m_state.enemies[8].set_speed(7.5f);
    m_state.enemies[8].set_width(0.3f);
    m_state.enemies[8].set_height(0.8f);
    m_state.enemies[8].deactivate();
    m_state.enemies[8].set_patrol_area(glm::vec4(22.0f, -4.0f, 0.0f, -14.0f));

    m_state.enemies[9].m_walking[LEFT] = new int[2] { 0, 1 };
    m_state.enemies[9].m_walking[RIGHT] = new int[2] { 2, 3};
    m_state.enemies[9].m_animation_indices = m_state.enemies[9].m_walking[RIGHT];
    m_state.enemies[9].m_animation_frames = 2;
    m_state.enemies[9].m_animation_index = 0;
    m_state.enemies[9].m_animation_time = 0.0f;
    m_state.enemies[9].m_animation_cols = 2;
    m_state.enemies[9].m_animation_rows = 2;

    m_state.enemies[9].set_ai_type(FOLLOW);
    m_state.enemies[9].set_ai_state(IDLE);
    m_state.enemies[9].m_texture_id = Utility::load_texture("assets/images/chase_monster.png");
    m_state.enemies[9].set_position(glm::vec3(28.0f, -20.0f, 0.0f));
    m_state.enemies[9].set_speed(1.0f);
    m_state.enemies[9].set_width(0.8f);
    m_state.enemies[9].set_height(0.8f);
    m_state.enemies[9].deactivate();
    m_state.enemies[9].set_patrol_area(glm::vec4(38.0f, -15.0f, 6.0f, -26.0f));

    m_state.enemies[10].m_walking[LEFT] = new int[1] { 3 };
    m_state.enemies[10].m_walking[RIGHT] = new int[1] { 1};
    m_state.enemies[10].m_walking[UP] = new int[1] { 2};
    m_state.enemies[10].m_walking[DOWN] = new int[1] { 0};
    m_state.enemies[10].m_animation_indices = m_state.enemies[10].m_walking[RIGHT];
    m_state.enemies[10].m_animation_frames = 1;
    m_state.enemies[10].m_animation_index = 0;
    m_state.enemies[10].m_animation_time = 0.0f;
    m_state.enemies[10].m_animation_cols = 4;
    m_state.enemies[10].m_animation_rows = 1;

    m_state.enemies[10].set_ai_type(STALK);
    m_state.enemies[10].set_ai_state(IDLE);
    m_state.enemies[10].m_texture_id = Utility::load_texture("assets/images/stalk_monster.png");
    m_state.enemies[10].set_position(glm::vec3(28.0f, -19.0f, 0.0f));
    m_state.enemies[10].set_speed(7.5f);
    m_state.enemies[10].set_width(0.3f);
    m_state.enemies[10].set_height(0.8f);
    m_state.enemies[10].deactivate();
    m_state.enemies[10].set_patrol_area(glm::vec4(38.0f, -15.0f, 6.0f, -26.0f));

    m_state.enemies[11].m_walking[LEFT] = new int[4] { 1, 5, 9, 13 };
    m_state.enemies[11].m_walking[RIGHT] = new int[4] { 3, 7, 11, 15 };
    m_state.enemies[11].m_animation_indices = m_state.enemies[11].m_walking[LEFT];
    m_state.enemies[11].m_animation_frames = 4;
    m_state.enemies[11].m_animation_index = 0;
    m_state.enemies[11].m_animation_time = 0.0f;
    m_state.enemies[11].m_animation_cols = 4;
    m_state.enemies[11].m_animation_rows = 4;

    m_state.enemies[11].set_ai_type(JUMP);
    m_state.enemies[11].set_ai_state(IDLE);
    m_state.enemies[11].m_texture_id = Utility::load_texture("assets/images/jump_monster.png");
    m_state.enemies[11].set_position(glm::vec3(11.0f, -25.0f, 0.0f));
    m_state.enemies[11].set_speed(2.75f);
    m_state.enemies[11].set_width(0.3f);
    m_state.enemies[11].set_height(0.7f);

    m_state.enemies[12].m_walking[LEFT] = new int[4] { 1, 5, 9, 13 };
    m_state.enemies[12].m_walking[RIGHT] = new int[4] { 3, 7, 11, 15 };
    m_state.enemies[12].m_animation_indices = m_state.enemies[12].m_walking[LEFT];
    m_state.enemies[12].m_animation_frames = 4;
    m_state.enemies[12].m_animation_index = 0;
    m_state.enemies[12].m_animation_time = 0.0f;
    m_state.enemies[12].m_animation_cols = 4;
    m_state.enemies[12].m_animation_rows = 4;

    m_state.enemies[12].set_ai_type(JUMP);
    m_state.enemies[12].set_ai_state(IDLE);
    m_state.enemies[12].m_texture_id = Utility::load_texture("assets/images/jump_monster.png");
    m_state.enemies[12].set_position(glm::vec3(29.0f, -26.0f, 0.0f));
    m_state.enemies[12].set_speed(2.75f);
    m_state.enemies[12].set_width(0.3f);
    m_state.enemies[12].set_height(0.7f);

    //Spawnpoints
    m_state.spawnpoints = new Spawnpoint[SPAWNPOINT_COUNT];
    m_state.spawnpoints[0].m_texture_id = Utility::load_texture("assets/images/doll.png");
    m_state.spawnpoints[0].set_position(glm::vec3(44.0f, -36.0f, 0.0f));
    m_state.spawnpoints[0].set_speed(0.0f);
    m_state.spawnpoints[0].set_movement(glm::vec3(1.0f, 0.0f, 0.0f));
    const char** dialogue_0 = new const char* [8];
    dialogue_0[0] = "TALK TO ME";
    dialogue_0[1] = "YOU ARE STUCK";
    dialogue_0[2] = "NOT THE FIRST";
    dialogue_0[3] = "MANY HAVE DIED";
    dialogue_0[4] = "I WILL HELP YOU";
    dialogue_0[5] = "COLLECT TEN PAPERS";
    dialogue_0[6] = "I AM WATCHING";
    dialogue_0[7] = "I WILL SEE YOU AGAIN";
    m_state.spawnpoints[0].set_dialogue(8, dialogue_0);

    m_state.spawnpoints[1].m_texture_id = Utility::load_texture("assets/images/doll.png");
    m_state.spawnpoints[1].set_position(glm::vec3(1.0f, -38.25f, 0.0f));
    m_state.spawnpoints[1].set_speed(0.0f);
    m_state.spawnpoints[1].set_movement(glm::vec3(1.0f, 0.0f, 0.0f));
    const char** dialogue_1 = new const char* [6];
    dialogue_1[0] = "STILL ALIVE";
    dialogue_1[1] = "GOOD";
    dialogue_1[2] = "YOU SHOULD HAVE ONE PAPER";
    dialogue_1[3] = "THREE MORE AHEAD";
    dialogue_1[4] = "I AM WATCHING";
    dialogue_1[5] = "I WILL SEE YOU AGAIN";
    m_state.spawnpoints[1].set_dialogue(6, dialogue_1);

    m_state.spawnpoints[2].m_texture_id = Utility::load_texture("assets/images/doll.png");
    m_state.spawnpoints[2].set_position(glm::vec3(36.0f, -33.5f, 0.0f));
    m_state.spawnpoints[2].set_speed(0.0f);
    m_state.spawnpoints[2].set_movement(glm::vec3(1.0f, 0.0f, 0.0f));
    const char** dialogue_2 = new const char* [8];
    dialogue_2[0] = "STILL ALIVE";
    dialogue_2[1] = "GOOD";
    dialogue_2[2] = "TWO MORE AHEAD";
    dialogue_2[3] = "DANGER AWAITS";
    dialogue_2[4] = "NEW FORMS OF EVIL";
    dialogue_2[5] = "GOOD LUCK";
    dialogue_2[6] = "I AM WATCHING";
    dialogue_2[7] = "I WILL SEE YOU AGAIN";
    m_state.spawnpoints[2].set_dialogue(8, dialogue_2);

    m_state.spawnpoints[3].m_texture_id = Utility::load_texture("assets/images/doll.png");
    m_state.spawnpoints[3].set_position(glm::vec3(3.0f, -23.5f, 0.0f));
    m_state.spawnpoints[3].set_speed(0.0f);
    m_state.spawnpoints[3].set_movement(glm::vec3(1.0f, 0.0f, 0.0f));
    const char** dialogue_3 = new const char* [5];
    dialogue_3[0] = "YOUR FINAL TRIAL";
    dialogue_3[1] = "THREE MORE AHEAD";
    dialogue_3[2] = "YOUR ESCAPE IS IMMINENT";
    dialogue_3[3] = "YOU WILL BE FREE";
    dialogue_3[4] = "GOOD LUCK";
    m_state.spawnpoints[3].set_dialogue(5, dialogue_3);
    

    //Goal
    m_state.goals = new Goal[GOAL_COUNT];
    m_state.goals[0].m_walking[LEFT] = new int[1] {0};
    m_state.goals[0].m_animation_frames = 1;
    m_state.goals[0].m_animation_index = 0;
    m_state.goals[0].m_animation_time = 0.0f;
    m_state.goals[0].m_animation_cols = 10;
    m_state.goals[0].m_animation_rows = 1;
    m_state.goals[0].m_texture_id = Utility::load_texture("assets/images/sigils.png");
    m_state.goals[0].set_position(glm::vec3(40.0f, -39.0f, 0.0f));
    m_state.goals[0].set_speed(0.0f);
    m_state.goals[0].set_movement(glm::vec3(-1.0f, 0.0f, 0.0f));
    m_state.goals[0].set_scale(glm::vec3(0.5f));
    m_state.goals[0].m_animation_indices = m_state.goals[0].m_walking[LEFT];

    m_state.goals[1].m_walking[LEFT] = new int[1] {1};
    m_state.goals[1].m_animation_frames = 1;
    m_state.goals[1].m_animation_index = 0;
    m_state.goals[1].m_animation_time = 0.0f;
    m_state.goals[1].m_animation_cols = 10;
    m_state.goals[1].m_animation_rows = 1;
    m_state.goals[1].m_texture_id = Utility::load_texture("assets/images/sigils.png");
    m_state.goals[1].set_position(glm::vec3(13.0f, -32.0f, 0.0f));
    m_state.goals[1].set_speed(0.0f);
    m_state.goals[1].set_movement(glm::vec3(-1.0f, 0.0f, 0.0f));
    m_state.goals[1].set_scale(glm::vec3(0.5f));
    m_state.goals[1].m_animation_indices = m_state.goals[1].m_walking[LEFT];

    m_state.goals[2].m_walking[LEFT] = new int[1] {2};
    m_state.goals[2].m_animation_frames = 1;
    m_state.goals[2].m_animation_index = 0;
    m_state.goals[2].m_animation_time = 0.0f;
    m_state.goals[2].m_animation_cols = 10;
    m_state.goals[2].m_animation_rows = 1;
    m_state.goals[2].m_texture_id = Utility::load_texture("assets/images/sigils.png");
    m_state.goals[2].set_position(glm::vec3(21.0f, -34.0f, 0.0f));
    m_state.goals[2].set_speed(0.0f);
    m_state.goals[2].set_movement(glm::vec3(-1.0f, 0.0f, 0.0f));
    m_state.goals[2].set_scale(glm::vec3(0.5f));
    m_state.goals[2].m_animation_indices = m_state.goals[2].m_walking[LEFT];

    m_state.goals[3].m_walking[LEFT] = new int[1] {3};
    m_state.goals[3].m_animation_frames = 1;
    m_state.goals[3].m_animation_index = 0;
    m_state.goals[3].m_animation_time = 0.0f;
    m_state.goals[3].m_animation_cols = 10;
    m_state.goals[3].m_animation_rows = 1;
    m_state.goals[3].m_texture_id = Utility::load_texture("assets/images/sigils.png");
    m_state.goals[3].set_position(glm::vec3(26.0f, -34.0f, 0.0f));
    m_state.goals[3].set_speed(0.0f);
    m_state.goals[3].set_movement(glm::vec3(-1.0f, 0.0f, 0.0f));
    m_state.goals[3].set_scale(glm::vec3(0.5f));
    m_state.goals[3].m_animation_indices = m_state.goals[3].m_walking[LEFT];

    m_state.goals[4].m_walking[LEFT] = new int[1] {4};
    m_state.goals[4].m_animation_frames = 1;
    m_state.goals[4].m_animation_index = 0;
    m_state.goals[4].m_animation_time = 0.0f;
    m_state.goals[4].m_animation_cols = 10;
    m_state.goals[4].m_animation_rows = 1;
    m_state.goals[4].m_texture_id = Utility::load_texture("assets/images/sigils.png");
    m_state.goals[4].set_position(glm::vec3(46.5f, -18.5f, 0.0f));
    m_state.goals[4].set_speed(0.0f);
    m_state.goals[4].set_movement(glm::vec3(-1.0f, 0.0f, 0.0f));
    m_state.goals[4].set_scale(glm::vec3(0.5f));
    m_state.goals[4].m_animation_indices = m_state.goals[4].m_walking[LEFT];

    m_state.goals[5].m_walking[LEFT] = new int[1] {5};
    m_state.goals[5].m_animation_frames = 1;
    m_state.goals[5].m_animation_index = 0;
    m_state.goals[5].m_animation_time = 0.0f;
    m_state.goals[5].m_animation_cols = 10;
    m_state.goals[5].m_animation_rows = 1;
    m_state.goals[5].m_texture_id = Utility::load_texture("assets/images/sigils.png");
    m_state.goals[5].set_position(glm::vec3(40.5f, -18.5f, 0.0f));
    m_state.goals[5].set_speed(0.0f);
    m_state.goals[5].set_movement(glm::vec3(-1.0f, 0.0f, 0.0f));
    m_state.goals[5].set_scale(glm::vec3(0.5f));
    m_state.goals[5].m_animation_indices = m_state.goals[5].m_walking[LEFT];

    m_state.goals[6].m_walking[LEFT] = new int[1] {6};
    m_state.goals[6].m_animation_frames = 1;
    m_state.goals[6].m_animation_index = 0;
    m_state.goals[6].m_animation_time = 0.0f;
    m_state.goals[6].m_animation_cols = 10;
    m_state.goals[6].m_animation_rows = 1;
    m_state.goals[6].m_texture_id = Utility::load_texture("assets/images/sigils.png");
    m_state.goals[6].set_position(glm::vec3(19.0f, -7.0f, 0.0f));
    m_state.goals[6].set_speed(0.0f);
    m_state.goals[6].set_movement(glm::vec3(-1.0f, 0.0f, 0.0f));
    m_state.goals[6].set_scale(glm::vec3(0.5f));
    m_state.goals[6].m_animation_indices = m_state.goals[6].m_walking[LEFT];


    m_state.goals[7].m_walking[LEFT] = new int[1] {7};
    m_state.goals[7].m_animation_frames = 1;
    m_state.goals[7].m_animation_index = 0;
    m_state.goals[7].m_animation_time = 0.0f;
    m_state.goals[7].m_animation_cols = 10;
    m_state.goals[7].m_animation_rows = 1;
    m_state.goals[7].m_texture_id = Utility::load_texture("assets/images/sigils.png");
    m_state.goals[7].set_position(glm::vec3(12.0f, -16.0f, 0.0f));
    m_state.goals[7].set_speed(0.0f);
    m_state.goals[7].set_movement(glm::vec3(-1.0f, 0.0f, 0.0f));
    m_state.goals[7].set_scale(glm::vec3(0.5f));
    m_state.goals[7].m_animation_indices = m_state.goals[7].m_walking[LEFT];

    m_state.goals[8].m_walking[LEFT] = new int[1] {8};
    m_state.goals[8].m_animation_frames = 1;
    m_state.goals[8].m_animation_index = 0;
    m_state.goals[8].m_animation_time = 0.0f;
    m_state.goals[8].m_animation_cols = 10;
    m_state.goals[8].m_animation_rows = 1;
    m_state.goals[8].m_texture_id = Utility::load_texture("assets/images/sigils.png");
    m_state.goals[8].set_position(glm::vec3(24.0f, -10.0f, 0.0f));
    m_state.goals[8].set_speed(0.0f);
    m_state.goals[8].set_movement(glm::vec3(-1.0f, 0.0f, 0.0f));
    m_state.goals[8].set_scale(glm::vec3(0.5f));
    m_state.goals[8].m_animation_indices = m_state.goals[8].m_walking[LEFT];

    m_state.goals[9].m_walking[LEFT] = new int[1] {9};
    m_state.goals[9].m_animation_frames = 1;
    m_state.goals[9].m_animation_index = 0;
    m_state.goals[9].m_animation_time = 0.0f;
    m_state.goals[9].m_animation_cols = 10;
    m_state.goals[9].m_animation_rows = 1;
    m_state.goals[9].m_texture_id = Utility::load_texture("assets/images/sigils.png");
    m_state.goals[9].set_position(glm::vec3(30.0f, -26.0f, 0.0f));
    m_state.goals[9].set_speed(0.0f);
    m_state.goals[9].set_movement(glm::vec3(-1.0f, 0.0f, 0.0f));
    m_state.goals[9].set_scale(glm::vec3(0.5f));
    m_state.goals[9].m_animation_indices = m_state.goals[9].m_walking[LEFT];


    for (int i = 0; i < m_score; i++) {
        m_state.goals[i].deactivate();
    }

}

void LevelA::update(float delta_time)
{
    m_state.player->update(delta_time, m_state.player, m_state.enemies, ENEMY_COUNT, m_state.map);

    
    for (int i = 0; i < ENEMY_COUNT; i++)
    {
        m_state.enemies[i].update(delta_time, m_state.player, 0, 0, m_state.map);
    }

    for (int i = 0; i < SPAWNPOINT_COUNT; i++)
    {
        m_state.spawnpoints[i].update(delta_time, m_state.player, 0, 0, m_state.map);
        if (m_state.spawnpoints[i].touched()) {
            m_state.spawnpoints[i].reset_touched();
            m_spawn = m_state.spawnpoints[i].get_position();
        }
    }

    for (int i = 0; i < GOAL_COUNT; i++)
    {
        m_state.goals[i].update(delta_time, m_state.player, 0, 0, m_state.map);
        if (m_state.goals[i].picked()) {
            m_state.goals[i].unpick();
            m_score++;
        }
    }
}


void LevelA::render(ShaderProgram *program)
{
    m_state.map->render(program);
    
    for (int i = 0; i < ENEMY_COUNT; i++)
    {
        m_state.enemies[i].render(program);
    }
    for (int i = 0; i < SPAWNPOINT_COUNT; i++)
    {
        m_state.spawnpoints[i].render(program);
    }

    m_state.player->render(program);

    for (int i = 0; i < GOAL_COUNT; i++)
    {
        m_state.goals[i].render(program);
    }
}
