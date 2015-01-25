#ifndef __FIRE_H_
#define __FIRE_H_

#include "Actor.h"
#include "utility/SpriteSheet.h"
#include "utility/SpriteAnimation.h"

class World;

class Fire : public Actor
{
    public:
        // ctor & dtor
        //
        Fire();
        Fire(float x, float y);
        ~Fire();

        void Initialize();
        virtual void OnRender() override;
        virtual void OnBeforeUpdate(World &world) override;

        // getters & setters
        //
        void SetSpriteSheet(SpriteSheet* spriteSheet);
        SpriteSheet* GetSpriteSheet();

    private:
        SpriteAnimation m_animation;
        SpriteSheet* m_spriteSheet;
        uint32_t m_nextFrameWait;
        bool m_bCanTriggerFireExtinguished;

        bool CanRenderNextFrame();
        void InitializeGeometry();
        void InitializeAnimation();
};


#endif //__FIRE_H_
