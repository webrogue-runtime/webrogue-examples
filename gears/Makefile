gears: gears.webc
	echo

CC = "/wasi-sdk/bin/clang"
SYSROOT = "/wasix-sysroot"

CFLAGS = --target=wasm32-wasmer-wasi \
		 -O2 \
		 --sysroot ${SYSROOT} \
		 -matomics \
		 -mbulk-memory \
		 -mmutable-globals \
		 -pthread \
		 -mthread-model posix \
		 -ftls-model=local-exec \
		 -fno-trapping-math \
		 -D_WASI_EMULATED_MMAN \
		 -D_WASI_EMULATED_SIGNAL \
		 -D_WASI_EMULATED_PROCESS_CLOCKS \
		 -Wall \
		 -Wextra \
		 -Werror \
		 -Wno-null-pointer-arithmetic \
		 -Wno-unused-parameter \
		 -Wno-sign-compare \
		 -Wno-unused-variable \
		 -Wno-unused-function \
		 -Wno-ignored-attributes \
		 -Wno-missing-braces \
		 -Wno-ignored-pragmas \
		 -Wno-unused-but-set-variable \
		 -Wno-unknown-warning-option \
		 -Wno-parentheses \
		 -Wno-shift-op-parentheses \
		 -Wno-bitwise-op-parentheses \
		 -Wno-logical-op-parentheses \
		 -Wno-string-plus-int \
		 -Wno-dangling-else \
		 -Wno-unknown-pragmas \
		 -MD \
		 -MP

CLFLAGS = -Wl,--shared-memory \
		  -Wl,--max-memory=4294967296 \
		  -Wl,--import-memory \
		  -Wl,--export-dynamic \
		  -Wl,--export=__heap_base \
		  -Wl,--export=__stack_pointer \
		  -Wl,--export=__data_end \
		  -Wl,--export=__wasm_init_tls \
		  -Wl,--export=__wasm_signal \
		  -Wl,--export=__tls_size \
		  -Wl,--export=__tls_align \
		  -Wl,--export=__tls_base

main.wasm: gears.c Makefile ../dest/lib/libSDL2.a
	${CC} $(CFLAGS) $(CLFLAGS) gears.c -Wl,-lwebrogue_gfx -Wl,../dest/lib/libSDL2.a -Wl,-L../dest/lib -I../dest/include -o main.wasm #-D__WEBROGUE__ #-nostdlib -Wl,--no-entry 

gears.webc: main.wasm
	rm -f gears.webc
	/.wasmer/bin/wasmer package build --out=gears.webc

clean:
	rm -f gears.webc main.d main.wasm
