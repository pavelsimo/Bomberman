#include "BombManager.h"
#include "World.h"
#include "EventBombExploded.h"

BombManager::BombManager()
: ActorManager()
{

}

BombManager::~BombManager()
{
    EventListener callback = fastdelegate::MakeDelegate(this,
            &BombManager::EvtHandlerBombExploded);

    World::GetInstance().GetEventManager().RemoveListener(callback,
            EventBombExploded::Id_EventType);
}


void BombManager::Initialize()
{
    EventListener callback = fastdelegate::MakeDelegate(this,
            &BombManager::EvtHandlerBombExploded);

    World::GetInstance().GetEventManager().AddListener(callback,
            EventBombExploded::Id_EventType);
}

void BombManager::EvtHandlerBombExploded(IEventPtr pEvent)
{

}
