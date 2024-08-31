
#pragma once
#include <raylib.h>
#include "Game.h"
#include "FrameRenderLayer.h"

class Transformation
{
    public:
        //This is euler
        Vector3 Rotation = {0, 0, 0};
        Vector3 Position = {0, 0, 0}; 
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
    virtual void OnFrameRender();

    Vector3 GetPosition() const;
    void SetPosition(const Vector3& position);
    Vector3 GetRotation() const;
    void SetRotation(const Vector3 &position);
    //
    Vector3 GetSize() const;
    void SetSize(const Vector3 &size);
    //
    Rectangle GetBounds() const;
    FrameRenderLayer GetFrameRenderLayer() const;

protected:
    const char *_fileName;
    FrameRenderLayer _frameRenderLayer;
    Game& _game;
    Texture2D _texture; 
    Transformation _transformation;
    Vector3 _size;
};