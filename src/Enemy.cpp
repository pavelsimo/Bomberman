#include "Enemy.h"

namespace
{
    const float ENEMY_WIDTH = 64.0f;
    const float ENEMY_HEIGHT = 64.0f;
    const float ENEMY_SHADOW_WIDTH = 16;
    const float ENEMY_SHADOW_HEIGHT = 8;
}

Enemy::Enemy()
: m_lowerLeftCorner(0, 0),
  m_state(EST_IDLE),
  m_curAnimation(nullptr),
  m_spriteSheet(nullptr)
{

}

Enemy::Enemy(float x, float y)
: Actor(x + ENEMY_WIDTH * 0.5f, y + ENEMY_HEIGHT - 5),
  m_lowerLeftCorner(x, y),
  m_state(EST_IDLE),
  m_curAnimation(nullptr),
  m_spriteSheet(nullptr)
{

}

Enemy::~Enemy()
{

}

void Enemy::OnRender()
{
    assert(m_spriteSheet != nullptr);
    m_curAnimation->Render();

#ifdef _DEBUG
    DrawAABB2(GetAABB2());
#endif
}

void Enemy::OnBeforeUpdate(World &world)
{

}

void Enemy::OnAfterUpdate(World &world)
{

}

void Enemy::Idle()
{

}

void Enemy::MoveLeft()
{
    SetState(EST_MOVING_LEFT);
}

void Enemy::MoveRight()
{
    SetState(EST_MOVING_RIGHT);
}

void Enemy::MoveUp()
{
    SetState(EST_MOVING_UP);
}

void Enemy::MoveDown()
{
    SetState(EST_MOVING_DOWN);
}

void Enemy::DropBomb()
{
    // do nothing
}

void Enemy::Initialize()
{
    //
    // Initialize Geometry
    //
    // upper-left corner
    m_geometry.push_back(Vector2(ENEMY_SHADOW_WIDTH, ENEMY_SHADOW_HEIGHT));
    // bottom-right corner
    m_geometry.push_back(Vector2(-ENEMY_SHADOW_WIDTH, -ENEMY_SHADOW_HEIGHT));


    //
    // Initialize Animation
    //
    m_walkingDownAnimation.SetPosition(m_lowerLeftCorner.x, m_lowerLeftCorner.y);
    m_walkingDownAnimation.AddFrame("Creep_F_f00.png");
    m_walkingDownAnimation.AddFrame("Creep_F_f01.png");
    m_walkingDownAnimation.AddFrame("Creep_F_f02.png");
    m_walkingDownAnimation.AddFrame("Creep_F_f03.png");
    m_walkingDownAnimation.AddFrame("Creep_F_f04.png");
    m_walkingDownAnimation.AddFrame("Creep_F_f05.png");

    m_walkingUpAnimation.SetPosition(m_lowerLeftCorner.x, m_lowerLeftCorner.y);
    m_walkingUpAnimation.AddFrame("Creep_B_f00.png");
    m_walkingUpAnimation.AddFrame("Creep_B_f01.png");
    m_walkingUpAnimation.AddFrame("Creep_B_f02.png");
    m_walkingUpAnimation.AddFrame("Creep_B_f03.png");
    m_walkingUpAnimation.AddFrame("Creep_B_f04.png");
    m_walkingUpAnimation.AddFrame("Creep_B_f05.png");

    m_walkingLeftAnimation.SetPosition(m_lowerLeftCorner.x, m_lowerLeftCorner.y);
    m_walkingLeftAnimation.AddFrame("Creep_LS_f00.png");
    m_walkingLeftAnimation.AddFrame("Creep_LS_f01.png");
    m_walkingLeftAnimation.AddFrame("Creep_LS_f02.png");
    m_walkingLeftAnimation.AddFrame("Creep_LS_f03.png");
    m_walkingLeftAnimation.AddFrame("Creep_LS_f04.png");
    m_walkingLeftAnimation.AddFrame("Creep_LS_f05.png");
    m_walkingLeftAnimation.AddFrame("Creep_LS_f06.png");

    m_walkingRightAnimation.SetPosition(m_lowerLeftCorner.x, m_lowerLeftCorner.y);
    m_walkingRightAnimation.AddFrame("Creep_RS_f00.png");
    m_walkingRightAnimation.AddFrame("Creep_RS_f01.png");
    m_walkingRightAnimation.AddFrame("Creep_RS_f02.png");
    m_walkingRightAnimation.AddFrame("Creep_RS_f03.png");
    m_walkingRightAnimation.AddFrame("Creep_RS_f04.png");
    m_walkingRightAnimation.AddFrame("Creep_RS_f05.png");
    m_walkingRightAnimation.AddFrame("Creep_RS_f06.png");

    m_curAnimation = &m_walkingDownAnimation;
}

void Enemy::SetSpriteSheet(SpriteSheet *spriteSheet)
{
    m_spriteSheet = spriteSheet;
    m_walkingDownAnimation.SetSpriteSheet(spriteSheet);
    m_walkingUpAnimation.SetSpriteSheet(spriteSheet);
    m_walkingLeftAnimation.SetSpriteSheet(spriteSheet);
    m_walkingRightAnimation.SetSpriteSheet(spriteSheet);
}

SpriteSheet* Enemy::GetSpriteSheet()
{
    return m_spriteSheet;
}

void Enemy::SetState(EnemyState state)
{
    m_state = state;
}

EnemyState Enemy::GetState() const
{
    return m_state;
}
