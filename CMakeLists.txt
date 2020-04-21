cmake_minimum_required(VERSION 3.1)
project(Epipov_Ray)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -W -Wall -Werror")

include_directories(Includes)
include_directories(Includes/Interfaces)
include_directories(Includes/Library)
include_directories(Includes/Tracing)
include_directories(Includes/Utils)
include_directories(Includes/Algo)
include_directories(Includes/Modeling)
include_directories(Includes/Loader)

set(SRCS Sources/)
file(
        GLOB_RECURSE
        SRCS
        ${SRCS}*.cpp
)

set(INCS Includes/ Includes/Utils/Intersection.hpp)
file(
        GLOB_RECURSE
        INCS
        ${INCS}*.hpp
)

add_executable(Epipov_Ray main.cpp ${SRCS} ${INCS})

target_compile_options(${PROJECT_NAME} PUBLIC
        -W -Wall -Wextra -Werror -Wuninitialized -Wduplicated-cond
        -Wduplicated-branches -Wlogical-op -Wnull-dereference -Wold-style-cast
        -Wuseless-cast -Wdouble-promotion -Wshadow -O3 -Ofast)


set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)
find_package(assimp REQUIRED)

if(ASSIMP_FOUND)
    message(STATUS "ASSIMP_INCLUDE_DIR: ${ASSIMP_INCLUDE_DIR}")
    include_directories(${ASSIMP_INCLUDE_DIR})
endif()

if(SFML_FOUND)
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
    include_directories(${SFML_INCLUDE_DIR})
else()
    message("SFML not found")
endif()

target_link_libraries(${PROJECT_NAME} ${ASSIMP_LIBRARIES} ${SFML_LIBRARIES} sfml-system sfml-window sfml-graphics sfml-network sfml-audio pthread)