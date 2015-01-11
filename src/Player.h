#ifndef __PLAYER_H_
#define __PLAYER_H_

#include "Actor.h"
#include "utility/SpriteSheet.h"
#include "utility/SpriteAnimation.h"

class World;

enum PlayerState
{
    PST_IDLE         = 1,
    PST_MOVING_UP    = 2,
    PST_MOVING_DOWN  = 4,
    PST_MOVING_LEFT  = 8,
    PST_MOVING_RIGHT = 16,
    PST_DEAD         = 32
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
        virtual void OnBeforeUpdate(World &world) override;
        virtual void OnAfterUpdate(World &world) override;
        virtual void OnMoveUp() override;
        virtual void OnMoveDown() override;
        virtual void OnMoveLeft() override;
        virtual void OnMoveRight() override;

        void MoveTo(float x, float y);

        // getters & setters
        //
        Vector2 GetLowerLeftCornerPosition() const;

        void SetSpriteSheet(SpriteSheet* spriteSheet);
        SpriteSheet* GetSpriteSheet();

        void SetState(PlayerState state);
        PlayerState GetState() const;

    private:
        Vector2 m_lowerLeftCorner;
        PlayerState m_state;
        SpriteSheet* m_spriteSheet;
        SpriteAnimation* m_curAnimation;

        // sprite animations
        //
        SpriteAnimation m_walkingDownAnimation;
        SpriteAnimation m_walkingUpAnimation;
        SpriteAnimation m_walkingLeftAnimation;
        SpriteAnimation m_walkingRightAnimation;

        // helpers
        //
        void InitializeGeometry();
        void InitializeAnimation();
        void OnMove();
        void NextAnimation(SpriteAnimation& animation);
};

#endif //__PLAYER_H_