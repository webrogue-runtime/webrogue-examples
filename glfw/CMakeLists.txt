cmake_minimum_required(VERSION 3.11)

project(WebrogueGLFWExample)

add_executable(main main.c) 
target_link_libraries(main glfw3 webrogue_gfx)
