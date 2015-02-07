#ifndef __FIREMANAGER_H_
#define __FIREMANAGER_H_

#include "ActorManager.h"
#include "../events/IEventManager.h"

class World;

class FireManager : public ActorManager
{
    public:
        FireManager();
        ~FireManager();

        void Initialize();

        //
        // Events
        //
        void OnBombExploded(IEventPtr pEvent);
        void OnFireExtinguished(IEventPtr pEvent);
};

typedef std::shared_ptr<FireManager> FireManagerPtr;

#endif //__FIREMANAGER_H_
