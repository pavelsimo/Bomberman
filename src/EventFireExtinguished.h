#ifndef __EVENTFIREEXTINGUISHED_H_
#define __EVENTFIREEXTINGUISHED_H_

#include "BaseEvent.h"
#include "Actor.h"
#include "utility/Vector2.h"

class EventFireExtinguished : public BaseEvent
{
    public:
        EventFireExtinguished(ActorId id, const Vector2& position);
        ~EventFireExtinguished();

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


#endif //__EVENTFIREEXTINGUISHED_H_
