simple: simple.webc

main.wasm: main.c Makefile
	/wasi-sdk/bin/clang main.c --target=wasm32-wasip1 -g -O0 -Wl,--no-entry -o main.wasm #-nostdlib 

simple.webc: main.wasm
	rm -f simple.webc
	/.wasmer/bin/wasmer package build --out=simple.webc

clean:
	rm -f main.wasm simple.webc
