#ifndef __MOVERIGHTCOMMAND_H_
#define __MOVERIGHTCOMMAND_H_

#include "Command.h"

class MoveRightCommand : public Command
{
    public:
        virtual void execute(IDynamicActor &actor) override;
};

#endif //__MOVERIGHTCOMMAND_H_

