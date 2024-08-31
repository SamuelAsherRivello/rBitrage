
#pragma once
#include <raylib.h>
#include "Game.h"
#include "FrameRenderLayer.h"
#include "Transform.h"


// NEEDED? Forward declaration of Game class
class Game;

class Actor
{
public:
    Actor(Game& game, const FrameRenderLayer& frameRenderLayer = FrameRenderLayer::Camera);
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
    virtual void SetSize(const Vector3 &size);
    //
    Rectangle GetBounds() const;
    FrameRenderLayer GetFrameRenderLayer() const;

protected:
    FrameRenderLayer _frameRenderLayer;
    Game& _game;
    Transformation _transformation;
    Vector3 _size;
};