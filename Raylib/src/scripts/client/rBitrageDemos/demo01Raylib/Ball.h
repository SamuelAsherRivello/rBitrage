#pragma once
#include <raylib.h>

namespace RMC 
{

    class Ball 
    {

        public:

            Ball(const char* assetPath, Vector2 position, Vector2 velocity, float radius);
            

            void SetPosition(Vector2 position);
            Vector2 GetPosition();
            

            void FrameUpdate(float deltaTime);
            void FrameRender();
   

        private:


            const char* _assetPath;
            Vector2 _position;
            Vector2 _velocity;
            float _radius;
            Texture _texture;


    };
    
}