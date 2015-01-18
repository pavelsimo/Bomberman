#include "Fire.h"
#include "World.h"
#include <algorithm>

namespace
{
    const uint32_t FIRE_WIDTH = 48;
    const uint32_t FIRE_HEIGHT = 48;
    const uint32_t FIRE_NEXTFRAME_WAIT = 10;
}

Fire::Fire()
: Actor(),
  m_spriteSheet(nullptr),
  m_nextFrameWait(FIRE_NEXTFRAME_WAIT)
{

}

Fire::Fire(float x, float y)
: Actor(x, y),
  m_spriteSheet(nullptr),
  m_nextFrameWait(FIRE_NEXTFRAME_WAIT)
{

}

Fire::~Fire()
{

}

void Fire::Initialize()
{
    InitializeGeometry();
    InitializeAnimation();
}

void Fire::OnRender()
{
    assert(m_spriteSheet != nullptr);
    m_animation.Render();

#ifdef _DEBUG
    DrawAABB2(GetAABB2());
#endif
}

void Fire::OnBeforeUpdate(World &world)
{
    if(CanRenderNextFrame())
    {
        m_animation.NextFrame();
        m_nextFrameWait = FIRE_NEXTFRAME_WAIT;
    }
    else
    {
        m_nextFrameWait = std::max<uint32_t>(0, m_nextFrameWait - 1);
    }
}

void Fire::SetSpriteSheet(SpriteSheet *spriteSheet)
{
    m_spriteSheet = spriteSheet;
    m_animation.SetSpriteSheet(spriteSheet);
}

SpriteSheet *Fire::GetSpriteSheet()
{
    return m_spriteSheet;
}

void Fire::InitializeGeometry()
{
    // upper-left corner
    m_geometry.push_back(Vector2(0, 0));
    // bottom-right corner
    m_geometry.push_back(Vector2(FIRE_WIDTH, FIRE_HEIGHT));
}

void Fire::InitializeAnimation()
{
    m_animation.SetPosition(m_position.x, m_position.y);
    m_animation.AddFrame("Flame_f00.png");
    m_animation.AddFrame("Flame_f01.png");
    m_animation.AddFrame("Flame_F02.png");
    m_animation.AddFrame("Flame_F03.png");
    m_animation.AddFrame("Flame_F04.png");
}


bool Fire::CanRenderNextFrame()
{
    return m_nextFrameWait == 0;
}
