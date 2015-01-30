#ifndef __PLAYERFIRECOLLISIONEVENT_H_
#define __PLAYERFIRECOLLISIONEVENT_H_

#include "BaseEvent.h"
#include "../Actor.h"
#include "../utility/Vector2.h"

class PlayerFireCollisionEvent : public BaseEvent
{
    public:

        // ctor & dtor
        //
        PlayerFireCollisionEvent(
            ActorId fireId,
            const Vector2& firePosition,
            const Vector2& playerPosition
        );
        ~PlayerFireCollisionEvent();

        // virtual
        //
        virtual const EventType& GetEventType() const override;
        virtual void Serialize(std::ostream &out) const override;
        virtual const std::string& GetName() const override;

        Vector2 GetPlayerPosition() const;
        ActorId GetFireId() const;
        Vector2 GetFirePosition() const;
        static const EventType Id_EventType;

    private:
        ActorId m_fireId;
        Vector2 m_firePosition;
        Vector2 m_playerPosition;
        std::string m_name;
};

#endif //__PLAYERFIRECOLLISIONEVENT_H_
