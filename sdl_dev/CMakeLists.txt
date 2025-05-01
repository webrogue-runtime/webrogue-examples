cmake_minimum_required(VERSION 3.22.0 FATAL_ERROR)

project(CppSDL)

set(SDL_VERSION 3)
set(USE_SUBDIRECTORIES OFF)

if(USE_SUBDIRECTORIES)
    add_subdirectory(/webrogue_sdk_libs/webroguegfx webroguegfx)
    set(BUILD_SHARED_LIBS OFF)
    if(SDL_VERSION EQUAL 2)
        add_subdirectory(/webrogue_sdk_libs/libsamplerate libsamplerate)
    endif()

    set(SDL_STATIC ON)
    set(SDL_SHARED OFF)
    add_subdirectory(/webrogue_sdk_libs/SDL${SDL_VERSION} SDL${SDL_VERSION})

    set(CMAKE_POSITION_INDEPENDENT_CODE OFF)
    add_subdirectory(/webrogue_sdk_libs/SDL${SDL_VERSION}_ttf SDL${SDL_VERSION}_ttf)
else()
    find_package(SDL${SDL_VERSION} REQUIRED)
    find_package(SDL${SDL_VERSION}_ttf REQUIRED)
endif()

add_executable(sdl_dev sdl_dev.c)
target_compile_definitions(sdl_dev PRIVATE -DSDL_VERSION=${SDL_VERSION})

target_link_libraries(sdl_dev SDL${SDL_VERSION} SDL${SDL_VERSION}_ttf freetype png zlib webroguegfx c++ c++abi)
if(SDL_VERSION EQUAL 2)
    target_link_libraries(sdl_dev samplerate)
endif()
