#include "BlockManager.h"
#include "World.h"

BlockManager::BlockManager()
: ActorManager()
{

}

BlockManager::~BlockManager()
{

}

void BlockManager::Add(const ActorPtr actor)
{
    ActorManager::Add(actor);
}

void BlockManager::Remove(ActorPtr actor)
{
    ActorManager::Remove(actor);
}

void BlockManager::Update(World &world)
{
    //ActorManager::Update(world);
}

void BlockManager::Render()
{
    //ActorManager::Render();
}

bool BlockManager::IsColliding(const Actor &actor, ActorPtr collisionActor)
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
                *collisionActor = *currentBlock;
                return true;
            }
        }
    }
    return false;
}
