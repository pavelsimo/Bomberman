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
        if(actor != nullptr)
        {
            if(actor->GetId() == id)
            {
                delete actor;
                m_actors.erase(it);
                return true;
            }
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

void ActorManager::Update()
{
    for(auto it = m_actors.begin(); it != m_actors.end(); ++it)
    {
        ActorPtr actor = *it;
        actor->Update();
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
        if(currentActor != nullptr)
        {
            if(actor.IsColliding(*currentActor))
            {
                *collider = *currentActor;
                return true;
            }
        }
    }
    return false;
}

bool ActorManager::IsColliding(const AABB2& box, ActorPtr collider)
{
    for(auto it = m_actors.begin(); it != m_actors.end(); ++it)
    {
        ActorPtr currentActor = *it;
        if(currentActor != nullptr)
        {
            AABB2 currentActorAABB = currentActor->GetAABB2();
            if(currentActorAABB.Intersects(box))
            {
                *collider = *currentActor;
                return true;
            }
        }
    }
    return false;
}
