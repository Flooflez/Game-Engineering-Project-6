/**
* Author: Maximilian Ta
* Assignment: The Caves (Final Project)
* Date due: 2023-12-15, 11:59pm
* I pledge that I have completed this assignment without
* collaborating with anyone else, in conformance with the
* NYU School of Engineering Policies and Procedures on
* Academic Misconduct.
*
* Original File created by Sebastián Romero Cruz
**/

#include "Win.h"
#include "Utility.h"



Win::~Win()
{
    Mix_FreeMusic(m_state.bgm);
}

void Win::initialise()
{
    text_texture_id = Utility::load_texture("assets/fonts/font1.png");

    //fake player so program doesn't crash
    m_state.player = new Player();
    m_state.player->set_position(glm::vec3(0.0f, 0.0f, 0.0f));
    m_state.player->set_movement(glm::vec3(0.0f));
    m_state.player->set_speed(0.0f);
    m_state.player->set_acceleration(glm::vec3(0.0f, 0.0f, 0.0f));
}

void Win::update(float delta_time)
{

}


void Win::render(ShaderProgram* program)
{
    Utility::draw_text(text_texture_id, "YOU WIN?", 0.6f, -0.1f, glm::vec3(-2.0f, 0.0f, 0));
    Utility::draw_text(text_texture_id, "Thanks for playing", 0.4f, -0.1f, glm::vec3(-1.25f, -0.5f, 0));
}
