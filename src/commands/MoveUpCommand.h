#ifndef __MOVEUPCOMMAND_H_
#define __MOVEUPCOMMAND_H_

#include "Command.h"

class MoveUpCommand : public Command
{
    public:
        virtual void execute(IDynamicActor &actor) override;
};

#endif //__MOVEUPCOMMAND_H_

