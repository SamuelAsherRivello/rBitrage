#include <raylib.h>
#include "InputSystem.h"
#include "Game.h"

namespace RMC::ProjectTemplate 
{
    InputSystem::InputSystem(Game& game) : System(game)
    {
    }

    void InputSystem::OnInitialize()
    {
        //UP
        Action upAction;
        //IsDown
        upAction.AddBinding(ActionType::IsPressed, []() { return IsKeyPressed(KEY_W); });
        upAction.AddBinding(ActionType::IsPressed, []() { return IsKeyPressed(KEY_UP); });
        upAction.AddBinding(ActionType::IsPressed, []() { return IsGamepadButtonPressed(0, GAMEPAD_BUTTON_LEFT_FACE_UP); });
        //IsDown
        upAction.AddBinding(ActionType::IsDown, []() { return IsKeyDown(KEY_W); });
        upAction.AddBinding(ActionType::IsDown, []() { return IsKeyDown(KEY_UP); });
        upAction.AddBinding(ActionType::IsDown, []() { return IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_UP); });
        //
        actions["up"] = upAction; 

        //Down
        Action downAction;
        //IsDown
        downAction.AddBinding(ActionType::IsPressed, []() { return IsKeyPressed(KEY_S); });
        downAction.AddBinding(ActionType::IsPressed, []() { return IsKeyPressed(KEY_DOWN); });
        downAction.AddBinding(ActionType::IsPressed, []() { return IsGamepadButtonPressed(0, GAMEPAD_BUTTON_LEFT_FACE_DOWN); });
        //IsDown
        downAction.AddBinding(ActionType::IsDown, []() { return IsKeyDown(KEY_S); });
        downAction.AddBinding(ActionType::IsDown, []() { return IsKeyDown(KEY_DOWN); });
        downAction.AddBinding(ActionType::IsDown, []() { return IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_DOWN); });
        //
        actions["down"] = downAction; 

        //Left
        Action leftAction;
        //IsDown
        leftAction.AddBinding(ActionType::IsPressed, []() { return IsKeyPressed(KEY_A); });
        leftAction.AddBinding(ActionType::IsPressed, []() { return IsKeyPressed(KEY_LEFT); });
        leftAction.AddBinding(ActionType::IsPressed, []() { return IsGamepadButtonPressed(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT); });
        //IsDown
        leftAction.AddBinding(ActionType::IsDown, []() { return IsKeyDown(KEY_A); });
        leftAction.AddBinding(ActionType::IsDown, []() { return IsKeyDown(KEY_LEFT); });
        leftAction.AddBinding(ActionType::IsDown, []() { return IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT); });
        //
        actions["left"] = leftAction; 

        //Right
        Action rightAction;
        //IsDown
        rightAction.AddBinding(ActionType::IsPressed, []() { return IsKeyPressed(KEY_D); });
        rightAction.AddBinding(ActionType::IsPressed, []() { return IsKeyPressed(KEY_RIGHT); });
        rightAction.AddBinding(ActionType::IsPressed, []() { return IsGamepadButtonPressed(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT); });
        //IsDown
        rightAction.AddBinding(ActionType::IsDown, []() { return IsKeyDown(KEY_D); });
        rightAction.AddBinding(ActionType::IsDown, []() { return IsKeyDown(KEY_RIGHT); });
        rightAction.AddBinding(ActionType::IsDown, []() { return IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT); });
        //
        actions["right"] = rightAction; 

        //Action
        Action action;
        //IsDown
        action.AddBinding(ActionType::IsPressed, []() { return IsKeyPressed(KEY_ENTER); });
        action.AddBinding(ActionType::IsPressed, []() { return IsKeyPressed(KEY_SPACE); });
        action.AddBinding(ActionType::IsPressed, []() { return IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_FACE_UP); });
        action.AddBinding(ActionType::IsPressed, []() { return IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT); });
        action.AddBinding(ActionType::IsPressed, []() { return IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN); });
        action.AddBinding(ActionType::IsPressed, []() { return IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_FACE_LEFT); });
        //IsDown
        action.AddBinding(ActionType::IsDown, []() { return IsKeyDown(KEY_ENTER); });
        action.AddBinding(ActionType::IsDown, []() { return IsKeyDown(KEY_SPACE); });
        action.AddBinding(ActionType::IsDown, []() { return IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_UP); });
        action.AddBinding(ActionType::IsDown, []() { return IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT); });
        action.AddBinding(ActionType::IsDown, []() { return IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN); });
        action.AddBinding(ActionType::IsDown, []() { return IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_LEFT); });
        //
        actions["action"] = action; 
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
