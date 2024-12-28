all: copy_glad copy_gles2 copy_gles3 copy_khr build_webrogue_gfx build_SDL2 build_glfw build_raylib build_jpeg build_png build_zlib build_libsamplerate build_vorbis build_ogg build_freetype build_harfbuzz build_curl build_mbedtls

CURRENT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
EXAMPLES_DIR:=$(shell dirname $(CURRENT_DIR))


# copy headers
copy_glad: $(CURRENT_DIR)/../dest/include/glad

$(CURRENT_DIR)/../dest/include/glad:
	mkdir -p $(CURRENT_DIR)/../dest/include/glad 
	cp -r glfw/deps/glad $(CURRENT_DIR)/../dest/include

copy_gles2: $(CURRENT_DIR)/../dest/include/GLES2 

$(CURRENT_DIR)/../dest/include/GLES2:
	mkdir -p $(CURRENT_DIR)/../dest/include/GLES2 
	cp -r GLES2 $(CURRENT_DIR)/../dest/include 

copy_gles3: $(CURRENT_DIR)/../dest/include/GLES3

$(CURRENT_DIR)/../dest/include/GLES3:
	mkdir -p $(CURRENT_DIR)/../dest/include/GLES3
	cp -r GLES3/ $(CURRENT_DIR)/../dest/include

copy_khr: $(CURRENT_DIR)/../dest/include/KHR

$(CURRENT_DIR)/../dest/include/KHR:
	mkdir -p $(CURRENT_DIR)/../dest/include/KHR
	cp -r KHR/ $(CURRENT_DIR)/../dest/include

# build and install libs
build_webrogue_gfx: copy_gles2 copy_gles3 copy_khr
	cd webrogue_gfx && cmake -S . -B build --toolchain=$(CURRENT_DIR)/../toolchain.cmake -DCMAKE_SYSROOT=/wasix-sysroot -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Release
	cmake --build webrogue_gfx/build --target=webrogue_gfx --parallel
	cmake --install webrogue_gfx/build --prefix $(CURRENT_DIR)/../dest

clean_webrogue_gfx:
	rm -rf webrogue_gfx/build

build_SDL2:
	cd SDL2 && cmake -S . -B build --toolchain=$(CURRENT_DIR)/../toolchain.cmake -DCMAKE_SYSROOT=/wasix-sysroot -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Release -DSDL_STATIC=ON -DSDL_SHARED=OFF
	cmake --build SDL2/build --target=SDL2-static --parallel
	cmake --build SDL2/build --target=SDL2main --parallel
	cmake --build SDL2/build --target=SDL2_test --parallel
	cmake --install SDL2/build --prefix $(CURRENT_DIR)/../dest

clean_SDL2:
	rm -rf SDL2/build

build_glfw: build_webrogue_gfx
	cd glfw && cmake -S . -B build --toolchain=$(CURRENT_DIR)/../toolchain.cmake -DCMAKE_SYSROOT=/wasix-sysroot -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Release -DGLFW_BUILD_EXAMPLES=ON -DGLFW_BUILD_WEBROGUE=ON
	cmake --build glfw/build --target=glfw --parallel
	cmake --install glfw/build --prefix $(CURRENT_DIR)/../dest

clean_glfw:
	rm -rf glfw/build

build_raylib: build_glfw build_webrogue_gfx
	cd raylib && cmake -S . -B build --toolchain=$(CURRENT_DIR)/../toolchain.cmake -DCMAKE_SYSROOT=/wasix-sysroot -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Release -DCUSTOMIZE_BUILD=ON -DSUPPORT_MODULE_RAUDIO=OFF -DUSE_AUDIO=OFF -DSUPPORT_QUADS_DRAW_MODE=ON -DOPENGL_VERSION="ES 3.0" -DOPENGL_INCLUDE_DIR=$(CURRENT_DIR)/../dest/include -DUSE_EXTERNAL_GLFW=ON -Dglfw3_DIR=$(CURRENT_DIR)/../dest/lib/cmake/glfw3
	cmake --build raylib/build --target=raylib --parallel
	cmake --install raylib/build --prefix $(CURRENT_DIR)/../dest

