#include "FireManager.h"


FireManager::FireManager()
: ActorManager()
{

}

FireManager::~FireManager()
{

}

void FireManager::Add(const ActorPtr actor)
{
    ActorManager::Add(actor);
}

void FireManager::Remove(ActorPtr actor)
{
    ActorManager::Remove(actor);
}

void FireManager::Update(World &world)
{
    ActorManager::Update(world);
}

void FireManager::Render()
{
    ActorManager::Render();
}

bool FireManager::IsColliding(const Actor &actor, ActorPtr collisionActor)
{
    return ActorManager::IsColliding(actor, collisionActor);
}
