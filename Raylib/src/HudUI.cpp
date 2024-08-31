#include "HudUI.h"
#include "Actor.h"
#include <iostream>
#include "FrameRenderLayer.h"

HudUI::HudUI(Game& game) : Actor(game, "", FrameRenderLayer::PostCamera) { 

    SetSize({game.size.x, game.size.y, 0});
    SetPosition({game.size.x/2, game.size.y/2, 0});
}

HudUI::~HudUI()
{
}

void HudUI::OnFrameRender(const FrameRenderLayer& frameRenderLayer)
{
    Actor::OnFrameRender(frameRenderLayer);

    if (_frameRenderLayer != frameRenderLayer)
    {
        return;
    }

   

    int margin = 50;
    int upperLeftX = margin;
    int upperLeftY = margin;
    int upperRightX = _game.size.x - margin - 290;
    int upperRightY = margin;
    Color fontColor = WHITE;
    int fontSize = 59;


    //Upper left
    int score = 100;
    const char* scoreText = TextFormat("Score: %d", score);
    DrawText(scoreText, upperLeftX, upperLeftY, fontSize, fontColor);

    //Upper Right
    int lives = 3;
    const char* livesText = TextFormat("Lives: 00%d", lives);
    DrawText(livesText, upperRightX, upperRightY, fontSize, fontColor);

}
