#ifndef __BOMBERMANGAME_H_
#define __BOMBERMANGAME_H_

#include <SDL_keycode.h>
#include "utility/Game.h"
#include "World.h"

class BombermanGame : public Game
{
    public:
        BombermanGame(const std::string &title, uint32_t width, uint32_t height);
        ~BombermanGame();

        virtual void OnInit() override;
        virtual void OnKeyDown(SDL_Keycode key) override;
        virtual void OnKeyUp(SDL_Keycode key) override;
        virtual void OnUpdate() override;
        virtual void OnRender() override;

    private:
        World* m_world;
};

#endif //__BOMBERMANGAME_H_


