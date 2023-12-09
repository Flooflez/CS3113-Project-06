#pragma once
#include "Entity.h"

class Player : public Entity {
private:
    float m_sprint_time = 10.0f;
    bool m_is_sprinting;
public:
    float get_sprint_time() { return m_sprint_time; }
    void set_sprint(bool new_sprint) { m_is_sprinting = new_sprint; }
    void update(float delta_time, Entity* player, Entity* objects, int object_count, Map* map);
};
