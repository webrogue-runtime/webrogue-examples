stk: stk.webc

CURRENT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
EXAMPLES_DIR:=$(shell dirname $(CURRENT_DIR))

stk.webc: main.wasm
	rm -f stk.webc
	/.wasmer/bin/wasmer package build --out=stk.webc

clean:
	rm -rf build stk.webc main.wasm
