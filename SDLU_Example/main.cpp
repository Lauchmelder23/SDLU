#include "header.hpp"

#include <iostream>

int main(int argc, char** argv)
{
    sdlu::Vector2f vec(.4f, -2.3f);
    std::cout << "Vector2f: " << vec.x << ", " << vec.y << std::endl;

    return 0;
}