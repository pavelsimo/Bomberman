#ifndef __IACTORMANAGER_H_
#define __IACTORMANAGER_H_

#include <list>
#include "../Actor.h"
#include "../utility/AABB2.h"

typedef Actor* ActorPtr;
typedef std::list<ActorPtr> ActorPtrList;

class IActorManager
{
    public:
        virtual ~IActorManager() {}
        virtual void Add(const ActorPtr actor) = 0;
        virtual bool Remove(ActorId id) = 0;
        virtual ActorPtr Get(ActorId id) = 0;
        virtual void Update() = 0;
        virtual void Render() = 0;
        virtual bool IsColliding(const Actor& actor, ActorPtr collider) = 0;
        virtual bool IsColliding(const AABB2& box, ActorPtr collider) = 0;
};

#endif //__IACTORMANAGER_H_
