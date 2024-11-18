all: build_wasmer build_simple build_gears build_glfw build_raylib

# utility
build_wasmer:
	cargo build --release --manifest-path ../external/wasmer/lib/cli/Cargo.toml --target-dir ./target
	cp ./target/release/wasmer wasmer

wasmer: build_wasmer

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

wasix-sysroot:
	curl -L https://github.com/wasix-org/wasix-libc/releases/download/v2024-07-08.1/sysroot.tar.gz | tar -xz

sysroot: wasi-sdk-24 wasix-sysroot

# apps
build_simple: wasmer sysroot
	cd simple && $(MAKE)

build_gears: wasmer sysroot
	cd gears && $(MAKE)

build_glfw: wasmer sysroot
	cd glfw && $(MAKE)

build_raylib: wasmer sysroot
	cd raylib && $(MAKE)
