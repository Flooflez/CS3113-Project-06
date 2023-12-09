#pragma once
#include "Entity.h"

class Player : public Entity {
private:
    float m_sprint_time = 10.0f;
    bool m_is_sprinting;
    int m_who_killed_me = -1;
public:
    float get_sprint_time() { return m_sprint_time; }
    void set_sprint(bool new_sprint) { m_is_sprinting = new_sprint; }
    void update(float delta_time, Entity* player, Entity* objects, int object_count, Map* map);

    void set_killer(int killer) { m_who_killed_me = killer; }
    int get_killer() { return m_who_killed_me; }
};
