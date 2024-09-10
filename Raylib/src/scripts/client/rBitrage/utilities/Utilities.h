
#pragma once
#include <raylib.h>
#include <raymath.h>
#include <string>
#include <sstream>
#include <iomanip>  
#include <guiddef.h>
//
#include "client/rBitrage/types/FrameRenderLayer.h"
#include "client/rBitrage/utilities/Random.h"
//
#define ENUM_TO_STRING_CASE(value) case value: return #value;

namespace RMC::rBitrage 
{
    class Utilities 
    {
        public:
        
            static Vector2 ToVector2(const Vector3 vector3)
            {
                return (Vector2){vector3.x, vector3.y};
            }

            static Vector3 ToVector3(const Vector2 vector2)
            {
                return (Vector3){vector2.x, vector2.y, 0};
            }




            static Vector2 ToVector2Normalized(const Vector2 vector2)
            {
                return (Vector2)
                {
                    Normalize(vector2.x, 0, 1),
                    Normalize(vector2.y, 0, 1)
                };
            }

            static Vector3 ToVector3Normalized(const Vector3 vector3)
            {
                return (Vector3)
                {
                    Normalize(vector3.x, 0, 1),
                    Normalize(vector3.y, 0, 1),
                    Normalize(vector3.x, 0, 1)
                };
            }

            static Vector2 ToVector2Average(const Vector2 vector2)
            {
                float average = (vector2.x + vector2.y)/2.0;
                return {average, average};
            }

            static Vector3 ToVector3Average(const Vector3 vector3)
            {
                float average = (vector3.x + vector3.y + vector3.z)/3.0;
                return {average, average, average};
            }


            static float ToFloatNormalized(const float f)
            {
                return Normalize(f, 0, 1);
            }

            static std::string ToString(FrameRenderLayer frameRenderLayer) {
                switch (frameRenderLayer) {
                    ENUM_TO_STRING_CASE(FrameRenderLayer::Camera2D);
                    ENUM_TO_STRING_CASE(FrameRenderLayer::Camera3D);
                    ENUM_TO_STRING_CASE(FrameRenderLayer::PostCamera);
                    ENUM_TO_STRING_CASE(FrameRenderLayer::PreCamera);
                    default: return "Unknown";
                }
            }

            static std::string ToString(float value)
            {
                // Use std::to_string with a cast to double for floating-point values
                return std::to_string((double)value);
            }

            static std::string ToString(Vector2 value)
            {
                return "[Vector2 (" + std::to_string(value.x) + ", " + std::to_string(value.y) + ")]"; 
            }


            static std::string ToString(Vector3 value)
            {
                return "[Vector3 (" + std::to_string(value.x) + ", " + std::to_string(value.y) + ", " + std::to_string(value.z) + ")]"; 
            }


            static std::string ToString(Rectangle value)
            {
                return "[Rectangle (" + std::to_string(value.x) + ", " + std::to_string(value.y) + ", " + std::to_string(value.width) + ", " + std::to_string(value.height) + ")]"; 
            }


            static std::string ToString(GUID value)
            {
                std::stringstream ss;
                ss << "[GUID (" << std::hex << std::uppercase
                   << std::setw(8) << std::setfill('0') << value.Data1 << "-"
                   << std::setw(4) << std::setfill('0') << value.Data2 << "-"
                   << std::setw(4) << std::setfill('0') << value.Data3 << "-"
                   << std::setw(2) << std::setfill('0') << static_cast<int>(value.Data4[0])
                   << std::setw(2) << std::setfill('0') << static_cast<int>(value.Data4[1])
                   << "-";
                for (int i = 2; i < 8; ++i)
                {
                    ss << std::setw(2) << std::setfill('0') << static_cast<int>(value.Data4[i]);
                }
                ss << ")]";
                return ss.str();
            }

            static int ToInt(float value)
            {
                return static_cast<int>(round(value));
            }

            static bool IsNullOrEmpty (const char* value)
            {
                return value == nullptr || value[0] == '\0';
            }

            static bool IsNullOrEmpty (Model& value)
            {
                return value.materials == nullptr || value.meshes == nullptr || value.materialCount == 0 || value.meshCount == 0;
            }


            
    };
}