// src/Action.cpp

#include "Action.h"
#include <functional>
namespace RMC::rBitrage 
{
void Action::AddBinding(ActionType actionType, std::function<bool()> binding) {
    if (binding != nullptr) {
        bindings[actionType].emplace_back(binding);
    }
}

bool Action::IsPressed() const {
    for (const auto& binding : bindings.at(ActionType::IsPressed)) {
        if (binding()) { // Call the function using its operator()
            return true;
        }
    }
    return false;
}

bool Action::IsDown() const {
    for (const auto& binding : bindings.at(ActionType::IsDown)) {
        if (binding()) { // Call the function using its operator()
            return true;
        }
    }
    return false;
}
}