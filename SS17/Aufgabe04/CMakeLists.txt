cmake_minimum_required(VERSION 3.8)
project(Aufgabe04)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Currency.cpp CurrencyTable.cpp)
add_executable(Aufgabe04 ${SOURCE_FILES})

add_custom_command(
        TARGET Aufgabe04
        POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy
                "${CMAKE_CURRENT_SOURCE_DIR}/data/currencies.txt"
                "$<TARGET_FILE_DIR:Aufgabe04>/currencies.txt"
)