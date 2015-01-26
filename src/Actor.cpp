#include <iostream>
#include <elf.h>

#include "Actor.h"

std::atomic<ActorId> Actor::counter(0);

Actor::Actor()
: m_position(0, 0),
  m_velocity(0, 0),
  m_direction(0, 0),
  m_lifeSpan(0)
{
    m_id = ++counter;
}

Actor::Actor(float x, float y)
: m_position(x, y),
  m_lifeSpan(0)
{
    m_id = ++counter;
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
    // updating lifespan
    //
    m_lifeSpan = std::max<uint32_t>(0, m_lifeSpan - 1);

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


void Actor::SetLifeSpan(uint32_t lifeSpan)
{
    m_lifeSpan = lifeSpan;
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

uint32_t Actor::GetLifeSpan() const
{
    return m_lifeSpan;
}

bool Actor::CanDelete()
{
    return GetLifeSpan() == 0;
}

ActorId Actor::GetId() const
{
    return m_id;
}
