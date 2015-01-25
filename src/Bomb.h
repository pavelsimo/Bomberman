#ifndef __BOMB_H_
#define __BOMB_H_

#include "Actor.h"
#include "utility/SpriteAnimation.h"

class World;

class Bomb : public Actor
{
    public:
        // ctor & dtor
        //
        Bomb();
        Bomb(float x, float y);
        ~Bomb();

        void Initialize();
        virtual void OnRender() override;
        virtual void OnBeforeUpdate(World &world) override;

        // getters & setters
        //
        void SetSpriteSheet(SpriteSheet* spriteSheet);
        SpriteSheet* GetSpriteSheet();

        static const uint32_t WIDTH;
        static const uint32_t HEIGHT;

    private:
        SpriteAnimation m_animation;
        SpriteSheet* m_spriteSheet;
        uint32_t m_nextFrameWait;
        bool m_bCanTriggerExplosion;

        bool CanRenderNextFrame();
        void InitializeGeometry();
        void InitializeAnimation();
};


#endif //__BOMB_H_
