/**
 * @file Vector2.hpp
 * @brief Provides a structure for simple vector calculations
 * @author Lauchmelder23
 * @date 16.05.2020
 */

#include <type_traits>

namespace sdlu
{
    template<
        typename T,
        typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type
    > struct Vector2
    {
        T x; ///< x component
        T y; ///< y component

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
    };

    typedef Vector2<unsigned int>   Vector2u, Vec2u;
    typedef Vector2<int>            Vector2i, Vec2i;
    typedef Vector2<float>          Vector2f, Vec2f;
    typedef Vector2<double>         Vector2d, Vec2d;
}