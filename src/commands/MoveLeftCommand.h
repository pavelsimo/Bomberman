#ifndef __MOVELEFTCOMMAND_H_
#define __MOVELEFTCOMMAND_H_

#include "Command.h"

class MoveLeftCommand : public Command
{
    public:
        virtual void execute(IDynamicActor &actor) override;
};

#endif //__MOVELEFTCOMMAND_H_

