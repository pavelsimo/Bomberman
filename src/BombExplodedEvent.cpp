#include "BombExplodedEvent.h"

const EventType BombExplodedEvent::Id_EventType(EVENT_BOMBEXPLODED);

BombExplodedEvent::BombExplodedEvent(ActorId id, const Vector2& position)
: m_id(id),
  m_position(position),
  m_name("EVENT_BOMBEXPLODED")
{

}

BombExplodedEvent::~BombExplodedEvent()
{

}

const EventType&BombExplodedEvent::GetEventType() const
{
    return Id_EventType;
}

void BombExplodedEvent::Serialize(std::ostream &out) const
{

}

const std::string&BombExplodedEvent::GetName() const
{
    return m_name;
}

ActorId BombExplodedEvent::GetActorId() const
{
    return m_id;
}

Vector2 BombExplodedEvent::GetBombPosition() const
{
    return m_position;
}
