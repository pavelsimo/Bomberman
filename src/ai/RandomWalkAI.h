#ifndef __RANDOMWALK_H_
#define __RANDOMWALK_H_

#include "../InputHandler.h"
#include "../utility/MathUtilities.h"

const int RANDOMWALK_NUMMOVES = 4;

class RandomWalkAI
{
    public:
        RandomWalkAI();
        CommandPtr GetNextStep();
        void NextDirection();

    private:
        int m_currentButton;
        Button m_buttons[RANDOMWALK_NUMMOVES] = {
            BUTTON_W,
            BUTTON_A,
            BUTTON_S,
            BUTTON_D
        };

        RandomWalkAI(const RandomWalkAI & rhs);
        RandomWalkAI & operator=(const RandomWalkAI & rhs);
};


#endif //___H_
