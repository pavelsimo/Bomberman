#ifndef __TILEMANAGER_H_
#define __TILEMANAGER_H_

#include <vector>
#include <cassert>
#include "Drawing.h"
#include "SpriteSheet.h"

typedef std::vector<std::vector<uint32_t> > TileMap;

class TileManager
{
    public:

        TileManager(
            SpriteSheet* spriteSheet,
            uint32_t tileWidth,
            uint32_t tileHeight
        );

        ~TileManager();

        void AddTile(const std::string &spriteName);
        bool LoadTileMapFromFile(const std::string filename);
        void Render();

    private:
        std::vector<std::string> m_tiles;
        SpriteSheet* m_spriteSheet;
        TileMap m_tileMap;
        uint32_t m_tileWidth;
        uint32_t m_tileHeight;
};

#endif //__TILEMANAGER_H_




