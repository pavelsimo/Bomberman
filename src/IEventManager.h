#ifndef __IEVENTMANAGER_H_
#define __IEVENTMANAGER_H_

#include <memory>

#include "IEvent.h"

typedef std::shared_ptr<IEvent> IEventPtr;
typedef fastdelegate::FastDelegate1<IEventPtr> EventListener;

class IEventManager
{
    public:
        virtual ~IEventManager() {};

        // Add a delegate function that will be called when certain event type is triggered.
        virtual bool AddListener(const EventListener& callback,
                                 const EventType& type) = 0;

        // Remove the delegate function from the listeners.
        virtual bool RemoveListener(const EventListener& callback,
                                    const EventType& type) = 0;

        // Fire off the event NOW.
        virtual bool TriggerEvent(const IEventPtr& pEvent) = 0;

        // Fire off the event on the next run of Update()
        virtual bool QueueEvent(const IEventPtr& pEvent) = 0;

        // Dispatch all the messages
        virtual bool Update() = 0;
};

#endif //__IEVENTMANAGER_H_
