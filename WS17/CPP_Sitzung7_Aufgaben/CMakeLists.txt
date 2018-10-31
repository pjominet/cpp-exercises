cmake_minimum_required(VERSION 3.6)
project(CPP_Sitzung7_Aufgaben)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(CPP_Sitzung7_Aufgaben ${SOURCE_FILES})

add_custom_command(
        TARGET CPP_Sitzung7_Aufgaben
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        "${CMAKE_CURRENT_SOURCE_DIR}./data.xml"
        "$<TARGET_FILE_DIR:CPP_Sitzung7_Aufgaben>/data.xml"
)