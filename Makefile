all: build_wrapp build_simple build_opengl build_gears build_glfw build_raylib

# utility
build_wrapp:
	cargo build --release --manifest-path ../crates/wrapp_cli/Cargo.toml
	cp ../crates/wrapp_cli/target/release/webrogue_wrapp_cli wrapp

wrapp: build_wrapp

wasi-sdk-22:
	curl -L https://github.com/WebAssembly/wasi-sdk/releases/download/wasi-sdk-22/wasi-sdk-22.0-linux.tar.gz | tar -xz
	mv wasi-sdk-22.0 wasi-sdk-22

# apps
build_simple: wrapp wasi-sdk-22
	cd simple && $(MAKE)

build_opengl: wrapp wasi-sdk-22
	cd opengl && $(MAKE)

build_gears: wrapp wasi-sdk-22
	cd gears && $(MAKE)

build_glfw: wrapp wasi-sdk-22
	cd glfw && $(MAKE)

build_raylib: wrapp wasi-sdk-22
	cd raylib && $(MAKE)
