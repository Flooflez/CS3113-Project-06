#pragma once
#include "Entity.h"

class Spawnpoint : public Entity {
protected:
    bool m_touched = false;
public:
    void update(float delta_time, Entity* player, Entity* objects, int object_count, Map* map);

    bool touched() { return m_touched; }
    void reset_touched() { m_touched = false; }
};
