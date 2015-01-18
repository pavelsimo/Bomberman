#ifndef __WORLD_H_
#define __WORLD_H_

#include "utility/SpriteSheet.h"
#include "utility/TileManager.h"
#include "utility/TileMap.h"
#include "Block.h"
#include "BombManager.h"
#include "BlockManager.h"
#include "FireManager.h"
#include "Player.h"
#include "Bomb.h"
#include "Fire.h"

#define SAFE_DELETE(p) { if(p != nullptr) { delete(p); (p)=nullptr; } }

class World
{
    public:
        World(uint32_t width, uint32_t height);
        ~World();

        void OnSetup();
        void OnKeyDown(unsigned char key);
        void OnKeyUp(unsigned char key);
        void OnMouseMove(int x, int y);
        void OnMouseClick(int button, int state, int x, int y);
        void OnUpdate();
        void OnRender();
        void OnDestroy();

        float GetWidth() const;
        float GetHeight() const;
        float GetLeft() const;
        float GetRight() const;
        float GetBottom() const;
        float GetTop() const;

        BlockManager* GetBlockManager();
        BombManager* GetBombManager();

    private:
        // non-copyable
        World(const World& rhs);
        World& operator=(const World& rhs);

        uint32_t m_width;
        uint32_t  m_height;
        Player* m_player;
        SpriteSheet* m_spriteSheet;
        TileMap* m_tileMap;
        TileManager* m_tileManager;
        BlockManager* m_blockManager;
        BombManager* m_bombManager;
        FireManager* m_fireManager;
        // TODO: (Pavel) this is going to be a manager, just for testing
        Bomb* m_bomb;
        Fire* m_fire;
};

#endif //__WORLD_H_
