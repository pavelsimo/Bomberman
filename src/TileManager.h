#ifndef __TILEMANAGER_H_
#define __TILEMANAGER_H_

#include <vector>
#include <cassert>
#include "Drawing.h"
#include "SpriteSheet.h"

const int MAX_ROW = 10;
const int MAX_COL = 10;

class TileManager
{
    public:

        TileManager(
            SpriteSheet* spriteSheet,
            uint32_t tileWidth,
            uint32_t tileHeight,
            uint32_t row,
            uint32_t col
        );

        ~TileManager();

        int map[MAX_ROW][MAX_COL] = {
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 2, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 2, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 2, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 2, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
        };

        void AddTile(const std::string &spriteName);
        void Render();

    private:
        std::vector<std::string> m_tiles;
        SpriteSheet* m_spriteSheet;
        uint32_t m_tileWidth;
        uint32_t m_tileHeight;
        uint32_t m_row;
        uint32_t m_col;
};


#endif //__TILEMANAGER_H_




