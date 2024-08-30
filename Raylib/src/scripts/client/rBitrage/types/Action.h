#pragma once
#include <functional>
#include <raylib.h>
#include <vector>

namespace RMC::rBitrage 
{
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


    void Action::AddBinding(ActionType actionType, std::function<bool()> binding) 
    {
        if (binding != nullptr) 
        {
            bindings[actionType].emplace_back(binding);
        }
    }


    bool Action::IsPressed() const 
    {
        for (const auto& binding : bindings.at(ActionType::IsPressed)) 
        {
            if (binding()) { // Call the function using its operator()
                return true;
            }
        }
        return false;
    }

    bool Action::IsDown() const {
        for (const auto& binding : bindings.at(ActionType::IsDown)) 
        {
            if (binding()) 
            { // Call the function using its operator()
                return true;
            }
        }
        return false;
    }
    
}