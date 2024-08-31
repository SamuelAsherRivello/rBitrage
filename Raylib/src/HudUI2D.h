#pragma once
#include "FrameRenderLayer.h"
#include "HudUI2D.h"
#include "Game.h"
#include "Actor2D.h"

namespace RMC::rBitrage 
{
    class HudUI2D : public Actor2D
    {
    public:
        HudUI2D(Game& game);
        ~HudUI2D(); 
        void OnFrameRender() override;

    private:
    };
}

