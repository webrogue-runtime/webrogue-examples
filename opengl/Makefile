opengl: opengl.wrapp

main.wasm: sdl2-opengl.c Makefile
	../wasi-sdk-24/bin/clang sdl2-opengl.c ../libs/webrogue_gfx/webrogue_gfx.c ../libs/GLES2/gl2.c -I../libs --target=wasm32-wasip1 -D__WEBROGUE__ -g -O0 -Wl,--no-entry -o main.wasm #-nostdlib 

opengl.wrapp: main.wasm ../wrapp webrogue.json
	../wrapp . opengl.wrapp
