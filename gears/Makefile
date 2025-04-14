gears: gears.webc
	echo

CC = "/opt/wasip1/bin/clang"

CFLAGS = --target=wasm32-wasip1-threads \
	-pthread \
	-g \
	-O0

CLFLAGS = -Wl,--no-entry \
	-Wl,--import-memory \
	-Wl,--export-memory \
	-Wl,--max-memory=4294967296

main.wasm: gears.c Makefile
	${CC} $(CFLAGS) $(CLFLAGS) gears.c \
		-o main.wasm

gears.webc: main.wasm
	rm -f gears.webc
	/.wasmer/bin/wasmer package build --out=gears.webc

clean:
	rm -f gears.webc main.d main.wasm
