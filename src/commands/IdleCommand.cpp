#include "IdleCommand.h"

void IdleCommand::execute(IDynamicActor &actor)
{
    actor.Idle();
}