#pragma once
#include "client/rBitrage/actors/Actor3D.h"



namespace RMC::rBitrage 
{
    // NEEDED? Forward declaration of Game class
    class Game;

    class Model3D : public Actor3D
    {
    public:
        Model3D(Game& game, std::unique_ptr<ModelData3D>);
        virtual ~Model3D();

        virtual void OnFrameUpdate(float deltaTime) override;
        virtual void OnFrameRender(const FrameRenderLayer &frameRenderLayer) override;

    protected:
        ModelData3D* _modelData3D;
        Model _model; //pointers????
        Texture2D _texture2D;
    };

}