/**
* Author: Maximilian Ta
* Assignment: Platformer
* Date due: 2023-12-02, 11:59pm
* I pledge that I have completed this assignment without
* collaborating with anyone else, in conformance with the
* NYU School of Engineering Policies and Procedures on
* Academic Misconduct.
**/

#include "Enemy.h"

void Enemy::ai_activate(Entity* player, float delta_time, Map* map)
{
    switch (m_ai_type)
    {
    case JUMP:
        ai_jump(player, delta_time, map);
        break;

    default:
        break;
    }
}

void Enemy::ai_jump(Entity* player, float delta_time, Map* map)
{
    switch (m_ai_state) {
    case IDLE:
        if (glm::distance(player->get_position(), get_position()) < 5.0f) {
            if (can_see_entity(player, map)) {
                //round to up down left or right
                glm::vec3 ray = get_raycast_to(player);

                float angle = glm::atan(ray.y, ray.x);
                float angleInDegrees = glm::degrees(angle);

                if (angleInDegrees >= -45 && angleInDegrees < 45) {

                    move_right();
                    m_animation_indices = m_walking[RIGHT];
                }
                else if (angleInDegrees >= 45 && angleInDegrees < 135) {
                    move_up();
                }
                else if (angleInDegrees >= -135 && angleInDegrees < -45) {
                    move_down();
                }
                else {
                    move_left();
                    m_animation_indices = m_walking[LEFT];
                }

                m_ai_state = ATTACKING;
            }
        }
        break;
    case ATTACKING:
        if (m_collided_bottom || m_collided_left || m_collided_right || m_collided_top) {
            m_ai_state = INACTIVE;
            m_attack_timer = 0.0f;
            set_movement(glm::vec3(0.0f));
        }
        break;
    case INACTIVE:
        m_attack_timer += delta_time;
        if (m_attack_timer > 3) {
            m_ai_state = IDLE;
        }
        break;
    }

    
}


void const Enemy::check_collision_y(Entity* collidable_entities, int collidable_entity_count)
{
    return;
}

void const Enemy::check_collision_x(Entity* collidable_entities, int collidable_entity_count)
{
	return;
}

void Enemy::update(float delta_time, Entity* player, Entity* objects, int object_count, Map* map)
{

    ai_activate(player, delta_time, map);
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
    //reset all the flags after since jump enemy relies on these
    m_collided_top = false;
    m_collided_bottom = false;
    m_collided_left = false;
    m_collided_right = false;

    m_base_velocity += m_acceleration * delta_time;
    m_velocity = m_base_velocity + (m_movement * m_speed);

    m_position.x += m_velocity.x * delta_time;
    Entity::check_collision_x(map);
    m_position.y += m_velocity.y * delta_time;
    Entity::check_collision_y(map);

    if (check_collision(player))
    {
        player->deactivate();
    }

    m_model_matrix = glm::mat4(1.0f);
    m_model_matrix = glm::translate(m_model_matrix, m_position);
    m_model_matrix = glm::scale(m_model_matrix, m_scale);
}
