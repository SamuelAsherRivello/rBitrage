
#pragma once
#include <raylib.h>
#include "Actor.h"
#include "Game.h"
#include "FrameRenderLayer.h"
#include "Transform.h"

// NEEDED? Forward declaration of Game class
class Game;

class Actor2D : public Actor
{
public:
    Actor2D(Game& game, const char *fileName, const FrameRenderLayer& frameRenderLayer = FrameRenderLayer::Camera);
    virtual ~Actor2D();

    virtual void OnInitialize();
    virtual void OnFixedUpdate(float fixedDeltaTime);
    virtual void OnFrameUpdate(float deltaTime);
    virtual void OnFrameRender();
    void SetSize(const Vector3 &size) override;

protected:
    const char *_fileName;
    Texture2D _texture; 
};