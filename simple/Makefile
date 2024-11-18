simple: simple.webc

main.wasm: main.c Makefile
	../wasi-sdk-24/bin/clang main.c --target=wasm32-wasip1 -g -O0 -Wl,--no-entry -o main.wasm #-nostdlib 

simple.webc: main.wasm ../wasmer
	rm -f simple.webc
	../wasmer package build --out=simple.webc
