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

/*
* first room needs spawn point, then jumpscare enemy in tunnel, side tunnel should have some sign/npc just to distract
* second big room introduce stalker enemy, player needs to turn around and look at it to survive
* at the end they reach a big tunnel with one big jumpscare enemy in it.
* they actually have to approach the enemy and just skim past upwards
* Then second one just for funsies at the side tunnel
*/

LevelA::~LevelA()
{
    delete [] m_state.enemies;
    delete    m_state.player;
    delete    m_state.map;
    Mix_FreeChunk(m_state.jump_sfx);
    Mix_FreeMusic(m_state.bgm);
}

void LevelA::initialise()
{
    GLuint map_texture_id = Utility::load_texture("assets/images/platforms.png");
    m_state.map = new Map(LEVEL_WIDTH, LEVEL_HEIGHT, LEVELA_DATA, map_texture_id, 1.0f, 15, 1);
    
    // Code from main.cpp's initialise()
    /**
     George's Stuff
     */
    // Existing
    m_state.player = new Player();
    m_state.player->set_position(glm::vec3(48.0f, -48.0f, 0.0f));
    m_state.player->set_movement(glm::vec3(0.0f));
    m_state.player->set_speed(1.25f);
    m_state.player->m_texture_id = Utility::load_texture("assets/images/player.png");
    
    // Walking
    m_state.player->m_walking[m_state.player->LEFT]  = new int[4] { 1, 5, 9,  13 };
    m_state.player->m_walking[m_state.player->RIGHT] = new int[4] { 3, 7, 11, 15 };
    m_state.player->m_walking[m_state.player->UP]    = new int[4] { 2, 6, 10, 14 };
    m_state.player->m_walking[m_state.player->DOWN]  = new int[4] { 0, 4, 8,  12 };

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

    m_state.enemies[0].m_walking[m_state.enemies[0].LEFT] = new int[4] { 1, 5, 9, 13 };
    m_state.enemies[0].m_walking[m_state.enemies[0].RIGHT] = new int[4] { 3, 7, 11, 15 };
    m_state.enemies[0].m_walking[m_state.enemies[0].UP] = new int[4] { 2, 6, 10, 14 };
    m_state.enemies[0].m_walking[m_state.enemies[0].DOWN] = new int[4] { 0, 4, 8, 12 };
    m_state.enemies[0].m_animation_indices = m_state.enemies[0].m_walking[m_state.enemies[0].RIGHT];
    m_state.enemies[0].m_animation_frames = 4;
    m_state.enemies[0].m_animation_index = 0;
    m_state.enemies[0].m_animation_time = 0.0f;
    m_state.enemies[0].m_animation_cols = 4;
    m_state.enemies[0].m_animation_rows = 4;

    m_state.enemies[0].set_ai_type(JUMP);
    m_state.enemies[0].set_ai_state(IDLE);
    m_state.enemies[0].m_texture_id = Utility::load_texture("assets/images/jump_monster.png");
    m_state.enemies[0].set_position(glm::vec3(31.0f, -45.0f, 0.0f));
    m_state.enemies[0].set_speed(3.5f);
    m_state.enemies[0].set_width(0.3f);
    m_state.enemies[0].set_height(0.8f);

    m_state.enemies[1].m_walking[m_state.enemies[1].LEFT] = new int[1] { 3 };
    m_state.enemies[1].m_walking[m_state.enemies[1].RIGHT] = new int[1] { 1};
    m_state.enemies[1].m_walking[m_state.enemies[1].UP] = new int[1] { 2};
    m_state.enemies[1].m_walking[m_state.enemies[1].DOWN] = new int[1] { 0};
    m_state.enemies[1].m_animation_indices = m_state.enemies[1].m_walking[m_state.enemies[1].RIGHT];
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



    //Goal
    m_state.goal = new Goal();
    m_state.goal->m_walking[m_state.goal->LEFT] = new int[4] { 1, 5, 9, 13 };
    m_state.goal->m_walking[m_state.goal->RIGHT] = new int[4] { 3, 7, 11, 15 };
    m_state.goal->m_walking[m_state.goal->UP] = new int[4] { 2, 6, 10, 14 };
    m_state.goal->m_walking[m_state.goal->DOWN] = new int[4] { 0, 4, 8, 12 };
    m_state.goal->m_animation_frames = 4;
    m_state.goal->m_animation_index = 0;
    m_state.goal->m_animation_time = 0.0f;
    m_state.goal->m_animation_cols = 4;
    m_state.goal->m_animation_rows = 4;
    m_state.goal->m_texture_id = Utility::load_texture("assets/images/cat.png");
    m_state.goal->set_position(glm::vec3(49.0f, -8.1f, 0.0f));
    m_state.goal->set_speed(0.0f);
    m_state.goal->set_movement(glm::vec3(-1.0f, 0.0f, 0.0f));
    m_state.goal->m_animation_indices = m_state.goal->m_walking[m_state.goal->LEFT];
    m_state.enemies->set_acceleration(glm::vec3(0.0f, 0.0f, 0.0f));

    
    m_state.jump_sfx = Mix_LoadWAV("assets/audio/woop.wav");
}

void LevelA::update(float delta_time)
{
    m_state.player->update(delta_time, m_state.player, m_state.enemies, ENEMY_COUNT, m_state.map);

    m_state.goal->update(delta_time, m_state.player, m_state.enemies, ENEMY_COUNT, m_state.map);
    
    for (int i = 0; i < ENEMY_COUNT; i++)
    {
        m_state.enemies[i].update(delta_time, m_state.player, 0, 0, m_state.map);
    }

    if (m_state.goal->level_win()) {
        m_state.next_scene_id = 2; //go to level B
    }
}


void LevelA::render(ShaderProgram *program)
{
    m_state.map->render(program);
    m_state.player->render(program);
    m_state.goal->render(program);
    for (int i = 0; i < ENEMY_COUNT; i++)
    {
        m_state.enemies[i].render(program);
    }
}
