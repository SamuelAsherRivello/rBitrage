#pragma once
#include <raylib.h>
#include "Actor.h"

class Cube : public Actor
{
public:
    Cube(Game& game);
    ~Cube(); 
    void OnFixedUpdate(float fixedDeltaTime) override;
    void OnFrameUpdate(float deltaTime) override;
    void OnFrameRender(const FrameRenderLayer& frameRenderLayer) override;
 

private:
    int _speed;
    bool _isCollision;
};

