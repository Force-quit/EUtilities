cmake_minimum_required(VERSION 3.26)
project(EUtilities LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(EUTILITIES_SOURCES
    src/EUtilities.cpp
    src/EUtilities-Windows.cpp
)

set(EUTILITIES_HEADERS
    src/EUtilities.h
    src/EUtilities-Windows.h
)

add_library(EUtilities STATIC ${EUTILITIES_SOURCES} ${EUTILITIES_HEADERS})

if(MSVC)
    target_compile_options(EUtilities PRIVATE /std:c++latest)
endif()

add_executable(EUtilitiesTest tests/main.cpp)
target_link_libraries(EUtilitiesTest PRIVATE EUtilities)

if(MSVC)
    target_compile_options(EUtilitiesTest PRIVATE /std:c++latest)
endif()