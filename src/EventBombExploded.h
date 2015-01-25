#ifndef __EVENTBOMBEXPLODED_H_
#define __EVENTBOMBEXPLODED_H_

#include "BaseEvent.h"
#include "Actor.h"
#include "utility/Vector2.h"

class EventBombExploded : public BaseEvent
{
    public:
        EventBombExploded(ActorId id, const Vector2& position);
        ~EventBombExploded();

        virtual const EventType& GetEventType() const override;
        virtual void Serialize(std::ostream &out) const override;
        virtual const std::string& GetName() const override;
        ActorId GetActorId() const;
        Vector2 GetBombPosition() const;

        static const EventType Id_EventType;
    private:
        ActorId m_id;
        Vector2 m_position;
        std::string m_name;
};

#endif //__EVENTBOMBEXPLODED_H_
