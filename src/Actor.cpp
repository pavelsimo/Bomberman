#include <iostream>

#include "Actor.h"

Actor::Actor()
: m_position(0, 0),
  m_velocity(0, 0),
  m_direction(0, 0)
{

}

Actor::Actor(float x, float y)
: m_position(x, y)
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
    // overwrite

}

void Actor::Update(World& world)
{
    OnBeforeUpdate(world);

    //
    // updating axis aligned bounding box
    //
    m_aabb2.Empty();

    for (auto it = m_geometry.cbegin(); it != m_geometry.cend(); ++it)
    {
        Vector2 point = *it;
        point += m_position;
        m_aabb2.Add(point);
    }

    OnAfterUpdate(world);
}

void Actor::OnBeforeUpdate(World &world)
{
    // overwrite
}

void Actor::OnAfterUpdate(World &world)
{
    // overwrite
}

void Actor::MoveUp()
{
    OnMoveUp();
}

void Actor::OnMoveUp()
{
    // overwrite
}

void Actor::MoveDown()
{
    OnMoveDown();
}

void Actor::OnMoveDown()
{

}

void Actor::MoveLeft()
{
    OnMoveLeft();
}

void Actor::OnMoveLeft()
{
    // overwrite
}


void Actor::MoveRight()
{
    OnMoveRight();
}

void Actor::OnMoveRight()
{
    // overwrite
}

bool Actor::IsColliding(const Actor &actor) const
{
    AABB2 lhs = GetAABB2();
    AABB2 rhs = actor.GetAABB2();
    return lhs.Intersects(rhs);
}

void Actor::SetPosition(const Vector2 &position)
{
    m_position = position;
}

void Actor::SetVelocity(const Vector2 &velocity)
{
    m_velocity = velocity;
}

void Actor::SetDirection(const Vector2 &direction)
{
    m_direction = direction;
}

Vector2 Actor::GetPosition() const
{
    return m_position;
}

Vector2 Actor::GetVelocity() const
{
    return m_velocity;
}

Vector2 Actor::GetDirection() const
{
    return m_direction;
}

AABB2 Actor::GetAABB2() const
{
    return m_aabb2;
}

bool Actor::CanDelete()
{
    return false;
}
