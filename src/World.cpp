#include "World.h"
#include "events/PlayerFireCollisionEvent.h"

namespace
{
    const int TILE_WIDTH = 64;
    const int TILE_HEIGHT = 64;
    const int TILE_NROWS = 10;
    const int TILE_NCOLS = 10;
}

World::~World()
{
    OnDestroy();

    SAFE_DELETE(m_player)
    SAFE_DELETE(m_spriteSheet)
    SAFE_DELETE(m_tileMap)
    SAFE_DELETE(m_tileManager)
    SAFE_DELETE(m_blockManager)
    SAFE_DELETE(m_bombManager)
    SAFE_DELETE(m_fireManager)
    SAFE_DELETE(m_eventManager)
    SAFE_DELETE(m_inputHandler)
}

void World::Initialize(uint32_t width, uint32_t height)
{
    m_player = nullptr;
    m_spriteSheet = nullptr;
    m_tileMap = nullptr;
    m_tileManager = nullptr;
    m_blockManager = nullptr;
    m_bombManager = nullptr;
    m_fireManager = nullptr;
    m_eventManager = nullptr;
    m_width = width;
    m_height = height;

    // Event Manager
    m_eventManager = new EventManager();

    // Sprite sheet
    m_spriteSheet = new SpriteSheet();
    // FIXME: (Pavel) Replaced this absolute paths with relative ones.
    m_spriteSheet->LoadFromFile("/home/pavelsimo/workspace/Games_Cpp/Bomberman/resources/BombermanSpriteSheet.png");
    m_spriteSheet->LoadSpritesFromXML("/home/pavelsimo/workspace/Games_Cpp/Bomberman/resources/BombermanSpriteSheet.xml");

    // Tile map
    m_tileMap = new TileMap();
    // FIXME: (Pavel) Replaced this absolute paths with relative ones.
    m_tileMap->LoadFromFile("/home/pavelsimo/workspace/Games_Cpp/Bomberman/resources/levels/lvl_002.txt", TILE_NROWS, TILE_NCOLS);

    // Tile manager
    m_tileManager = new TileManager(m_spriteSheet, TILE_WIDTH, TILE_HEIGHT);
    m_tileManager->SetTileMap(m_tileMap);
    m_tileManager->AddSprite("Block_Background.png");
    m_tileManager->AddSprite("Block_Solid.png");
    m_tileManager->AddSprite("Block_Explodable.png");
    m_tileManager->AddSprite("Block_Portal.png");

    // Block Manager
    m_blockManager = new BlockManager();
    m_blockManager->Initialize();

    for(int i = 0; i < TILE_NROWS; ++i)
    {
        for(int j = 0; j < TILE_NCOLS; ++j)
        {
            int x = j * TILE_WIDTH + 0.5f * TILE_WIDTH;
            int y = i * TILE_HEIGHT + 0.5f * TILE_HEIGHT;

            BlockType blockType = static_cast<BlockType>(m_tileMap->GetTile(i, j));
            Block* block = new Block();
            block->Initialize();
            block->SetType(blockType);
            block->SetPosition(Vector2(x, y));
            // FIXME: (Pavel) The AABB2 should be initialize before call update
            block->Update(*this);
            m_blockManager->Add(block);
        }
    }

    // Bomb Manager
    m_bombManager = new BombManager();
    m_bombManager->Initialize();

    // Bomb Manager
    m_fireManager = new FireManager();
    m_fireManager->Initialize();

    // Player
    m_player = new Player(128, 128);
    m_player->SetSpriteSheet(m_spriteSheet);
    m_player->Initialize();
    m_player->Update(*this);

    // Input handler
    m_inputHandler = new InputHandler();

    // Adding Listener OnPlayerFireCollision
    EVENT_MGR_ADD_LISTENER(callbackPlayerFireCollision,
            &World::OnPlayerFireCollision, PlayerFireCollisionEvent::Id_EventType)
}

void World::OnDestroy()
{
    EVENT_MGR_REMOVE_LISTENER(callbackPlayerFireCollision,
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

    m_eventManager->Update();
    m_player->Update(*this);
    m_bombManager->Update(*this);
    m_fireManager->Update(*this);
}

BlockManager& World::GetBlockManager()
{
    return *m_blockManager;
}

BombManager& World::GetBombManager()
{
    return *m_bombManager;
}

TileMap& World::GetTileMap()
{
    return *m_tileMap;
}

TileManager& World::GetTileManager()
{
    return *m_tileManager;
}

EventManager &World::GetEventManager()
{
    return *m_eventManager;
}

SpriteSheet &World::GetSpriteSheet()
{
    return *m_spriteSheet;
}

FireManager &World::GetFireManager()
{
    return *m_fireManager;
}

void World::OnRender()
{
    m_tileManager->Render();
    m_bombManager->Render();
    m_fireManager->Render();
    m_player->Render();
}

void World::OnKeyDown(uint8_t key)
{
    m_inputHandler->OnKeyDown(key);


    /*
    switch(key)
    {
        case 'w':
        case 'W':
            m_player->SetState(PST_MOVING_UP);
            break;
        case 'a':
        case 'A':
            m_player->SetState(PST_MOVING_LEFT);
            break;
        case 's':
        case 'S':
            m_player->SetState(PST_MOVING_DOWN);
            break;
        case 'd':
        case 'D':
            m_player->SetState(PST_MOVING_RIGHT);
            break;
        case ' ':
            m_player->DropBomb(*this);
            break;
    }
    */
}

void World::OnKeyUp(uint8_t key)
{
    m_inputHandler->OnKeyUp(key);
    /*
    switch(key)
    {
        case 'w':
        case 'W':
        case 'a':
        case 'A':
        case 's':
        case 'S':
        case 'd':
        case 'D':
            m_player->SetState(PST_IDLE);
            break;
    }
    */
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
    std::cout << "OnPlayerFireCollision()" << std::endl;
}
