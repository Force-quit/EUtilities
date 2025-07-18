cmake_minimum_required(VERSION 3.26)
project(EUtilities LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    src/EUtilities.cpp
    src/EShortcutListener.cpp
    include/EShortcutListener.hpp
    include/EUtilities.hpp
)

if(WIN32)
    list(APPEND SOURCES
        src/EUtilities-Windows.cpp
        include/EUtilities-Windows.hpp
    )
endif()

add_library(EUtilities ${SOURCES})
target_include_directories(EUtilities PUBLIC include)

if(PROJECT_IS_TOP_LEVEL)
    add_subdirectory(tests)
endif()