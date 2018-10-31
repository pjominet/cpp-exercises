cmake_minimum_required(VERSION 3.6)
project(CPP_Sitzung11_Aufgaben)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp AttributeToken.cpp AttributeToken.h Token.cpp Token.h Element.cpp Element.h)
add_executable(CPP_Sitzung11_Aufgaben ${SOURCE_FILES})