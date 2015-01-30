#include "BaseEvent.h"

BaseEvent::BaseEvent(const float timeStamp)
: m_timeStamp(timeStamp)
{

}

BaseEvent::~BaseEvent()
{

}

float BaseEvent::GetTimeStamp() const
{
    return m_timeStamp;
}

void BaseEvent::Serialize(std::ostream &out) const
{

}
