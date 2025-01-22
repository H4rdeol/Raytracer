cmake_minimum_required(VERSION 3.20)
project(my_project)

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

add_executable(my_program 
    src/Main.cpp
    src/ConfigObserver/ConfigObserver.cpp
    include/ASubject.hpp
    include/IObserver.hpp
    include/ISubject.hpp
    include/ASubject.cpp
)

target_include_directories(my_program PUBLIC include)
target_link_libraries(my_program PRIVATE SFML::Graphics SFML::Audio SFML::System SFML::Window)

add_custom_target(clean_build
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}
    COMMENT "Removing build directory"
)
