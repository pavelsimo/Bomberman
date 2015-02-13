#include "Enemy.h"
#include "World.h"
#include "ai/RandomWalkAI.h"

namespace
{
    const float ENEMY_WIDTH = 48.0f;
    const float ENEMY_HEIGHT = 48.0f;
    const float ENEMY_SHADOW_WIDTH = 16;
    const float ENEMY_SHADOW_HEIGHT = 8;
    const float ENEMY_SPEED = 1.0f;
    const Vector2 ENEMY_DIR_UP = Vector2(0, -1);
    const Vector2 ENEMY_DIR_DOWN = Vector2(0, 1);
    const Vector2 ENEMY_DIR_LEFT = Vector2(-1, 0);
    const Vector2 ENEMY_DIR_RIGHT = Vector2(1, 0);
}

Enemy::Enemy()
: m_lowerLeftCorner(0, 0),
  m_state(EST_IDLE),
  m_curAnimation(nullptr),
  m_spriteSheet(nullptr),
  m_speed(ENEMY_SPEED)
{

}

Enemy::Enemy(float x, float y)
: Actor(x + 0.5f * ENEMY_WIDTH, y + ENEMY_HEIGHT - 5),
  m_lowerLeftCorner(x, y),
  m_state(EST_IDLE),
  m_curAnimation(nullptr),
  m_spriteSheet(nullptr),
  m_speed(ENEMY_SPEED)
{
#ifdef _DEBUG
    std::cout << "Creating the Enemy with ID " << GetId() << std::endl;;
#endif
}

Enemy::~Enemy()
{
#ifdef _DEBUG
    std::cout << "Destroying the Enemy with ID " << GetId() << std::endl;;
#endif
}

void Enemy::OnRender()
{
    assert(m_spriteSheet);
    m_curAnimation->Render();

#ifdef _DEBUG
    DrawAABB2(GetAABB2());
#endif
}

void Enemy::OnBeforeUpdate()
{
    switch(m_state)
    {
        case EST_IDLE:
            // do nothing
            break;
        case EST_MOVING_UP:
            MoveToDirection(ENEMY_DIR_UP);
            NextAnimation(m_walkingUpAnimation);
            break;
        case EST_MOVING_DOWN:
            MoveToDirection(ENEMY_DIR_DOWN);
            NextAnimation(m_walkingDownAnimation);
            break;
        case EST_MOVING_LEFT:
            MoveToDirection(ENEMY_DIR_LEFT);
            NextAnimation(m_walkingLeftAnimation);
            break;
        case EST_MOVING_RIGHT:
            MoveToDirection(ENEMY_DIR_RIGHT);
            NextAnimation(m_walkingRightAnimation);
            break;
        case EST_DEAD:
            // do nothing
            break;
    }
}

void Enemy::OnAfterUpdate()
{
    World& world = World::GetInstance();
    Actor collisionBlock;
    if(world.GetBlockManager()->IsColliding(*this, &collisionBlock))
    {
        m_randomWalkAI.NextDirection();

#if _DEBUG
        std::cout << "EBLOCK: " << "(" << collisionBlock.GetAABB2().min.x << ","
                << collisionBlock.GetAABB2().min.y << ")" << " "
                << "(" << collisionBlock.GetAABB2().max.x << ","
                << collisionBlock.GetAABB2().max.y << ")" << std::endl;
#endif
        Clamp(collisionBlock);
    }
}

void Enemy::Idle()
{
    SetState(EST_IDLE);
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

void Enemy::SetSpriteSheet(SpriteSheetPtr spriteSheet)
{
    m_spriteSheet = spriteSheet;
    m_walkingDownAnimation.SetSpriteSheet(spriteSheet);
    m_walkingUpAnimation.SetSpriteSheet(spriteSheet);
    m_walkingLeftAnimation.SetSpriteSheet(spriteSheet);
    m_walkingRightAnimation.SetSpriteSheet(spriteSheet);
}

SpriteSheetPtr Enemy::GetSpriteSheet()
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

void Enemy::NextAnimation(SpriteAnimation &animation)
{
    m_curAnimation = &animation;
    m_curAnimation->SetPosition(m_lowerLeftCorner.x, m_lowerLeftCorner.y);
    m_curAnimation->NextFrame();
}

void Enemy::Clamp(const Actor &collisionActor)
{
    if(GetDirection() == ENEMY_DIR_UP)
    {
        MoveTo(m_lowerLeftCorner.x, collisionActor.GetAABB2().max.y - ENEMY_HEIGHT + 5 + ENEMY_SHADOW_HEIGHT);
    }
    else if(GetDirection() == ENEMY_DIR_DOWN)
    {
        MoveTo(m_lowerLeftCorner.x, collisionActor.GetAABB2().min.y - ENEMY_HEIGHT - 5);
    }
    else if(GetDirection() == ENEMY_DIR_LEFT)
    {
        MoveTo(collisionActor.GetAABB2().max.x - m_speed, m_lowerLeftCorner.y);
    }
    else if(GetDirection() == ENEMY_DIR_RIGHT)
    {
        MoveTo(collisionActor.GetAABB2().min.x - ENEMY_WIDTH + m_speed, m_lowerLeftCorner.y);
    }
}

void Enemy::MoveTo(float x, float y)
{
    m_position = Vector2(x + 0.5f * ENEMY_WIDTH, y + ENEMY_HEIGHT - 5);
    m_lowerLeftCorner = Vector2(x, y);
    m_walkingDownAnimation.SetPosition(m_lowerLeftCorner.x, m_lowerLeftCorner.y);
    m_walkingUpAnimation.SetPosition(m_lowerLeftCorner.x, m_lowerLeftCorner.y);
    m_walkingLeftAnimation.SetPosition(m_lowerLeftCorner.x, m_lowerLeftCorner.y);
    m_walkingRightAnimation.SetPosition(m_lowerLeftCorner.x, m_lowerLeftCorner.y);
}

void Enemy::MoveToDirection(const Vector2 &direction)
{
    m_direction = direction;
    m_position += m_direction * m_speed;
    m_lowerLeftCorner += m_direction * m_speed;
}


CommandPtr Enemy::GetNextAction()
{
    return m_randomWalkAI.GetNextStep();
}
