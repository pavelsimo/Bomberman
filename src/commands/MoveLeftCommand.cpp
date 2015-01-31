#include "MoveLeftCommand.h"

void MoveLeftCommand::execute(IDynamicActor &actor)
{
    actor.MoveLeft();
}
