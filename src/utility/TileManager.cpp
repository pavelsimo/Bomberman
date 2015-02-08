#include <iostream>
#include <fstream>
#include "TileManager.h"

TileManager::TileManager(SpriteSheetPtr spriteSheet, uint32_t tileWidth, uint32_t tileHeight
) : m_spriteSheet(spriteSheet),
    m_tileMap(nullptr),
    m_tileWidth(tileWidth),
    m_tileHeight(tileHeight)
{
#ifdef _DEBUG
    std::cout << "Creating the TileManager " <<  std::endl;
#endif
}

TileManager::~TileManager()
{
    m_sprites.clear();
#ifdef _DEBUG
    std::cout << "Destroying the TileManager " <<  std::endl;
#endif
}

void TileManager::AddSprite(const std::string &spriteName)
{
    m_sprites.push_back(spriteName);
}

void TileManager::Render()
{
    if(m_tileMap == nullptr)
    {
        std::cerr << "ERROR: Unassigned TileMap. Try to set the TileMap before call the Render() function." << '\n';
        return;
    }

    if(m_tileMap->IsEmpty())
    {
        std::cerr << "ERROR: Empty TileMap." << '\n';
        return;
    }

    int n = static_cast<int>(m_tileMap->GetRowsCount());
    int m = static_cast<int>(m_tileMap->GetColsCount());
    uint8_t* tiles = m_tileMap->GetTiles();

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            uint8_t curTile = tiles[i * m + j];
            assert(curTile < m_sprites.size());

            Sprite sprite = m_spriteSheet->GetSprite(m_sprites[curTile]);
            Rect rect(sprite.x, sprite.y, sprite.w, sprite.h);

            DrawTexture(
                j * m_tileWidth,
                i * m_tileHeight,
                m_spriteSheet->GetTexId(),
                m_spriteSheet->GetImgWidth(),
                m_spriteSheet->GetImgHeight(),
                m_spriteSheet->GetTexWidth(),
                m_spriteSheet->GetTexHeight(),
                &rect
            );
        }
    }
}

void TileManager::SetTileMap(TileMapPtr tileMap)
{
    m_tileMap = tileMap;
}

TileMapPtr TileManager::GetTileMap()
{
    return m_tileMap;
}


uint32_t TileManager::GetTileWidth() const
{
    return m_tileWidth;
}

uint32_t TileManager::GetTileHeight() const
{
    return m_tileHeight;
}
