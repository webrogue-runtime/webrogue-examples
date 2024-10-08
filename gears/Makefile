gears: gears.wrapp
	echo

main.wasm: gears.c Makefile
	../wasi-sdk-24/bin/clang gears.c ../libs/webrogue_gfx/webrogue_gfx.c ../libs/GLES2/gl2.c -I../libs --target=wasm32-wasip1 -D__WEBROGUE__ -g -O0 -Wl,--no-entry -o main.wasm #-nostdlib 

gears.wrapp: main.wasm ../wrapp webrogue.json
	../wrapp . gears.wrapp
