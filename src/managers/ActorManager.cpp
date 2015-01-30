#include "ActorManager.h"

#include <iostream>

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

bool ActorManager::Remove(ActorId id)
{
    for(auto it = m_actors.begin(); it != m_actors.end(); ++it)
    {
        ActorPtr actor = *it;
        if(actor->GetId() == id)
        {
            delete actor;
            m_actors.erase(it);
            return true;
        }
    }
    return false;
}

ActorPtr ActorManager::Get(ActorId id)
{
    for(auto it = m_actors.begin(); it != m_actors.end(); ++it)
    {
        ActorPtr actor = *it;
        if(actor->GetId() == id)
        {
            return actor;
        }
    }
    return nullptr;
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

bool ActorManager::IsColliding(const Actor &actor, ActorPtr collider)
{
    for(auto it = m_actors.begin(); it != m_actors.end(); ++it)
    {
        ActorPtr currentActor = *it;
        if(actor.IsColliding(*currentActor))
        {
            *collider = *currentActor;
            return true;
        }
    }
    return false;
}
