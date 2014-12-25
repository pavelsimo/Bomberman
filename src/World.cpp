#include "World.h"

const int TILE_WIDTH = 64;
const int TILE_HEIGHT = 64;
const int TILE_NROWS = 10;
const int TILE_NCOLS = 10;

World::World(float width, float height)
: m_width(width),
  m_height(height),
  m_player(nullptr),
  m_spriteSheet(nullptr),
  m_tileMap(nullptr),
  m_blockManager(nullptr)
{

}

World::~World() {
    if (m_player != nullptr)
    {
        delete m_player;
        m_player = nullptr;
    }

    if(m_tileManager != nullptr)
    {
        delete m_tileManager;
        m_tileManager = nullptr;
    }

    if(m_spriteSheet != nullptr)
    {
        delete m_spriteSheet;
        m_spriteSheet = nullptr;
    }

    if(m_tileMap != nullptr)
    {
        delete m_tileMap;
        m_tileMap = nullptr;
    }

    if(m_blockManager != nullptr)
    {
        delete m_blockManager;
        m_blockManager = nullptr;
    }
}

void World::OnSetup()
{
    //
    // Sprite sheet
    //
    m_spriteSheet = new SpriteSheet();
    m_spriteSheet->LoadFromFile("/home/pavelsimo/workspace/Games_Cpp/Bomberman/resources/BombermanSpriteSheet.png");
    m_spriteSheet->LoadSpritesFromXML("/home/pavelsimo/workspace/Games_Cpp/Bomberman/resources/BombermanSpriteSheet.xml");

    //
    // Tile map
    //
    m_tileMap = new TileMap();
    m_tileMap->LoadFromFile("/home/pavelsimo/workspace/Games_Cpp/Bomberman/resources/levels/lvl_002.txt", TILE_NROWS, TILE_NCOLS);

    //
    // Tile manager
    //
    m_tileManager = new TileManager(m_spriteSheet, TILE_WIDTH, TILE_HEIGHT);
    m_tileManager->SetTileMap(m_tileMap);
    m_tileManager->AddSprite("Block_Background.png");
    m_tileManager->AddSprite("Block_Solid.png");
    m_tileManager->AddSprite("Block_Explodable.png");
    m_tileManager->AddSprite("Block_Portal.png");

    //
    // Player
    //
    m_player = new Player(128, 128);
    m_player->SetSpriteSheet(m_spriteSheet);
    m_player->Initialize();

    //
    // Block Manager
    //
    m_blockManager = new BlockManager();
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

            m_blockManager->AddBlock(block);
        }
    }
}

void World::OnDestroy()
{

}

void World::OnUpdate()
{
    m_player->Update(*this);

    if(m_blockManager->IsColliding(*m_player))
    {
        std::cout << "*** BLOCK COLLISION ***" << std::endl;
    }
}

void World::OnRender()
{
    m_tileManager->Render();
    m_player->Render();
}

void World::OnKeyDown(unsigned char key)
{
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
    }
}

void World::OnKeyUp(unsigned char key)
{
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
