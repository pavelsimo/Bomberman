#ifndef __ACTOR_H_
#define __ACTOR_H_

#include "utility/Vector2.h"
#include "utility/AABB2.h"

class Actor
{
    public:
        Actor();
        virtual ~Actor();

        void Render();
        virtual void OnRender();

        void Update(World& world);
        virtual void OnUpdate(World& world);

        void MoveForward();
        virtual void OnMoveForward();

        void MoveBackward();
        virtual void OnMoveBackward();

        void MoveLeft();
        virtual void OnMoveLeft();

        void MoveRight();
        virtual void OnMoveRight();

        bool IsColliding(const Actor& actor);

        void SetPosition(const Vector2& position);
        void SetVelocity(const Vector2& velocity);
        void SetDirection(const Vector2& direction);

        Vector2 GetPosition() const;
        Vector2 GetVelocity() const;
        Vector2 GetDirection() const;
        AABB2 GetAABB2() const;

    protected:
        Vector2 m_position;
        Vector2 m_velocity;
        Vector2 m_direction;

    private:
        AABB2 m_aabb2;
};

#endif //__ACTOR_H_

