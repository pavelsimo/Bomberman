#ifndef __PLAYER_H_
#define __PLAYER_H_

#include "Actor.h"
#include "utility/SpriteSheet.h"
#include "utility/SpriteAnimation.h"

class World;

enum PlayeState
{
    PST_IDLE = 1,
    PST_MOVING_UP = 2,
    PST_MOVING_DOWN = 4,
    PST_MOVING_LEFT = 8,
    PST_MOVING_RIGHT = 16,
    PST_DEAD = 32
};

class Player : public Actor
{
    public:
        Player();
        Player(float x, float y);
        ~Player();

        void Initialize();

        void OnIdle();
        virtual void OnRender() override;
        virtual void OnUpdate(World &world) override;
        virtual void OnMoveUp() override;
        virtual void OnMoveDown() override;
        virtual void OnMoveLeft() override;
        virtual void OnMoveRight() override;

        // getters & setters
        //
        void SetSpriteSheet(SpriteSheet* spriteSheet);
        SpriteSheet* GetSpriteSheet();

        void SetState(PlayeState state);
        PlayeState GetState() const;

    private:
        PlayeState m_state;
        SpriteSheet* m_spriteSheet;
        SpriteAnimation* m_curAnimation;

        // sprite animations
        //
        SpriteAnimation m_walkingAnimationDown;
        SpriteAnimation m_walkingAnimationUp;
        SpriteAnimation m_walkingAnimationLeft;
        SpriteAnimation m_walkingAnimationRight;

        // helpers
        //
        void OnMove();
        void InitializeGeometry();
        void InitializeAnimation();
};

#endif //__PLAYER_H_