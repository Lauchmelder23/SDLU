# SDL Utility
A wrapper for SDL2 to make development on quick, simple graphics applications easier.

![C/C++ CI](https://github.com/Lauchmelder23/SDLU/workflows/C/C++%20CI/badge.svg?branch=development)

**This branch is not the final version yet. This version is missing a lot of the features planned for this library**

## Motivation
While SDL2 is a great library to handle graphics and audio, it can be laborious to get a quick program up and running. SDLU tries to solve that by implementing objects that sit on top of native SDL2 functions and act as a sort of API between your program and SDL2. However it still allows the user to access SDL2 objects like `SDL_Window` and use them in native SDL2 functions. SDLU also contains primitive shapes that can be quickly set up and rendered onto the screen.

This library aims to minimize the work needed to setup a simple project.

## How to compile
1. Clone the development branch `git clone -b development https://github.com/Lauchmelder23/SDLU`
2. Clone the submodules `git submodule update --init`
3. Create a build directory and enter it `mkdir build`, `cd build`
4. Run `ccmake ..` (Install ccmake via `sudo apt install cmake-curses-gui`)
5. Configure CMake and enable `ENABLE_EXAMPLE`
6. Click Generate
7. Exit ccmake and type `make`

## Documentation
The source code is annotated with doxygen comments. Simply run doxygen on the SDLU directory to generate the documentation for this library. An example project can also be built (Set the `ENABLE_EXAMPLE` flag in CMake), which implements a simple program using the SDLU library.
