#include "Player.h"
#include "World.h"
#include "events/PlayerFireCollisionEvent.h"

namespace
{
    const float PLAYER_WIDTH = 47.0f;
    const float PLAYER_HEIGHT = 86.0f;
    const float PLAYER_SPEED = 5.0f;
    const float PLAYER_DRAG = 0.9f;
    const float PLAYER_SHADOW_WIDTH = 16;
    const float PLAYER_SHADOW_HEIGHT = 8;
    const Vector2 PLAYER_DIR_UP = Vector2(0, -1);
    const Vector2 PLAYER_DIR_DOWN = Vector2(0, 1);
    const Vector2 PLAYER_DIR_LEFT = Vector2(-1, 0);
    const Vector2 PLAYER_DIR_RIGHT = Vector2(1, 0);
}

Player::Player()
: m_lowerLeftCorner(0, 0),
  m_state(PST_IDLE),
  m_curAnimation(nullptr),
  m_speed(PLAYER_SPEED)
{

}

Player::Player(float x, float y)
: Actor(x + PLAYER_WIDTH * 0.5f, y + PLAYER_HEIGHT - 10),
  m_lowerLeftCorner(x, y),
  m_state(PST_IDLE),
  m_curAnimation(nullptr),
  m_speed(PLAYER_SPEED)
{
#ifdef _DEBUG
    std::cout << "Creating the Player with ID " << GetId() << std::endl;
#endif
}

Player::~Player()
{
#ifdef _DEBUG
    std::cout << "Destroying the Player with ID " << GetId() << std::endl;;
#endif
}

void Player::Initialize()
{
    InitializeGeometry();
    InitializeAnimation();
}

void Player::OnRender()
{
    assert(m_spriteSheet);
    m_curAnimation->Render();

    #ifdef _DEBUG
    DrawAABB2(GetAABB2());
    #endif
}

void Player::OnBeforeUpdate()
{
    switch(m_state)
    {
        case PST_IDLE:
            // do nothing
            break;
        case PST_MOVING_UP:
            MoveToDirection(PLAYER_DIR_UP);
            NextAnimation(m_walkingUpAnimation);
            break;
        case PST_MOVING_DOWN:
            MoveToDirection(PLAYER_DIR_DOWN);
            NextAnimation(m_walkingDownAnimation);
            break;
        case PST_MOVING_LEFT:
            MoveToDirection(PLAYER_DIR_LEFT);
            NextAnimation(m_walkingLeftAnimation);
            break;
        case PST_MOVING_RIGHT:
            MoveToDirection(PLAYER_DIR_RIGHT);
            NextAnimation(m_walkingRightAnimation);
            break;
        case PST_DEAD:
            // do nothing
            break;
    }
}

void Player::OnAfterUpdate()
{
    World& world = World::GetInstance();
    Actor collisionBlock;
    if(world.GetBlockManager()->IsColliding(*this, &collisionBlock))
    {
#if _DEBUG
        std::cout << "CBLOCK: " << "(" << collisionBlock.GetAABB2().min.x << ","
                << collisionBlock.GetAABB2().min.y << ")" << " "
                << "(" << collisionBlock.GetAABB2().max.x << ","
                << collisionBlock.GetAABB2().max.y << ")" << std::endl;
#endif
        Clamp(collisionBlock);
    }

    Actor collisionFire;
    if(world.GetFireManager()->IsColliding(*this, &collisionFire))
    {
        ActorId fireId = collisionFire.GetId();
        Vector2 firePosition = collisionFire.GetPosition();
        Vector2 playerPosition = GetPosition();

        std::shared_ptr<PlayerFireCollisionEvent> playerFireCollisionEvent(
                new PlayerFireCollisionEvent(fireId, firePosition, playerPosition));
        world.GetEventManager()->QueueEvent(playerFireCollisionEvent);

        #if _DEBUG
                std::cout << "PLAYER IS DEAD!!" << std::endl;
        #endif
    }

    /*
    Actor collisionBomb;
    if(world.GetBombManager()->IsColliding(*this, &collisionBomb))
    {
        Clamp(collisionBomb);
    }
    */
}

