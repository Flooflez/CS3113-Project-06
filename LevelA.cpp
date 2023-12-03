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

    0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0,
    4, 2, 3, 1, 3, 2, 2, 2, 3, 1, 3, 3, 1, 1, 3, 1, 3, 1, 2, 2, 3, 2, 3, 1, 1, 2, 2, 1, 3, 3, 1, 3, 1, 2, 1, 2, 1, 2, 2, 3, 2, 3, 3, 1, 1, 1, 3, 3, 2, 7,
    4, 3, 1, 2, 3, 2, 3, 1, 1, 2, 2, 3, 2, 3, 3, 3, 1, 2, 3, 2, 1, 2, 1, 3, 2, 3, 1, 2, 3, 2, 2, 1, 3, 1, 3, 3, 2, 3, 3, 2, 2, 3, 3, 1, 1, 3, 3, 2, 3, 7,
    4, 1, 3, 3, 1, 1, 3, 3, 3, 3, 1, 1, 2, 3, 1, 2, 3, 2, 3, 1, 1, 1, 2, 3, 3, 2, 2, 2, 3, 3, 2, 1, 1, 1, 1, 1, 1, 2, 2, 1, 2, 1, 1, 2, 3, 2, 2, 1, 1, 7,
    4, 2, 2, 2, 3, 3, 3, 1, 3, 1, 3, 1, 3, 2, 3, 1, 3, 3, 2, 2, 1, 1, 3, 2, 2, 2, 2, 1, 2, 3, 3, 2, 2, 1, 1, 2, 2, 2, 3, 1, 2, 1, 3, 2, 1, 1, 2, 3, 2, 7,
    4, 2, 3, 1, 2, 1, 2, 2, 1, 3, 1, 3, 2, 2, 3, 3, 2, 2, 1, 1, 1, 3, 3, 3, 3, 1, 1, 3, 3, 2, 3, 2, 2, 3, 1, 3, 2, 3, 3, 1, 2, 2, 2, 1, 3, 2, 2, 2, 1, 7,
    4, 3, 1, 2, 1, 2, 2, 3, 3, 1, 3, 2, 3, 3, 1, 2, 1, 1, 1, 2, 2, 3, 2, 1, 2, 3, 3, 3, 2, 3, 3, 3, 2, 2, 2, 3, 1, 1, 3, 3, 3, 1, 3, 1, 2, 3, 1, 3, 1, 7,
    4, 2, 2, 1, 3, 3, 1, 1, 2, 2, 3, 3, 3, 3, 2, 1, 1, 3, 3, 3, 3, 3, 1, 2, 1, 1, 1, 3, 1, 3, 1, 1, 1, 3, 1, 2, 1, 2, 3, 1, 2, 1, 1, 1, 3, 3, 3, 1, 3, 7,
    4, 3, 2, 3, 1, 2, 1, 1, 1, 2, 3, 1, 3, 2, 2, 3, 3, 2, 1, 2, 3, 3, 3, 2, 2, 1, 1, 3, 2, 3, 2, 3, 1, 1, 1, 1, 3, 1, 2, 3, 3, 3, 1, 1, 3, 2, 1, 1, 2, 7,
    4, 1, 3, 2, 3, 3, 2, 3, 1, 1, 2, 2, 3, 1, 1, 2, 1, 2, 1, 2, 2, 3, 2, 3, 1, 1, 1, 1, 3, 2, 1, 1, 1, 3, 2, 3, 1, 1, 1, 3, 1, 2, 1, 3, 2, 1, 1, 2, 2, 7,
    4, 1, 2, 2, 2, 2, 3, 2, 2, 3, 1, 3, 1, 2, 3, 2, 1, 3, 3, 3, 1, 1, 2, 2, 2, 2, 3, 1, 1, 1, 2, 3, 2, 1, 3, 1, 2, 3, 2, 1, 3, 3, 1, 1, 1, 1, 1, 2, 1, 7,
    4, 1, 1, 1, 2, 3, 1, 3, 3, 2, 2, 3, 1, 2, 3, 3, 3, 2, 3, 2, 2, 2, 1, 1, 1, 2, 1, 1, 3, 3, 3, 2, 1, 1, 1, 3, 2, 2, 1, 3, 1, 2, 1, 1, 2, 2, 2, 2, 2, 7,
    4, 3, 3, 3, 2, 2, 3, 2, 2, 2, 1, 3, 1, 1, 2, 2, 2, 1, 3, 1, 3, 2, 3, 1, 1, 3, 1, 1, 2, 2, 2, 1, 2, 3, 3, 2, 3, 1, 3, 3, 2, 1, 1, 2, 2, 3, 3, 3, 2, 7,
    4, 3, 2, 1, 3, 2, 1, 3, 2, 3, 1, 1, 1, 3, 3, 1, 3, 1, 3, 2, 1, 3, 1, 2, 2, 1, 3, 1, 1, 1, 2, 1, 3, 2, 1, 2, 2, 2, 1, 3, 1, 3, 2, 1, 1, 2, 1, 1, 1, 7,
    4, 1, 1, 2, 2, 1, 2, 3, 2, 1, 2, 2, 3, 1, 2, 1, 1, 3, 1, 3, 3, 1, 3, 1, 3, 3, 3, 2, 3, 2, 1, 1, 1, 1, 1, 3, 2, 1, 2, 2, 3, 2, 2, 2, 1, 2, 2, 2, 3, 7,
    4, 3, 3, 2, 1, 2, 3, 1, 2, 3, 2, 2, 1, 3, 3, 3, 3, 2, 3, 1, 1, 2, 3, 3, 3, 3, 3, 1, 2, 1, 2, 3, 1, 1, 2, 3, 1, 2, 1, 1, 1, 1, 2, 1, 2, 1, 3, 2, 1, 7,
    4, 1, 2, 3, 3, 3, 2, 1, 1, 3, 3, 3, 1, 1, 3, 3, 3, 1, 2, 1, 3, 1, 3, 2, 2, 2, 3, 1, 2, 2, 3, 1, 3, 1, 1, 2, 2, 3, 1, 2, 1, 3, 1, 3, 3, 3, 3, 1, 3, 7,
    4, 1, 3, 2, 2, 3, 3, 2, 2, 1, 1, 3, 1, 2, 1, 3, 1, 3, 2, 2, 2, 2, 1, 3, 1, 2, 3, 1, 2, 1, 1, 3, 2, 2, 2, 3, 3, 3, 3, 1, 3, 2, 2, 3, 1, 3, 2, 1, 2, 7,
    4, 2, 1, 1, 3, 2, 3, 2, 3, 3, 2, 2, 2, 2, 2, 2, 3, 3, 3, 2, 3, 3, 2, 3, 2, 3, 2, 1, 1, 1, 1, 3, 1, 3, 2, 3, 2, 3, 1, 1, 2, 1, 3, 1, 3, 3, 2, 3, 2, 7,
    4, 3, 3, 1, 2, 3, 1, 3, 2, 1, 2, 3, 2, 2, 2, 1, 3, 3, 3, 3, 1, 1, 3, 2, 3, 1, 1, 1, 2, 1, 1, 1, 2, 3, 2, 1, 3, 1, 2, 3, 3, 2, 2, 3, 1, 1, 2, 1, 2, 7,
    4, 3, 3, 1, 1, 2, 3, 3, 3, 1, 3, 1, 3, 2, 1, 2, 1, 1, 3, 1, 1, 1, 3, 3, 2, 3, 3, 2, 2, 3, 3, 3, 3, 1, 1, 1, 3, 2, 3, 2, 3, 3, 1, 2, 1, 1, 2, 3, 1, 7,
    4, 1, 2, 2, 3, 3, 1, 2, 3, 3, 2, 2, 1, 1, 3, 1, 2, 3, 1, 1, 2, 1, 3, 1, 1, 1, 3, 1, 3, 3, 2, 2, 2, 2, 1, 3, 3, 2, 3, 3, 3, 3, 2, 2, 3, 2, 2, 1, 1, 7,
    4, 2, 2, 2, 3, 3, 3, 2, 1, 3, 3, 3, 2, 2, 2, 1, 1, 1, 3, 2, 3, 3, 3, 1, 1, 1, 2, 1, 2, 2, 3, 1, 1, 1, 3, 2, 1, 2, 1, 2, 2, 1, 1, 1, 3, 2, 2, 2, 1, 7,
    4, 2, 1, 1, 3, 2, 1, 3, 2, 1, 1, 2, 3, 2, 3, 3, 1, 1, 2, 1, 1, 2, 3, 1, 2, 1, 3, 3, 1, 3, 1, 1, 3, 1, 3, 1, 2, 3, 2, 2, 2, 3, 2, 2, 1, 1, 3, 3, 2, 7,
    4, 3, 3, 2, 3, 1, 3, 3, 3, 1, 2, 2, 1, 3, 2, 2, 2, 3, 1, 2, 1, 1, 3, 1, 1, 2, 3, 1, 3, 2, 2, 1, 3, 3, 2, 3, 1, 3, 1, 1, 1, 3, 2, 3, 3, 3, 2, 1, 1, 7,
    4, 1, 3, 3, 2, 1, 2, 1, 3, 1, 3, 2, 2, 1, 3, 1, 3, 1, 1, 1, 3, 3, 1, 2, 2, 3, 2, 1, 1, 1, 1, 3, 1, 9, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0,
    4, 2, 1, 3, 3, 2, 1, 2, 2, 1, 3, 2, 1, 2, 3, 3, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 1, 3, 1, 1, 2, 1, 2, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    4, 3, 1, 1, 1, 3, 3, 1, 1, 1, 2, 1, 3, 1, 3, 3, 2, 2, 2, 3, 1, 3, 2, 2, 3, 1, 3, 3, 2, 3, 1, 2, 1, 8, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0,
    4, 2, 2, 2, 3, 2, 1, 3, 2, 2, 2, 1, 1, 3, 3, 1, 1, 1, 1, 3, 1, 2, 1, 1, 1, 3, 1, 3, 2, 1, 3, 3, 2, 2, 3, 1, 1, 2, 1, 1, 1, 1, 1, 2, 2, 2, 1, 1, 2, 0,
    4, 2, 3, 2, 3, 1, 3, 1, 1, 2, 1, 2, 2, 2, 2, 3, 2, 2, 1, 3, 2, 3, 2, 1, 1, 2, 1, 1, 2, 3, 1, 1, 3, 9, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0,
    4, 2, 3, 3, 2, 2, 3, 1, 2, 1, 3, 1, 2, 2, 2, 3, 1, 2, 2, 2, 2, 2, 3, 3, 1, 2, 2, 2, 1, 2, 1, 1, 1, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    4, 3, 3, 2, 1, 3, 1, 3, 1, 2, 1, 1, 3, 2, 1, 1, 1, 2, 1, 1, 3, 2, 2, 1, 2, 3, 1, 1, 3, 2, 1, 3, 2, 8, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    4, 3, 1, 1, 1, 2, 2, 2, 2, 3, 2, 2, 3, 3, 1, 3, 3, 1, 3, 1, 3, 1, 3, 2, 2, 3, 2, 2, 3, 3, 1, 3, 1, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    4, 1, 2, 1, 1, 3, 1, 2, 2, 1, 1, 2, 1, 2, 3, 3, 3, 2, 2, 2, 2, 2, 1, 3, 3, 2, 2, 3, 2, 3, 3, 3, 2, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    4, 2, 3, 4, 3, 7, 3, 3, 2, 2, 2, 1, 1, 3, 1, 2, 1, 2, 3, 3, 1, 1, 2, 1, 2, 1, 3, 2, 1, 3, 1, 3, 2, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 0, 0, 0,
    4, 3, 3, 4, 1, 1, 1, 2, 1, 1, 2, 3, 1, 1, 1, 1, 3, 3, 1, 3, 2, 1, 1, 2, 2, 2, 2, 2, 1, 1, 1, 3, 1, 7, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 3, 2, 7, 0, 0, 0,
    4, 3, 2, 4, 1, 7, 1, 3, 1, 1, 3, 1, 3, 2, 1, 2, 3, 1, 2, 2, 2, 3, 1, 1, 1, 2, 1, 3, 3, 1, 1, 1, 3, 7, 0, 0, 0, 0, 0, 0, 0, 0, 4, 2, 3, 2, 8, 5, 5, 0,
    0, 5, 5,11, 3, 7, 2, 1, 3, 3, 2, 1, 3, 1, 1, 2, 3, 2, 3, 2, 2, 3, 2, 2, 3, 3, 2, 1, 1, 3, 2, 2, 2, 7, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 2, 1, 2, 1, 2, 7,
    4, 1, 3, 3, 1, 7, 2, 2, 1, 3, 1, 1, 2, 3, 3, 2, 1, 2, 1, 2, 2, 3, 1, 2, 3, 3, 1, 2, 2, 3, 1, 3, 3, 7, 0, 0, 0, 5, 5, 5, 5, 0, 4, 1, 1, 1, 9,10, 1, 7,
    0, 6, 6,10, 2, 7, 3, 2, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 2, 3, 3, 3, 2, 2, 2, 1, 2, 1, 3, 1, 3, 7, 0, 0, 4, 1, 2, 2, 3, 7, 4, 1, 2, 2, 7, 4, 1, 7,
    0, 0, 0, 4, 2, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 4, 2, 9, 6, 6, 0, 4, 3, 1, 1, 7, 4, 3, 7,
    0, 0, 0, 4, 3, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 7, 0, 0, 4, 1, 7, 0, 0, 0, 4, 2, 3, 2, 7, 4, 3, 7,
    0, 0, 0, 4, 3, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 2, 3, 3, 1, 1, 1, 3, 1, 1, 3, 2, 1, 2, 1, 2, 7, 0, 0, 4, 1, 7, 0, 0, 0, 4, 2, 1, 3, 7, 4, 1, 7,
    0, 0, 0, 4, 2, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 3, 2, 3, 3, 3, 1, 1, 1, 1, 3, 3, 1, 1, 1, 1, 7, 0, 0, 4, 1, 7, 0, 0, 0, 4, 1, 3, 1, 7, 4, 2, 7,
    0, 5, 5,11, 1, 8, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,11, 2, 3, 3, 3, 2, 3, 2, 1, 1, 3, 3, 1, 2, 1, 3, 8, 5, 5,11, 1, 8, 5, 5, 5,11, 2, 3, 1, 7, 4, 1, 7,
    4, 1, 1, 2, 3, 2, 1, 1, 3, 1, 2, 2, 2, 3, 2, 3, 3, 1, 3, 1, 3, 2, 2, 1, 2, 2, 1, 2, 1, 1, 2, 1, 1, 3, 2, 1, 1, 3, 2, 2, 1, 3, 1, 3, 2, 1, 7, 4, 1, 7,
    0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,10, 3, 2, 1, 1, 3, 3, 3, 3, 3, 1, 3, 3, 1, 1, 2, 9, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 4, 3, 7,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 2, 2, 2, 2, 1, 1, 2, 3, 1, 2, 2, 1, 1, 2, 2, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 3, 7,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 2, 3, 1, 1, 3, 3, 1, 2, 2, 1, 1, 3, 2, 1, 1, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 2, 7,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0,
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
    m_state.map = new Map(LEVEL_WIDTH, LEVEL_HEIGHT, LEVELA_DATA, map_texture_id, 1.0f, 12, 1);
    
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
