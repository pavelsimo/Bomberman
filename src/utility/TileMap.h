#ifndef __TILEMAP_H_
#define __TILEMAP_H_

#include <cstdint>
#include <string>
#include <memory>

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
        bool LoadFromBuffer(uint8_t* tiles, uint32_t rows, uint32_t cols);
        void Clean();
        bool IsEmpty() const;

        // getters & setters
        //
        uint8_t GetTile(uint32_t row, uint32_t col);
        void SetTile(uint32_t row, uint32_t col, uint8_t tile);

        //FIXME: (Pavel) This breaks encapsulation, change to const
        uint8_t* GetTiles();
        uint32_t GetRowsCount() const;
        uint32_t GetColsCount() const;
        uint32_t GetTilesCount() const;

    private:
        // non-copyable
        TileMap(const TileMap& rhs);
        TileMap& operator=(const TileMap& rhs);

        uint32_t m_rows;
        uint32_t m_cols;
        uint8_t* m_tiles;
};

typedef std::shared_ptr<TileMap> TileMapPtr;

#endif //__TILEMAP_H_

