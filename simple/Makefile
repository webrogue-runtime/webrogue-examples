simple: simple.wrapp

main.wasm: main.c Makefile
	../wasi-sdk-22/bin/clang main.c --target=wasm32-wasip1 -g -O0 -Wl,--no-entry -o main.wasm #-nostdlib 

simple.wrapp: main.wasm ../wrapp
	../wrapp . simple.wrapp
