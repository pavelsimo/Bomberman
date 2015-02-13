#include "RandomWalkAI.h"
#include "../World.h"

RandomWalkAI::RandomWalkAI()
: m_currentButton(0)
{

}

CommandPtr RandomWalkAI::GetNextStep()
{
    InputHandlerPtr inputHandler = World::GetInstance().GetInputHandler();
    CommandPtr command = inputHandler->GetCommand(m_buttons[m_currentButton]);
    return command;
}

void RandomWalkAI::NextDirection()
{
    m_currentButton = Random<int>(0, RANDOMWALK_NUMMOVES - 1);
}
