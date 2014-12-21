#ifndef __TILEMAP_H_
#define __TILEMAP_H_

#include <cstdint>
#include <string>

// 1024 x 1024
#define MAX_TILES 1048576

class TileMap
{
    public:
        // ctor & dtor
        //
        TileMap();
        virtual ~TileMap();

        // methods
        //
        bool LoadFromFile(const std::string &filename, uint32_t rows, uint32_t cols);
        bool LoadFromBuffer(uint8_t* buffer, uint32_t rows, uint32_t cols);
        void Clean();

        // getters
        //
        uint8_t* GetTiles();
        uint32_t GetRowsCount() const;
        uint32_t GetColsCount() const;
        uint32_t GetTilesCount() const;

    private:
        uint32_t m_rows;
        uint32_t m_cols;
        uint8_t* m_tiles;
};

#endif //__TILEMAP_H_
