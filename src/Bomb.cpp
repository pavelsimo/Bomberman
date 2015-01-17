#include "Bomb.h"

namespace
{
    const uint32_t BOMB_WIDTH = 48;
    const uint32_t BOMB_HEIGHT = 48;
}

Bomb::Bomb()
{

}

Bomb::Bomb(float x, float y)
: Actor(x, y)
{

}

Bomb::~Bomb()
{

}


void Bomb::Initialize()
{
    InitializeGeometry();
    InitializeAnimation();
}

void Bomb::OnRender()
{
    assert(m_spriteSheet != nullptr);
    m_animation.Render();

#ifdef _DEBUG
    DrawAABB2(GetAABB2());
#endif
}

void Bomb::InitializeGeometry()
{
    // upper-left corner
    m_geometry.push_back(Vector2(0, 0));
    // bottom-right corner
    m_geometry.push_back(Vector2(BOMB_WIDTH, BOMB_HEIGHT));
}

void Bomb::InitializeAnimation()
{
    m_animation.SetPosition(m_position.x, m_position.y);
    m_animation.AddFrame("Bomb_f01.png");
    m_animation.AddFrame("Bomb_f02.png");
    m_animation.AddFrame("Bomb_f03.png");
}

void Bomb::SetSpriteSheet(SpriteSheet *spriteSheet)
{
    m_spriteSheet = spriteSheet;
    m_animation.SetSpriteSheet(spriteSheet);
}

SpriteSheet *Bomb::GetSpriteSheet()
{
    return m_spriteSheet;
}