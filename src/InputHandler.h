#ifndef __INPUTHANDLER_H_
#define __INPUTHANDLER_H_

#include <vector>
#include <cstdint>
#include <memory>

#include "commands/Command.h"

class IKeyboardHandler
{
    public:
        virtual void OnKeyDown(uint8_t keyCode) = 0;
        virtual void OnKeyUp(uint8_t keyCode) = 0;
};

// IMouseHandler
// IGamepadHandler
// IJostickHandler

enum Button
{
    BUTTON_A = 'a',
    BUTTON_D = 'd',
    BUTTON_W = 'w',
    BUTTON_S = 's',
    BUTTON_SPACE = ' '
};

typedef Command* CommandPtr;
typedef std::vector<CommandPtr> CommandList;

class InputHandler : public IKeyboardHandler
{
    public:
        InputHandler();
        virtual ~InputHandler();

        //
        // Keyboard handler
        //
        virtual void OnKeyDown(uint8_t keyCode) override;
        virtual void OnKeyUp(uint8_t keyCode) override;

        void AddCommand(uint8_t keyCode, CommandPtr command);
        void RemoveCommand(uint8_t keyCode);
        CommandPtr GetCommand(Button button);
        bool IsPressed(Button button);
        void FetchCommands(CommandList& commandList);
        CommandPtr GetIdleCommand();

    private:
        static const int NUM_KEYS = 256;

        bool m_bIsPressed[NUM_KEYS];
        CommandPtr m_commands[NUM_KEYS];
        CommandPtr m_idleCommand;
};

typedef std::shared_ptr<InputHandler> InputHandlerPtr;

#endif //__INPUTHANDLER_H_
