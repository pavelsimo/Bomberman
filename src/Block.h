#ifndef __BLOCK_H_
#define __BLOCK_H_

#include "Actor.h"

enum BlockType
{
    BT_BACKGROUND = 0,
    BT_SOLID      = 1,
    BT_EXPLODABLE = 2,
    BT_PORTAL     = 3
};

class Block : public Actor
{
    public:
        // ctor & dtor
        //
        Block();
        Block(float x, float y, BlockType type = BT_BACKGROUND);
        ~Block();

        void Initialize();

        void SetType(BlockType type);
        BlockType GetType() const;

    private:
        BlockType m_type;

        // helpers
        //
        void InitializeGeometry();
};

#endif //__BLOCK_H_
