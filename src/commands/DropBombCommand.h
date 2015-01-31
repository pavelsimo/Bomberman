#ifndef __DROPBOMBCOMMAND_H_
#define __DROPBOMBCOMMAND_H_

#include "Command.h"

class DropBombCommand : public Command
{
    public:
        virtual void execute(IDynamicActor &actor) override;
};

#endif //__DROPBOMBCOMMAND_H_


