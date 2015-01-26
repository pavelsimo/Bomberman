#include "EventFireExtinguished.h"

const EventType EventFireExtinguished::Id_EventType(EVENT_FIREEXTINGUISHED);

EventFireExtinguished::EventFireExtinguished(ActorId id, const Vector2& position)
: m_id(id),
  m_position(position),
  m_name("EVENT_FIREEXTINGUISHED")
{

}

EventFireExtinguished::~EventFireExtinguished()
{

}

const EventType& EventFireExtinguished::GetEventType() const
{
    return Id_EventType;
}

void EventFireExtinguished::Serialize(std::ostream &out) const
{

}

const std::string& EventFireExtinguished::GetName() const
{
    return m_name;
}

ActorId EventFireExtinguished::GetActorId() const
{
    return m_id;
}

Vector2 EventFireExtinguished::GetFirePosition() const
{
    return m_position;
}
