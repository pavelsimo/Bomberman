#ifndef __TILEMANAGER_H_
#define __TILEMANAGER_H_

#include <vector>
#include <cassert>

#include "Drawing.h"
#include "SpriteSheet.h"

typedef std::vector<std::vector<uint32_t> > TileMap;
typedef std::vector<std::string> TileList;

class TileManager
{
    public:

        // ctor & dtor
        //
        TileManager(SpriteSheet* spriteSheet, uint32_t tileWidth, uint32_t tileHeight);
        ~TileManager();

        // methods
        //
        void AddTile(const std::string &spriteName);
        bool LoadTileMapFromFile(const std::string &filename);
        void Render();

    private:
        TileList m_tiles;
        TileMap m_tileMap;
        SpriteSheet* m_spriteSheet;
        uint32_t m_tileWidth;
        uint32_t m_tileHeight;
};

#endif //__TILEMANAGER_H_




