#pragma once
#include "FrameRenderLayer.h"
#include "HudUI.h"
#include "Game.h"


class HudUI : public Actor
{
public:
    HudUI(Game& game);
    ~HudUI(); 
    void OnFrameRender() override;

private:
};

