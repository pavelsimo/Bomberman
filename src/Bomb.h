#ifndef __BOMB_H_
#define __BOMB_H_

#include "Actor.h"
#include "utility/SpriteAnimation.h"

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

        // getters & setters
        //
        void SetSpriteSheet(SpriteSheet* spriteSheet);
        SpriteSheet* GetSpriteSheet();

    private:
        SpriteAnimation m_animation;
        SpriteSheet* m_spriteSheet;

        void InitializeGeometry();
        void InitializeAnimation();
};


#endif //__BOMB_H_
