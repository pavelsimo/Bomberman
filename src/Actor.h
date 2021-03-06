#ifndef __ACTOR_H_
#define __ACTOR_H_

#include <vector>
#include <atomic>
#include <algorithm>

#include "ActorType.h"
#include "utility/Vector2.h"
#include "utility/AABB2.h"

typedef std::vector<Vector2> VertexLst;
typedef uint32_t ActorId;

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
        void Update();
        bool IsColliding(const Actor& actor) const;

        // virtual
        //
        virtual void OnRender();
        virtual void OnBeforeUpdate();
        virtual void OnAfterUpdate();
        virtual bool CanDelete();

        // getters & setters
        //
        void SetPosition(const Vector2& position);
        Vector2 GetPosition() const;

        void SetVelocity(const Vector2& velocity);
        Vector2 GetVelocity() const;

        void SetDirection(const Vector2& direction);
        Vector2 GetDirection() const;

        AABB2 GetAABB2() const;
        ActorId GetId() const;

        uint32_t GetLifeSpan() const;
        void SetLifeSpan(uint32_t lifeSpan);

    protected:
        VertexLst m_geometry;
        Vector2 m_position;
        Vector2 m_velocity;
        Vector2 m_direction;

    private:
        static std::atomic<ActorId> counter;
        ActorId m_id;
        AABB2 m_aabb2;
        uint32_t m_lifeSpan;
};

#endif //__ACTOR_H_
