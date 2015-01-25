#include "FireManager.h"
#include "EventBombExploded.h"
#include "EventFireExtinguished.h"
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
            EventBombExploded::Id_EventType);

    // Removing Listener OnFireExtinguished
    EventListener callbackFireExtinguished = fastdelegate::MakeDelegate(this,
            &FireManager::OnFireExtinguished);

    World::GetInstance().GetEventManager().RemoveListener(callbackFireExtinguished,
            EventFireExtinguished::Id_EventType);
}

void FireManager::Initialize()
{
    // Adding Listener OnBombExploded
    EventListener callbackBombExploded = fastdelegate::MakeDelegate(this,
            &FireManager::OnBombExploded);

    World::GetInstance().GetEventManager().AddListener(callbackBombExploded,
            EventBombExploded::Id_EventType);

    // Adding Listener OnFireExtinguished
    EventListener callbackFireExtinguished = fastdelegate::MakeDelegate(this,
            &FireManager::OnFireExtinguished);

    World::GetInstance().GetEventManager().AddListener(callbackFireExtinguished,
            EventFireExtinguished::Id_EventType);
}

void FireManager::OnBombExploded(IEventPtr pEvent)
{
    std::shared_ptr<EventBombExploded> bombExplosionEvent =
            std::static_pointer_cast<EventBombExploded>(pEvent);

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
    for(int dis = -2; dis <= 2; ++dis)
    {
        if(dis == 0) continue;

        // FIXME: (Pavel) Replace this magic numbers
        Fire *fire1 = new Fire(position.x + dis * 64, position.y);
        fire1->SetSpriteSheet(&spriteSheet);
        fire1->Initialize();
        fire1->Update(World::GetInstance());
        Add(fire1);

        // FIXME: (Pavel) Replace this magic numbers
        Fire *fire2 = new Fire(position.x, position.y + dis * 64);
        fire2->SetSpriteSheet(&spriteSheet);
        fire2->Initialize();
        fire2->Update(World::GetInstance());
        Add(fire2);
    }
}

void FireManager::OnFireExtinguished(IEventPtr pEvent)
{
    std::shared_ptr<EventFireExtinguished> fireExtinguishedEvent =
            std::static_pointer_cast<EventFireExtinguished>(pEvent);

    ActorId id = fireExtinguishedEvent->GetActorId();
    Remove(id);
}
