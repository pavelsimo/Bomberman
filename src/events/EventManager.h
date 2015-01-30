#ifndef __EVENTMANAGER_H_
#define __EVENTMANAGER_H_

#include <list>
#include <map>

#include "IEventManager.h"

const unsigned int EVENTMANAGER_NUM_QUEUES = 2;

class EventManager : public IEventManager
{
    public:
        EventManager();
        virtual ~EventManager();

        virtual bool AddListener(const EventListener& callback,
                                 const EventType& type) override;
        virtual bool RemoveListener(const EventListener& callback,
                                    const EventType& type) override;
        virtual bool TriggerEvent(const IEventPtr& pEvent) override;
        virtual bool QueueEvent(const IEventPtr& pEvent) override;
        virtual bool Update() override;

    private:
        typedef std::list<EventListener> EventListenerList;
        typedef std::map<EventType, EventListenerList> EventListenerMap;
        typedef std::list<IEventPtr> EventQueue;

        EventListenerMap m_eventListenerMap;
        EventQueue m_queues[EVENTMANAGER_NUM_QUEUES];
        int m_activeQueue;
};

#endif //__EVENTMANAGER_H_



