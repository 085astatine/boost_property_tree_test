cmake_minimum_required(VERSION 2.8)

add_definitions(
            -std=c++11
            -Wall
            -Wextra)

message("CXX Compiler ID: " ${CMAKE_CXX_COMPILER_ID})
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    add_definitions(-stdlib=libc++)
endif()

message("CMake System Name: " ${CMAKE_SYSTEM_NAME})

find_package(Boost)
message("Boost Include Directory: " ${Boost_INCLUDE_DIR})
include_directories(
            ${Boost_INCLUDE_DIR})
# Library
add_library(io
    io/xml.cpp)
add_library(card
    card/card.cpp
    card/card_convert.cpp)
# Executable
add_executable(CardTest
    card_test.cpp)
target_link_libraries(CardTest
    card
    io)
