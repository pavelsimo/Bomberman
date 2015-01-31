#ifndef __PLAYER_H_
#define __PLAYER_H_

#include "Actor.h"
#include "IDynamicActor.h"
#include "utility/SpriteSheet.h"
#include "utility/SpriteAnimation.h"

class World;

enum PlayerState
{
    PST_IDLE         = 0,
    PST_MOVING_UP    = 1,
    PST_MOVING_DOWN  = 2,
    PST_MOVING_LEFT  = 4,
    PST_MOVING_RIGHT = 8,
    PST_DEAD         = 16
};

class Player : public Actor, public IDynamicActor
{
    public:
        Player();
        Player(float x, float y);
        ~Player();

        void Initialize();
        virtual void OnRender() override;
        virtual void OnBeforeUpdate(World &world) override;
        virtual void OnAfterUpdate(World &world) override;

        // IDynamicActor
        //
        virtual void Idle() override;
        virtual void MoveLeft() override;
        virtual void MoveRight() override;
        virtual void MoveUp() override;
        virtual void MoveDown() override;
        virtual void DropBomb() override;

        void SetSpriteSheet(SpriteSheet* spriteSheet);
        SpriteSheet* GetSpriteSheet();

        void SetState(PlayerState state);
        PlayerState GetState() const;

    private:
        Vector2 m_lowerLeftCorner;
        PlayerState m_state;
        SpriteSheet* m_spriteSheet;
        float m_speed;

        // sprite animations
        //
        SpriteAnimation* m_curAnimation;
        SpriteAnimation m_walkingDownAnimation;
        SpriteAnimation m_walkingUpAnimation;
        SpriteAnimation m_walkingLeftAnimation;
        SpriteAnimation m_walkingRightAnimation;
        void NextAnimation(SpriteAnimation& animation);

        // helpers
        //
        void InitializeGeometry();
        void InitializeAnimation();
        void Clamp(const Actor& collisionActor);
        void MoveTo(float x, float y);
        void OnMove(const Vector2& direction);
};

#endif //__PLAYER_H_