void Player::Clamp(const Actor &collisionActor)
{
    if(GetDirection() == PLAYER_DIR_UP)
    {
        MoveTo(m_lowerLeftCorner.x, collisionActor.GetAABB2().max.y - PLAYER_HEIGHT + PLAYER_SHADOW_HEIGHT + 10);
    }
    else if(GetDirection() == PLAYER_DIR_DOWN)
    {
        MoveTo(m_lowerLeftCorner.x, collisionActor.GetAABB2().min.y - PLAYER_HEIGHT);
    }
    else if(GetDirection() == PLAYER_DIR_LEFT)
    {
        MoveTo(collisionActor.GetAABB2().max.x - m_speed, m_lowerLeftCorner.y);
    }
    else if(GetDirection() == PLAYER_DIR_RIGHT)
    {
        MoveTo(collisionActor.GetAABB2().min.x - PLAYER_WIDTH + m_speed, m_lowerLeftCorner.y);
    }
}

void Player::MoveToDirection(const Vector2 &direction)
{
    m_direction = direction;
    m_position += m_direction * m_speed;
    m_lowerLeftCorner += m_direction * m_speed;
}

void Player::SetSpriteSheet(SpriteSheetPtr spriteSheet)
{
    m_spriteSheet = spriteSheet;
    m_walkingDownAnimation.SetSpriteSheet(spriteSheet);
    m_walkingUpAnimation.SetSpriteSheet(spriteSheet);
    m_walkingLeftAnimation.SetSpriteSheet(spriteSheet);
    m_walkingRightAnimation.SetSpriteSheet(spriteSheet);
}

void Player::SetState(PlayerState state)
{
    m_state = state;
}

PlayerState Player::GetState() const
{
    return m_state;
}

SpriteSheetPtr Player::GetSpriteSheet()
{
    return m_spriteSheet;
}

void Player::InitializeGeometry()
{
    // upper-left corner
    m_geometry.push_back(Vector2(PLAYER_SHADOW_WIDTH, PLAYER_SHADOW_HEIGHT));
    // bottom-right corner
    m_geometry.push_back(Vector2(-PLAYER_SHADOW_WIDTH, -PLAYER_SHADOW_HEIGHT));
}

void Player::InitializeAnimation()
{
    m_walkingDownAnimation.SetPosition(m_lowerLeftCorner.x, m_lowerLeftCorner.y);
    m_walkingDownAnimation.AddFrame("Bman_F_f00.png");
    m_walkingDownAnimation.AddFrame("Bman_F_f01.png");
    m_walkingDownAnimation.AddFrame("Bman_F_f02.png");
    m_walkingDownAnimation.AddFrame("Bman_F_f03.png");
    m_walkingDownAnimation.AddFrame("Bman_F_f04.png");
    m_walkingDownAnimation.AddFrame("Bman_F_f05.png");
    m_walkingDownAnimation.AddFrame("Bman_F_f06.png");
    m_walkingDownAnimation.AddFrame("Bman_F_f07.png");

    m_walkingUpAnimation.SetPosition(m_lowerLeftCorner.x, m_lowerLeftCorner.y);
    m_walkingUpAnimation.AddFrame("Bman_B_f00.png");
    m_walkingUpAnimation.AddFrame("Bman_B_f01.png");
    m_walkingUpAnimation.AddFrame("Bman_B_f02.png");
    m_walkingUpAnimation.AddFrame("Bman_B_f03.png");
    m_walkingUpAnimation.AddFrame("Bman_B_f04.png");
    m_walkingUpAnimation.AddFrame("Bman_B_f05.png");
    m_walkingUpAnimation.AddFrame("Bman_B_f06.png");
    m_walkingUpAnimation.AddFrame("Bman_B_f07.png");

    m_walkingLeftAnimation.SetPosition(m_lowerLeftCorner.x, m_lowerLeftCorner.y);
    m_walkingLeftAnimation.AddFrame("Bman_LS_f00.png");
    m_walkingLeftAnimation.AddFrame("Bman_LS_f01.png");
    m_walkingLeftAnimation.AddFrame("Bman_LS_f02.png");
    m_walkingLeftAnimation.AddFrame("Bman_LS_f03.png");
    m_walkingLeftAnimation.AddFrame("Bman_LS_f04.png");
    m_walkingLeftAnimation.AddFrame("Bman_LS_f05.png");
    m_walkingLeftAnimation.AddFrame("Bman_LS_f06.png");
    m_walkingLeftAnimation.AddFrame("Bman_LS_f07.png");

    m_walkingRightAnimation.SetPosition(m_lowerLeftCorner.x, m_lowerLeftCorner.y);
    m_walkingRightAnimation.AddFrame("Bman_RS_f00.png");
    m_walkingRightAnimation.AddFrame("Bman_RS_f01.png");
    m_walkingRightAnimation.AddFrame("Bman_RS_f02.png");
    m_walkingRightAnimation.AddFrame("Bman_RS_f03.png");
    m_walkingRightAnimation.AddFrame("Bman_RS_f04.png");
    m_walkingRightAnimation.AddFrame("Bman_RS_f05.png");
    m_walkingRightAnimation.AddFrame("Bman_RS_f06.png");
    m_walkingRightAnimation.AddFrame("Bman_RS_f07.png");

    m_curAnimation = &m_walkingDownAnimation;
}

