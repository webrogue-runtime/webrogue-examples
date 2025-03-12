glfw: BUILD glfw.webc

CURRENT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
EXAMPLES_DIR:=$(shell dirname $(CURRENT_DIR))

BUILD:
	rm -f main.wasm
	cmake -S . -B build --toolchain=/opt/wasi-sdk/share/cmake/wasi-sdk-pthread.cmake -DGLFW_BUILD_EXAMPLES=ON -DGLFW_BUILD_WEBROGUE=ON
	cmake -S . -B build --toolchain=/opt/wasi-sdk/share/cmake/wasi-sdk-pthread.cmake -DGLFW_BUILD_EXAMPLES=ON -DGLFW_BUILD_WEBROGUE=ON
	cmake --build build --target=main --parallel
	cp build/main main.wasm

main.wasm: BUILD

glfw.webc: main.wasm
	rm -f glfw.webc
	/.wasmer/bin/wasmer package build --out=glfw.webc

clean:
	rm -rf build glfw.webc main.wasm
