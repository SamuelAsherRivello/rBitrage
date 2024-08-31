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
    void OnFrameRender() override;
 

private:
    Vector3 _velocityLinear;
    Vector3 _velocityAngular;
    bool _isCollision;
};

