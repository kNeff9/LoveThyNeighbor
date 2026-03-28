#cmake_minimum_required(VERSION 3.2...3.5) # Made compatibility up to 3.5
#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#
#project(Project2)
#
### If you want to link SFML statically
## set(SFML_STATIC_LIBRARIES TRUE)
#
### In most cases better set in the CMake cache
#set(SFML_DIR "C:/Users/kevin/SFML/SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit/SFML-2.5.1/lib/cmake/SFML")
#
#find_package(SFML 2.5.1 COMPONENTS system window graphics audio REQUIRED)
#add_executable(Project2 main.cpp
#        Objects/Node.h
#        Objects/Node.cpp
#        Objects/Network.h
#        Objects/PersonData.h
#        Objects/Network.cpp
#        Objects/ButtonInterface.h)
#target_link_libraries(Project2 sfml-system sfml-window sfml-graphics sfml-audio)

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
        Objects/ButtonInterface.h
        Objects/ButtonInterface.cpp
        Objects/Country.h
        Objects/CountryInterface.h
        Objects/CountryInterface.cpp
        Objects/NeighborhoodInterface.h
        Objects/NeighborhoodInterface.cpp)
target_link_libraries(Project2 sfml-system sfml-window sfml-graphics)
