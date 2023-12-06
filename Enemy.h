#pragma once
#include "Entity.h"

enum AIType { JUMP, STALK, FOLLOW };
enum AIState { INACTIVE, IDLE, ATTACKING };

class Enemy : public Entity {
    AIType     m_ai_type;
    AIState    m_ai_state;

    void ai_activate(Entity* player, float delta_time, Map* map);
    void ai_jump(Entity* player, float delta_time, Map* map);
    void ai_stalk(Entity* player, float delta_time, Map* map);
    void ai_follow(Entity* player, float delta_time, Map* map);

    void const check_collision_y(Entity* collidable_entities, int collidable_entity_count) override;
    void const check_collision_x(Entity* collidable_entities, int collidable_entity_count) override;

    
public:
    void update(float delta_time, Entity* player, Entity* objects, int object_count, Map* map);

    AIType     const get_ai_type()        const { return m_ai_type; };
    AIState    const get_ai_state()       const { return m_ai_state; };
    void const set_ai_type(AIType new_ai_type) { m_ai_type = new_ai_type; };
    void const set_ai_state(AIState new_state) { m_ai_state = new_state; };
};
