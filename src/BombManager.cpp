#include "BombManager.h"
#include "World.h"
#include "EventBombExploded.h"
#include <iostream>
#include <memory>

BombManager::BombManager()
: ActorManager()
{

}

BombManager::~BombManager()
{
    EventListener callback = fastdelegate::MakeDelegate(this,
            &BombManager::OnBombExploded);

    World::GetInstance().GetEventManager().RemoveListener(callback,
            EventBombExploded::Id_EventType);
}

void BombManager::Initialize()
{
    EventListener callback = fastdelegate::MakeDelegate(this,
            &BombManager::OnBombExploded);

    World::GetInstance().GetEventManager().AddListener(callback,
            EventBombExploded::Id_EventType);
}

void BombManager::OnBombExploded(IEventPtr pEvent)
{
    std::shared_ptr<EventBombExploded> bombExplosionEvent = std::static_pointer_cast<EventBombExploded>(pEvent);

    #ifdef _DEBUG
        std::cout << "BOOOM!!! " << bombExplosionEvent->GetName() << " " <<
                  bombExplosionEvent->GetEventType() << " (" <<
                  bombExplosionEvent->GetBombPosition().x << "," <<
                  bombExplosionEvent->GetBombPosition().y << ") " <<
                  bombExplosionEvent->GetActorId() << std::endl;
    #endif

    ActorId id = bombExplosionEvent->GetActorId();
    Vector2 position = bombExplosionEvent->GetBombPosition();
    Remove(id);
}
