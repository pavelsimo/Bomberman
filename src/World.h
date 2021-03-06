#ifndef __WORLD_H_
#define __WORLD_H_

#include "utility/SpriteSheet.h"
#include "utility/TileManager.h"
#include "utility/TileMap.h"
#include "managers/BombManager.h"
#include "managers/BlockManager.h"
#include "managers/FireManager.h"
#include "managers/EnemyManager.h"
#include "events/EventManager.h"
#include "InputHandler.h"
#include "Player.h"
#include "Bomb.h"
#include "Fire.h"
#include "Block.h"
#include "Shortcuts.h"
#include <memory>

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

        BlockManagerPtr GetBlockManager();
        BombManagerPtr GetBombManager();
        FireManagerPtr GetFireManager();
        EnemyManagerPtr GetEnemyManager();
        TileMapPtr GetTileMap();
        TileManagerPtr GetTileManager();
        EventManagerPtr GetEventManager();
        SpriteSheetPtr GetSpriteSheet();
        InputHandlerPtr GetInputHandler();

        // events
        //
        void OnPlayerFireCollision(IEventPtr pEvent);


    private:
        World()
        {
#ifdef _DEBUG
            std::cout << "Creating the World" << std::endl;
#endif
        };
        // non-copyable
        World(const World& rhs);
        World& operator=(const World& rhs);

        uint32_t m_width;
        uint32_t  m_height;
        PlayerPtr m_player;
        SpriteSheetPtr m_spriteSheet;
        TileMapPtr m_tileMap;
        TileManagerPtr m_tileManager;
        BlockManagerPtr m_blockManager;
        BombManagerPtr m_bombManager;
        FireManagerPtr m_fireManager;
        EnemyManagerPtr m_enemyManager;
        EventManagerPtr m_eventManager;
        InputHandlerPtr m_inputHandler;
};

#endif //__WORLD_H_