clean_raylib:
	rm -rf raylib/build

build_jpeg: 
	cd jpeg && cmake -S . -B build --toolchain=$(CURRENT_DIR)/../toolchain.cmake -DCMAKE_SYSROOT=/wasix-sysroot -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Release
	cmake --build jpeg/build --target=jpeg --parallel
	cmake --install jpeg/build --prefix $(CURRENT_DIR)/../dest

clean_jpeg:
	rm -rf jpeg/build

build_png: build_zlib
	cd libpng && cmake -S . -B build --toolchain=$(CURRENT_DIR)/../toolchain.cmake -DCMAKE_SYSROOT=/wasix-sysroot -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Release -DZLIB_LIBRARY=$(CURRENT_DIR)/../dest/lib/libzlib.a -DZLIB_INCLUDE_DIR=$(CURRENT_DIR)/../dest/include -DPNG_SHARED=OFF -DPNG_STATIC=ON
	cmake --build libpng/build --target=png_static --parallel
	cmake --install libpng/build --prefix $(CURRENT_DIR)/../dest

clean_png:
	rm -rf libpng/build

build_zlib: 
	cd zlib && cmake -S . -B build --toolchain=$(CURRENT_DIR)/../toolchain.cmake -DCMAKE_SYSROOT=/wasix-sysroot -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=$(CURRENT_DIR)/../dest -DZLIB_SKIP_SHARED=ON
	cmake --build zlib/build --target=zlibstatic --parallel
	cmake --install zlib/build --prefix $(CURRENT_DIR)/../dest
	cp $(CURRENT_DIR)/../dest/lib/libzlibstatic.a $(CURRENT_DIR)/../dest/lib/libzlib.a

clean_zlib:
	rm -rf zlib/build

build_libsamplerate: 
	cd libsamplerate && cmake -S . -B build --toolchain=$(CURRENT_DIR)/../toolchain.cmake -DCMAKE_SYSROOT=/wasix-sysroot -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=$(CURRENT_DIR)/../dest -DBUILD_SHARED_LIBS=OFF
	cmake --build libsamplerate/build --target=samplerate --parallel
	cmake --install libsamplerate/build --prefix $(CURRENT_DIR)/../dest

clean_libsamplerate:
	rm -rf libsamplerate/build

build_vorbis: build_ogg
	cd vorbis && cmake -S . -B build --toolchain=$(CURRENT_DIR)/../toolchain.cmake -DCMAKE_SYSROOT=/wasix-sysroot -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=$(CURRENT_DIR)/../dest -DBUILD_SHARED_LIBS=OFF -DOGG_LIBRARY=$(CURRENT_DIR)/../dest/lib/libogg.a -DOGG_INCLUDE_DIR=$(CURRENT_DIR)/../dest/include/ogg/ogg.h
	cmake --build vorbis/build --target=vorbis --parallel
	cmake --build vorbis/build --target=vorbisenc --parallel
	cmake --build vorbis/build --target=vorbisfile --parallel
	cmake --install vorbis/build --prefix $(CURRENT_DIR)/../dest

clean_vorbis:
	rm -rf vorbis/build

build_ogg: 
	cd ogg && cmake -S . -B build --toolchain=$(CURRENT_DIR)/../toolchain.cmake -DCMAKE_SYSROOT=/wasix-sysroot -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=$(CURRENT_DIR)/../dest -DBUILD_SHARED_LIBS=OFF
	cmake --build ogg/build --target=install --parallel

clean_ogg:
	rm -rf ogg/build

