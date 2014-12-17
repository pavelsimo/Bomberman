#include "Actor.h"

Actor::Actor()
{

}

Actor::~Actor()
{

}

void Actor::Render()
{
    OnRender();
}

void Actor::OnRender()
{

}

void Actor::Update(World & world)
{
    OnUpdate();
}

void Actor::OnUpdate(World & world)
{

}

void Actor::MoveForward()
{
    OnMoveForward();
}

void Actor::OnMoveForward()
{

}

void Actor::MoveBackward()
{
    OnMoveBackward();
}

void Actor::OnMoveBackward()
{

}

void Actor::MoveLeft()
{
    OnMoveLeft();
}

void Actor::OnMoveLeft()
{

}

void Actor::MoveRight()
{
    OnMoveRight();
}

void Actor::OnMoveRight()
{

}

bool Actor::IsColliding(const Actor &actor)
{
    return false;
}

void Actor::SetPosition(const Vector2 &position)
{

}

void Actor::SetVelocity(const Vector2 &velocity)
{

}

void Actor::SetDirection(const Vector2 &direction)
{

}

Vector2 Actor::GetPosition() const
{
    return Vector2();
}

Vector2 Actor::GetVelocity() const
{
    return Vector2();
}

Vector2 Actor::GetDirection() const
{
    return Vector2();
}

AABB2 Actor::GetAABB2() const
{
    return AABB2();
}

