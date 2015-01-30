#ifndef __FIREEXTINGUISHEDEVENT_H_
#define __FIREEXTINGUISHEDEVENT_H_

#include "BaseEvent.h"
#include "../Actor.h"
#include "../utility/Vector2.h"

class FireExtinguishedEvent : public BaseEvent
{
    public:
        FireExtinguishedEvent(ActorId id, const Vector2& position);
        ~FireExtinguishedEvent();

        virtual const EventType& GetEventType() const override;
        virtual void Serialize(std::ostream &out) const override;
        virtual const std::string& GetName() const override;
        ActorId GetActorId() const;
        Vector2 GetFirePosition() const;

        static const EventType Id_EventType;
    private:
        ActorId m_id;
        Vector2 m_position;
        std::string m_name;
};


#endif //__FIREEXTINGUISHEDEVENT_H_
