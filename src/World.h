#ifndef __WORLD_H_
#define __WORLD_H_

#include "utility/SpriteSheet.h"
#include "utility/TileManager.h"
#include "utility/TileMap.h"
#include "Block.h"
#include "BlockManager.h"
#include "Player.h"

#define SAFE_DELETE(p) { if(p != nullptr) { delete(p); (p)=nullptr; } }

class World
{
    public:
        World(float width, float height);
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

    private:
        TileMap* m_tileMap;
        TileManager* m_tileManager;
        SpriteSheet* m_spriteSheet;
        Player* m_player;
        BlockManager* m_blockManager;

        float m_width;
        float m_height;
};

#endif //__WORLD_H_
