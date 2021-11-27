cmake_minimum_required(VERSION 3.15)
project(project6)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Werror -Wextra -pedantic -pedantic-errors")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-limit-debug-info")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

# dear student -- in the end, all .h & .cpp source files should be
#  in the following list of SOURCE_FILES, except for the test files
set(SOURCE_FILES
    DblQueue.h
    DblQueue.cpp
    GuitarHero.cpp
    GuitarString.h
    GuitarString.cpp)

add_executable(project6 ${SOURCE_FILES})


set(DBLQUEUE_TEST
        DblQueue.h
        DblQueue.cpp
        DblQueueTest.cpp)

add_executable(DblQueue_test ${DBLQUEUE_TEST})


set(STRING_TEST
        DblQueue.h
        DblQueue.cpp
        GuitarStringTest.cpp
        GuitarString.h
        GuitarString.cpp)

add_executable(String_test ${STRING_TEST})
