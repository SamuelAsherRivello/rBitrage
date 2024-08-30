#include "Ball.h"

namespace RMC 
{

    /**
     * The Ball constructor 
     *
     * @param assetPath  The path to the ball's asset.
     * @param position   The initial position of the ball.
     * @param velocity   The initial velocity of the ball.
     * @param radius     The radius of the ball.
     */
    Ball::Ball( const char* assetPath, Vector2 position, Vector2 velocity, float radius) : 
        _assetPath(assetPath), 
        _position(position), 
        _velocity(velocity), 
        _radius(radius)
    {
        _texture = LoadTexture(_assetPath);
    }


    /**
     * Sets the position of the ball.
     *
     * @param position The new position of the ball.
     */
    void Ball::SetPosition(Vector2 position)
    {
        _position = position;
    }


    /**
     * Gets the current position of the ball.
     *
     * @return The current position of the ball.
     */
    Vector2 Ball::GetPosition()
    {
        return _position;
    }


    /**
     * Updates the ball's position based on its velocity and a given time delta (time elapsed since the last update).
     *
     * @param deltaTime The time elapsed since the last update.
     */
    void Ball::FrameUpdate(float deltaTime)
    {
        // Move
        _position.x += _velocity.x * deltaTime;
        _position.y += _velocity.y * deltaTime;

        // Check bounds
        if (_position.x <= 0 || _position.x + _texture.width >= GetScreenWidth()) 
        {
            _velocity.x *= -1;
        }
        if (_position.y <= 0 || _position.y + _texture.height >= GetScreenHeight()) 
        {
            _velocity.y *= -1;
        }
    }


    /**
     * Renders the ball at its current position.
     */
    void Ball::FrameRender()
    {
        DrawTexturePro
        (
            _texture, 
            {0, 0, (float) _texture.width, (float) _texture.height},
            {_position.x, _position.y, (float) _texture.width, (float) _texture.height},
            {0, 0},
            0,
            WHITE
        );
    }
}