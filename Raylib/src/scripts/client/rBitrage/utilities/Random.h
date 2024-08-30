
#pragma once
#include "client/rBitrage/types/FrameRenderLayer.h"
#include <raylib.h>
#include <raymath.h>
#include <string>
#define ENUM_TO_STRING_CASE(value) case value: return #value;

namespace RMC::rBitrage 
{
    class Random 
    {
        public:

           static void SetRandomSeed(unsigned int seed)
            {
                ::SetRandomSeed(seed);
            }

            static int GetRandomInt(int min, int max)
            {
                return ::GetRandomValue(min, max);
            }

            static float GetRandomFloat(float min, float max)
            {
                return (float)::GetRandomValue(min * INT_TO_FLOAT_FACTOR, max * INT_TO_FLOAT_FACTOR) / INT_TO_FLOAT_FACTOR;
            }

       
            static Vector3 GetRandomVector3(const Vector3 min, const Vector3 max)
            {
                return 
                {
                    GetRandomFloat(min.x, max.x),
                    GetRandomFloat(min.y, max.y),
                    GetRandomFloat(min.z, max.z),

                };
            }

            static Vector2 GetRandomVector3(const Vector2 min, const Vector2 max)
            {
                return 
                {
                    GetRandomFloat(min.x, max.x),
                    GetRandomFloat(min.y, max.y)
                };
            }

        private:
            static float constexpr INT_TO_FLOAT_FACTOR = 1000;
            
    };
}