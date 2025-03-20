simple: simple.wrapp

main.wasm: main.c Makefile
	/opt/wasi-sdk/bin/clang main.c --target=wasm32-wasip1-threads -pthread -g -O0 -Wl,--no-entry -Wl,--import-memory -Wl,--export-memory -Wl,--max-memory=4294967296  -o main.wasm #-nostdlib 

simple.wrapp: main.wasm webrogue.json
	rm -f simple.wrapp
	webrogue-wrapp-cli . simple.wrapp

clean:
	rm -f main.wasm simple.wrapp
