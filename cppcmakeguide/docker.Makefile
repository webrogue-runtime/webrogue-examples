cppcmakeguide: cppcmakeguide.wrapp

CURRENT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
EXAMPLES_DIR:=$(shell dirname $(CURRENT_DIR))

_BUILD:
	cmake -S . -B build --toolchain=/opt/webrogue-sdk/share/cmake/wasi-sdk-p1-pthread.cmake -DCMAKE_BUILD_TYPE=Release
	cmake --build build --target=main --parallel
	cp build/main main.wasm.hot

main.wasm.cold: _BUILD
	cmp -s main.wasm.hot main.wasm.cold; \
	RETVAL=$$?; \
	if [ $$RETVAL -eq 0 ]; then \
	    echo; \
	else \
	    echo; \
	    cp main.wasm.hot main.wasm.cold; \
	fi

cppcmakeguide.wrapp: main.wasm.cold webrogue.json
	rm -f cppcmakeguide.wrapp
	webrogue pack -o cppcmakeguide.wrapp

clean:
	rm -rf build cppcmakeguide.wrapp main.wasm
