#include "FireExtinguishedEvent.h"

const EventType FireExtinguishedEvent::Id_EventType(EVENT_FIREEXTINGUISHED);

FireExtinguishedEvent::FireExtinguishedEvent(ActorId id, const Vector2& position)
: m_id(id),
  m_position(position),
  m_name("EVENT_FIREEXTINGUISHED")
{

}

FireExtinguishedEvent::~FireExtinguishedEvent()
{

}

const EventType&FireExtinguishedEvent::GetEventType() const
{
    return Id_EventType;
}

void FireExtinguishedEvent::Serialize(std::ostream &out) const
{

}

const std::string&FireExtinguishedEvent::GetName() const
{
    return m_name;
}

ActorId FireExtinguishedEvent::GetActorId() const
{
    return m_id;
}

Vector2 FireExtinguishedEvent::GetFirePosition() const
{
    return m_position;
}
