
#pragma once
#include <raylib.h>
#include "Game.h"
#include "FrameRenderLayer.h"

class Transformation
{
    public:
        Vector3 Position; 
        Vector3 Rotation;
};

// NEEDED? Forward declaration of Game class
class Game;

class Actor
{
public:
    Actor(Game& game, const char *fileName, const FrameRenderLayer& frameRenderLayer = FrameRenderLayer::Camera);
    virtual ~Actor();

    virtual void OnInitialize();
    virtual void OnFixedUpdate(float fixedDeltaTime);
    virtual void OnFrameUpdate(float deltaTime);
    virtual void OnFrameRender(const FrameRenderLayer& frameRenderLayer);

    Vector3 GetPosition() const;
    void SetPosition(const Vector3& position);
    //
    Vector3 GetSize() const;
    void SetSize(const Vector3 &size);
    //
    Rectangle GetBounds() const;
    FrameRenderLayer GetFrameRenderLayer() const;

protected:
    Game& _game;
    Transformation _transformation;
    Vector3 _size;
    const char *_fileName;
    FrameRenderLayer _frameRenderLayer;
    Texture2D _texture; 
};