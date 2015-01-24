#include "BombermanGame.h"

BombermanGame::BombermanGame(const std::string &title, uint32_t width, uint32_t height)
: Game(title, width, height)
{

}

BombermanGame::~BombermanGame()
{

}

void BombermanGame::OnKeyDown(SDL_KeyboardEvent& event)
{
    switch(event.keysym.sym)
    {
        case SDLK_w:
            World::GetInstance().OnKeyDown('w');
            break;
        case SDLK_s:
            World::GetInstance().OnKeyDown('s');
            break;
        case SDLK_a:
            World::GetInstance().OnKeyDown('a');
            break;
        case SDLK_d:
            World::GetInstance().OnKeyDown('d');
            break;
        case SDLK_SPACE:
            World::GetInstance().OnKeyDown(' ');
            break;
    }
}

void BombermanGame::OnKeyUp(SDL_KeyboardEvent& event)
{
    switch(event.keysym.sym)
    {
        case SDLK_w:
            World::GetInstance().OnKeyUp('w');
            break;
        case SDLK_s:
            World::GetInstance().OnKeyUp('s');
            break;
        case SDLK_a:
            World::GetInstance().OnKeyUp('a');
            break;
        case SDLK_d:
            World::GetInstance().OnKeyUp('d');
            break;
    }
}

void BombermanGame::OnUpdate()
{
    World::GetInstance().OnUpdate();
}

void BombermanGame::OnRender()
{
    World::GetInstance().OnRender();
}

void BombermanGame::OnInit()
{
    World::GetInstance().Initialize(m_width, m_height);
}
