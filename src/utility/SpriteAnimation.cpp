#include "SpriteAnimation.h"

SpriteAnimation::SpriteAnimation()
: m_curFrame(0),
  m_spriteSheet(nullptr)
{

}

SpriteAnimation::~SpriteAnimation()
{

}

void SpriteAnimation::AddFrame(const std::string& spriteName)
{
    m_frames.push_back(spriteName);
}

SpriteSheetPtr SpriteAnimation::GetSpriteSheet() const
{
    return m_spriteSheet;
}

void SpriteAnimation::SetSpriteSheet(SpriteSheetPtr spriteSheet)
{
    m_spriteSheet = spriteSheet;
}

Vector2 SpriteAnimation::GetPosition() const
{
    return m_position;
}

void SpriteAnimation::SetPosition(const Vector2& pos)
{
    m_position = pos;
}

void SpriteAnimation::SetPosition(float x, float y)
{
    m_position = Vector2(x, y);
}

bool SpriteAnimation::NextFrame()
{
    int nxtFrame = (m_curFrame + 1) % Size();
    m_curFrame = nxtFrame;
    return true;
}

bool SpriteAnimation::PrevFrame()
{
    int nxtFrame = (Size() + m_curFrame - 1) % Size();
    m_curFrame = nxtFrame;
    return true;
}

void SpriteAnimation::Render()
{
    if(m_spriteSheet)
    {
        Sprite sprite = m_spriteSheet->GetSprite(m_frames[m_curFrame]);
        Rect rect;
        rect.x = sprite.x;
        rect.y = sprite.y;
        rect.w = sprite.w;
        rect.h = sprite.h;

        DrawTexture(m_position.x, m_position.y,
            m_spriteSheet->GetTexId(),
            m_spriteSheet->GetImgWidth(),
            m_spriteSheet->GetImgHeight(),
            m_spriteSheet->GetTexWidth(),
            m_spriteSheet->GetTexHeight(),
            &rect
        );
    }
}

std::size_t SpriteAnimation::Size() const
{
    return m_frames.size();
}





