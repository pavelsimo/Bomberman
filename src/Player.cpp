#include "Player.h"

const float PLAYER_WIDTH = 47.0f;
const float PLAYER_HEIGHT = 86.0f;
const float PLAYER_SPEED = 5.0f;

Player::Player()
: m_state(PST_IDLE),
  m_curAnimation(nullptr)
{

}

Player::Player(float x, float y)
: m_state(PST_IDLE),
  m_curAnimation(nullptr),
  Actor(x, y)
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
}

void Player::OnMoveUp()
{
    m_direction.x = 0;
    m_direction.y = -1;
    OnMove();
    NextAnimation(m_walkingUpAnimation);
}

void Player::OnMoveDown()
{
    m_direction.x = 0;
    m_direction.y = 1;
    OnMove();
    NextAnimation(m_walkingDownAnimation);
}

void Player::OnMoveLeft()
{
    m_direction.x = -1;
    m_direction.y = 0;
    OnMove();
    NextAnimation(m_walkingLeftAnimation);
}

void Player::OnMoveRight()
{
    m_direction.x = 1;
    m_direction.y = 0;
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

void Player::SetState(PlayeState state)
{
    m_state = state;
}

PlayeState Player::GetState() const
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
    m_geometry.push_back(Vector2(PLAYER_WIDTH * -0.5f, PLAYER_HEIGHT * -0.5f));

    // bottom-right corner
    m_geometry.push_back(Vector2(PLAYER_WIDTH * 0.5f, PLAYER_HEIGHT * 0.5f));
}

void Player::InitializeAnimation()
{
    m_walkingDownAnimation.SetPosition(m_position.x, m_position.y);
    m_walkingDownAnimation.AddFrame("Bman_F_f00.png");
    m_walkingDownAnimation.AddFrame("Bman_F_f01.png");
    m_walkingDownAnimation.AddFrame("Bman_F_f02.png");
    m_walkingDownAnimation.AddFrame("Bman_F_f03.png");
    m_walkingDownAnimation.AddFrame("Bman_F_f04.png");
    m_walkingDownAnimation.AddFrame("Bman_F_f05.png");
    m_walkingDownAnimation.AddFrame("Bman_F_f06.png");
    m_walkingDownAnimation.AddFrame("Bman_F_f07.png");

    m_walkingUpAnimation.SetPosition(m_position.x, m_position.y);
    m_walkingUpAnimation.AddFrame("Bman_B_f00.png");
    m_walkingUpAnimation.AddFrame("Bman_B_f01.png");
    m_walkingUpAnimation.AddFrame("Bman_B_f02.png");
    m_walkingUpAnimation.AddFrame("Bman_B_f03.png");
    m_walkingUpAnimation.AddFrame("Bman_B_f04.png");
    m_walkingUpAnimation.AddFrame("Bman_B_f05.png");
    m_walkingUpAnimation.AddFrame("Bman_B_f06.png");
    m_walkingUpAnimation.AddFrame("Bman_B_f07.png");

    m_walkingLeftAnimation.SetPosition(m_position.x, m_position.y);
    m_walkingLeftAnimation.AddFrame("Bman_LS_f00.png");
    m_walkingLeftAnimation.AddFrame("Bman_LS_f01.png");
    m_walkingLeftAnimation.AddFrame("Bman_LS_f02.png");
    m_walkingLeftAnimation.AddFrame("Bman_LS_f03.png");
    m_walkingLeftAnimation.AddFrame("Bman_LS_f04.png");
    m_walkingLeftAnimation.AddFrame("Bman_LS_f05.png");
    m_walkingLeftAnimation.AddFrame("Bman_LS_f06.png");
    m_walkingLeftAnimation.AddFrame("Bman_LS_f07.png");

    m_walkingRightAnimation.SetPosition(m_position.x, m_position.y);
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
    m_curAnimation->SetPosition(m_position.x, m_position.y);
    m_curAnimation->NextFrame();
}
