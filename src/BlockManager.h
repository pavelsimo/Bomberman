#ifndef __BLOCKMANAGER_H_
#define __BLOCKMANAGER_H_

#include "ActorManager.h"
#include "Actor.h"

class World;

class BlockManager : public ActorManager
{
    public:
        BlockManager();
        ~BlockManager();

        virtual void Add(const ActorPtr actor) override;
        virtual void Remove(ActorPtr actor) override;
        virtual void Update(World &world) override;
        virtual void Render() override;
        virtual bool IsColliding(const Actor &actor, ActorPtr collisionActor) override;
};


#endif //__BLOCKMANAGER_H_
