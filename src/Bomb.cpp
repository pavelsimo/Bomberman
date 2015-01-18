#include "Bomb.h"
#include "World.h"

namespace
{
    const uint32_t BOMB_WIDTH = 48;
    const uint32_t BOMB_HEIGHT = 48;
    const uint32_t BOMB_NEXTFRAME_WAIT = 10;
}

Bomb::Bomb()
: Actor(),
  m_spriteSheet(nullptr),
  m_nextFrameWait(BOMB_NEXTFRAME_WAIT)
{

}

Bomb::Bomb(float x, float y)
: Actor(x, y),
  m_spriteSheet(nullptr),
  m_nextFrameWait(BOMB_NEXTFRAME_WAIT)
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

void Bomb::OnBeforeUpdate(World &world)
{
    if(CanRenderNextFrame())
    {
        m_animation.NextFrame();
        m_nextFrameWait = BOMB_NEXTFRAME_WAIT;
    }
    else
    {
        m_nextFrameWait = std::max<uint32_t>(0, m_nextFrameWait - 1);
    }
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

bool Bomb::CanRenderNextFrame()
{
    return m_nextFrameWait == 0;
}
