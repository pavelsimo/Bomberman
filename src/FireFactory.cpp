#include "FireFactory.h"
#include "World.h"


FireFactory::~FireFactory()
{

}

Fire* FireFactory::CreateFire(float x, float y)
{
    World& world = World::GetInstance();
    SpriteSheet& spriteSheet = World::GetInstance().GetSpriteSheet();
    Fire *fire = new Fire(x, y);
    fire->SetSpriteSheet(&spriteSheet);
    fire->Initialize();
    fire->Update(world);
    return fire;
}