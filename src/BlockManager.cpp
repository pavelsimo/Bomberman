#include "BlockManager.h"
#include "World.h"
#include "Actor.h"
#include <iostream>

BlockManager::BlockManager()
{

}

BlockManager::~BlockManager()
{
    for(auto it = m_blocks.begin(); it != m_blocks.end(); ++it)
    {
        ActorPtr actor = *it;
        if(actor != nullptr)
        {
            delete actor;
        }
    }
    m_blocks.clear();
}

void BlockManager::Add(const ActorPtr actor)
{
    m_blocks.push_back(actor);
}

void BlockManager::Remove(ActorPtr actor)
{
    // TODO: (Pavel) IMPLEMENT ME!
}

void BlockManager::Update(World &world)
{
    for(auto it = m_blocks.begin(); it != m_blocks.end(); ++it)
    {
        ActorPtr actor = *it;
        actor->Update(world);
    }
}

void BlockManager::Render()
{
    for(auto it = m_blocks.begin(); it != m_blocks.end(); ++it)
    {
        ActorPtr actor = *it;
        actor->Render();
    }
}

bool BlockManager::IsColliding(const Actor &actor, ActorPtr collisionActor)
{
    for(auto it = m_blocks.begin(); it != m_blocks.end(); ++it)
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
