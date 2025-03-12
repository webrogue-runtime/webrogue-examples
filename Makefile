all: build_simple build_raylib

CURRENT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))

webrogue-wrapp-cli:
	cargo build --release --manifest-path=/host_dir/crates/wrapp-cli/Cargo.toml --target-dir=target
	cp target/release/webrogue-wrapp-cli webrogue-wrapp-cli

build_libs:
	cd libs && $(MAKE)

# apps
build_simple: webrogue-wrapp-cli
	cd simple && $(MAKE)

build_gears: build_libs
	cd gears && $(MAKE)

build_glfw: build_libs
	cd glfw && $(MAKE)

build_raylib: build_libs
	cd raylib && $(MAKE)

stk-assets:
	svn checkout https://svn.code.sf.net/p/supertuxkart/code/stk-assets stk-assets

build_stk: build_libs stk-assets
	cd stk && cmake -S . -B build --toolchain=/opt/wasi-sdk/share/cmake/wasi-sdk-pthread.cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Debug -DUSE_GLES2=ON -DUSE_MOJOAL=ON -DNO_SHADERC=ON -DSDL2_INCLUDEDIR=$(CURRENT_DIR)/dest/include/SDL2 -DSDL2_LIBRARY=$(CURRENT_DIR)/dest/lib/libSDL2.a -DJPEG_INCLUDE_DIR=$(CURRENT_DIR)/dest/include/jpeg -DJPEG_LIBRARY=$(CURRENT_DIR)/dest/lib/libjpeg.a -DPNG_LIBRARY=$(CURRENT_DIR)/dest/lib/libpng.a -DPNG_PNG_INCLUDE_DIR=$(CURRENT_DIR)/dest/include/libpng16 -DZLIB_LIBRARY=$(CURRENT_DIR)/dest/lib/libzlib.a -DZLIB_INCLUDE_DIR=$(CURRENT_DIR)/dest/include -DLIBSAMPLERATE_LIBRARY=$(CURRENT_DIR)/dest/lib/libsamplerate.a -DLIBSAMPLERATE_INCLUDEDIR=$(CURRENT_DIR)/dest/include -DOGGVORBIS_OGG_INCLUDE_DIR=$(CURRENT_DIR)/dest/include/ogg -DOGGVORBIS_VORBIS_INCLUDE_DIR=$(CURRENT_DIR)/dest/include/vorbis -DOGGVORBIS_OGG_LIBRARY=$(CURRENT_DIR)/dest/lib/libogg.a -DOGGVORBIS_VORBIS_LIBRARY=$(CURRENT_DIR)/dest/lib/libvorbis.a -DOGGVORBIS_VORBISFILE_LIBRARY=$(CURRENT_DIR)/dest/lib/libvorbisfile.a -DOGGVORBIS_VORBISENC_LIBRARY=$(CURRENT_DIR)/dest/lib/libvorbisenc.a -DFREETYPE_LIBRARY=$(CURRENT_DIR)/dest/lib/libfreetype.a -DFREETYPE_INCLUDE_DIRS=$(CURRENT_DIR)/dest/include/freetype2 -DHARFBUZZ_LIBRARY=$(CURRENT_DIR)/dest/lib/libharfbuzz.a -DHARFBUZZ_INCLUDEDIR=$(CURRENT_DIR)/dest/include -DCURL_LIBRARY=$(CURRENT_DIR)/dest/lib/libcurl.a -DCURL_INCLUDE_DIR=$(CURRENT_DIR)/dest/include/curl -DMBEDCRYPTO_LIBRARY=$(CURRENT_DIR)/dest/lib/libmbedcrypto.a -DMBEDTLS_LIBRARY=$(CURRENT_DIR)/dest/lib/libmbedtls.a -DMBEDX509_LIBRARY=$(CURRENT_DIR)/dest/lib/libmbedx509.a -DMBEDTLS_INCLUDE_DIRS=$(CURRENT_DIR)/dest/include/mbedtls -DUSE_CRYPTO_OPENSSL=OFF -DLIBRESOLV_LIBRARY=/opt/wasi-sdk/share/wasi-sysroot/lib/wasm32-wasi-threads/libresolv.a -DPTHREAD_LIBRARY=/opt/wasi-sdk/share/wasi-sysroot/lib/wasm32-wasi-threads/libpthread.a -DUSE_WIIUSE=OFF
	cd stk && cmake --build build --target=supertuxkart -j4
	cp stk/build/bin/supertuxkart stk_webc/main.wasm
	cd stk_webc && $(MAKE)

clean:
	cd libs && $(MAKE) clean
	cd simple && $(MAKE) clean
	cd gears && $(MAKE) clean
	cd glfw && $(MAKE) clean
	cd raylib && $(MAKE) clean
