/**
 * @file Transformable.hpp
 * @brief Contains information for transformable objects
 * @author Lauchmelder23
 * @date 23.05.2020
 */
#pragma once

#include "structures/Vector2.hpp"

SDLU_BEGIN
/**
    * @brief A class that stores locational information
    *
    * Stores position, rotation, scale and the origin of an
    * object, and provides functions to get/set those values.
    * "Origin" is the offset between the position and the top-left
    * corner of the object.
    */
class Transformable
{
public:
    /**
        * @brief Default constructur
        */
    Transformable();

    /**
        * @brief Deconstructor
        */
    virtual ~Transformable();

    /**
        * @brief Returns the position of the object
        *
        * @return A 2D vector of the position
        */
    Vector2f GetPosition();

    /**
        * @brief Sets a new position
        * 
        * @param[in] position A 2D vector with the new position
        */
    void SetPosition(const Vector2f& position);

    /**
        * @brief Sets a new position
        * 
        * @param[in] x The new x position
        * @param[in] y The new y position
        */
    void SetPosition(float x, float y);

    /**
        * @brief Adds to the current position
        *
        * @param[in] position A 2D movement vector
        */
    void Move(const Vector2f& position);

    /**
        * @brief Adds to the current position
        *
        * @param[in] x The offset in x direction
        * @param[in] y The offset in y direction
        */
    void Move(float x, float y);


    /**
        * @brief Gets the current local origin
        *
        * @return A 2D vector with the offset
        */
    Vector2f GetOrigin();

    /**
        * @brief Sets a new local origin
        *
        * @param[in] origin A 2D vector with the new origin
        */
    void SetOrigin(const Vector2f& origin);

    /**
        * @brief Sets a new local origin
        *
        * @param[in] x The new x component of the origin
        * @param[in] y The new y component of the origin
        */
    void SetOrigin(float x, float y);

    /**
        * @brief Gets the current scale of the object
        * 
        * @return A 2D vector with the scale in x- and y-direction
        */
    Vector2f GetScale();

    /**
        * @brief Sets a new scale
        *
        * @param[in] scale A 2D vector with the new scale
        */
    void SetScale(const Vector2f& scale);

    /**
        * @brief Sets a new scale
        * 
        * @param[in] x The new scale in x direction
        * @param[in] y The new scale in y direction
        */
    void SetScale(float x, float y);

    /**
        * @brief Scales the object by some amount
        *
        * @param[in] scale The amount to scale by in x- and y-direction
        */
    void Scale(const Vector2f& scale);

    /**
        * @brief Scales the object by some amount
        * 
        * @param[in] x The amount to scale by in x direction
        * @param[in] y The amount to scale by in y direction
        */
    void Scale(float x, float y);

    /**
        * @brief Gets the current rotation
        *
        * @return The rotation in degrees
        */
    float GetRotation();

    /**
        * @brief Sets a new rotation
        *
        * @param[in] angle The new rotation in degrees
        */
    void SetRotation(float angle);

    /**
        * @brief Rotates by some amount
        *
        * @param[in] angle The angle to rotate by in degrees
        */
    void Rotate(float angle);

protected:
    Vector2f position; ///< Position of the object
    Vector2f origin;   ///< Offset of the top-left corner from the position
    Vector2f scale;    ///< Scale of the object
    float rotation;    ///< Rotation of the object (in degrees)
};
SDLU_END