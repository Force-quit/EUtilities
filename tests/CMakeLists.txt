add_executable(WhatKeysAmIPressing WhatKeysAmIPressing.cpp)
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

add_executable(EUtilitiesTest main.cpp EUtilitiesTest.cpp)
target_link_libraries(EUtilitiesTest PRIVATE EUtilities GTest::gtest_main)
target_include_directories(EUtilitiesTest PRIVATE include)

add_executable(EShortcutListenerTest main.cpp EShortcutListenerTest.cpp)
target_link_libraries(EShortcutListenerTest PRIVATE EUtilities GTest::gtest_main)
target_include_directories(EShortcutListenerTest PRIVATE include)

include(GoogleTest)
gtest_discover_tests(EUtilitiesTest)
gtest_discover_tests(EShortcutListenerTest)