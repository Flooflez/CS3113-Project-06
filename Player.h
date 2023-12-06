#pragma once
#include "Entity.h"

class Player : public Entity {
private:
    int m_facing;
public:
    int const get_facing()       const { return m_facing; };
    void const set_facing(int new_dir) { m_facing = new_dir; };

    void update(float delta_time, Entity* player, Entity* objects, int object_count, Map* map);
};
