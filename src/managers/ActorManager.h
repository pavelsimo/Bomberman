#ifndef __ACTORMANAGER_H_
#define __ACTORMANAGER_H_

#include "IActorManager.h"
#include "../Actor.h"
#include <memory>

class ActorManager : public IActorManager
{
    public:
        ActorManager();
        virtual ~ActorManager();

        virtual void Add(const ActorPtr actor) override;
        virtual bool Remove(ActorId id) override;
        virtual ActorPtr Get(ActorId id) override;
        virtual void Update() override;
        virtual void Render() override;
        virtual bool IsColliding(const Actor &actor, ActorPtr collider) override;

    private:
        // non-copyable
        ActorManager(const ActorManager& rhs);
        ActorManager& operator=(const ActorManager& rhs);

    protected:
        ActorPtrList m_actors;
};

#endif //__ACTORMANAGER_H_
