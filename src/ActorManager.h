#ifndef __ACTORMANAGER_H_
#define __ACTORMANAGER_H_

#include "IActorManager.h"
#include "Actor.h"

class World;

class ActorManager : public IActorManager
{
    public:
        ActorManager();
        virtual ~ActorManager();

        virtual void Add(const ActorPtr actor) override;
        virtual void Remove(ActorPtr actor) override;
        virtual void Update(World &world) override;
        virtual void Render() override;
        virtual bool IsColliding(const Actor &actor, ActorPtr collisionActor) override;

    private:
        // non-copyable
        ActorManager(const ActorManager& rhs);
        ActorManager& operator=(const ActorManager& rhs);

    protected:
        ActorPtrList m_actors;
};

#endif //__ACTORMANAGER_H_
