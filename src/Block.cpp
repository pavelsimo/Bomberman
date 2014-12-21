#include "Block.h"

const uint32_t BLOCK_WIDTH = 64;
const uint32_t BLOCK_HEIGHT = 64;

Block::Block()
: m_type(BT_BACKGROUND)
{
    InitializeGeometry();
}


Block::Block(float x, float y, BlockType type)
: Actor(x, y),
  m_type(type)
{
    InitializeGeometry();
}

Block::~Block()
{

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
