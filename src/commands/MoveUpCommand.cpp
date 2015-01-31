#include "MoveUpCommand.h"

void MoveUpCommand::execute(IDynamicActor &actor)
{
    actor.MoveUp();
}
