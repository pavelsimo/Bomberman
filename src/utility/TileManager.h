#ifndef __TILEMANAGER_H_
#define __TILEMANAGER_H_

#include <vector>
#include <cassert>

#include "TileMap.h"
#include "Drawing.h"
#include "SpriteSheet.h"

typedef std::vector<std::string> SpriteList;

class TileManager
{
    public:

        // ctor & dtor
        //
        TileManager(SpriteSheet* spriteSheet, uint32_t tileWidth, uint32_t tileHeight);
        ~TileManager();

        // methods
        //
        void AddSprite(const std::string &spriteName);
        void SetTileMap(TileMap *tileMap);
        TileMap* GetTileMap();
        void Render();

    private:
        SpriteSheet* m_spriteSheet;
        SpriteList m_sprites;
        TileMap* m_tileMap;
        uint32_t m_tileWidth;
        uint32_t m_tileHeight;
};

#endif //__TILEMANAGER_H_




