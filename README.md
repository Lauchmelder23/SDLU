# SDL Utility
A wrapper for SDL2 to make development on quick, simple graphics applications easier.

**This branch is not the final version yet. This version is missing a lot of the features planned for this library**

![C/C++ CI](https://github.com/Lauchmelder23/SDLU/workflows/C/C++%20CI/badge.svg?branch=development)

## How to compile
1. Clone the development branch `git clone -b development https://github.com/Lauchmelder23/SDLU`
2. Clone the submodules `git submodule update --init`
3. Create a build directory and enter it `mkdir build`, `cd build`
4. Run `ccmake ..` (Install ccmake via `sudo apt install cmake-curses-gui`)
5. Configure CMake and enable `ENABLE_EXAMPLE`
6. Click Generate
7. Exit ccmake and type `make`
