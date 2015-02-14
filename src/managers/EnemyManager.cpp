#include "EnemyManager.h"
#include "../World.h"
#include "../Enemy.h"
#include "../Shortcuts.h"
#include "../events/EnemyFireCollisionEvent.h"

EnemyManager::EnemyManager()
{

}

EnemyManager::~EnemyManager()
{
    // Removing Listener OnEnemyFireCollision
    EVENT_MGR_REMOVE_LISTENER(callbackEnemyFireCollision, &EnemyManager::OnEnemyFireCollision,
            EnemyFireCollisionEvent::Id_EventType)
}

void EnemyManager::Initialize()
{
    // Adding Listener OnEnemyFireCollision
    EVENT_MGR_ADD_LISTENER(callbackEnemyFireCollision, &EnemyManager::OnEnemyFireCollision,
            EnemyFireCollisionEvent::Id_EventType)
}


void EnemyManager::Update()
{
    for(auto it = m_actors.begin(); it != m_actors.end(); ++it)
    {
        Enemy* currentEnemy = dynamic_cast<Enemy*>(*it);

        CommandPtr enemyCommand = currentEnemy->GetNextAction();
        if(enemyCommand != nullptr)
        {
            enemyCommand->execute(*currentEnemy);
        }

        currentEnemy->Update();
    }
}

void EnemyManager::OnEnemyFireCollision(IEventPtr pEvent)
{
    std::shared_ptr<EnemyFireCollisionEvent> enemyFireCollisionEvent =
            std::static_pointer_cast<EnemyFireCollisionEvent>(pEvent);
    ActorId id = enemyFireCollisionEvent->GetEnemyId();
    Remove(id);
}
