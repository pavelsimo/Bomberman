#ifndef __WORLD_H_
#define __WORLD_H_

#include "utility/SpriteSheet.h"
#include "utility/TileManager.h"
#include "utility/TileMap.h"
#include "managers/BombManager.h"
#include "managers/BlockManager.h"
#include "managers/FireManager.h"
#include "events/EventManager.h"
#include "InputHandler.h"
#include "Player.h"
#include "Bomb.h"
#include "Fire.h"
#include "Block.h"
#include "Enemy.h"
#include "Shortcuts.h"

class World
{
    public:
        ~World();

        void Initialize(uint32_t width, uint32_t height);
        void OnKeyDown(uint8_t key);
        void OnKeyUp(uint8_t key);
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

        static World& GetInstance()
        {
            static World instance;
            return instance;
        }

        BlockManager& GetBlockManager();
        BombManager& GetBombManager();
        FireManager& GetFireManager();
        TileMap& GetTileMap();
        TileManager& GetTileManager();
        EventManager& GetEventManager();
        SpriteSheet& GetSpriteSheet();

        // events
        //
        void OnPlayerFireCollision(IEventPtr pEvent);

    private:
        World() {};
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
        EventManager* m_eventManager;
        InputHandler* m_inputHandler;
        // TODO: (Pavel) Remove this
        Enemy* m_enemy;

};

#endif //__WORLD_H_
