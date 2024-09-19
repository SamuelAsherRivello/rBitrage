
#pragma once
#include <raylib.h>
#include <raymath.h>
#include <iostream>

namespace RMC::rBitrage 
{
    /*
        This is the world-relative size, and the actor-relative pivot and center.

        REMEMBER: If you want to get global pivot or global center you have to add the Actor.GetPosition()
    */
    class Bounds
    {
        public:

            // TODO: Find a better way to give ALL subclasses of actor a friend
            // Make Actor a friend so it can access private methods
            friend class Actor;
            friend class Sprite2D;
            friend class Shape2D;
            friend class Shape3D;
        
            Bounds() 
            {
            
            }


            //Remove float after migration
            Bounds(Vector3 size, Vector3 center, Vector3 pivot)
            {
                this->_size = size;
                this->_center = center;
                this->_pivot = pivot;
            }


            const Vector3 GetMin()
            {
                return 
                {
                    _center.x - (_size.x / 2),
                    _center.y - (_size.y / 2), 
                    _center.z - (_size.z / 2)
                };
            }

            const Vector3 GetMax()
            {
                return 
                {
                    _center.x + (_size.x / 2) ,
                    _center.y + (_size.y / 2) , 
                    _center.z + (_size.z / 2) ,
                };
            }

            const Rectangle ToRectangle() 
            {
                float minX = GetMin().x;
                float maxX = GetMax().x;
                float minY = GetMin().y;
                float maxY = GetMax().y;

                return {minX, minY, maxX - minX, maxY - minY};
            }
            

            // Pivot 
            Vector3 GetPivot() const { return Vector3(_pivot);; }
            void SetPivot(Vector3 pivot) { this->_pivot = pivot; }

            // Center 
            Vector3 GetCenter() const { return Vector3(_center); }

            // Size 
            Vector3 GetSize() const { return Vector3(_size); } //TODO: do I need to return copy like this?


        
        protected:

            //This is protected and cannot be called from outside the class.
            //Despite what the intellisense says
            //Devs cannot do this from OUTSIDE
            //Only the internals of actor can do it
            void SetSize(Vector3& size) 
            { 
                this->_size = size; 
                this->_center = Vector3Multiply(this->_size, {0.5f, 0.5f, 0.5f});
            }

        private:

            Vector3 _pivot = {0.5f, 0.5f, 0.5f}; //Normalized in unscaled bounds. In Middle by default
            Vector3 _center = {0.5f, 0.5f, 0.5f}; //Normalized in unscaled bounds. In Middle by default
            Vector3 _size = {1,1,1}; //1 is the default size.

    };
}