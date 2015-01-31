#ifndef __MOVEDOWNCOMMAND_H_
#define __MOVEDOWNCOMMAND_H_

#include "Command.h"

class MoveDownCommand : public Command
{
    public:
        virtual void execute(IDynamicActor &actor) override;
};

#endif //__MOVEDOWNCOMMAND_H_