build_freetype:
	cd freetype && cmake -S . -B build --toolchain=$(CURRENT_DIR)/../toolchain.cmake -DCMAKE_SYSROOT=/wasix-sysroot -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=$(CURRENT_DIR)/../dest -DBUILD_SHARED_LIBS=OFF
	cmake --build freetype/build --target=install --parallel
	# cmake --install freetype/build --prefix $(CURRENT_DIR)/../dest

clean_freetype:
	rm -rf freetype/build

build_harfbuzz:
	cd harfbuzz && cmake -S . -B ../harfbuzz_build_dir --toolchain=$(CURRENT_DIR)/../toolchain.cmake -DCMAKE_SYSROOT=/wasix-sysroot -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=$(CURRENT_DIR)/../dest -DBUILD_SHARED_LIBS=OFF -DHB_HAVE_ICU=OFF -DHB_BUILD_SUBSET=OFF -DHB_HAVE_FREETYPE=ON -DFREETYPE_INCLUDE_DIR_freetype2=$(CURRENT_DIR)/../dest/include/freetype2 -DFREETYPE_INCLUDE_DIR_ft2build=$(CURRENT_DIR)/../dest/include/freetype2 -DFREETYPE_LIBRARY_DEBUG=$(CURRENT_DIR)/../dest/lib/libfreetype.a -DFREETYPE_LIBRARY_RELEASE=$(CURRENT_DIR)/../dest/lib/libfreetype.a
	cmake --build harfbuzz_build_dir --target=harfbuzz --parallel
	cmake --install harfbuzz_build_dir --prefix $(CURRENT_DIR)/../dest

clean_harfbuzz:
	rm -rf harfbuzz/build

build_curl: build_mbedtls
	cd curl && cmake -S . -B build --toolchain=$(CURRENT_DIR)/../toolchain.cmake -DCMAKE_SYSROOT=/wasix-sysroot -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=$(CURRENT_DIR)/../dest -DBUILD_SHARED_LIBS=OFF -DBUILD_STATIC_LIBS=ON -DCURL_USE_MBEDTLS=ON -DMBEDTLS_INCLUDE_DIR=$(CURRENT_DIR)/../dest/include/mbedtls -DMBEDTLS_LIBRARY=$(CURRENT_DIR)/../dest/lib/libmbedtls.a -DMBEDX509_LIBRARY=$(CURRENT_DIR)/../dest/lib/libmbedx509.a -DMBEDCRYPTO_LIBRARY=$(CURRENT_DIR)/../dest/lib/libmbedcrypto.a -DCURL_USE_LIBPSL=OFF -DBUILD_LIBCURL_DOCS=OFF -DBUILD_MISC_DOCS=OFF -DENABLE_CURL_MANUAL=OFF -DBUILD_CURL_EXE=OFF
	cmake --build curl/build --target=libcurl_static --parallel
	cmake --install curl/build --prefix $(CURRENT_DIR)/../dest

clean_curl:
	rm -rf curl/build

build_mbedtls:
	cd mbedtls && cmake -S . -B build --toolchain=$(CURRENT_DIR)/../toolchain.cmake -DCMAKE_SYSROOT=/wasix-sysroot -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=$(CURRENT_DIR)/../dest -DBUILD_SHARED_LIBS=OFF -DENABLE_TESTING=Off -DGEN_FILES=OFF -DENABLE_PROGRAMS=OFF
	cmake --build mbedtls/build --target=mbedtls --parallel
	cmake --install mbedtls/build --prefix $(CURRENT_DIR)/../dest

clean_mbedtls:
	rm -rf mbedtls/build

clean: clean_webrogue_gfx clean_SDL2 clean_glfw clean_raylib clean_jpeg clean_png clean_zlib clean_libsamplerate clean_vorbis clean_ogg clean_freetype clean_harfbuzz clean_curl clean_mbedtls
	rm -rf $(CURRENT_DIR)/../dest/include
	rm -rf $(CURRENT_DIR)/../dest/lib
