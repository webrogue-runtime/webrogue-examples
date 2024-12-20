cmake_minimum_required(VERSION 3.31)

add_library(webrogue_gfx STATIC webrogue_gfx.c webrogue_gl_loader.c gl2.c)
set_target_properties(webrogue_gfx PROPERTIES PUBLIC_HEADER "webrogue_gfx.h")

install(
    TARGETS webrogue_gfx
    PUBLIC_HEADER DESTINATION include/webrogue_gfx
)