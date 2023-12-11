#pragma once
#include "Entity.h"
#include "Utility.h"

class Spawnpoint : public Entity {
protected:
    bool m_touched = false;
    GLuint text_texture_id;

    const char** m_dialogue;
    int m_dialogue_index = 0;
    int m_dialogue_size = 0;
    
    float m_display_time = 2.5f;
    float m_accumulator = 0.0f;

public:
    Spawnpoint();

    void update(float delta_time, Entity* player, Entity* objects, int object_count, Map* map);

    bool touched() { return m_touched; }
    void reset_touched() { m_touched = false; }

    void render(ShaderProgram* program) override;

    void set_dialogue(int size, const char** new_dialogue) { m_dialogue = new_dialogue; m_dialogue_size = size; }
    void set_disp_time(float new_time) { m_display_time = new_time; }
};
