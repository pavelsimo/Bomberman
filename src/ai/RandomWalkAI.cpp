#include "RandomWalkAI.h"
#include "../World.h"

const Button RandomWalkAI::buttons[RANDOMWALK_NUMMOVES] = {
    BUTTON_W,
    BUTTON_A,
    BUTTON_S,
    BUTTON_D
};

RandomWalkAI::RandomWalkAI()
: m_currentButton(0)
{

}

CommandPtr RandomWalkAI::GetNextStep()
{
    InputHandlerPtr inputHandler = World::GetInstance().GetInputHandler();
    CommandPtr command = inputHandler->GetCommand(buttons[m_currentButton]);
    return command;
}

void RandomWalkAI::NextDirection()
{
    m_currentButton = Random<int>(0, RANDOMWALK_NUMMOVES - 1);
}
