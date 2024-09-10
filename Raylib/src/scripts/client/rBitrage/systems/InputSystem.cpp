#include <raylib.h>
#include "client/rBitrage/systems/InputSystem.h"

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
        if (it == actions.end()) 
        {
            std::cout << "ERROR: InputSystem failed. No action is registered for " + actionName << "." << std::endl;
            return false;
        }

        try 
        {
            return it->second.IsPressed();
        } catch (const std::exception& e) {
            std::cout << "ERROR: InputSystem failed. Action of " + actionName << " has no " << "IsPressed()" << "." << std::endl;
            return false;
        }
    }

    bool InputSystem::IsActionDown(const std::string& actionName) const
    {
        auto it = actions.find(actionName);
        if (it == actions.end()) 
        {
            std::cout << "ERROR: InputSystem failed. No action is registered for " + actionName << "." << std::endl;
            return false;
        }
        
        try 
        {
            return it->second.IsDown();
        } catch (const std::exception& e) {
            std::cout << "ERROR: InputSystem failed. Action of " + actionName << " has no " << "IsDown()" << "." << std::endl;
            return false;
        }
    }

    void InputSystem::OnFrameUpdate(float deltaTime)
    {
    }

    void InputSystem::OnFrameRender(const FrameRenderLayer& frameRenderLayer)
    {
    }
}
