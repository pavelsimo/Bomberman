#include "Player.h"

const float PLAYER_WIDTH = 47.0f;
const float PLAYER_HEIGHT = 86.0f;
const float PLAYER_SPEED = 5.0f;
const float PLAYER_SHADOW_WIDTH = 16;
const float PLAYER_SHADOW_HEIGHT = 8;
const Vector2 PLAYER_DIR_UP = Vector2(0, -1);
const Vector2 PLAYER_DIR_DOWN = Vector2(0, 1);
const Vector2 PLAYER_DIR_LEFT = Vector2(-1, 0);
const Vector2 PLAYER_DIR_RIGHT = Vector2(1, 0);

Player::Player()
: m_state(PST_IDLE),
  m_curAnimation(nullptr),
  m_lowerLeftCorner(0, 0)
{

}

Player::Player(float x, float y)
: m_state(PST_IDLE),
  m_curAnimation(nullptr),
  m_lowerLeftCorner(x, y),
  Actor(x + PLAYER_WIDTH * 0.5f, y + PLAYER_HEIGHT - 10)
{

}

Player::~Player()
{

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

    #ifdef DEBUG
    DrawAABB2(GetAABB2());
    #endif
}

void Player::OnUpdate(World & world)
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
    }
}

void Player::OnIdle()
{
    // do nothing
}

void Player::OnMove()
{
    m_position += m_direction * PLAYER_SPEED;
    m_lowerLeftCorner += m_direction * PLAYER_SPEED;
}

void Player::OnMoveUp()
{
    m_direction = PLAYER_DIR_UP;
    OnMove();
    NextAnimation(m_walkingUpAnimation);
}

void Player::OnMoveDown()
{
    m_direction = PLAYER_DIR_DOWN;
    OnMove();
    NextAnimation(m_walkingDownAnimation);
}

void Player::OnMoveLeft()
{
    m_direction = PLAYER_DIR_LEFT;
    OnMove();
    NextAnimation(m_walkingLeftAnimation);
}

void Player::OnMoveRight()
{
    m_direction = PLAYER_DIR_RIGHT;
    OnMove();
    NextAnimation(m_walkingRightAnimation);
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
