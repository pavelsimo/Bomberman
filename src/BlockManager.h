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

        virtual bool IsColliding(const Actor &actor, ActorPtr collider) override;
};


#endif //__BLOCKMANAGER_H_
