#include <iostream>
#include <cassert>
#include <fstream>
#include <cstdint>


#include "TileMap.h"

TileMap::TileMap()
: m_tiles(nullptr),
  m_rows(0),
  m_cols(0)
{

}

TileMap::~TileMap()
{
    Clean();
}

bool TileMap::LoadFromFile(const std::string &filename, uint32_t rows, uint32_t cols)
{
    Clean();

    assert(m_tiles == nullptr);

    if(rows * cols >= MAX_TILES)
    {
        std::cerr << "ERROR: The tile number exceed the maximum allowed." << '\n';
        return false;
    }

    m_tiles = new uint8_t[rows * cols + 2];
    m_rows = rows;
    m_cols = cols;

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

bool TileMap::LoadFromBuffer(uint8_t* tiles, uint32_t rows, uint32_t cols)
{
    Clean();

    assert(m_tiles == nullptr);

    if(rows * cols >= MAX_TILES)
    {
        std::cerr << "ERROR: The tile number exceed the maximum allowed." << '\n';
        return false;
    }

    m_tiles = tiles;
    m_rows = rows;
    m_cols = cols;

    return true;
}

void TileMap::Clean()
{
    if(m_tiles != nullptr)
    {
        delete[] m_tiles;
        m_tiles = nullptr;
    }
}

bool TileMap::IsEmpty() const
{
    return m_rows == 0 && m_cols == 0;
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

uint8_t TileMap::GetTile(uint32_t row, uint32_t col)
{
    assert(row < m_rows && col < m_cols);
    return m_tiles[row * m_cols + col];
}

void TileMap::SetTile(uint32_t row, uint32_t col, uint8_t tile)
{
    assert(row < m_rows && col < m_cols);
    m_tiles[row * m_cols + col] = tile;
}


