#include "BombManager.h"


BombManager::BombManager()
{

}

BombManager::~BombManager()
{
    for(auto it = m_bombs.begin(); it != m_bombs.end(); ++it)
    {
        ActorPtr actor = *it;
        if(actor != nullptr)
        {
            delete actor;
        }
    }
    m_bombs.clear();
}

void BombManager::Add(const ActorPtr actor)
{
    m_bombs.push_back(actor);
}

void BombManager::Remove(const ActorPtr actor)
{
    // TODO: (Pavel) IMPLEMENT ME!
}

void BombManager::Update(World &world)
{
    for(auto it = m_bombs.begin(); it != m_bombs.end(); ++it)
    {
        ActorPtr actor = *it;
        actor->Update(world);
    }
}

void BombManager::Render()
{
    for(auto it = m_bombs.begin(); it != m_bombs.end(); ++it)
    {
        ActorPtr actor = *it;
        actor->Render();
    }
}

bool BombManager::IsColliding(const Actor &actor, ActorPtr collisionActor)
{
    for(auto it = m_bombs.begin(); it != m_bombs.end(); ++it)
    {
        ActorPtr currentBomb = *it;
        if(actor.IsColliding(*currentBomb))
        {
            *collisionActor = *currentBomb;
            return true;
        }
    }
    return false;
}