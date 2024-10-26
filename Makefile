all: build_wrapp build_simple build_opengl build_gears build_glfw build_raylib

# utility
build_wrapp:
	cargo build --release --manifest-path ../Cargo.toml --target-dir ../target --package webrogue_wrapp_cli
	cp ../target/release/webrogue_wrapp_cli wrapp

wrapp: build_wrapp

UNAME_S := $(shell uname -s)
UNAME_M := $(shell uname -m)

ifeq ($(UNAME_S),Linux)
	ifeq ($(UNAME_M),x86_64)
		WASI_SDK_URL = https://github.com/WebAssembly/wasi-sdk/releases/download/wasi-sdk-24/wasi-sdk-24.0-x86_64-linux.tar.gz
		WASI_SDK_DIR_NAME = wasi-sdk-24.0-x86_64-linux
	endif
	ifeq ($(UNAME_M),aarch64)
		WASI_SDK_URL = https://github.com/WebAssembly/wasi-sdk/releases/download/wasi-sdk-24/wasi-sdk-24.0-arm64-linux.tar.gz
		WASI_SDK_DIR_NAME = wasi-sdk-24.0-arm64-linux
	endif
endif
ifeq ($(UNAME_S),Darwin)
	WASI_SDK_URL = https://github.com/WebAssembly/wasi-sdk/releases/download/wasi-sdk-24/wasi-sdk-24.0-x86_64-macos.tar.gz
	WASI_SDK_DIR_NAME = wasi-sdk-24.0-x86_64-macos
endif


wasi-sdk-24:
	curl -L $(WASI_SDK_URL) | tar -xz
	mv $(WASI_SDK_DIR_NAME) wasi-sdk-24

# apps
build_simple: wrapp wasi-sdk-24
	cd simple && $(MAKE)

build_opengl: wrapp wasi-sdk-24
	cd opengl && $(MAKE)

build_gears: wrapp wasi-sdk-24
	cd gears && $(MAKE)

build_glfw: wrapp wasi-sdk-24
	cd glfw && $(MAKE)

build_raylib: wrapp wasi-sdk-24
	cd raylib && $(MAKE)
