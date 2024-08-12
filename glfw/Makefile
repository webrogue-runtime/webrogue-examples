glfw: BUILD glfw.wrapp

CURRENT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
ROOT_DIR:=$(shell dirname $(CURRENT_DIR))

BUILD:
	cmake -S . -B build --toolchain=$(CURRENT_DIR)/toolchain.cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
	cmake --build build --target=triangle-opengles --parallel
	cp build/glfw/examples/triangle-opengles main.wasm

main.wasm: BUILD

glfw.wrapp: main.wasm ../wrapp
	../wrapp . glfw.wrapp
