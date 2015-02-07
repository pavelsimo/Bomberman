#ifndef __RANDOMWALK_H_
#define __RANDOMWALK_H_

#include "../InputHandler.h"
#include "../utility/MathUtilities.h"

const int RANDOMWALK_NUMMOVES = 4;

class RandomWalk
{
    public:

        CommandPtr GetNextStep();

        void NextDirection();

        static RandomWalk& GetInstance()
        {
            static RandomWalk instance;
            return instance;
        }

    private:
        int m_currentButton;
        Button m_buttons[RANDOMWALK_NUMMOVES] = {
            BUTTON_W,
            BUTTON_A,
            BUTTON_S,
            BUTTON_D
        };

        RandomWalk()
        : m_currentButton(0)
        {}
        RandomWalk(const RandomWalk& rhs);
        RandomWalk& operator=(const RandomWalk& rhs);
};


#endif //___H_
