#pragma once

#include <raylib.h>
#include "client/rBitrage/systems/System.h"
#include "client/rBitrage/types/FrameRenderLayer.h"
#include "client/rBitrage/types/Action.h"
#include <unordered_map>
#include <string>


namespace RMC::rBitrage 
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