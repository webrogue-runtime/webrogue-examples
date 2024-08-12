gears: a.out gears.wrapp
	echo

a.out: gears.c Makefile
	gcc gears.c -lSDL2 -lGL -lm

main.wasm: gears.c Makefile
	../wasi-sdk-22/bin/clang gears.c ../libs/webrogue_gfx/webrogue_gfx.c ../libs/GLES2/gl2.c -I../libs --target=wasm32-wasip1 -D__WEBROGUE__ -g -O0 -Wl,--no-entry -o main.wasm #-nostdlib 

gears.wrapp: main.wasm ../wrapp
	../wrapp . gears.wrapp
