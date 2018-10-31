cmake_minimum_required(VERSION 3.6)
project(CPP_Sitzung9_Aufgaben)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp tagset.cpp tagset.h token.h token.cpp attribute.h attribute.cpp)
add_executable(CPP_Sitzung9_Aufgaben ${SOURCE_FILES})