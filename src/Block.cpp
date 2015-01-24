#include "Block.h"

#include <iostream>

namespace
{
    const uint32_t BLOCK_WIDTH = 64;
    const uint32_t BLOCK_HEIGHT = 64;
}

Block::Block()
: Actor(),
  m_type(BT_BACKGROUND)
{

}

void Block::Initialize()
{
    InitializeGeometry();
}


Block::Block(float x, float y, BlockType type)
: Actor(x, y),
  m_type(type)
{

}

Block::~Block()
{
    #ifdef _DEBUG
        std::cout << "DESTROY BLOCK: " << GetId() << '\n';
    #endif
}

void Block::SetType(BlockType type)
{
    m_type = type;
}

BlockType Block::GetType() const
{
    return m_type;
}

void Block::InitializeGeometry()
{
    // upper-left corner
    m_geometry.push_back(Vector2(BLOCK_WIDTH * -0.5f, BLOCK_HEIGHT * -0.5f));
    // bottom-right corner
    m_geometry.push_back(Vector2(BLOCK_WIDTH * 0.5f, BLOCK_HEIGHT * 0.5f));
}

