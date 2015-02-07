#include <elf.h>
#include <stdint-gcc.h>
#include "InputHandler.h"

#include "commands/MoveLeftCommand.h"
#include "commands/MoveRightCommand.h"
#include "commands/MoveUpCommand.h"
#include "commands/MoveDownCommand.h"
#include "commands/DropBombCommand.h"
#include "commands/IdleCommand.h"
#include "Shortcuts.h"
#include <cassert>

InputHandler::InputHandler()
: m_idleCommand(new IdleCommand())
{
    for(int i = 0; i < NUM_KEYS; ++i)
    {
        m_commands[i] = nullptr;
        m_bIsPressed[i] = false;
    }
    // FIXME: (Pavel) This should be added dynamically
    m_commands[BUTTON_A] = new MoveLeftCommand();
    m_commands[BUTTON_D] = new MoveRightCommand();
    m_commands[BUTTON_W] = new MoveUpCommand();
    m_commands[BUTTON_S] = new MoveDownCommand();
    m_commands[BUTTON_SPACE] = new DropBombCommand();
}

InputHandler::~InputHandler()
{
    for(int i = 0; i < NUM_KEYS; ++i)
    {
        SAFE_DELETE(m_commands[i])
    }
}

void InputHandler::OnKeyDown(uint8_t keyCode)
{
    assert(keyCode >= 0 && keyCode < NUM_KEYS);
    m_bIsPressed[keyCode] = true;
}

void InputHandler::OnKeyUp(uint8_t keyCode)
{
    assert(keyCode >= 0 && keyCode < NUM_KEYS);
    m_bIsPressed[keyCode] = false;
}

bool InputHandler::IsPressed(Button button)
{
    assert(button >= 0 && button < NUM_KEYS);
    return m_bIsPressed[button];
}

void InputHandler::FetchCommands(CommandList &commandList)
{
    for(int i = 0; i < NUM_KEYS; ++i)
    {
        if(m_bIsPressed[i] && m_commands[i] != nullptr)
        {
            commandList.push_back(m_commands[i]);
        }
    }
}



void InputHandler::AddCommand(uint8_t keyCode, CommandPtr command)
{
    assert(keyCode >= 0 && keyCode < NUM_KEYS);
    SAFE_DELETE(m_commands[keyCode])
    m_commands[keyCode] = command;
}

void InputHandler::RemoveCommand(uint8_t keyCode)
{
    assert(keyCode >= 0 && keyCode < NUM_KEYS);
    SAFE_DELETE(m_commands[keyCode])
}

CommandPtr InputHandler::GetIdleCommand()
{
    return m_idleCommand;
}

CommandPtr InputHandler::GetCommand(Button button)
{
    return m_commands[button];
}
