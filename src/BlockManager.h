#ifndef __BLOCKMANAGER_H_
#define __BLOCKMANAGER_H_


#include "IActorManager.h"
#include "Actor.h"

class World;

class BlockManager : public IActorManager
{
    public:
        BlockManager();
        ~BlockManager();

        virtual void Add(const ActorPtr actor) override;
        virtual void Remove(ActorPtr actor) override;
        virtual void Update(World &world) override;
        virtual void Render() override;
        virtual bool IsColliding(const Actor &actor, ActorPtr collisionActor) override;

    private:
        // non-copyable
        BlockManager(const BlockManager& rhs);
        BlockManager& operator=(const BlockManager& rhs);


        ActorList m_blocks;
};


#endif //__BLOCKMANAGER_H_
