#ifndef __BOMBMANAGER_H_
#define __BOMBMANAGER_H_

#include "ActorManager.h"
#include "../Actor.h"
#include "../events/IEventManager.h"

class World;

class BombManager : public ActorManager
{
    public:
        BombManager();
        ~BombManager();

        void Initialize();

        //
        // Events
        //
        void OnBombExploded(IEventPtr pEvent);
};

typedef std::shared_ptr<BombManager> BombManagerPtr;

#endif //__BOMBMANAGER_H_

