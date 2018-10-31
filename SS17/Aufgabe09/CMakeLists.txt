cmake_minimum_required(VERSION 3.8)
project(Aufgabe09)

set(CMAKE_CXX_STANDARD 11)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

set(SOURCE_FILES main.cpp Mainframe.h Mainframe.cpp Canvas.h Canvas.cpp Ball.cpp Ball.h utils/VectorQuantity.cpp utils/VectorQuantity.h)
# Find the Qt libraries
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)

# Run program as Window Application based on OS
IF(WIN32)
    SET(GUI_TYPE WIN32)
ENDIF(WIN32)
IF (APPLE)
    SET(GUI_TYPE MACOSX_BUNDLE)
ENDIF (APPLE)

add_executable(${PROJECT_NAME} ${GUI_TYPE} ${SOURCE_FILES})
# Use the Qt modules from Qt5
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Widgets Qt5::Gui)
