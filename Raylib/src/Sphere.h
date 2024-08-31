#pragma once
#include <raylib.h>
#include "Actor.h"


class Sphere : public Actor
{
public:

    //
    Sphere(Game& game);
    ~Sphere(); 

    //
    void OnFixedUpdate(float fixedDeltaTime) override;
    void OnFrameUpdate(float deltaTime) override;
    void OnFrameRender() override;

    //
    Vector3 GetVelocity() const;
    void SetVelocity(const Vector3& velocity);

private:
    Vector3 _velocity; 
};

