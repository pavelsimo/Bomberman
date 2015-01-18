#include "ActorManager.h"

ActorManager::ActorManager()
{

}

ActorManager::~ActorManager()
{
    for(auto it = m_actors.begin(); it != m_actors.end(); ++it)
    {
        ActorPtr actor = *it;
        if(actor != nullptr)
        {
            delete actor;
        }
    }
    m_actors.clear();
}

void ActorManager::Add(const ActorPtr actor)
{
    m_actors.push_back(actor);
}

void ActorManager::Remove(ActorPtr actor)
{

}

void ActorManager::Update(World &world)
{
    for(auto it = m_actors.begin(); it != m_actors.end(); ++it)
    {
        ActorPtr actor = *it;
        actor->Update(world);
    }
}

void ActorManager::Render()
{
    for(auto it = m_actors.begin(); it != m_actors.end(); ++it)
    {
        ActorPtr actor = *it;
        actor->Render();
    }
}

bool ActorManager::IsColliding(const Actor &actor, ActorPtr collisionActor)
{
    for(auto it = m_actors.begin(); it != m_actors.end(); ++it)
    {
        ActorPtr currentActor = *it;
        if(actor.IsColliding(*currentActor))
        {
            *collisionActor = *currentActor;
            return true;
        }
    }
    return false;
}

