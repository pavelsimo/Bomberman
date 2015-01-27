#include "FireManager.h"
#include "BombExplodedEvent.h"
#include "FireExtinguishedEvent.h"
#include "World.h"
#include "FireFactory.h"

#include <cstdio>

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

    World& world = World::GetInstance();
    TileMap& tileMap = world.GetTileMap();
    Vector2 bombPosition = bombExplosionEvent->GetBombPosition();
    int tileWidth = world.GetTileManager().GetTileWidth();
    int tileHeight = world.GetTileManager().GetTileHeight();

    Fire *fireCenter = FireFactory::GetInstance().CreateFire(bombPosition.x, bombPosition.y);
    Add(fireCenter);

    // FIXME: (Pavel) Replace this magic numbers
    for(int direction = -1; direction <= 1; direction+= 2)
    {
        bool bCanPropagateVertical = true;
        bool bCanPropagateHorizontal = true;
        for(int amplitude = 1; amplitude <= 2; ++amplitude)
        {
            // FIXME: (Pavel) Create a method for both kinds of propagation
            if(bCanPropagateHorizontal)
            {
                int xHorizontal = bombPosition.x + (direction * amplitude) * tileWidth;
                int yHorizontal = bombPosition.y;
                int rowHorizontal = yHorizontal / tileHeight;
                int colHorizontal = xHorizontal / tileWidth;
                BlockType btHorizontal = static_cast<BlockType>(tileMap.GetTile(rowHorizontal, colHorizontal));

                if(btHorizontal == BT_BACKGROUND || btHorizontal == BT_EXPLODABLE)
                {
                    Fire *fireHorizontal = FireFactory::GetInstance().CreateFire(xHorizontal, yHorizontal);
                    Add(fireHorizontal);
                }
                else
                {
                    bCanPropagateHorizontal = false;
                }
            }

            if(bCanPropagateVertical)
            {
                int xVertical = bombPosition.x;
                int yVertical = bombPosition.y + (direction * amplitude) * tileHeight;
                int rowVertical = yVertical / tileHeight;
                int colVertical = xVertical / tileWidth;
                BlockType btVertical = static_cast<BlockType>(tileMap.GetTile(rowVertical, colVertical));
                if(btVertical == BT_BACKGROUND || btVertical == BT_EXPLODABLE)
                {
                    Fire *fireVertical = FireFactory::GetInstance().CreateFire(xVertical, yVertical);
                    Add(fireVertical);
                }
                else
                {
                    bCanPropagateVertical = false;
                }
            }
        }
    }
}

void FireManager::OnFireExtinguished(IEventPtr pEvent)
{
    std::shared_ptr<FireExtinguishedEvent> fireExtinguishedEvent =
            std::static_pointer_cast<FireExtinguishedEvent>(pEvent);

    ActorId id = fireExtinguishedEvent->GetActorId();
    Remove(id);
}
