# CPPND: Capstone Project (Option 1)

This is a Capstone project for the [Udacity C++ Nanodegree Programme](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). It creates the beginnings of a point and click game.

<img src="snake_game.gif"/>

The Capstone Project was a chance to integrate some of the principles I learned throughout the Nanodegree Programme. 


## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2, SDL2_image, SDL2_ttf >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

If using a Udacity Workspace to run the project, most dependencies are already installed, simply run the following commands to install SDL2_image and SDL2_ttf:
`sudo apt-get install libsdl2-image-dev` and `sudo apt-get install libsdl2-ttf-dev`

## Basic Build Instructions

1. Clone this repo
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./bin/PointAndClickGame`

## Project Overview

The functionality using SDL2 is based on tutorials from [Will Usher] (https://www.willusher.io/pages/sdl2/https://www.willusher.io/pages/sdl2/) and [Lazy Foo] (http://lazyfoo.net/tutorials/SDL/).

## Expected Output

## File Structure
  ```sh

  ```


## 5 Rubric Points

* The project demonstrates an understanding of C++ functions and control structures.
  * main.cpp line 18
* The project accepts user input and processes the input.
  * main.cpp line 88
* The project uses Object Oriented Programming techniques.
  * item.h line 12
* Class constructors utilize member initialization lists.
  * item.h line 15
* Overloaded functions allow the same function to operate on different parameters.
  * picture.h line 15