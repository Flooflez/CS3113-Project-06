/**
* Author: Maximilian Ta
* Assignment: The Caves (Final Project)
* Date due: 2023-12-15, 11:59pm
* I pledge that I have completed this assignment without
* collaborating with anyone else, in conformance with the
* NYU School of Engineering Policies and Procedures on
* Academic Misconduct.
**/

#include "Jumpscare.h"
#include "Utility.h"

void Jumpscare::initialise()
{
	jump = new DummyEntity();
    jump->set_position(glm::vec3(0.0f));
    jump->set_movement(glm::vec3(-1.0f, 0.0f,0.0f));
    jump->set_speed(0.0f);
    jump->m_texture_id = Utility::load_texture("assets/images/jump_jumpscare.png");

    // Walking
    jump->m_walking[jump->LEFT] = new int[16] { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
    jump->m_animation_indices = jump->m_walking[jump->LEFT];
    jump->m_animation_frames = 16;
    jump->m_animation_index = 0;
    jump->m_animation_time = 0.0f;
    jump->m_animation_cols = 4;
    jump->m_animation_rows = 4;
    jump->set_height(0.0f);
    jump->set_width(0.0f);
    jump->set_scale(glm::vec3(10.0f));
    jump->deactivate();

    stalk = new DummyEntity();
    stalk->set_position(glm::vec3(0.0f));
    stalk->set_movement(glm::vec3(-1.0f, 0.0f, 0.0f));
    stalk->set_speed(0.0f);
    stalk->m_texture_id = Utility::load_texture("assets/images/stalk_monster.png");

    // Walking
    stalk->m_walking[stalk->LEFT] = new int[1] { 0};
    stalk->m_animation_indices = stalk->m_walking[stalk->LEFT];
    stalk->m_animation_frames = 1;
    stalk->m_animation_index = 0;
    stalk->m_animation_time = 0.0f;
    stalk->m_animation_cols = 4;
    stalk->m_animation_rows = 1;
    stalk->set_height(0.0f);
    stalk->set_width(0.0f);
    stalk->set_scale(glm::vec3(10.0f));
    stalk->deactivate();


	follow = new DummyEntity();
    follow->set_position(glm::vec3(0.0f));
    follow->set_movement(glm::vec3(-1.0f, 0.0f, 0.0f));
    follow->set_speed(0.0f);
    follow->m_texture_id = Utility::load_texture("assets/images/chase_monster.png");

    // Walking
    follow->m_walking[follow->LEFT] = new int[1] { 0 };
    follow->m_animation_indices = follow->m_walking[follow->LEFT];
    follow->m_animation_frames = 1;
    follow->m_animation_index = 0;
    follow->m_animation_time = 0.0f;
    follow->m_animation_cols = 2;
    follow->m_animation_rows = 2;
    follow->set_height(0.0f);
    follow->set_width(0.0f);
    follow->set_scale(glm::vec3(10.0f));
    follow->deactivate();
}

void Jumpscare::play_jump(glm::vec3 player_pos)
{
    if (m_playing) return; //skip if already playing
    jump->m_animation_index = 0;
    jump->set_position(player_pos + glm::vec3(1.5f,0.0f,0.0f));
    jump->activate();
    jump->set_scale(glm::vec3(0.75f));
    m_timer = 0.4f;
    m_playing = true;
}

void Jumpscare::play_stalk(glm::vec3 player_pos)
{
    if (m_playing) return; //skip if already playing
    stalk->m_animation_index = 0;
    stalk->set_position(player_pos + glm::vec3(-0.5f, -5.0f, 0.0f));
    stalk->activate();
    stalk->set_scale(glm::vec3(1.0f));
    m_timer = 0.4f;
    m_playing = true;
}

void Jumpscare::play_follow(glm::vec3 player_pos)
{
    if (m_playing) return; //skip if already playing
    follow->m_animation_index = 0;
    follow->set_position(player_pos);
    follow->activate();
    follow->set_scale(glm::vec3(0.75f));
    m_timer = 0.4f;
    m_playing = true;
}


void Jumpscare::update(float delta_time)
{
    if (m_playing) {
        if (m_timer <= 0) {
            jump->deactivate();
            stalk->deactivate();
            follow->deactivate();
            m_playing = false;
            m_finished_playing = true;
        }
        else {
            m_timer -= delta_time;
        }
    }
    
    jump->update(delta_time, nullptr, nullptr, 0, nullptr);
    stalk->update(delta_time, nullptr, nullptr, 0, nullptr);
    follow->update(delta_time, nullptr, nullptr, 0, nullptr);
}



void Jumpscare::render(ShaderProgram* update) {
    jump->render(update);
    stalk->render(update);
    follow->render(update);
}
