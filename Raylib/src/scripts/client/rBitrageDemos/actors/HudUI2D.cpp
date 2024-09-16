#include "client/rBitrageDemos/actors/HudUI2D.h"
#include "HudUI2D.h"

namespace RMC::rBitrage 
{

    HudUI2D::HudUI2D(Game& game) : Actor2D(game, "", FrameRenderLayer::PostCamera) 
    { 
        //TODO: Set hudUi2d as a 'friend' in bounds so I can call this?/
        //GetBounds().SetSize({game.screen.GetSize().x, game.screen.GetSize().y, 0});
 
        SetPosition({game.screen.GetSize().x/2, game.screen.GetSize().y/2, 0});
    }

    HudUI2D::~HudUI2D()
    {
    }

    void HudUI2D::OnFrameRender(const FrameRenderLayer& frameRenderLayer)
    {
        Actor2D::OnFrameRender(frameRenderLayer);

        const int MAGIC = _game.screen.GetSize().x / 40; //TODO: rethink

        int margin = MAGIC;
        int leftX = margin;
        int topY = margin;
        int rightX = _game.screen.GetSize().x - margin;
        int bottomY = _game.screen.GetSize().y - margin;
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
