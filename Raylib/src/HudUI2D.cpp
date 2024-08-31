#include "HudUI2D.h"
#include "Actor2D.h"
#include <iostream>
#include "FrameRenderLayer.h"
HudUI2D::HudUI2D(Game& game) : Actor2D(game, "", FrameRenderLayer::PostCamera) 
{ 
    SetSize({game.size.x, game.size.y, 0});
    SetPosition({game.size.x/2, game.size.y/2, 0});
}

HudUI2D::~HudUI2D()
{
}

void HudUI2D::OnFrameRender()
{
    Actor2D::OnFrameRender();

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
