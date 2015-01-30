#include "PlayerFireCollisionEvent.h"

const EventType PlayerFireCollisionEvent::Id_EventType(EVENT_PLAYERFIRECOLLISION);

PlayerFireCollisionEvent::PlayerFireCollisionEvent(ActorId fireId,
        const Vector2& firePosition,
        const Vector2& playerPosition)
: m_fireId(fireId),
  m_firePosition(firePosition),
  m_playerPosition(playerPosition),
  m_name("EVENT_PLAYERFIRECOLLISION")
{

}

PlayerFireCollisionEvent::~PlayerFireCollisionEvent()
{

}

const EventType &PlayerFireCollisionEvent::GetEventType() const
{
    return Id_EventType;
}

void PlayerFireCollisionEvent::Serialize(std::ostream &out) const
{
    // TODO: (Pavel) IMPLEMENT ME!
}

const std::string &PlayerFireCollisionEvent::GetName() const
{
    return m_name;
}

Vector2 PlayerFireCollisionEvent::GetPlayerPosition() const
{
    return m_playerPosition;
}

ActorId PlayerFireCollisionEvent::GetFireId() const
{
    return m_fireId;
}

Vector2 PlayerFireCollisionEvent::GetFirePosition() const
{
    return m_firePosition;
}
