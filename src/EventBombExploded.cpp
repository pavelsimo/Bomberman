#include "EventBombExploded.h"

const EventType EventBombExploded::Id_EventType(EVENT_BOMBEXPLODED);

EventBombExploded::EventBombExploded(ActorId id, const Vector2& position)
: m_id(id),
  m_position(position),
  m_name("EVENT_BOMBEXPLODED")
{

}

EventBombExploded::~EventBombExploded()
{

}

const EventType& EventBombExploded::GetEventType() const
{
    return Id_EventType;
}

void EventBombExploded::Serialize(std::ostream &out) const
{

}

const std::string& EventBombExploded::GetName() const
{
    return m_name;
}

ActorId EventBombExploded::GetActorId() const
{
    return m_id;
}

Vector2 EventBombExploded::GetBombPosition() const
{
    return m_position;
}
