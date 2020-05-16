#include "header.hpp"

#include <iostream>

int main(int argc, char** argv)
{
    sdlu::Vector2f vecA(.4f, -2.3f);
    sdlu::Vector2f vecB(-8.9f, 0.003f);
    sdlu::Vector2f vec = vecA + vecB;

    std::cout << "Vector2f: " << vec.x << ", " << vec.y << std::endl;

    vec *= 1.8f;
    std::cout << "Vector2f: " << vec.x << ", " << vec.y << std::endl;
    return 0;
}