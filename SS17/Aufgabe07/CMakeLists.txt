cmake_minimum_required(VERSION 3.8)
project(Aufgabe07)

set(CMAKE_CXX_STANDARD 11)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

set(SOURCE_FILES main.cpp Mainframe.h Mainframe.cpp Canvas.h Canvas.cpp)
# Find the Qt libraries
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)

add_executable(Aufgabe07 ${SOURCE_FILES})
# Use the Qt modules from Qt5
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Widgets Qt5::Gui)