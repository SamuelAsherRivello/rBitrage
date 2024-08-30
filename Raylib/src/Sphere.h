#pragma once
#include <raylib.h>
#include "Actor.h"


class Sphere : public Actor
{
public:
    Sphere(Game& game);
    ~Sphere(); 
    void OnFixedUpdate(float fixedDeltaTime) override;
    void OnFrameUpdate(float deltaTime) override;
    void OnFrameRender(const FrameRenderLayer& frameRenderLayer) override;
 

private:
    int _speed;
};

