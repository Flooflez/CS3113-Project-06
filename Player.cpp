/**
* Author: Maximilian Ta
* Assignment: Platformer
* Date due: 2023-12-02, 11:59pm
* I pledge that I have completed this assignment without
* collaborating with anyone else, in conformance with the
* NYU School of Engineering Policies and Procedures on
* Academic Misconduct.
*
**/

#include "Player.h"


void Player::update(float delta_time, Entity* player, Entity* objects, int object_count, Map* map)
{
    if (!m_is_active) return;

    m_collided_top = false;
    m_collided_bottom = false;
    m_collided_left = false;
    m_collided_right = false;


    if (m_animation_indices != NULL)
    {
        if (glm::length(m_movement) != 0)
        {
            m_animation_time += delta_time;
            float seconds_per_frame = 1.0f / FRAMES_PER_SECOND;

            if (m_animation_time >= seconds_per_frame)
            {
                m_animation_time = 0.0f;
                m_animation_index++;

                if (m_animation_index >= m_animation_frames)
                {
                    m_animation_index = 0;
                }
            }
        }
    }

    m_speed = 1.25f;
    if (m_is_sprinting) {
        if (m_sprint_time > 0) {
            m_speed = 2.0f;
            m_sprint_time -= delta_time;
        }
    }
    else {
        if (m_sprint_time < 10) //10 seconds of sprint; 
        m_sprint_time += delta_time / 2.0f; //regen sprint        
    }


    m_base_velocity += m_acceleration * delta_time;
    m_velocity = m_base_velocity + (m_movement * m_speed);

    // We make two calls to our check_collision methods, one for the collidable objects and one for
    // the map.
    m_position.y += m_velocity.y * delta_time;
    Entity::check_collision_y_simple(map);
    
    m_position.x += m_velocity.x * delta_time;
    Entity::check_collision_x(map);
    
    if (m_is_jumping)
    {
        m_is_jumping = false;

        m_base_velocity.y += m_jumping_power;
    }

    m_model_matrix = glm::mat4(1.0f);
    m_model_matrix = glm::translate(m_model_matrix, m_position);
    m_model_matrix = glm::scale(m_model_matrix, m_scale);
}
