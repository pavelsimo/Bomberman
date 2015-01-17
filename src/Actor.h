#ifndef __ACTOR_H_
#define __ACTOR_H_

#include <vector>

#include "utility/Vector2.h"
#include "utility/AABB2.h"

class World;

typedef std::vector<Vector2> VertexLst;

class Actor
{
    public:
        // ctor & dtor
        //
        Actor();
        Actor(float x, float y);
        virtual ~Actor();

        // actions
        //
        void Render();
        void Update(World& world);
        void MoveUp();
        void MoveDown();
        void MoveLeft();
        void MoveRight();
        bool IsColliding(const Actor& actor) const;

        // virtual
        //
        virtual void OnRender();
        virtual void OnBeforeUpdate(World &world);
        virtual void OnAfterUpdate(World &world);
        virtual void OnMoveUp();
        virtual void OnMoveDown();
        virtual void OnMoveLeft();
        virtual void OnMoveRight();

        // getters & setters
        //
        void SetPosition(const Vector2& position);
        Vector2 GetPosition() const;

        void SetVelocity(const Vector2& velocity);
        Vector2 GetVelocity() const;

        void SetDirection(const Vector2& direction);
        Vector2 GetDirection() const;

        AABB2 GetAABB2() const;

    protected:
        VertexLst m_geometry;
        Vector2 m_position;
        Vector2 m_velocity;
        Vector2 m_direction;

    private:
        AABB2 m_aabb2;
};

#endif //__ACTOR_H_
