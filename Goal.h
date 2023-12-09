#pragma once
#include "Entity.h"

class Goal : public Entity {
    bool m_picked = false;
public:
    void update(float delta_time, Entity* player, Entity* objects, int object_count, Map* map);

    bool picked() { return m_picked; }
    void unpick() { m_picked = false; }
};