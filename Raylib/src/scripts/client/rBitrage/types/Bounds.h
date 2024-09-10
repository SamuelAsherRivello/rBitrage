
#pragma once
#include <raylib.h>
#include <raymath.h>

namespace RMC::rBitrage 
{
    /*
        This is the world-relative size, and the actor-relative pivot and center.

        REMEMBER: If you want to get global pivot or global center you have to add the Actor.GetPosition()
    */
    class Bounds
    {
        public:

            // Make Actor a friend so it can access private methods
            friend class Actor;
        
            Bounds() : 
                _size({1,1,1}), // will be set by actor-child to match asset (sprite/model)
                _center({0.5, 0.5, 0.5 }),
                _pivot({0.5, 0.5, 0.5}) //center (good default for 3d. For 2d?)
            {
            
            }


            Bounds(Vector3 size, Vector3 pivot)
            {
                this->SetSize(size);
                this->_pivot = pivot; 
            }


            Vector3 GetMin()
            {
                return {_center.x - (_size.x / 2), _center.y - (_size.y / 2), _center.z - (_size.z / 2)};
            }

            Vector3 GetMax()
            {
                return {_center.x + (_size.x / 2), _center.y + (_size.y / 2), _center.z + (_size.z /2 )};
            }
            

            Rectangle ToRectangleAtCenter() 
            {
                return {_center.x, _center.y, _size.x, _size.y};
            }


            // Pivot 
            Vector3 GetPivot() const { return _pivot; }
            void SetPivot(Vector3 pivot) { this->_pivot = pivot; }
            void SetPivotAtCenter() { this->_pivot = this->_center; }

            // Center 
            Vector3 GetCenter() const { return _center; }

            // Size 
            Vector3 GetSize() const { return _size; }

        
        protected:
            // Size - Subclass will set this to match asset (sprite/model)
            void SetSize(Vector3 size) 
            { 
                this->_size = size; 
                this->_center = Vector3Multiply(this->_size, {0.5f, 0.5f, 0.5f});
            }

        private:

            Vector3 _pivot;
            Vector3 _center;
            Vector3 _size;

    };
}