cmake_minimum_required(VERSION 3.26)
project(EUtilities LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(EUtilities src/EUtilities.cpp include/EUtilities.h)
target_include_directories(EUtilities PUBLIC include)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/b514bdc898e2951020cbdca1304b75f5950d1f59.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(EUtilitiesTest tests/main.cpp tests/EUtilitiesTest.cpp)
target_link_libraries(EUtilitiesTest PRIVATE EUtilities GTest::gtest_main)
target_include_directories(EUtilitiesTest PRIVATE include)

include(GoogleTest)
gtest_discover_tests(EUtilitiesTest)

add_executable(EUtilitiesManualTest tests/EUtilitiesManualTest.cpp)
target_link_libraries(EUtilitiesManualTest PRIVATE EUtilities)
target_include_directories(EUtilitiesManualTest PRIVATE include)
