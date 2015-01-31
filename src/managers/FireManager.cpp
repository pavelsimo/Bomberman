#include "FireManager.h"
#include "../World.h"
#include "../events/BombExplodedEvent.h"
#include "../events/FireExtinguishedEvent.h"
#include "../factories/FireFactory.h"

FireManager::FireManager()
: ActorManager()
{

}

FireManager::~FireManager()
{
    // Removing Listener OnBombExploded
    EVENT_MGR_REMOVE_LISTENER(callbackBombExploded, &FireManager::OnBombExploded,
            BombExplodedEvent::Id_EventType)
    // Removing Listener OnFireExtinguished
    EVENT_MGR_REMOVE_LISTENER(callbackFireExtinguished, &FireManager::OnFireExtinguished,
            FireExtinguishedEvent::Id_EventType)
}

void FireManager::Initialize()
{
    // Adding Listener OnBombExploded
    EVENT_MGR_ADD_LISTENER(callbackBombExploded, &FireManager::OnBombExploded,
            BombExplodedEvent::Id_EventType)
    // Adding Listener OnFireExtinguished
    EVENT_MGR_ADD_LISTENER(callbackFireExtinguished, &FireManager::OnFireExtinguished,
            FireExtinguishedEvent::Id_EventType)
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

                    if(btHorizontal == BT_EXPLODABLE)
                    {
                        bCanPropagateHorizontal = false;
                    }
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

                    if(btVertical == BT_EXPLODABLE)
                    {
                        bCanPropagateVertical = false;
                    }
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
