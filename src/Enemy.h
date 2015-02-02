#ifndef __ENEMY_H_
#define __ENEMY_H_

#include "Actor.h"
#include "IDynamicActor.h"
#include "utility/SpriteSheet.h"
#include "utility/SpriteAnimation.h"

class World;

enum EnemyState
{
    EST_IDLE         = 0,
    EST_MOVING_UP    = 1,
    EST_MOVING_DOWN  = 2,
    EST_MOVING_LEFT  = 4,
    EST_MOVING_RIGHT = 8,
    EST_DEAD         = 16
};

// FIXME: (Pavel) Deal with the repetition of code in Enemy and Player classes...

class Enemy : public Actor, public IDynamicActor
{
    public:
        Enemy();
        Enemy(float x, float y);
        ~Enemy();

        // methods
        //
        void Initialize();

        // actor
        //
        virtual void OnRender() override;
        virtual void OnBeforeUpdate(World &world) override;
        virtual void OnAfterUpdate(World &world) override;

        // dynamic actor
        //
        virtual void Idle() override;
        virtual void MoveLeft() override;
        virtual void MoveRight() override;
        virtual void MoveUp() override;
        virtual void MoveDown() override;
        virtual void DropBomb() override;

        // getters & setters
        //
        void SetSpriteSheet(SpriteSheet* spriteSheet);
        SpriteSheet* GetSpriteSheet();
        void SetState(EnemyState state);
        EnemyState GetState() const;

    private:
        Vector2 m_lowerLeftCorner;
        EnemyState m_state;
        SpriteSheet* m_spriteSheet;

        SpriteAnimation* m_curAnimation;
        SpriteAnimation m_walkingDownAnimation;
        SpriteAnimation m_walkingUpAnimation;
        SpriteAnimation m_walkingLeftAnimation;
        SpriteAnimation m_walkingRightAnimation;
};


#endif //__ENEMY_H_


