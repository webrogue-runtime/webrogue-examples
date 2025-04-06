raylib: raylib.wrapp

CURRENT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
EXAMPLES_DIR:=$(shell dirname $(CURRENT_DIR))

_BUILD:
	cmake -S . -B build --toolchain=/opt/wasip1/toolchain.cmake -DCMAKE_BUILD_TYPE=Release -DCUSTOMIZE_BUILD=ON -DSUPPORT_MODULE_RAUDIO=OFF -DUSE_AUDIO=OFF -DSUPPORT_QUADS_DRAW_MODE=ON -DOPENGL_VERSION="ES 3.0" -DOPENGL_INCLUDE_DIR=/opt/wasip1/include -DPLATFORM=SDL -DUSE_EXTERNAL_GLFW=ON -Dglfw3_DIR=/opt/wasip1/lib/cmake/glfw3 -DSDL2_DIR=/opt/wasip1/lib/cmake/SDL2
	cmake --build build --target=webrogue_raylib_example --parallel
	cp build/webrogue_raylib_example main.wasm.hot

main.wasm: _BUILD
	cmp -s main.wasm.hot main.wasm; \
	RETVAL=$$?; \
	if [ $$RETVAL -eq 0 ]; then \
	    echo; \
	else \
	    echo; \
	    cp main.wasm.hot main.wasm; \
	fi

raylib.wrapp: main.wasm webrogue.json
	rm -f raylib.wrapp
	webrogue pack -o raylib.wrapp

clean:
	rm -rf build raylib.wrapp main.wasm
