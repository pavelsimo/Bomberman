#ifndef __IDLECOMMAND_H_
#define __IDLECOMMAND_H_

#include "Command.h"

class IdleCommand : public Command
{
    public:
        virtual void execute(IDynamicActor &actor) override;
};


#endif //__IDLECOMMAND_H_


