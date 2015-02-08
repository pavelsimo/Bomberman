#ifndef __SHORTCUTS_H_
#define __SHORTCUTS_H_

#define SAFE_DELETE(p) { if(p != nullptr) { delete(p); (p)=nullptr; } }

//
// Event Manager
//

#define EVENT_MGR_ADD_LISTENER(callback, listener, eventtype) { \
    EventListener callback = fastdelegate::MakeDelegate(this, listener); \
    World::GetInstance().GetEventManager()->AddListener(callback, eventtype); \
}

#define EVENT_MGR_REMOVE_LISTENER(callback, listener, eventtype)

//#define EVENT_MGR_REMOVE_LISTENER(callback, listener, eventtype) { \
//    EventListener callback = fastdelegate::MakeDelegate(this, listener); \
//    World::GetInstance().GetEventManager()->RemoveListener(callback, eventtype); \
//}

#endif //__SHORTCUTS_H_
