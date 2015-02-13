#ifndef __ENEMYMANAGER_H_
#define __ENEMYMANAGER_H_

#include <memory>
#include "ActorManager.h"


class EnemyManager  : public ActorManager
{
    public:
        EnemyManager();
        ~EnemyManager();

        void Initialize();

    virtual void Update() override;
};

typedef std::shared_ptr<EnemyManager> EnemyManagerPtr;

#endif //__ENEMYMANAGER_H_
