#ifndef __GAME_H_
#define __GAME_H_

#include <SDL.h>
#include <SDL_opengl.h>
#include <string>
#include "LDevIL.h"

enum GameState
{
    GAME_RUNNING = 0,
    GAME_PAUSED  = 1,
    GAME_QUIT    = 2
};

class Game
{
    public:
        Game(const std::string& title, uint32_t width, uint32_t height,
                uint32_t framesPerSecond = 60);
        virtual ~Game();

        bool Init();
        bool Run();
        void Render();
        void Update();

        void OnEvent(SDL_Event &event);
        void OnCleanup();
        void OnResize(uint32_t width, uint32_t height);
        virtual void OnInit();
        virtual void OnKeyDown(SDL_Keycode key);
        virtual void OnKeyUp(SDL_Keycode key);
        virtual void OnExit();
        virtual void OnUpdate();
        virtual void OnRender();

    protected:
        GameState m_state;
        std::string m_title;
        uint32_t m_width;
        uint32_t m_height;
        SDL_Window* m_window;
        SDL_GLContext m_glContext;
        uint32_t m_framesPerSecond;
        uint32_t m_timePerFrame;
};

#endif //__GAME_H_
