#include <iostream>
#include <fstream>
#include "TileManager.h"

TileManager::TileManager(SpriteSheet *spriteSheet, uint32_t tileWidth, uint32_t tileHeight
) : m_spriteSheet(spriteSheet),
    m_tileMap(nullptr),
    m_tileWidth(tileWidth),
    m_tileHeight(tileHeight)
{

}

TileManager::~TileManager()
{
    m_sprites.clear();
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

    uint32_t m = m_tileMap->GetColsCount();
    uint32_t n = m_tileMap->GetRowsCount();
    uint8_t* tiles = m_tileMap->GetTiles();

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            uint8_t curTile = tiles[i * n + j];
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

void TileManager::SetTileMap(TileMap *tileMap)
{
    m_tileMap = tileMap;
}

TileMap* TileManager::GetTileMap()
{
    return m_tileMap;
}
