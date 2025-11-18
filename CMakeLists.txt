cmake_minimum_required(VERSION 4.1.1)
project(EUtilities LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    include/EUtilities.hpp
    src/EUtilities.cpp
)

if(WIN32)
    list(APPEND SOURCES
        include/EUtilities-Windows.hpp
        include/EShortcutListener.hpp
        src/EUtilities-Windows.cpp
        src/EShortcutListener.cpp
    )
endif()

add_library(EUtilities ${SOURCES})
target_include_directories(EUtilities PUBLIC include)

if(MSVC)
    target_compile_options(EUtilities PRIVATE /EHsc)
endif()

if(PROJECT_IS_TOP_LEVEL)
    add_subdirectory(tests)
endif()