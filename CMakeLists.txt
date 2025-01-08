cmake_minimum_required(VERSION 3.26)
project(EUtilities LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_DEBUG_POSTFIX "-Debug")

add_library(EUtilities STATIC src/EUtilities.cpp src/EUtilities.h)
target_include_directories(EUtilities PUBLIC src)

if(MSVC)
    target_compile_options(EUtilities PRIVATE /std:c++latest)
endif()

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
target_include_directories(EUtilitiesTest PRIVATE src)

if(MSVC)
    target_compile_options(EUtilitiesTest PRIVATE /std:c++latest)
endif()

include(GoogleTest)
gtest_discover_tests(EUtilitiesTest)
