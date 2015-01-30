#ifndef __FIREFACTORY_H_
#define __FIREFACTORY_H_

#include "../Fire.h"

class FireFactory
{
    public:
        ~FireFactory();

        Fire* CreateFire(float x, float y);

        static FireFactory& GetInstance()
        {
            static FireFactory instance;
            return instance;
        }

    private:
        FireFactory() {}

        // non-copyable
        FireFactory(const FireFactory& rhs);
        FireFactory& operator=(const FireFactory& rhs);
};

#endif //__FIREFACTORY_H_
