cmake_minimum_required(VERSION 3.11)
# cmake_policy(SET CMP0144 NEW)

project(WebrogueGLFWExample)

# set(OPENGLES2_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../libs/GLES2)
# add_library(gl STATIC ${CMAKE_CURRENT_SOURCE_DIR}/../libs/wr_gl/wr_gl.c)
# target_include_directories(gl PRIVATE ${OPENGLES2_INCLUDE_DIR})
# set(OPENGLES2_gl_LIBRARY gl)
set(GLFW_BUILD_EXAMPLES ON)
add_subdirectory(../libs/glfw glfw)
# add_executable(main main.cpp cxa_exception.cpp)
# target_include_directories(
#     main
#     PUBLIC
#     ${CMAKE_CURRENT_SOURCE_DIR}/ogre/OgreMain/include
# )
# target_link_libraries(main OgreMain OgreBites)
# set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
