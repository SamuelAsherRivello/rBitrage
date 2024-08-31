#include <raylib.h>
#include "InputSystem.h"
#include "Game.h"

namespace RMC::rBitrage 
{
    InputSystem::InputSystem(Game& game) : System(game)
    {
    }

    void InputSystem::OnInitialize()
    {
       
    }

    void InputSystem::AddAction(const std::string& name, const Action& action)
    {
        actions[name] = action;
    }

    bool InputSystem::IsActionPressed(const std::string& actionName) const
    {
        auto it = actions.find(actionName);
        return it != actions.end() && it->second.IsPressed();
    }

    bool InputSystem::IsActionDown(const std::string& actionName) const
    {
        auto it = actions.find(actionName);
        return it != actions.end() && it->second.IsDown();
    }

    void InputSystem::OnFrameUpdate(float deltaTime)
    {
    }

    void InputSystem::OnFrameRender(const FrameRenderLayer& frameRenderLayer)
    {
    }
}
