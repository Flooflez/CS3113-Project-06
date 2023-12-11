#pragma once
#include "Entity.h"
#include "Utility.h"

class Spawnpoint : public Entity {
protected:
    bool m_touched = false;
    GLuint text_texture_id;
public:
    Spawnpoint();

    void update(float delta_time, Entity* player, Entity* objects, int object_count, Map* map);

    bool touched() { return m_touched; }
    void reset_touched() { m_touched = false; }

    void render(ShaderProgram* program) override;
};
