#include "FireManager.h"
#include "BombExplodedEvent.h"
#include "FireExtinguishedEvent.h"
#include "World.h"

FireManager::FireManager()
: ActorManager()
{

}

FireManager::~FireManager()
{
    // Removing Listener OnBombExploded
    EventListener callbackBombExploded = fastdelegate::MakeDelegate(this,
            &FireManager::OnBombExploded);

    World::GetInstance().GetEventManager().RemoveListener(callbackBombExploded,
            BombExplodedEvent::Id_EventType);

    // Removing Listener OnFireExtinguished
    EventListener callbackFireExtinguished = fastdelegate::MakeDelegate(this,
            &FireManager::OnFireExtinguished);

    World::GetInstance().GetEventManager().RemoveListener(callbackFireExtinguished,
            FireExtinguishedEvent::Id_EventType);
}

void FireManager::Initialize()
{
    // Adding Listener OnBombExploded
    EventListener callbackBombExploded = fastdelegate::MakeDelegate(this,
            &FireManager::OnBombExploded);

    World::GetInstance().GetEventManager().AddListener(callbackBombExploded,
            BombExplodedEvent::Id_EventType);

    // Adding Listener OnFireExtinguished
    EventListener callbackFireExtinguished = fastdelegate::MakeDelegate(this,
            &FireManager::OnFireExtinguished);

    World::GetInstance().GetEventManager().AddListener(callbackFireExtinguished,
            FireExtinguishedEvent::Id_EventType);
}

void FireManager::OnBombExploded(IEventPtr pEvent)
{
    std::shared_ptr<BombExplodedEvent> bombExplosionEvent =
            std::static_pointer_cast<BombExplodedEvent>(pEvent);

    ActorId id = bombExplosionEvent->GetActorId();
    Vector2 position = bombExplosionEvent->GetBombPosition();
    SpriteSheet& spriteSheet = World::GetInstance().GetSpriteSheet();

    // FIXME: (Pavel) Use a FireFactory

    Fire *fire = new Fire(position.x, position.y);
    fire->SetSpriteSheet(&spriteSheet);
    fire->Initialize();
    fire->Update(World::GetInstance());
    Add(fire);

    // Fire
    // FIXME: (Pavel) Replace this magic numbers: -2, 2
    for(int dis = -2; dis <= 2; ++dis)
    {
        // TODO: (Pavel) Check for BT_SOLID Blocks. Not fire should be created
        // TODO: (Pavel) Check for BT_EXPLODABLE Blocks. Fire should be created, and trigger OnBlockExplosion().

        if(dis == 0)
        {
            continue;
        }

        // FIXME: (Pavel) Replace this magic number: 64
        Fire *fire1 = new Fire(position.x + dis * 64, position.y);
        fire1->SetSpriteSheet(&spriteSheet);
        fire1->Initialize();
        fire1->Update(World::GetInstance());
        Add(fire1);

        // FIXME: (Pavel) Replace this magic numbers: 64
        Fire *fire2 = new Fire(position.x, position.y + dis * 64);
        fire2->SetSpriteSheet(&spriteSheet);
        fire2->Initialize();
        fire2->Update(World::GetInstance());
        Add(fire2);
    }
}

void FireManager::OnFireExtinguished(IEventPtr pEvent)
{
    std::shared_ptr<FireExtinguishedEvent> fireExtinguishedEvent =
            std::static_pointer_cast<FireExtinguishedEvent>(pEvent);

    ActorId id = fireExtinguishedEvent->GetActorId();
    Remove(id);
}
