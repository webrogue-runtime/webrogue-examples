cmake_minimum_required(VERSION 3.22.0 FATAL_ERROR)

project(webrogue_raylib_example C CXX)

set(PROJECT_TARGET ${PROJECT_NAME})
set(SOURCE_DIR "src")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# file(COPY "${CMAKE_SOURCE_DIR}/assets" DESTINATION "${CMAKE_BINARY_DIR}")


add_executable(${PROJECT_TARGET} main.c ../libs/webrogue_gfx/webrogue_gfx.c)
add_library(GL STATIC ${CMAKE_CURRENT_SOURCE_DIR}/../libs/GLES2/gl2.c ${CMAKE_CURRENT_SOURCE_DIR}/../libs/cxa_exception.cpp ../libs/webrogue_gfx/webrogue_gl_loader.c)
target_include_directories(GL PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../libs/)

target_include_directories(${PROJECT_TARGET} PRIVATE ${SOURCE_DIR})

set(OPENGL_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../libs)
set(USE_EXTERNAL_GLFW OFF)
set(glfw3_FOUND ON)


set(GLFW_BUILD_WEBROGUE ON)
# set(OPENGLES2_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../libs/GLES2)
add_subdirectory(../libs/glfw glfw)
target_include_directories(glfw PRIVATE ../libs)
add_subdirectory(../libs/raylib raylib)
target_link_libraries(${PROJECT_TARGET} raylib)

target_link_libraries(raylib glfw)
target_include_directories(${PROJECT_TARGET} PRIVATE ../libs/raylib/src)
target_link_options(${PROJECT_TARGET} PRIVATE -Wl,--max-memory=16777216)
