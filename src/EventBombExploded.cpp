#include "EventBombExploded.h"

const EventType EventBombExploded::Id_EventType(EVENT_BOMBEXPLODED);

EventBombExploded::EventBombExploded(ActorId id)
: m_id(id),
  m_name("EVENT_BOMB_EXPLODED")
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

