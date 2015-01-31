#include "DropBombCommand.h"

void DropBombCommand::execute(IDynamicActor &actor)
{
    actor.DropBomb();
}