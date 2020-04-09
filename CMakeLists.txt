cmake_minimum_required(VERSION 3.15)
project(Epipov_Ray)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -W -Wall -Werror")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

include_directories(Includes)
include_directories(Includes/Interfaces)
include_directories(Includes/Library)
include_directories(Includes/Raytracing)

set(SRCS Sources/)
file(
        GLOB_RECURSE
        SRCS
        ${SRCS}*.cpp
)

set(INCS Includes/)
file(
        GLOB_RECURSE
        INCS
        ${INCS}*.hpp
)

add_executable(Epipov_Ray main.cpp ${SRCS} ${INCS})

if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Epipov_Ray ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()