#include "BlockManager.h"
#include "../World.h"
#include "../events/FireExtinguishedEvent.h"

BlockManager::BlockManager()
: ActorManager()
{

}

BlockManager::~BlockManager()
{
    // Removing Listener OnFireExtinguished
    EventListener callbackFireExtinguished = fastdelegate::MakeDelegate(this,
            &BlockManager::OnFireExtinguished);

    World::GetInstance().GetEventManager().RemoveListener(callbackFireExtinguished,
            FireExtinguishedEvent::Id_EventType);
}


void BlockManager::Initialize()
{
    // Adding Listener OnFireExtinguished
    EventListener callbackFireExtinguished = fastdelegate::MakeDelegate(this,
            &BlockManager::OnFireExtinguished);

    World::GetInstance().GetEventManager().AddListener(callbackFireExtinguished,
            FireExtinguishedEvent::Id_EventType);
}

bool BlockManager::IsColliding(const Actor &actor, ActorPtr collider)
{
    for(auto it = m_actors.begin(); it != m_actors.end(); ++it)
    {
        Block* currentBlock = dynamic_cast<Block*>(*it);

        if(currentBlock->GetType() == BT_SOLID || currentBlock->GetType() == BT_EXPLODABLE)
        {
            if(actor.IsColliding(*currentBlock))
            {
#ifdef _DEBUG
                std::cout << "ACTOR: " << "(" << actor.GetAABB2().min.x
                        << "," << actor.GetAABB2().min.y << ")"
                        << " " << "(" << actor.GetAABB2().max.x << ","
                        << actor.GetAABB2().max.y << ")" << std::endl;

                std::cout << "BLOCK: " << "(" << currentBlock->GetAABB2().min.x << ","
                        << currentBlock->GetAABB2().min.y << ")" << " " << "("
                        << currentBlock->GetAABB2().max.x << ","
                        << currentBlock->GetAABB2().max.y << ")" << std::endl;
#endif
                *collider = *currentBlock;
                return true;
            }
        }
    }
    return false;
}


void BlockManager::OnFireExtinguished(IEventPtr pEvent)
{
    std::shared_ptr<FireExtinguishedEvent> fireExtinguishedEvent =
            std::static_pointer_cast<FireExtinguishedEvent>(pEvent);

    ActorId id = fireExtinguishedEvent->GetActorId();
    Vector2 firePosition = fireExtinguishedEvent->GetFirePosition();

    for(auto it = m_actors.begin(); it != m_actors.end(); )
    {
        Block* currentBlock = dynamic_cast<Block*>(*it);
        assert(currentBlock != nullptr);

        if(currentBlock->GetType() == BT_EXPLODABLE &&
                currentBlock->GetAABB2().IsInside(firePosition))
        {
            SAFE_DELETE(currentBlock)
            it = m_actors.erase(it);
            int row = firePosition.y / 64;
            int col = firePosition.x / 64;

#ifdef _DEBUG
            std::cout << "DESTROYING BLOCK : " << row << " " << col << std::endl;
#endif
            World::GetInstance().GetTileMap().SetTile(row, col, BT_BACKGROUND);
        }
        else
        {
            ++it;
        }
    }
}