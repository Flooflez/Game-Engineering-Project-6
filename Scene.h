#pragma once
#define GL_SILENCE_DEPRECATION

#ifdef _WINDOWS
#include <GL/glew.h>
#endif

#define GL_GLEXT_PROTOTYPES 1
#include <SDL_mixer.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "ShaderProgram.h"
#include "Utility.h"
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "Goal.h"
#include "Map.h"
#include "Spawnpoint.h"

/**
    Notice that the game's state is now part of the Scene class, not the main file.
*/
struct GameState
{
    // ————— GAME OBJECTS ————— //
    Map *map;
    Player *player = nullptr;
    Enemy *enemies;
    Goal* goals;
    Spawnpoint* spawnpoints;
    
    // ————— AUDIO ————— //
    Mix_Music *bgm;
    
    // ————— POINTERS TO OTHER SCENES ————— //
    int next_scene_id = -1;

};

class Scene {
public:
    // ————— ATTRIBUTES ————— //
    glm::vec3 m_spawn;
    GameState m_state;
    
    // ————— METHODS ————— //
    virtual void initialise() = 0;
    virtual void update(float delta_time) = 0;
    virtual void render(ShaderProgram *program) = 0;
    
    // ————— GETTERS ————— //
    GameState const get_state()             const { return m_state;             }

    // ----- Setters ----- //
    void set_spawn(glm::vec3 new_spawn) {m_spawn = new_spawn;}

    int m_score = 0;

protected:
    GLuint text_texture_id;
};
