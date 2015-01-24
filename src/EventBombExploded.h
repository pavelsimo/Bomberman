#ifndef __EVENTBOMBEXPLODED_H_
#define __EVENTBOMBEXPLODED_H_

#include "BaseEvent.h"
#include "Actor.h"

class EventBombExploded : public BaseEvent
{
    public:
        explicit EventBombExploded(ActorId id);
        ~EventBombExploded();

        virtual const EventType& GetEventType() const override;
        virtual void Serialize(std::ostream &out) const override;
        virtual const std::string& GetName() const override;

        static const EventType Id_EventType;
    private:
        ActorId m_id;
        std::string m_name;
};

#endif //__EVENTBOMBEXPLODED_H_
