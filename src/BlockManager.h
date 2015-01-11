#ifndef __BLOCKMANAGER_H_
#define __BLOCKMANAGER_H_

#include <list>

#include "Block.h"

typedef std::list<Block*> BlockList;

class BlockManager
{
    public:
        BlockManager();
        ~BlockManager();

        void Clean();
        void AddBlock(Block* block);
        void RemoveBlock(Block* block);
        bool IsColliding(const Actor& actor, Block& block);

    private:
        BlockList m_blocks;
};


#endif //__BLOCKMANAGER_H_
