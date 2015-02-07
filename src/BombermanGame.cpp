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
    World::GetInstance()->OnKeyDown(event.keysym.sym);
}

void BombermanGame::OnKeyUp(SDL_KeyboardEvent& event)
{
    World::GetInstance()->OnKeyUp(event.keysym.sym);
}

void BombermanGame::OnUpdate()
{
    World::GetInstance()->OnUpdate();
}

void BombermanGame::OnRender()
{
    World::GetInstance()->OnRender();
}

void BombermanGame::OnInit()
{
    World::GetInstance()->Initialize(m_width, m_height);
}