void Player::NextAnimation(SpriteAnimation& animation)
{
    m_curAnimation = &animation;
    m_curAnimation->SetPosition(m_lowerLeftCorner.x, m_lowerLeftCorner.y);
    m_curAnimation->NextFrame();
}

// FIXME: (Pavel) Should restrict the use of SetPosition
void Player::MoveTo(float x, float y)
{
    m_position = Vector2(x + PLAYER_WIDTH * 0.5f, y + PLAYER_HEIGHT - 10);
    m_lowerLeftCorner = Vector2(x, y);
    m_walkingDownAnimation.SetPosition(m_lowerLeftCorner.x, m_lowerLeftCorner.y);
    m_walkingUpAnimation.SetPosition(m_lowerLeftCorner.x, m_lowerLeftCorner.y);
    m_walkingLeftAnimation.SetPosition(m_lowerLeftCorner.x, m_lowerLeftCorner.y);
    m_walkingRightAnimation.SetPosition(m_lowerLeftCorner.x, m_lowerLeftCorner.y);
}

void Player::MoveLeft()
{
    SetState(PST_MOVING_LEFT);
}

void Player::MoveRight()
{
    SetState(PST_MOVING_RIGHT);
}

void Player::MoveUp()
{
    SetState(PST_MOVING_UP);
}

void Player::MoveDown()
{
    SetState(PST_MOVING_DOWN);
}

void Player::Idle()
{
    SetState(PST_IDLE);
}

void Player::DropBomb()
{
    World& world = World::GetInstance();
    uint32_t TILE_WIDTH = world.GetTileManager()->GetTileWidth();
    uint32_t TILE_HEIGHT = world.GetTileManager()->GetTileWidth();
    int x = floor(m_position.x / TILE_WIDTH) * TILE_WIDTH + (TILE_WIDTH - Bomb::WIDTH) * 0.5;
    int y = floor(m_position.y / TILE_HEIGHT) * TILE_HEIGHT + (TILE_HEIGHT - Bomb::HEIGHT) * 0.5;

    // FIXME: (Pavel) Create a BombFactory
    Bomb *bomb = new Bomb(x, y);
    bomb->SetSpriteSheet(m_spriteSheet);
    bomb->Initialize();
    bomb->Update();

#if _DEBUG
    std::cout << "BOMB: " << x << " " << y << std::endl;
#endif

    // adding a bomb to the world
    world.GetBombManager()->Add(bomb);
}
