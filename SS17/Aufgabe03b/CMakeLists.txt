cmake_minimum_required(VERSION 3.6)
project(Practice)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Student.cpp Mitarbeiter.cpp Professor.cpp Person.cpp)
add_executable(Practice ${SOURCE_FILES})