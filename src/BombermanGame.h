#ifndef __BOMBERMANGAME_H_
#define __BOMBERMANGAME_H_

#include "utility/Game.h"
#include "World.h"

class BombermanGame : public Game
{
    public:
        BombermanGame(const std::string &title, uint32_t width, uint32_t height);
        ~BombermanGame();

        virtual void OnInit();
        virtual void OnKeyDown(SDL_KeyboardEvent& event);
        virtual void OnKeyUp(SDL_KeyboardEvent& event);
        virtual void OnUpdate();
        virtual void OnRender();
};

#endif //__BOMBERMANGAME_H_


