#pragma once
#include "client/rBitrage/core/Game.h"
#include "client/rBitrage/actors/Actor2D.h"
#include "client/rBitrage/types/FrameRenderLayer.h"
#include <iostream>

namespace RMC::rBitrage 
{
    class HudUI2D : public Actor2D
    {
    public:
        HudUI2D(Game& game, int fontSize);
        ~HudUI2D();
        void OnFrameRender(const FrameRenderLayer &frameRenderLayer) override;


        void SetTextUpperLeft(const char*);
        void SetTextUpperRight(const char*);
        void SetTextLowerLeft(const char*);
        void SetTextLowerRight(const char*);

    private:
        const char* _textUpperLeft = "";
        const char* _textUpperRight = "";
        const char* _textLowerLeft = "";
        const char* _textLowerRight = "";
        int _fontSize;
    };
}

