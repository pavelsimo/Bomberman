#include "World.h"
#include "events/PlayerFireCollisionEvent.h"
#include "events/FireExtinguishedEvent.h"
#include "events/BombExplodedEvent.h"
#include "ai/RandomWalk.h"

namespace
{
    const int WORLD_TILE_WIDTH = 64;
    const int WORLD_TILE_HEIGHT = 64;
    const int WORLD_TILE_NUM_ROWS = 10;
    const int WORLD_TILE_NUM_COLS = 10;
}

World::~World()
{
    #ifdef _DEBUG
        std::cout << "Destroying the World" << std::endl;
    #endif

    //
    // Removing the World listeners
    //
    EVENT_MGR_REMOVE_LISTENER(callbackPlayerFireCollision,
            &World::OnPlayerFireCollision, PlayerFireCollisionEvent::Id_EventType)
}

void World::Initialize(uint32_t width, uint32_t height)
{
    m_width = width;
    m_height = height;
    srand(time(NULL));

    // Event Manager
    m_eventManager = std::make_shared<EventManager>();

    // Sprite sheet
    m_spriteSheet = std::make_shared<SpriteSheet>();
    // FIXME: (Pavel) Replaced this absolute paths with relative ones.
    m_spriteSheet->LoadFromFile("/home/pavelsimo/workspace/Games_Cpp/Bomberman/resources/BombermanSpriteSheet.png");
    m_spriteSheet->LoadSpritesFromXML("/home/pavelsimo/workspace/Games_Cpp/Bomberman/resources/BombermanSpriteSheet.xml");

    // Tile map
    m_tileMap = std::make_shared<TileMap>();
    // FIXME: (Pavel) Replaced this absolute paths with relative ones.
    m_tileMap->LoadFromFile("/home/pavelsimo/workspace/Games_Cpp/Bomberman/resources/levels/lvl_002.txt",
            WORLD_TILE_NUM_ROWS, WORLD_TILE_NUM_COLS);

    // Tile manager
    m_tileManager = std::make_shared<TileManager>(m_spriteSheet, WORLD_TILE_WIDTH, WORLD_TILE_HEIGHT);
    m_tileManager->SetTileMap(m_tileMap);
    m_tileManager->AddSprite("Block_Background.png");
    m_tileManager->AddSprite("Block_Solid.png");
    m_tileManager->AddSprite("Block_Explodable.png");
    m_tileManager->AddSprite("Block_Portal.png");

    // Block Manager
    m_blockManager = std::make_shared<BlockManager>();
    m_blockManager->Initialize();

    for(int row = 0; row < WORLD_TILE_NUM_ROWS; ++row)
    {
        for(int col = 0; col < WORLD_TILE_NUM_COLS; ++col)
        {
            int x = col * WORLD_TILE_WIDTH + 0.5f * WORLD_TILE_WIDTH;
            int y = row * WORLD_TILE_HEIGHT + 0.5f * WORLD_TILE_HEIGHT;

            BlockType blockType = static_cast<BlockType>(m_tileMap->GetTile(row, col));
            Block* block = new Block();
            block->Initialize();
            block->SetType(blockType);
            block->SetPosition(Vector2(x, y));
            // FIXME: (Pavel) The AABB2 should be initialize before call update
            block->Update();
            m_blockManager->Add(block);
        }
    }

    // Bomb Manager
    m_bombManager = std::make_shared<BombManager>();
    m_bombManager->Initialize();

    // Fire Manager
    m_fireManager = std::make_shared<FireManager>();
    m_fireManager->Initialize();

    // Player
    m_player = std::make_shared<Player>(128, 128);
    m_player->SetSpriteSheet(m_spriteSheet);
    m_player->Initialize();
    m_player->Update();

    // Enemy
    m_enemy = std::make_shared<Enemy>(128, 400);
    m_enemy->SetSpriteSheet(m_spriteSheet);
    m_enemy->Initialize();
    m_enemy->Update();

    // Input handler
    m_inputHandler = std::make_shared<InputHandler>();

    // Adding Listener OnPlayerFireCollision
    EVENT_MGR_ADD_LISTENER(callbackPlayerFireCollision,
            &World::OnPlayerFireCollision, PlayerFireCollisionEvent::Id_EventType)
}

void World::OnUpdate()
{
    CommandList commands;
    m_inputHandler->FetchCommands(commands);

    if(!commands.empty())
    {
        for(auto it = commands.begin(); it != commands.end(); ++it)
        {
            CommandPtr command = *it;
            command->execute(*m_player);
        }
    }
    else
    {
        CommandPtr idleCommand = m_inputHandler->GetIdleCommand();
        idleCommand->execute(*m_player);
    }

    CommandPtr enemyCommand = RandomWalk::GetInstance().GetNextStep();
    enemyCommand->execute(*m_enemy);

    m_eventManager->Update();
    m_player->Update();
    m_enemy->Update();
    m_bombManager->Update();
    m_fireManager->Update();
}

BlockManagerPtr World::GetBlockManager()
{
    return m_blockManager;
}

BombManagerPtr World::GetBombManager()
{
    return m_bombManager;
}

TileMapPtr World::GetTileMap()
{
    return m_tileMap;
}

TileManagerPtr World::GetTileManager()
{
    return m_tileManager;
}

EventManagerPtr World::GetEventManager()
{
    return m_eventManager;
}

SpriteSheetPtr World::GetSpriteSheet()
{
    return m_spriteSheet;
}

FireManagerPtr World::GetFireManager()
{
    return m_fireManager;
}


InputHandlerPtr World::GetInputHandler()
{
    return m_inputHandler;
}

void World::OnRender()
{
    m_tileManager->Render();
    m_bombManager->Render();
    m_fireManager->Render();
    m_player->Render();
    m_enemy->Render();
}

void World::OnKeyDown(uint8_t key)
{
    m_inputHandler->OnKeyDown(key);
}

void World::OnKeyUp(uint8_t key)
{
    m_inputHandler->OnKeyUp(key);
}

void World::OnMouseMove(int x, int y)
{

}

void World::OnMouseClick(int button, int state, int x, int y)
{

}

float World::GetWidth() const
{
    return m_width;
}

float World::GetHeight() const
{
    return m_height;
}

float World::GetLeft() const
{
    return 0;
}

float World::GetRight() const
{
    return m_width;
}

float World::GetBottom() const
{
    return m_height;
}

float World::GetTop() const
{
    return 0;
}

void World::OnPlayerFireCollision(IEventPtr pEvent)
{
    std::shared_ptr<PlayerFireCollisionEvent> fireExtinguishedEvent =
            std::static_pointer_cast<PlayerFireCollisionEvent>(pEvent);

    // TODO: (Pavel) Trigger OnPlayerDead()

    ActorId fireId = fireExtinguishedEvent->GetFireId();

#ifdef _DEBUG
    std::cout << "OnPlayerFireCollision()" << std::endl;
#endif

}
