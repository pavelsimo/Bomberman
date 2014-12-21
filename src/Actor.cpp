#include "Actor.h"

#include <iostream>

Actor::Actor()
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
    OnUpdate(world);

    //
    // updating axis aligned bounding box
    //
    m_aabb2.Empty();

    for (auto it = m_geometry.cbegin(); it != m_geometry.cend(); ++it)
    {
        Vector2 point = Vector2(it->x + m_position.x, it->y + m_position.y);
        m_aabb2.Add(point);
    }

    /*
    std::cout << "(" << m_aabb2.min.x << "," << m_aabb2.min.y << ") (" <<
            m_aabb2.max.x << "," << m_aabb2.max.y << ")" << std::endl;
    */
}

void Actor::OnUpdate(World& world)
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

bool Actor::IsColliding(const Actor &actor)
{
    return false;
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

