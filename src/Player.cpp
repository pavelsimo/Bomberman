#include "Player.h"
#include "World.h"

namespace
{
    const float PLAYER_WIDTH = 47.0f;
    const float PLAYER_HEIGHT = 86.0f;
    const float PLAYER_SPEED = 5.0f;
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
  m_curAnimation(nullptr)
{

}

Player::Player(float x, float y)
: Actor(x + PLAYER_WIDTH * 0.5f, y + PLAYER_HEIGHT - 10),
  m_lowerLeftCorner(x, y),
  m_state(PST_IDLE),
  m_curAnimation(nullptr)
{

}

Player::~Player()
{
    #ifdef _DEBUG
        std::cout << "DESTROY PLAYER: " << GetId() << '\n';
    #endif
}

void Player::Initialize()
{
    InitializeGeometry();
    InitializeAnimation();
}

void Player::OnRender()
{
    assert(m_spriteSheet != nullptr);
    m_curAnimation->Render();

    #ifdef _DEBUG
    DrawAABB2(GetAABB2());
    #endif
}

void Player::OnBeforeUpdate(World &world)
{
    switch(m_state)
    {
        case PST_IDLE:
            OnIdle();
            break;
        case PST_MOVING_UP:
            OnMoveUp();
            break;
        case PST_MOVING_DOWN:
            OnMoveDown();
            break;
        case PST_MOVING_LEFT:
            OnMoveLeft();
            break;
        case PST_MOVING_RIGHT:
            OnMoveRight();
            break;
        case PST_DEAD:
            // do nothing
            break;
    }
}

void Player::OnAfterUpdate(World &world)
{
    Actor collisionBlock;
    if(world.GetBlockManager().IsColliding(*this, &collisionBlock))
    {

#if _DEBUG
        std::cout << "CBLOCK: " << "(" << collisionBlock.GetAABB2().min.x << ","
                << collisionBlock.GetAABB2().min.y << ")" << " "
                << "(" << collisionBlock.GetAABB2().max.x << ","
                << collisionBlock.GetAABB2().max.y << ")" << std::endl;
#endif

        Clamp(collisionBlock);
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
        MoveTo(collisionActor.GetAABB2().max.x - PLAYER_SPEED, m_lowerLeftCorner.y);
    }
    else if(GetDirection() == PLAYER_DIR_RIGHT)
    {
        MoveTo(collisionActor.GetAABB2().min.x - PLAYER_WIDTH + PLAYER_SPEED, m_lowerLeftCorner.y);
    }
}

void Player::OnIdle()
{
    // do nothing
}

void Player::OnMove(SpriteAnimation& animation, const Vector2& direction)
{
    m_direction = direction;
    m_position += m_direction * PLAYER_SPEED;
    m_lowerLeftCorner += m_direction * PLAYER_SPEED;
    NextAnimation(animation);
}

void Player::OnMoveUp()
{
    OnMove(m_walkingUpAnimation, PLAYER_DIR_UP);
}

void Player::OnMoveDown()
{
    OnMove(m_walkingDownAnimation, PLAYER_DIR_DOWN);
}

void Player::OnMoveLeft()
{
    OnMove(m_walkingLeftAnimation, PLAYER_DIR_LEFT);
}

void Player::OnMoveRight()
{
    OnMove(m_walkingRightAnimation, PLAYER_DIR_RIGHT);
}

void Player::SetSpriteSheet(SpriteSheet* spriteSheet)
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

SpriteSheet* Player::GetSpriteSheet()
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

void Player::DropBomb(World& world)
{
    uint32_t TILE_WIDTH = world.GetTileManager().GetTileWidth();
    uint32_t TILE_HEIGHT = world.GetTileManager().GetTileWidth();
    int x = floor(m_position.x / TILE_WIDTH) * TILE_WIDTH + (TILE_WIDTH - Bomb::WIDTH) * 0.5;
    int y = floor(m_position.y / TILE_HEIGHT) * TILE_HEIGHT + (TILE_HEIGHT - Bomb::HEIGHT) * 0.5;

    // FIXME: (Pavel) Create a BombFactory
    Bomb *bomb = new Bomb(x, y);
    bomb->SetSpriteSheet(m_spriteSheet);
    bomb->Initialize();
    bomb->Update(world);

#if _DEBUG
    std::cout << "BOMB: " << x << " " << y << std::endl;
#endif

    // adding a bomb to the world
    world.GetBombManager().Add(bomb);
}
