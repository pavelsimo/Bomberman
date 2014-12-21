#include <cassert>
#include <fstream>
#include <cstdint>

#include "TileMap.h"

TileMap::TileMap()
: m_tiles(nullptr)
{

}

TileMap::~TileMap()
{
    Clean();
}

bool TileMap::LoadFromFile(const std::string &filename, uint32_t rows, uint32_t cols)
{
    //
    // if allocated, clean the previous tile map
    //
    Clean();

    //
    // check invariants
    //
    assert(m_tiles == nullptr);
    assert(rows * cols <= MAX_TILES);

    //
    // allocating tiles memory
    //
    m_tiles = new uint8_t[rows * cols + 2];

    //
    // assign the rows and cols
    //
    m_rows = rows;
    m_cols = cols;

    //
    // reading the file and filling the buffer
    //
    std::ifstream in(filename);
    std::string line = "";
    int index = 0;

    for(int row = 0; std::getline(in, line); ++row)
    {
        for(int col = 0; col < line.size(); ++col)
        {
            m_tiles[index] = line[col] - '0';
            index++;
        }
    }

    return true;
}

bool TileMap::LoadFromBuffer(uint8_t* buffer, uint32_t rows, uint32_t cols)
{
    return false;
}

void TileMap::Clean()
{
    if(m_tiles != nullptr)
    {
        delete[] m_tiles;
        m_tiles = nullptr;
    }
}

uint8_t* TileMap::GetTiles()
{
    return m_tiles;
}

uint32_t TileMap::GetRowsCount() const
{
    return m_rows;
}

uint32_t TileMap::GetColsCount() const
{
    return m_cols;
}

uint32_t TileMap::GetTilesCount() const
{
    return m_rows * m_cols;
}
