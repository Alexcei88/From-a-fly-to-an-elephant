cmake_minimum_required (VERSION 2.8)
 
set (PROJECT libflyandanelephant) 

#Setup CMake to run tests
enable_testing()

include(CheckCXXCompilerFlag)

project (${PROJECT})

# Подключаем С++11
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
        message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

aux_source_directory("${PROJECT_SOURCE_DIR}/heuristicestimator/" SUB_SOURCES)

set (SOURCES
        world.cpp
        flytoelephant.cpp
        ${SUB_SOURCES})

set (HEADERS
    world.h
    flytoelephant.h)

add_library (${PROJECT} ${HEADERS} ${SOURCES})

target_link_libraries (${PROJECT}
    ${CMAKE_THREAD_LIBS_INIT})
