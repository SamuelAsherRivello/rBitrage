// src/Action.h

#pragma once
#include <functional>
#include "raylib.h"
#include <vector>

enum class ActionType 
{
    IsPressed,
    IsDown,
};
    
class Action {
public:
    void AddBinding(ActionType actionType, std::function<bool()> binding);
    bool IsPressed() const;
    bool IsDown() const;

private:
    std::unordered_map<ActionType, std::vector<std::function<bool()>>> bindings;
};