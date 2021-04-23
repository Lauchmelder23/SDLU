# SDL Utility
A wrapper for SDL2 to make development on quick, simple graphics applications easier.

## Important
I abandoned this project a year ago and picked up development recently. 
I am very unhappy with how I set up this project back then and gained a lot of experience in the meantime,
so I decided to restructure this repo. In case you're using this, or plan on using this you might wanna
watch out for possible major changes in the near future.

![Build (Ubuntu)](https://github.com/Lauchmelder23/SDLU/workflows/Build%20(Ubuntu)/badge.svg)

**This branch is not the final version yet. This version is missing a lot of the features planned for this library**

You should definitely check out my other SDL-related project called [SDL Framework](https://github.com/Lauchmelder23/SDLFramework). It does not use this wrapper library but it sets up some interfaces you can derive from to have a fully-functional and fully-customizable SDL MessageLoop with no effort!

## Motivation
While SDL2 is a great library to handle graphics and audio, it can be laborious to get a quick program up and running. SDLU tries to solve that by implementing objects that sit on top of native SDL2 functions and act as a sort of API between your program and SDL2. However it still allows the user to access SDL2 objects like `SDL_Window` and use them in native SDL2 functions. SDLU also contains primitive shapes that can be quickly set up and rendered onto the screen.

This library aims to minimize the work needed to setup a simple project.

## How to compile
Note: Under Linux, it might be necessary to install `libdbus-1-dev` in order for SDL2 to build successfully.

1. Clone the development branch `git clone -b development https://github.com/Lauchmelder23/SDLU`
2. Clone the submodules `git submodule update --init`
3. Create a build directory and enter it `mkdir build`, `cd build`
4. Run `cmake-gui ..` or `ccmake ..`
5. Configure CMake and enable `ENABLE_EXAMPLE`
6. Click Generate
7. Type `make`

## Documentation
The source code is annotated with doxygen comments. Simply run doxygen on the SDLU directory to generate the documentation for this library. An example project can also be built (Set the `ENABLE_EXAMPLE` flag in CMake), which implements a simple program using the SDLU library.
