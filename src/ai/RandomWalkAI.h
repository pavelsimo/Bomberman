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
        static const Button buttons[RANDOMWALK_NUMMOVES];
        int m_currentButton;
        
        RandomWalkAI(const RandomWalkAI & rhs);
        RandomWalkAI & operator=(const RandomWalkAI & rhs);
};


#endif //___H_
