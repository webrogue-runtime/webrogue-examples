simple:
	wasm32-wasip1-threads-clang main.c --target=wasm32-wasip1-threads -pthread -g -O0 -Wl,--no-entry -Wl,--import-memory -Wl,--export-memory -Wl,--max-memory=4294967296 -o main.wasm #-nostdlib 

clean:
	rm -f main.wasm
