#include "BombManager.h"
#include "../World.h"
#include "../events/BombExplodedEvent.h"
#include <iostream>
#include <memory>

BombManager::BombManager()
: ActorManager()
{

}

BombManager::~BombManager()
{
    // Removing Listener OnBombExploded
    EVENT_MGR_REMOVE_LISTENER(callbackBombExploded, &BombManager::OnBombExploded,
            BombExplodedEvent::Id_EventType)
}

void BombManager::Initialize()
{
    // Adding Listener OnBombExploded
    EVENT_MGR_ADD_LISTENER(callbackBombExploded, &BombManager::OnBombExploded,
            BombExplodedEvent::Id_EventType)
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
