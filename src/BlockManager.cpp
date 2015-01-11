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

void BlockManager::RemoveBlock(Block *block)
{
    // IMPLEMENT ME!
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

bool BlockManager::IsColliding(const Actor& actor, Block& block)
{
    for(auto it = m_blocks.begin(); it != m_blocks.end(); ++it)
    {
        Block* curBlock = *it;

        if(curBlock->GetType() == BT_SOLID || curBlock->GetType() == BT_EXPLODABLE)
        {
            if(curBlock->IsColliding(actor))
            {

#ifdef _DEBUG
                std::cout << "ACTOR: " << "(" << actor.GetAABB2().min.x
                        << "," << actor.GetAABB2().min.y << ")"
                        << " " << "(" << actor.GetAABB2().max.x << ","
                        << actor.GetAABB2().max.y << ")" << std::endl;

                std::cout << "BLOCK: " << "(" << curBlock->GetAABB2().min.x << ","
                        << curBlock->GetAABB2().min.y << ")" << " " << "("
                        << curBlock->GetAABB2().max.x << ","
                        << curBlock->GetAABB2().max.y << ")" << std::endl;
#endif
                block = *curBlock;
                return true;
            }
        }
    }
    return false;
}
