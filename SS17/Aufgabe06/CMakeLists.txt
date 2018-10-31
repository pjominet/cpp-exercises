cmake_minimum_required(VERSION 3.8)
project(Aufgabe06)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp
        Saint.cpp
        SaintsCalender.cpp
        basic_uitls/fstream_utils/ifstream_utils.h
        basic_uitls/fstream_utils/ifstream_utils.cpp
        basic_uitls/string_utils/string_utils.h
        basic_uitls/string_utils/string_utils.cpp)
add_executable(Aufgabe06 ${SOURCE_FILES})

add_custom_command(TARGET Aufgabe06 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_CURRENT_SOURCE_DIR}/saints.txt"
        "$<TARGET_FILE_DIR:Aufgabe06>/saints.txt")