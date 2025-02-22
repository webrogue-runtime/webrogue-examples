cmake_minimum_required(VERSION 3.22.0 FATAL_ERROR)

project(webrogue_raylib_example C CXX)

set(PROJECT_TARGET ${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# file(COPY "${CMAKE_SOURCE_DIR}/assets" DESTINATION "${CMAKE_BINARY_DIR}")


add_executable(${PROJECT_TARGET} main.c)


target_link_libraries(${PROJECT_TARGET} raylib glfw3 webrogue_gfx c++ c++abi)

# target_include_directories(${PROJECT_TARGET} PRIVATE ../libs/raylib/src)
target_link_options(${PROJECT_TARGET} PRIVATE -Wl,--max-memory=16777216)
