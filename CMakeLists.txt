cmake_minimum_required(VERSION 3.10) # Made compatibility up to 3.5
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)

project(Project2)

## If you want to link SFML statically
# set(SFML_STATIC_LIBRARIES TRUE)

## In most cases better set in the CMake cache
include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.5.1
        GIT_SHALLOW ON
        )
FetchContent_MakeAvailable(SFML)

#find_package(SFML 3 COMPONENTS system window graphics audio REQUIRED)

add_executable(Project2 main.cpp
        Objects/Node.h
        Objects/Node.cpp
        Objects/Network.h
        Objects/PersonData.h
        Objects/Network.cpp
        Objects/Country.h
        Objects/CountryInterface.h
        Objects/CountryInterface.cpp
        Objects/NeighborhoodInterface.h
        Objects/NeighborhoodInterface.cpp
        Objects/BFS.h
        Objects/BFS.cpp)
target_link_libraries(Project2 sfml-system sfml-window sfml-graphics)
