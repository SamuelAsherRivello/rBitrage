#include "client/rBitrageDemos/actors/HudUI2D.h"

namespace RMC::rBitrage 
{

    HudUI2D::HudUI2D(Game& game) : Actor2D(game, "", FrameRenderLayer::PostCamera) 
    { 
        SetSize({game.screen.size.x, game.screen.size.y, 0});
        SetPosition({game.screen.size.x/2, game.screen.size.y/2, 0});
    }

    HudUI2D::~HudUI2D()
    {
    }

    void HudUI2D::OnFrameRender()
    {
        Actor2D::OnFrameRender();

        const int MAGIC = _game.screen.size.x / 40; //TODO: rethink

        int margin = MAGIC;
        int leftX = margin;
        int topY = margin;
        int rightX = _game.screen.size.x - margin;
        int bottomY = _game.screen.size.y - margin;
        Color fontColor = WHITE;
        int fontSize = MAGIC;

        //Upper left
        DrawText(_textUpperLeft, leftX, topY, fontSize, fontColor);

        //Upper Right
        int upperRightWidth = MeasureText(_textUpperRight, fontSize);
        DrawText(_textUpperRight, rightX - upperRightWidth, topY, fontSize, fontColor);

        //Lower Left
        DrawText(_textLowerLeft, leftX, bottomY - margin, fontSize, fontColor);

        //Lower Right
        int lowerRightWidth = MeasureText(_textLowerRight, fontSize);
        DrawText(_textLowerRight, rightX - lowerRightWidth, bottomY - margin, fontSize, fontColor);

    }

    void HudUI2D::SetTextUpperLeft(const char* text)
    {
        if (text != nullptr && strlen(text) > 0)
        {
            _textUpperLeft = text;
        }
    }
    void HudUI2D::SetTextUpperRight(const char* text)
    {
        if (text != nullptr && strlen(text) > 0)
        {
            _textUpperRight = text;
        }
    }

    void HudUI2D::SetTextLowerLeft(const char* text)
    {
        if (text != nullptr && strlen(text) > 0)
        {
            _textLowerLeft = text;
        }
    }

    void HudUI2D::SetTextLowerRight(const char* text)
    {
        if (text != nullptr && strlen(text) > 0)
        {
            _textLowerRight = text;
        }
    }
}
