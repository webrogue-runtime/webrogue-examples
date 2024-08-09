all: build_simple build_opengl

# utility
wrapp:
	cargo build --release --manifest-path ../crates/wrapp_cli/Cargo.toml
	cp ../crates/wrapp_cli/target/release/webrogue_wrapp_cli wrapp

wasi-sdk-22:
	curl -L https://github.com/WebAssembly/wasi-sdk/releases/download/wasi-sdk-22/wasi-sdk-22.0-linux.tar.gz | tar -xz
	mv wasi-sdk-22.0 wasi-sdk-22

# apps
build_simple: wrapp wasi-sdk-22
	cd simple && $(MAKE)

build_opengl: wrapp wasi-sdk-22
	cd opengl && $(MAKE)
