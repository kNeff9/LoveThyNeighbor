cmake_minimum_required(VERSION 3.2...3.5) # Made compatibility up to 3.5
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Project2)

## If you want to link SFML statically
# set(SFML_STATIC_LIBRARIES TRUE)

## In most cases better set in the CMake cache
set(SFML_DIR "C:/Users/kevin/SFML/SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit/SFML-2.5.1/lib/cmake/SFML")

find_package(SFML 2.5.1 COMPONENTS system window graphics audio REQUIRED)
add_executable(Project2 main.cpp
        Objects/Node.h
        Objects/Node.cpp
        Objects/Network.h
        Objects/PersonData.h
        Objects/Network.cpp
        Objects/ButtonInterface.h)
target_link_libraries(Project2 sfml-system sfml-window sfml-graphics sfml-audio)
