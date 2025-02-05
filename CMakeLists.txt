cmake_minimum_required(VERSION 3.20)
project(my_project)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

option(Release "Build in release mode" OFF)

if (Release)
    message(STATUS "Building in release mode")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
    set(CMAKE_BUILD_TYPE Release)
else()
    message(STATUS "Building in debug mode")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g3")
    set(CMAKE_BUILD_TYPE Debug)
endif()

find_package(SFML 3.0 REQUIRED COMPONENTS Graphics Audio System Window)
find_package(nlohmann_json 3.11.3 REQUIRED)
find_package(glm 0.9.9.8 REQUIRED)

add_executable(my_program
    src/Main.cpp
    src/Camera/Camera.cpp
    src/Application/Application.cpp
    src/Colors/Colors.cpp
    src/Colors/Colors.hpp
    src/ConfigObserver/ConfigObserver.cpp
    include/ASubject.hpp
    include/IObserver.hpp
    include/ISubject.hpp
    include/ASubject.cpp
    src/NamePipe/NamePipe.cpp
    src/ConfigSubject/ConfigSubject.cpp
    src/ConfigUpdater/ConfigUpdater.cpp
)

target_include_directories(my_program
    PUBLIC include
    PRIVATE src
)
target_link_libraries(my_program
    PRIVATE SFML::Graphics SFML::Audio SFML::System SFML::Window
    nlohmann_json::nlohmann_json
)

add_custom_target(clean_build
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}
    COMMENT "Removing build directory"
)
