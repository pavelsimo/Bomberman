#ifndef __BOMBMANAGER_H_
#define __BOMBMANAGER_H_

#include "ActorManager.h"
#include "Actor.h"

class World;

class BombManager : public ActorManager
{
    public:
        BombManager();
        ~BombManager();

        virtual void Add(const ActorPtr actor) override;
        virtual void Remove(ActorPtr actor) override;
        virtual void Update(World &world) override;
        virtual void Render() override;
        virtual bool IsColliding(const Actor &actor, ActorPtr collisionActor) override;
};

#endif //__BOMBMANAGER_H_

