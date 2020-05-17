/**
 * @file Color.hpp
 * @brief Provides utility for creating and handling colors
 * @author Lauchmelder23
 * @date 16.05.2020
 */
#pragma once

#include <Util.hpp>

namespace sdlu
{
    /**
     * @brief A structure holding color data
     *
     * This struct allows for the easy passing of color data between 
     * objects or functions. It holds RGBA values and allows for 
     * arithmetical operations.
     */
    struct Color
    {
        Uint8 r; ///< Red component
        Uint8 g; ///< Green component
        Uint8 b; ///< Blue component
        Uint8 a; ///< Alpha component

        /**
         * @brief Default constructor (Black)
         */
        Color();

        /**
         * @brief Construct color from four 8-Bit integer values
         *
         * @param[in] r Red component
         * @param[in] g Green component
         * @param[in] b Blue component
         * @param[in] a Alpha component
         */
        Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255);

        /**
         * @brief Construct color from a 32-Bit integer value
         *
         * @param[in] color The color data structured as RGBA
         */
        Color(Uint32 color);

        /**
         * @brief Returns color data as a 32-Bit integer
         *
         * @return A 32-Bit containing the RGBA values
         */
        Uint32 ToInt();

        /**
         * @brief Generate color from HSV values
         *
         * @return An RGBA Color object generated from HSV
         */
        static Color& FromHSV(Uint16 h, Uint8 s, Uint8 v);


        /////////////////// DEFAULT COLORS ///////////////////

        static const Color Black;         ///< Default Color Black   (#000000FF)
        static const Color Red;           ///< Default Color Red     (#FF0000FF)
        static const Color Green;         ///< Default Color Green   (#00FF00FF)
        static const Color Blue;          ///< Default Color Blue    (#0000FFFF)
        static const Color Yellow;        ///< Default Color Yellow  (#FFFF00FF)
        static const Color Magenta;       ///< Default Color Magenta (#FF00FFFF)
        static const Color Cyan;          ///< Default Color Cyan    (#00FFFFFF)
        static const Color White;         ///< Default Color White   (#FFFFFFFF)
        
        static const Color Transparent;   ///< Default Color Transparent (#00000000)


        /////////////////// OPERATOR OVERLOADS ///////////////////

        /**
         * @brief Componentwise color addition
         *
         * @param[in] left  Left operand
         * @param[in] right Right operand
         * @return left + right
         */
        friend Color operator+(const Color& left, const Color& right);

        /**
         * @brief Componentwise color subtraction
         *
         * @param[in] left  Left operand
         * @param[in] right Right operand
         * @return left - right
         */
        friend Color operator-(const Color& left, const Color& right);

        /**
         * @brief Componentwise color multiplication
         *
         * @param[in] left  Left operand
         * @param[in] right Right operand
         * @return left * right
         */
        friend Color operator*(const Color& left, const Color& right);

        /**
         * @brief Componentwise color division
         *
         * @param[in] left  Left operand
         * @param[in] right Right operand
         * @return left / right
         */
        friend Color operator/(const Color& left, const Color& right);

        /**
         * @brief Componentwise color addition
         *
         * @param[in] left  Left operand
         * @param[in] right Right operand
         * @return left += right
         */
        friend Color& operator+=(Color& left, const Color& right);

        /**
         * @brief Componentwise color subtraction
         *
         * @param[in] left  Left operand
         * @param[in] right Right operand
         * @return left -= right
         */
        friend Color& operator-=(Color& left, const Color& right);

        /**
         * @brief Componentwise color multiplication
         *
         * @param[in] left  Left operand
         * @param[in] right Right operand
         * @return left *= right
         */
        friend Color& operator*=(Color& left, const Color& right);

        /**
         * @brief Componentwise color division
         *
         * @param[in] left  Left operand
         * @param[in] right Right operand
         * @return left /= right
         */
        friend Color& operator/=(Color& left, const Color& right);

        /**
         * @brief Componentwise color comparison
         *
         * @param[in] left  Left operand
         * @param[in] right Right operand
         * @return True if the respective color components are equal, False if not
         */
        friend bool operator==(const Color& left, const Color& right);

        /**
         * @brief Componentwise color comparison
         *
         * @param[in] left  Left operand
         * @param[in] right Right operand
         * @return False if the respective color components are equal, True if not
         */
        friend bool operator!=(const Color& left, const Color& right);
    };
}