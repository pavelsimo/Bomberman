#include "BlockManager.h"

#include <iostream>

BlockManager::BlockManager()
{

}

BlockManager::~BlockManager()
{
    Clean();
}

void BlockManager::AddBlock(Block* block)
{
    m_blocks.push_back(block);
}

void BlockManager::Clean()
{
    for(auto it = m_blocks.begin(); it != m_blocks.end(); ++it)
    {
        if(*it == nullptr)
        {
            delete *it;
        }
    }
    m_blocks.clear();
}

bool BlockManager::IsColliding(const Actor& actor)
{
    for(auto it = m_blocks.begin(); it != m_blocks.end(); ++it)
    {
        Block* block = *it;

        if(block->GetType() == BT_SOLID || block->GetType() == BT_EXPLODABLE)
        {
            if(block->IsColliding(actor))
            {
                #ifdef _DEBUG
                    std::cout << "ACTOR: " << "(" << actor.GetAABB2().min.x << "," << actor.GetAABB2().min.y << ")" << " " << "(" << actor.GetAABB2().max.x << "," << actor.GetAABB2().max.y << ")" << std::endl;
                    std::cout << "BLOCK: " << "(" << block->GetAABB2().min.x << "," << block->GetAABB2().min.y << ")" << " " << "(" << block->GetAABB2().max.x << "," << block->GetAABB2().max.y << ")" << std::endl;
                #endif
                return true;
            }
        }
    }
    return false;
}
