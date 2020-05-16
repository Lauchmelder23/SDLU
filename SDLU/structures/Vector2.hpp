/**
 * @file Vector2.hpp
 * @brief Provides a structure for simple vector calculations
 * @author Lauchmelder23
 * @date 16.05.2020
 */
#pragma once
#include <type_traits>

namespace sdlu
{
    /**
     * A struct to handle basic 2D vector operations.
     *
     * @tparam T The (arithmetical) type of the vector components
     */
    template<
        typename T,
        typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type
    > struct Vector2
    {
        T x; ///< x component
        T y; ///< y component

        //################## CONSTRUCTORS ##################//

        /// Initializes a zero vector
        Vector2() :
            x(0), y(0)
        { 
            // Empty
        }

        /// Initializes a vector with default values
        Vector2(T x, T y) :
            x(x), y(y)
        {
            // Empty
        }

        /// Copies the components of a vector
        Vector2(const Vector2<T>& other) :
            x(other.x), y(other.y)
        {
            // Empty
        }


        //################## OPERATORS ##################//

        friend Vector2<T> operator-(const Vector2<T>& right)
        {
            return Vector2<T>(-right.x, -right.y);
        }

        friend Vector2<T> operator+(const Vector2<T>& left, const Vector2<T>& right)
        {
            return Vector2<T>(left.x + right.x, left.y + right.y);
        }

        friend Vector2<T> operator-(const Vector2<T>& left, const Vector2<T>& right)
        {
            return left + (-right)
        }

        friend Vector2<T> operator*(const Vector2<T>& left, const Vector2<T>& right)
        {
            return Vector2<T>(left.x * right.x, left.y * right.y);
        }

        friend Vector2<T> operator/(const Vector2<T>& left, const Vector2<T>& right)
        {
            return Vector2<T>(left.x / right.x, left.y / right.y);
        }

        friend Vector2<T> operator*(T left, const Vector2<T>& right)
        {
            return Vector2<T>(left * right.x, left * right.y);
        }

        friend Vector2<T> operator*(const Vector2<T>& left, T right)
        {
            return right * left;
        }

        friend Vector2<T> operator/(const Vector2<T>& left, T right)
        {
            return Vector2<T>(left.x / right, left.y / right);
        }

        friend Vector2<T>& operator+=(Vector2<T>& left, const Vector2<T>& right)
        {
            left.x += right.x;
            left.y += right.y;
            return left;
        }

        friend Vector2<T>& operator-=(Vector2<T>& left, const Vector2<T>& right)
        {
            left += (-right);
            return left;
        }

        friend Vector2<T>& operator*=(Vector2<T>& left, const Vector2<T>& right)
        {
            left.x *= right.x;
            left.y *= right.y;
            return left;
        }

        friend Vector2<T>& operator/(Vector2<T>& left, const Vector2<T>& right)
        {
            left.x /= right.x;
            left.y /= right.y;
            return left;
        }

        friend Vector2<T>& operator*=(Vector2<T>& left, T right)
        {
            left.x *= right;
            left.y *= right;
            return left;
        }

        friend Vector2<T>& operator/=(Vector2<T>& left, T right)
        {
            left.x /= right;
            left.y /= right;
            return left;
        }

        friend bool operator==(const Vector2<T>& left, const Vector2<T>& right)
        {
            return ((left.x == right.x) && (left.y == right.y));
        }

        friend bool operator!=(const Vector2<T>& left, const Vector2<T>& right)
        {
            return !(left == right);
        }
    };


    

    //################## TYPEDEFS ##################//

    typedef Vector2<unsigned int>   Vector2u, Vec2u;
    typedef Vector2<int>            Vector2i, Vec2i;
    typedef Vector2<float>          Vector2f, Vec2f;
    typedef Vector2<double>         Vector2d, Vec2d;
}