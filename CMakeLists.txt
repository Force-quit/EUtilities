cmake_minimum_required(VERSION 3.26)
project(EUtilities LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    src/EUtilities.cpp
    src/EUtilities-Windows.cpp
    src/EShortcutListener.cpp
    include/EShortcutListener.hpp
    include/EUtilities.hpp
    include/EUtilities-Windows.hpp
)

add_library(EUtilities ${SOURCES})
target_include_directories(EUtilities PUBLIC include)

######################################
#  _______        _   _              #
# |__   __|      | | (_)             #
#    | | ___  ___| |_ _ _ __   __ _  #
#    | |/ _ \/ __| __| | '_ \ / _` | #
#    | |  __/\__ \ |_| | | | | (_| | #
#    |_|\___||___/\__|_|_| |_|\__, | #
#                              __/ | #
#                             |___/  #
######################################
add_executable(WhatKeysAmIPressing tests/WhatKeysAmIPressing.cpp)
target_link_libraries(WhatKeysAmIPressing PRIVATE EUtilities)
target_include_directories(WhatKeysAmIPressing PRIVATE include)

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

add_executable(EShortcutListenerTest tests/main.cpp tests/EShortcutListenerTest.cpp)
target_link_libraries(EShortcutListenerTest PRIVATE EUtilities GTest::gtest_main)
target_include_directories(EShortcutListenerTest PRIVATE include)

include(GoogleTest)
gtest_discover_tests(EUtilitiesTest)
gtest_discover_tests(EShortcutListenerTest)