cmake_minimum_required(VERSION 3.25)
project(mission)

set(CMAKE_CXX_STANDARD 17)

add_executable(mission main.cpp include/Character.h include/Mission.h include/Planet.h include/Spaceship.h src/Character.cpp src/Mission.cpp src/Planet.cpp src/Spaceship.cpp src/Controller.cpp include/Controller.h)
