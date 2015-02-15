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
        virtual void OnBeforeUpdate() override;

        // getters & setters
        //
        void SetSpriteSheet(SpriteSheetPtr spriteSheet);
        SpriteSheetPtr GetSpriteSheet();

    private:
        SpriteAnimation m_animation;
        SpriteSheetPtr m_spriteSheet;
        uint32_t m_nextFrameWait;
        bool m_bCanTriggerFireExtinguished;

        bool CanRenderNextFrame();
        bool CanTriggerFireExtinguished();
        void InitializeGeometry();
        void InitializeAnimation();
};


#endif //__FIRE_H_
