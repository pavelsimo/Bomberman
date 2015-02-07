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
        TileManager(SpriteSheetPtr spriteSheet, uint32_t tileWidth, uint32_t tileHeight);
        ~TileManager();

        // methods
        //
        void AddSprite(const std::string &spriteName);
        void Render();

        // getters & setters
        //
        void SetTileMap(TileMapPtr tileMap);
        TileMapPtr GetTileMap();
        uint32_t GetTileWidth() const;
        uint32_t GetTileHeight() const;

    private:
        SpriteSheetPtr m_spriteSheet;
        SpriteList m_sprites;
        TileMapPtr m_tileMap;
        uint32_t m_tileWidth;
        uint32_t m_tileHeight;
};

typedef std::shared_ptr<TileManager> TileManagerPtr;

#endif //__TILEMANAGER_H_




