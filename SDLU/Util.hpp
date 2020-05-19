/**
 * @file Util.hpp
 * @brief Basic utility macros, typedefs...
 * @author Lauchmelder23
 * @date 16.05.2020
 */
#pragma once
#include <cstdint>

#define PI 3.1415926f

#define IS_NULLPTR( x ) (x == nullptr)

#define RETURN_IF_NULLPTR( x, ... ) { if(IS_NULLPTR(x)) return __VA_ARGS__; }
#define RETURN_IF_NOT_NULLPTR( x, ... ) { if(!IS_NULLPTR(x)) return __VA_ARGS__; }

typedef uint8_t Uint8;
typedef int8_t  Int8;

typedef uint16_t Uint16;
typedef int16_t  Int16;

typedef uint32_t Uint32;
typedef int32_t  Int32;

typedef uint64_t Uint64;
typedef int64_t  Int64;