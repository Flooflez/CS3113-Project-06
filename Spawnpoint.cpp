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


#include "Spawnpoint.h"


Spawnpoint::Spawnpoint()
{
    text_texture_id = Utility::load_texture("assets/fonts/handwritten_capitals.png");
}


void Spawnpoint::update(float delta_time, Entity* player, Entity* objects, int object_count, Map* map)
{
    if (!m_is_active) return;

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

    if (check_collision(player))
    {
        m_accumulator += delta_time;
        if (m_accumulator >= m_display_time) {
            m_accumulator = 0;
            m_dialogue_index++;
        }

        m_touched = true;
    }

    m_model_matrix = glm::mat4(1.0f);
    m_model_matrix = glm::translate(m_model_matrix, m_position);
    m_model_matrix = glm::scale(m_model_matrix, m_scale);
}

void Spawnpoint::render(ShaderProgram* program)
{
    if(m_dialogue_index < m_dialogue_size)
    Utility::draw_text(text_texture_id, m_dialogue[m_dialogue_index], 0.25f, -0.1f, m_position + glm::vec3(-1.0f, 0.5f, 0.0f));

    Entity::render(program);
}

