raylib: BUILD_ raylib.webc

CURRENT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
EXAMPLES_DIR:=$(shell dirname $(CURRENT_DIR))

BUILD_:
	rm -f main.wasm
	cmake -S . -B build --toolchain=$(CURRENT_DIR)/../toolchain.cmake -DCMAKE_SYSROOT=/wasix-sysroot -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Release -DCUSTOMIZE_BUILD=ON -DSUPPORT_MODULE_RAUDIO=OFF -DUSE_AUDIO=OFF -DSUPPORT_QUADS_DRAW_MODE=ON -DOPENGL_VERSION="ES 3.0"
	cmake -S . -B build --toolchain=$(CURRENT_DIR)/../toolchain.cmake -DCMAKE_SYSROOT=/wasix-sysroot -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Release -DCUSTOMIZE_BUILD=ON -DSUPPORT_MODULE_RAUDIO=OFF -DUSE_AUDIO=OFF -DSUPPORT_QUADS_DRAW_MODE=ON -DOPENGL_VERSION="ES 3.0"
	cmake --build build --target=webrogue_raylib_example --parallel
	cp build/webrogue_raylib_example main.wasm

main.wasm: BUILD_

raylib.webc: main.wasm
	rm -f raylib.webc
	/.wasmer/bin/wasmer package build --out=raylib.webc

clean:
	rm -rf build raylib.webc main.wasm
