#include "MoveDownCommand.h"

void MoveDownCommand::execute(IDynamicActor &actor)
{
    actor.MoveDown();
}
