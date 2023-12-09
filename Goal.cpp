/**
* Author: Maximilian Ta
* Assignment: Platformer
* Date due: 2023-12-02, 11:59pm
* I pledge that I have completed this assignment without
* collaborating with anyone else, in conformance with the
* NYU School of Engineering Policies and Procedures on
* Academic Misconduct.
**/

#include "Goal.h"

void Goal::update(float delta_time, Entity* player, Entity* objects, int object_count, Map* map)
{
    if (!m_is_active) return;


    if (check_collision(player))
    {
        m_picked = 0;
        deactivate();
    }

    m_model_matrix = glm::mat4(1.0f);
    m_model_matrix = glm::translate(m_model_matrix, m_position);
    m_model_matrix = glm::scale(m_model_matrix, m_scale);
}
