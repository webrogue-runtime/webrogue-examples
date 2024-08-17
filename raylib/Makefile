raylib: BUILD raylib.wrapp

CURRENT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
ROOT_DIR:=$(shell dirname $(CURRENT_DIR))

BUILD:
	rm -f main.wasm
	cmake -S . -B build --toolchain=$(CURRENT_DIR)/../glfw/toolchain.cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Debug
	cmake --build build --target=webrogue_raylib_example --parallel
	cp build/webrogue_raylib_example main.wasm

main.wasm: BUILD

raylib.wrapp: main.wasm ../wrapp
	../wrapp . raylib.wrapp
