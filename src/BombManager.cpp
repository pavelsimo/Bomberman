#include "BombManager.h"
#include "World.h"


BombManager::BombManager()
{

}

BombManager::~BombManager()
{

}

void BombManager::Add(const ActorPtr actor)
{
    ActorManager::Add(actor);
}

void BombManager::Remove(ActorPtr actor)
{
    ActorManager::Remove(actor);
}

void BombManager::Update(World &world)
{
    ActorManager::Update(world);
}

void BombManager::Render()
{
    ActorManager::Render();
}

bool BombManager::IsColliding(const Actor &actor, ActorPtr collisionActor)
{
    return ActorManager::IsColliding(actor, collisionActor);
}
