cmake_minimum_required(VERSION 3.11)
# cmake_policy(SET CMP0144 NEW)

project(WebrogueGLFWExample)

# set(OPENGLES2_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../libs/GLES2)
# add_library(gl STATIC ${CMAKE_CURRENT_SOURCE_DIR}/../libs/wr_gl/wr_gl.c)
# target_include_directories(gl PRIVATE ${OPENGLES2_INCLUDE_DIR})
# set(OPENGLES2_gl_LIBRARY gl)
set(GLFW_BUILD_EXAMPLES ON)
set(GLFW_BUILD_WEBROGUE ON)
set(WEBROGUE_GFX_INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../libs)
add_subdirectory(../libs/glfw glfw)
add_executable(main main.c ../libs/webrogue_gfx/webrogue_gl_loader.c ../libs/webrogue_gfx/webrogue_gfx.c ../libs/GLES2/gl2.c) 
target_include_directories(
    main
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../libs/glfw/deps
    ${CMAKE_CURRENT_SOURCE_DIR}/../libs/glfw/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../libs
)
target_link_libraries(main glfw)
# target_link_libraries(main OgreMain OgreBites)
# set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
