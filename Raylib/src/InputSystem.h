#pragma once

#include <raylib.h>
#include "Game.h"
#include <unordered_map>
#include <string>
#include "Action.h"
#include "FrameRenderLayer.h"

namespace RMC::ProjectTemplate 
{
    class InputSystem : public System 
    {
        public:
            InputSystem(Game& game);
            void AddAction(const std::string& name, const Action& action);
            bool IsActionPressed(const std::string& actionName) const;
            bool IsActionDown(const std::string &actionName) const;

        protected:
            void OnInitialize() override;
            void OnFrameUpdate(float deltaTime) override;
            void OnFrameRender(const FrameRenderLayer& frameRenderLayer) override;

        private:
            std::unordered_map<std::string, Action> actions;
    };
}