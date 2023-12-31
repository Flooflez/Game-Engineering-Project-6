#pragma once
#define GL_SILENCE_DEPRECATION

#ifdef _WINDOWS
#include <GL/glew.h>
#endif

#define GL_GLEXT_PROTOTYPES 1
#include <vector>
#include <math.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "ShaderProgram.h"

enum EffectType { NONE, TINT, BLACK, FADEIN, FADEOUT};

class Effects {
private:
    ShaderProgram m_program;
    EffectType    m_current_effect;

    float m_alpha;
    float m_effect_speed;
    glm::vec3 m_size = glm::vec3(10.0f);
    float m_time_left;

public:
    glm::vec3 m_view_offset;

    Effects(glm::mat4 projection_matrix, glm::mat4 view_matrix);

    void draw_overlay();
    void start(EffectType effect_type, float effect_speed);
    void update(float delta_time, float param);
    void render();

    float get_alpha() { return m_alpha; }
};