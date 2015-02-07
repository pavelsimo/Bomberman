#include "FireFactory.h"
#include "../World.h"


FireFactory::~FireFactory()
{

}

Fire* FireFactory::CreateFire(float x, float y)
{
    WorldPtr world = World::GetInstance();
    SpriteSheetPtr spriteSheet = World::GetInstance()->GetSpriteSheet();
    Fire *fire = new Fire(x, y);
    fire->SetSpriteSheet(spriteSheet);
    fire->Initialize();
    fire->Update();
    return fire;
}
