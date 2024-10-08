raylib: BUILD_ raylib.wrapp

CURRENT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
ROOT_DIR:=$(shell dirname $(CURRENT_DIR))

BUILD_:
	rm -f main.wasm
	cmake -S . -B build --toolchain=$(CURRENT_DIR)/../glfw/toolchain.cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Debug -DCUSTOMIZE_BUILD=ON -DSUPPORT_MODULE_RAUDIO=OFF -DUSE_AUDIO=OFF -DSUPPORT_QUADS_DRAW_MODE=ON -DOPENGL_VERSION="ES 2.0"
	cmake --build build --target=webrogue_raylib_example --parallel
	cp build/webrogue_raylib_example main.wasm

main.wasm: BUILD_

raylib.wrapp: main.wasm ../wrapp webrogue.json
	../wrapp . raylib.wrapp
