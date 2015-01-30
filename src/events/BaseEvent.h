#ifndef __BASEEVENT_H_
#define __BASEEVENT_H_

#include "IEvent.h"

class BaseEvent : public IEvent
{
    public:
        explicit BaseEvent(const float timeStamp = 0.0f);
        virtual ~BaseEvent();

        virtual const EventType& GetEventType() const = 0;
        virtual float GetTimeStamp() const override;
        virtual void Serialize(std::ostream &out) const override;
        virtual const std::string& GetName() const = 0;

    private:
        const float m_timeStamp;
};

#endif //__BASEEVENT_H_



