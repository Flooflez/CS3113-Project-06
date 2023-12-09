#include "Effects.h"

Effects::Effects(glm::mat4 projection_matrix, glm::mat4 view_matrix)
{
    // Non textured Shader
    m_program.load("shaders/vertex.glsl", "shaders/fragment.glsl");
    m_program.set_projection_matrix(projection_matrix);
    m_program.set_view_matrix(view_matrix);

    m_current_effect = NONE;
    m_alpha = 1.0f;
    m_effect_speed = 1.0;

    m_view_offset = glm::vec3(0.0f);
}

void Effects::draw_overlay()
{
    glUseProgram(this->m_program.get_program_id());

    float vertices[] =
    {
        -0.5, -0.5,
         0.5, -0.5,
         0.5,  0.5,

        -0.5, -0.5,
         0.5,  0.5,
        -0.5,  0.5
    };

    glVertexAttribPointer(m_program.get_position_attribute(), 2, GL_FLOAT, false, 0, vertices);
    glEnableVertexAttribArray(m_program.get_position_attribute());
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glDisableVertexAttribArray(m_program.get_position_attribute());
}

void Effects::start(EffectType effect_type, float effect_speed = 0)
{
    m_current_effect = effect_type;
    m_effect_speed = effect_speed;

    switch (m_current_effect)
    {
    case NONE:                         break;
    }
}

void Effects::update(float delta_time, float param)
{
    switch (m_current_effect)
    {
    case NONE: break;
    case BLACK:
        if (param == 0) m_current_effect = NONE;
        break;
        // TINT
    case TINT:
        m_alpha = param;
        if (m_alpha <= 0) m_current_effect = NONE;
        break;
    }
}


void Effects::render()
{
    glm::mat4 model_matrix = glm::mat4(1.0f);

    switch (m_current_effect)
    {
    case NONE:
        break;

    case TINT:
        model_matrix = glm::scale(model_matrix, m_size);
        this->m_program.set_model_matrix(model_matrix);
        this->m_program.set_colour(0.5f, 0.0f, 0.0f, m_alpha);
        this->draw_overlay();
        break;
    case BLACK:
        model_matrix = glm::scale(model_matrix, m_size);
        this->m_program.set_model_matrix(model_matrix);
        this->m_program.set_colour(0.15f, 0.0f, 0.0f, 1.0);
        this->draw_overlay();
        break;
    }
}