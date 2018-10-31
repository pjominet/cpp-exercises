cmake_minimum_required(VERSION 3.7)
project(Aufgabe05)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(Aufgabe05 ${SOURCE_FILES})

add_custom_command(
        TARGET Aufgabe05
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_CURRENT_SOURCE_DIR}/data/data.txt"
        "$<TARGET_FILE_DIR:Aufgabe05>/data.txt"
)
