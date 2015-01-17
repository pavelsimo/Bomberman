#ifndef __BOMBMANAGER_H_
#define __BOMBMANAGER_H_

#include "IActorManager.h"
#include "Actor.h"

class World;

class BombManager : public IActorManager
{
    public:
        BombManager();
        ~BombManager();

        virtual void Add(const ActorPtr actor) override;
        virtual void Remove(const ActorPtr actor) override;
        virtual void Update(World &world) override;
        virtual void Render() override;
        virtual bool IsColliding(const Actor &actor, ActorPtr collisionActor) override;

    private:
        // non-copyable
        BombManager(const BombManager& rhs);
        BombManager& operator=(const BombManager& rhs);

        ActorList m_bombs;
};

#endif //__BOMBMANAGER_H_

