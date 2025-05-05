cmake_minimum_required(VERSION 3.22.0 FATAL_ERROR)

project(SDLGuide)

find_package(SDL3 REQUIRED)
find_package(SDL3_ttf REQUIRED)

add_executable(main main.c)
target_link_libraries(main SDL3 SDL3_ttf freetype zlib png webroguegfx c++abi c++)
