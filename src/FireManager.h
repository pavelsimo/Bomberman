#ifndef __FIREMANAGER_H_
#define __FIREMANAGER_H_

#include "ActorManager.h"

class World;

class FireManager : public ActorManager
{
    public:
        FireManager();
        virtual ~FireManager();

        virtual void Add(const ActorPtr actor) override;
        virtual void Remove(ActorPtr actor) override;
        virtual void Update(World &world) override;
        virtual void Render() override;
        virtual bool IsColliding(const Actor &actor, ActorPtr collisionActor) override;
};

#endif //__FIREMANAGER_H_
