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
    case STALK:
        ai_stalk(player, delta_time, map);
        break;
    case FOLLOW:
        ai_follow(player, delta_time, map);
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
        if (m_attack_timer > 1) {
            m_ai_state = IDLE;
        }
        break;
    }
}

void Enemy::ai_stalk(Entity* player, float delta_time, Map* map)
{
    switch (m_ai_state) {
    case IDLE:
        if (check_player_in_area(player) ) {
            m_attack_timer = 2.0f; //kickstart first time
            m_ai_state = INACTIVE;
        }
        break;
    case ATTACKING:
        if (m_facing != player->get_facing()) {
            deactivate();
            if (check_player_in_area(player)) {
                m_attack_timer = (rand() % 26)/10.0f;
                m_ai_state = INACTIVE;
            }
            else {
                m_ai_state = IDLE;
            }
        }
        else {
            m_position.y = player->get_position().y;
        }
        
        break;
    case INACTIVE:
        m_attack_timer += delta_time;
        if (m_attack_timer > 4) {
            activate();
            set_position(player->get_position());
            if (player->get_facing() == LEFT) { //appear on the right
                m_position.x += 10.0f;
                move_left();
                m_facing = LEFT;
                m_animation_indices = m_walking[LEFT];

            }
            else{ //appear on the left
                m_position.x -= 10.0f;
                m_facing = RIGHT;
                move_right();
                m_animation_indices = m_walking[RIGHT];
            }
            m_ai_state = ATTACKING;
        }
        break;
    }
}

void Enemy::ai_follow(Entity* player, float delta_time, Map* map) {
    switch (m_ai_state) {
    case IDLE:
        if (check_player_in_area(player)) {
            m_attack_timer = 0.0f;
            m_ai_state = INACTIVE;
        }
        break;
    case ATTACKING:
        if (check_player_in_area(player)) {
            m_movement = calc_chase_movement();
            if (m_movement.x > 0) {
                m_animation_indices = m_walking[RIGHT];
            }
            else {
                m_animation_indices = m_walking[LEFT];
            }

            glm::vec3 temp = m_position + m_movement;

            glm::vec3 player_pos = player->get_position();
            add_next_pos(glm::vec2(player_pos.x, player_pos.y));
        }
        else {
            m_ai_state = IDLE;
            deactivate();
        }

        break;
    case INACTIVE:
        m_attack_timer += delta_time;
        if (m_attack_timer > 5) {
            activate();
            m_ai_state = ATTACKING;
        }
        else {
            glm::vec3 player_pos = player->get_position();
            add_next_pos(glm::vec2(player_pos.x, player_pos.y));
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

bool Enemy::check_player_in_area(Entity* player)
{
    glm::vec2 positive_positive = glm::vec2(m_patrol_area.x, m_patrol_area.y);
    glm::vec2 negative_negative = glm::vec2(m_patrol_area.z, m_patrol_area.w);

    glm::vec3 player_pos = player->get_position();

    bool is_inside = player_pos.x >= negative_negative.x && player_pos.x <= positive_positive.x &&
        player_pos.y >= negative_negative.y && player_pos.y <= positive_positive.y;

    return is_inside;
}

void const Enemy::add_next_pos(glm::vec2 player_pos)
{
    if (m_follow_queue.empty()) {
        m_follow_queue.push(player_pos);
        return;
    }

    glm::vec2 difference = m_follow_queue.back() - player_pos;
    float length = glm::length(difference);

    if (length != 0.0f) //get rid of loitering!
        m_follow_queue.push(player_pos);
}

glm::vec3 Enemy::calc_chase_movement()
{
    if (m_follow_queue.empty())
        return glm::vec3(0.0f); //safety

    glm::vec2 player_og_pos_2d = m_follow_queue.front();
    m_follow_queue.pop();

    return glm::vec3(player_og_pos_2d.x, player_og_pos_2d.y, 0.0f) - get_position();
}



void Enemy::update(float delta_time, Entity* player, Entity* objects, int object_count, Map* map)
{

    ai_activate(player, delta_time, map);

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
    //reset all the flags after since jump enemy relies on these
    m_collided_top = false;
    m_collided_bottom = false;
    m_collided_left = false;
    m_collided_right = false;

    m_base_velocity += m_acceleration * delta_time;
    m_velocity = m_base_velocity + (m_movement * m_speed);

    m_position.x += m_velocity.x * delta_time;
    if(m_ai_type == JUMP)
    Entity::check_collision_x(map);
    m_position.y += m_velocity.y * delta_time;
    if (m_ai_type == JUMP)
    Entity::check_collision_y_simple(map);

    if (check_collision(player))
    {
        player->deactivate();
    }

    m_model_matrix = glm::mat4(1.0f);
    m_model_matrix = glm::translate(m_model_matrix, m_position);
    m_model_matrix = glm::scale(m_model_matrix, m_scale);
}
