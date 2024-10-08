glfw: BUILD glfw.wrapp

CURRENT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
ROOT_DIR:=$(shell dirname $(CURRENT_DIR))

BUILD:
	rm -f main.wasm
	cmake -S . -B build --toolchain=$(CURRENT_DIR)/toolchain.cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Debug
	cmake --build build --target=main --parallel
	cp build/main main.wasm

main.wasm: BUILD

glfw.wrapp: main.wasm ../wrapp webrogue.json
	../wrapp . glfw.wrapp
