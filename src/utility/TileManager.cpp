#include <fstream>

#include "TileManager.h"

TileManager::TileManager(SpriteSheet *spriteSheet, uint32_t tileWidth, uint32_t tileHeight
) : m_spriteSheet(spriteSheet),
    m_tileWidth(tileWidth),
    m_tileHeight(tileHeight)
{

}

TileManager::~TileManager()
{
    m_tiles.clear();
    m_tileMap.clear();
}

void TileManager::AddTile(const std::string& spriteName)
{
    m_tiles.push_back(spriteName);
}


bool TileManager::LoadTileMapFromFile(const std::string& filename)
{
    std::ifstream in(filename);
    std::string line = "";
    while(std::getline(in, line))
    {
        m_tileMap.push_back(std::vector<uint32_t>());
        int last = m_tileMap.size() - 1;
        for(int i = 0; i < line.size(); ++i)
        {
            m_tileMap[last].push_back(line[i] - '0');
        }
    }
    return true;
}

void TileManager::Render()
{
    assert(!m_tileMap.empty());

    uint32_t m = m_tileMap[0].size();
    uint32_t n = m_tileMap.size();

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            assert(m_tileMap[j][i] < m_tiles.size());

            Sprite sprite = m_spriteSheet->GetSprite(m_tiles[m_tileMap[j][i]]);
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

