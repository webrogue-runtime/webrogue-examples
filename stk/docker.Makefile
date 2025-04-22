stk: stk.wrapp

CURRENT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
EXAMPLES_DIR:=$(shell dirname $(CURRENT_DIR))
SYSROOT_DIR=/opt/webrogue-sdk/share/wasi-sysroot/lib/wasm32-wasip1-threads

_BUILD:
	cmake -S stk-code -B stk-code/build --toolchain=/opt/webrogue-sdk/share/cmake/wasi-sdk-p1-pthread.cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Release -DUSE_GLES2=ON -DUSE_MOJOAL=ON -DNO_SHADERC=ON -DUSE_WIIUSE=OFF -DUSE_CRYPTO_OPENSSL=OFF -DJPEG_INCLUDE_DIR=$SYSROOT_DIR/include/jpeg # -DZLIB_INCLUDE_DIR=$SYSROOT_DIR/include -DLIBSAMPLERATE_INCLUDEDIR=$SYSROOT_DIR/include -DOGGVORBIS_OGG_INCLUDE_DIR=$SYSROOT_DIR/include/ogg -DOGGVORBIS_VORBIS_INCLUDE_DIR=$SYSROOT_DIR/include/vorbis -DHARFBUZZ_INCLUDEDIR=$SYSROOT_DIR/include -DMBEDTLS_INCLUDE_DIRS=$SYSROOT_DIR/include/mbedtls -DMBEDCRYPTO_LIBRARY=$SYSROOT_DIR/lib/libmbedcrypto.a -DFREETYPE_INCLUDE_DIRS=$SYSROOT_DIR/include/freetype2
	cmake -S stk-code -B stk-code/build --toolchain=/opt/webrogue-sdk/share/cmake/wasi-sdk-p1-pthread.cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Release -DUSE_GLES2=ON -DUSE_MOJOAL=ON -DNO_SHADERC=ON -DUSE_WIIUSE=OFF -DUSE_CRYPTO_OPENSSL=OFF -DJPEG_INCLUDE_DIR=$SYSROOT_DIR/include/jpeg # -DZLIB_INCLUDE_DIR=$SYSROOT_DIR/include -DLIBSAMPLERATE_INCLUDEDIR=$SYSROOT_DIR/include -DOGGVORBIS_OGG_INCLUDE_DIR=$SYSROOT_DIR/include/ogg -DOGGVORBIS_VORBIS_INCLUDE_DIR=$SYSROOT_DIR/include/vorbis -DHARFBUZZ_INCLUDEDIR=$SYSROOT_DIR/include -DMBEDTLS_INCLUDE_DIRS=$SYSROOT_DIR/include/mbedtls -DMBEDCRYPTO_LIBRARY=$SYSROOT_DIR/lib/libmbedcrypto.a -DFREETYPE_INCLUDE_DIRS=$SYSROOT_DIR/include/freetype2
	# -DSDL2_LIBRARY=$(CURRENT_DIR)/dest/lib/libSDL2.a -DJPEG_LIBRARY=$(CURRENT_DIR)/dest/lib/libjpeg.a -DPNG_LIBRARY=$(CURRENT_DIR)/dest/lib/libpng.a -DPNG_PNG_INCLUDE_DIR=$(CURRENT_DIR)/dest/include/libpng16 -DZLIB_LIBRARY=$(CURRENT_DIR)/dest/lib/libzlib.a -DZLIB_INCLUDE_DIR=$(CURRENT_DIR)/dest/include -DLIBSAMPLERATE_LIBRARY=$(CURRENT_DIR)/dest/lib/libsamplerate.a -DLIBSAMPLERATE_INCLUDEDIR=$(CURRENT_DIR)/dest/include -DOGGVORBIS_OGG_INCLUDE_DIR=$(CURRENT_DIR)/dest/include/ogg -DOGGVORBIS_VORBIS_INCLUDE_DIR=$(CURRENT_DIR)/dest/include/vorbis -DOGGVORBIS_OGG_LIBRARY=$(CURRENT_DIR)/dest/lib/libogg.a -DOGGVORBIS_VORBIS_LIBRARY=$(CURRENT_DIR)/dest/lib/libvorbis.a -DOGGVORBIS_VORBISFILE_LIBRARY=$(CURRENT_DIR)/dest/lib/libvorbisfile.a -DOGGVORBIS_VORBISENC_LIBRARY=$(CURRENT_DIR)/dest/lib/libvorbisenc.a -DFREETYPE_LIBRARY=$(CURRENT_DIR)/dest/lib/libfreetype.a -DFREETYPE_INCLUDE_DIRS=$(CURRENT_DIR)/dest/include/freetype2 -DHARFBUZZ_LIBRARY=$(CURRENT_DIR)/dest/lib/libharfbuzz.a -DHARFBUZZ_INCLUDEDIR=$(CURRENT_DIR)/dest/include -DMBEDCRYPTO_LIBRARY=$(CURRENT_DIR)/dest/lib/libmbedcrypto.a -DMBEDTLS_LIBRARY=$(CURRENT_DIR)/dest/lib/libmbedtls.a -DMBEDX509_LIBRARY=$(CURRENT_DIR)/dest/lib/libmbedx509.a -DMBEDTLS_INCLUDE_DIRS=$(CURRENT_DIR)/dest/include/mbedtls -DUSE_CRYPTO_OPENSSL=OFF -DLIBRESOLV_LIBRARY=/opt/wasi-sdk/share/wasi-sysroot/lib/wasm32-wasi-threads/libresolv.a -DPTHREAD_LIBRARY=/opt/wasi-sdk/share/wasi-sysroot/lib/wasm32-wasi-threads/libpthread.a
	cmake --build stk-code/build --target=supertuxkart -j4
	cp stk-code/build/bin/supertuxkart main.wasm.hot

main.wasm: _BUILD
	cmp -s main.wasm.hot main.wasm; \
	RETVAL=$$?; \
	if [ $$RETVAL -eq 0 ]; then \
	    echo; \
	else \
	    echo; \
	    cp main.wasm.hot main.wasm; \
	fi

stk.wrapp: main.wasm
	rm -f stk.wrapp
	webrogue pack -o stk.wrapp

clean:
	rm -rf stk-code/build stk.wrapp main.wasm
