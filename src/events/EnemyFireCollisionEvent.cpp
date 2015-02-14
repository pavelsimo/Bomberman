#include "EnemyFireCollisionEvent.h"
#include "EventType.h"


const EventType EnemyFireCollisionEvent::Id_EventType(EVENT_ENEMYFIRECOLLISION);

EnemyFireCollisionEvent::EnemyFireCollisionEvent(ActorId fireId,
                                                 ActorId enemyId,
                                                 const Vector2& firePosition,
                                                 const Vector2& enemyPosition)
: m_fireId(fireId),
  m_enemyId(enemyId),
  m_firePosition(firePosition),
  m_enemyPosition(enemyPosition),
  m_name("EVENT_ENEMYFIRECOLLISION")
{

}

EnemyFireCollisionEvent::~EnemyFireCollisionEvent()
{

}

const EventType &EnemyFireCollisionEvent::GetEventType() const
{
    return Id_EventType;
}

void EnemyFireCollisionEvent::Serialize(std::ostream &out) const
{
    // TODO: (Pavel) IMPLEMENT ME!
}

const std::string &EnemyFireCollisionEvent::GetName() const
{
    return m_name;
}

Vector2 EnemyFireCollisionEvent::GetEnemyPosition() const
{
    return m_enemyPosition;
}

ActorId EnemyFireCollisionEvent::GetFireId() const
{
    return m_fireId;
}


ActorId EnemyFireCollisionEvent::GetEnemyId() const
{
    return m_enemyId;
}

Vector2 EnemyFireCollisionEvent::GetFirePosition() const
{
    return m_firePosition;
}
