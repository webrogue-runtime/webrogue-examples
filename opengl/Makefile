opengl: a.out opengl.wrapp

a.out: sdl2-opengl.c Makefile
	g++ sdl2-opengl.c -lSDL2 -lGL

main.wasm: sdl2-opengl.c Makefile
	../wasi-sdk-22/bin/clang sdl2-opengl.c ../libs/wr_gl/wr_gl.c -I../libs --target=wasm32-wasip1 -D__WEBROGUE__ -g -O0 -Wl,--no-entry -o main.wasm #-nostdlib 

opengl.wrapp: main.wasm ../wrapp
	../wrapp . opengl.wrapp
