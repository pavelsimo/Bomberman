#include "MoveRightCommand.h"

void MoveRightCommand::execute(IDynamicActor &actor)
{
    actor.MoveRight();
}
