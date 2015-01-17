#ifndef __IACTORMANAGER_H_
#define __IACTORMANAGER_H_

#include <list>

class Actor;
class World;

typedef Actor* ActorPtr;
typedef std::list<ActorPtr> ActorList;

class IActorManager
{
    public:
        virtual ~IActorManager() {}
        virtual void Add(const ActorPtr actor) = 0;
        virtual void Remove(ActorPtr actor) = 0;
        virtual void Update(World& world) = 0;
        virtual void Render() = 0;
        virtual bool IsColliding(const Actor& actor, ActorPtr collisionActor) = 0;
};

#endif //__IACTORMANAGER_H_
