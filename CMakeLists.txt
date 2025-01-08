cmake_minimum_required(VERSION 3.26)
project(EUtilities LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API ON)

set(LIBRARY_SOURCES
    src/EUtilities.ixx
    src/EUtilities.cpp
#    src/EUtilities-Windows.ixx
#    src/EUtilities-Windows.cpp
)

add_library(EUtilities STATIC ${LIBRARY_SOURCES})

if(MSVC)
    target_compile_options(EUtilities PRIVATE /experimental:module /std:c++latest /Z7)
endif()

add_executable(EUtilitiesTest tests/main.cpp)
target_link_libraries(EUtilitiesTest PRIVATE EUtilities)

if(MSVC)
    target_compile_options(EUtilitiesTest PRIVATE /std:c++latest /Z7)
endif()