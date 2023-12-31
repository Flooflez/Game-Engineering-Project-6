/**
* Author: Maximilian Ta
* Assignment: The Caves (Final Project)
* Date due: 2023-12-15, 11:59pm
* I pledge that I have completed this assignment without
* collaborating with anyone else, in conformance with the
* NYU School of Engineering Policies and Procedures on
* Academic Misconduct.
**/

#include "Menu.h"
#include "Utility.h"

Menu::~Menu()
{
    Mix_FreeMusic(m_state.bgm);
}

void Menu::initialise()
{
    text_texture_id = Utility::load_texture("assets/fonts/font1.png");

    /**
     BGM and SFX
     */
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);



    //fake player so program doesn't crash
    m_state.player = new Player();
    m_state.player->set_position(glm::vec3(0.0f, 0.0f, 0.0f));
    m_state.player->set_movement(glm::vec3(0.0f));
    m_state.player->set_speed(0.0f);
    m_state.player->set_acceleration(glm::vec3(0.0f, 0.0f, 0.0f));


}

void Menu::update(float delta_time)
{
    
}


void Menu::render(ShaderProgram* program)
{
    Utility::draw_text(text_texture_id, "The Caves", 0.6f, -0.1f, glm::vec3(-1.0f, 1.0f, 0));
    Utility::draw_text(text_texture_id, "PRESS ENTER", 0.4f, -0.1f, glm::vec3(0.0f, 0.0f, 0));
}
