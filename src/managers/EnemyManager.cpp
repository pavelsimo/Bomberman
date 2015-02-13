#include "EnemyManager.h"
#include "../Enemy.h"

EnemyManager::EnemyManager()
{

}

EnemyManager::~EnemyManager()
{

}

void EnemyManager::Initialize()
{

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
