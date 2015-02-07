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

        static std::shared_ptr<World> GetInstance()
        {
            static std::shared_ptr<World> instance = std::shared_ptr<World>(new World());
            return instance;
        }

        BlockManagerPtr GetBlockManager();
        BombManagerPtr GetBombManager();
        FireManagerPtr GetFireManager();
        TileMapPtr GetTileMap();
        TileManagerPtr GetTileManager();
        EventManagerPtr GetEventManager();
        SpriteSheetPtr GetSpriteSheet();
        InputHandlerPtr GetInputHandler();

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
        PlayerPtr m_player;
        SpriteSheetPtr m_spriteSheet;
        TileMapPtr m_tileMap;
        TileManagerPtr m_tileManager;
        BlockManagerPtr m_blockManager;
        BombManagerPtr m_bombManager;
        FireManagerPtr m_fireManager;
        EventManagerPtr m_eventManager;
        InputHandlerPtr m_inputHandler;
        // TODO: (Pavel) Remove this
        EnemyPtr m_enemy;
};

typedef std::shared_ptr<World> WorldPtr;

#endif //__WORLD_H_
