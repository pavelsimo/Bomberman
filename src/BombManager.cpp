#include "BombManager.h"
#include "World.h"
#include "BombExplodedEvent.h"
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
            BombExplodedEvent::Id_EventType);
}

void BombManager::Initialize()
{
    EventListener callback = fastdelegate::MakeDelegate(this,
            &BombManager::OnBombExploded);

    World::GetInstance().GetEventManager().AddListener(callback,
            BombExplodedEvent::Id_EventType);
}

void BombManager::OnBombExploded(IEventPtr pEvent)
{
    std::shared_ptr<BombExplodedEvent> bombExplosionEvent =
            std::static_pointer_cast<BombExplodedEvent>(pEvent);

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
