#ifndef __BLOCKMANAGER_H_
#define __BLOCKMANAGER_H_

#include "../events/IEventManager.h"
#include "../Actor.h"
#include "ActorManager.h"

class BlockManager : public ActorManager
{
    public:
        BlockManager();
        ~BlockManager();

        void Initialize();
        virtual bool IsColliding(const Actor &actor, ActorPtr collider) override;

        //
        // Events
        //
        void OnFireExtinguished(IEventPtr pEvent);
};

typedef std::shared_ptr<BlockManager> BlockManagerPtr;

#endif //__BLOCKMANAGER_H_
