#include "BombermanGame.h"

BombermanGame::BombermanGame(const std::string &title, uint32_t width, uint32_t height)
: Game(title, width, height),
  m_world(new World(width, height))
{

}

BombermanGame::~BombermanGame()
{
    if(m_world != nullptr)
    {
        delete m_world;
        m_world = nullptr;
    }
}

void BombermanGame::OnKeyDown(SDL_Keycode key)
{
    switch(key)
    {
        case SDLK_w:
            m_world->OnKeyDown('w');
            break;
        case SDLK_s:
            m_world->OnKeyDown('s');
            break;
        case SDLK_a:
            m_world->OnKeyDown('a');
            break;
        case SDLK_d:
            m_world->OnKeyDown('d');
            break;
    }
}

void BombermanGame::OnKeyUp(SDL_Keycode key)
{
    switch(key)
    {
        case SDLK_w:
            m_world->OnKeyUp('w');
            break;
        case SDLK_s:
            m_world->OnKeyUp('s');
            break;
        case SDLK_a:
            m_world->OnKeyUp('a');
            break;
        case SDLK_d:
            m_world->OnKeyUp('d');
            break;
    }
}

void BombermanGame::OnUpdate()
{
    m_world->OnUpdate();
}

void BombermanGame::OnRender()
{
    m_world->OnRender();
}

void BombermanGame::OnInit()
{
    m_world->OnSetup();
}
