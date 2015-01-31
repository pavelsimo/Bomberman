#ifndef __ICOMMAND_H_
#define __ICOMMAND_H_

#include "../IDynamicActor.h"

class Command
{
    public:
        virtual ~Command() {}
        virtual void execute(IDynamicActor& actor) = 0;
};

#endif //__ICOMMAND_H_
