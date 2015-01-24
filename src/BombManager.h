#ifndef __BOMBMANAGER_H_
#define __BOMBMANAGER_H_

#include "ActorManager.h"
#include "Actor.h"
#include "IEventManager.h"

class World;

class BombManager : public ActorManager
{
    public:
        BombManager();
        ~BombManager();

        void Initialize();

        void EvtHandlerBombExploded(IEventPtr pEvent);
};



#endif //__BOMBMANAGER_H_

