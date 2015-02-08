#include "RandomWalk.h"
#include "../World.h"

CommandPtr RandomWalk::GetNextStep()
{
    InputHandlerPtr inputHandler = World::GetInstance().GetInputHandler();
    CommandPtr command = inputHandler->GetCommand(m_buttons[m_currentButton]);
    return command;
}

void RandomWalk::NextDirection()
{
    m_currentButton = Random<int>(0, RANDOMWALK_NUMMOVES - 1);
}
