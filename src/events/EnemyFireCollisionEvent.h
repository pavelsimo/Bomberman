#ifndef __ENEMYFIRECOLLISIONEVENT_H_
#define __ENEMYFIRECOLLISIONEVENT_H_

#include "BaseEvent.h"
#include "../Actor.h"
#include "../utility/Vector2.h"

// FIXME: (Pavel) Extend for an ActorCollisionEvent

class EnemyFireCollisionEvent : public BaseEvent
{
    public:

        // ctor & dtor
        //
        EnemyFireCollisionEvent(
            ActorId fireId,
            ActorId enemyId,
            const Vector2& firePosition,
            const Vector2& enemyPosition
        );
        ~EnemyFireCollisionEvent();

        // virtual
        //
        virtual const EventType& GetEventType() const override;
        virtual void Serialize(std::ostream &out) const override;
        virtual const std::string& GetName() const override;

        Vector2 GetEnemyPosition() const;
        ActorId GetFireId() const;
        ActorId GetEnemyId() const;
        Vector2 GetFirePosition() const;
        static const EventType Id_EventType;

    private:
        ActorId m_fireId;
        ActorId m_enemyId;
        Vector2 m_firePosition;
        Vector2 m_enemyPosition;
        std::string m_name;
};

#endif //__ENEMYFIRECOLLISIONEVENT_H_
