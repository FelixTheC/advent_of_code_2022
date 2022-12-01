cmake_minimum_required(VERSION 3.24)
project(day_1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS NO)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

#$ENV { TESTING }
if ("$ENV { TESTING }")
    enable_testing()

    include(FetchContent)
    FetchContent_Declare(
            googletest
            URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
    )

    FetchContent_MakeAvailable(googletest)
    include_directories(${GTEST_INCLUDE_DIRS})

    add_executable(day_1 tests/testmain.cpp)
    target_link_libraries(day_1 gtest_main)

    include(GoogleTest)
    gtest_discover_tests(day_1)

else ()
    add_executable(day_1 main.cpp elve_calories.cpp elve_calories.hpp)
endif ()
