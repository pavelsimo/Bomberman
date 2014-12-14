#include "TileManager.h"

TileManager::TileManager(SpriteSheet *spriteSheet, uint32_t tileWidth,
    uint32_t tileHeight, uint32_t row, uint32_t col
) : m_spriteSheet(spriteSheet),
    m_tileWidth(tileWidth),
    m_tileHeight(tileHeight),
    m_row(row),
    m_col(col)
{

}


TileManager::~TileManager()
{

}

void TileManager::AddTile(const std::string &spriteName)
{
    m_tiles.push_back(spriteName);
}

void TileManager::Render()
{
    for(int i = 0; i < m_row; i++)
    {
        for(int j = 0; j < m_col; j++)
        {
            assert(map[i][j] < m_tiles.size());

            Sprite sprite = m_spriteSheet->GetSprite(m_tiles[map[j][i]]);
            Rect rect(sprite.x, sprite.y, sprite.w, sprite.h);

            DrawTexture(
                i * m_tileWidth,
                j * m_tileHeight,
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

