cmake_minimum_required(VERSION 3.24)
project(day_7)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS NO)
set(LIB_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/libs/include)

#$ENV { TESTING }
if ("$ENV{TESTING}")
    enable_testing()

    include(FetchContent)
    FetchContent_Declare(
            googletest
            URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
    )

    FetchContent_MakeAvailable(googletest)
    include_directories(${GTEST_INCLUDE_DIRS} ${LIB_INCLUDE_DIR})

    find_library(PUZZLE_LIB puzzleinput "${CMAKE_SOURCE_DIR}/libs/lib")

    add_executable(day_7 tests/testmain.cpp parse_command.hpp PathObject.cpp PathObject.hpp)
    target_link_libraries(day_7 gtest_main ${PUZZLE_LIB})

    include(GoogleTest)
    gtest_discover_tests(day_7)

else ()
    include_directories(${LIB_INCLUDE_DIR})
    find_library(PUZZLE_LIB puzzleinput "${CMAKE_SOURCE_DIR}/libs/lib")

    add_executable(day_7 main.cpp parse_command.hpp PathObject.cpp PathObject.hpp solution.hpp)
    target_link_libraries(day_7 ${PUZZLE_LIB})
endif ()
