stk: stk-assets
	cmake -S stk-code -B stk-code/build --toolchain=/opt/webrogue-sdk/share/cmake/wasi-sdk-p1-pthread.cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Debug -DUSE_GLES2=ON -DUSE_MOJOAL=ON -DNO_SHADERC=ON -DUSE_WIIUSE=OFF -DUSE_CRYPTO_OPENSSL=OFF -DJPEG_INCLUDE_DIR=$SYSROOT_DIR/include/jpeg # -DZLIB_INCLUDE_DIR=$SYSROOT_DIR/include -DLIBSAMPLERATE_INCLUDEDIR=$SYSROOT_DIR/include -DOGGVORBIS_OGG_INCLUDE_DIR=$SYSROOT_DIR/include/ogg -DOGGVORBIS_VORBIS_INCLUDE_DIR=$SYSROOT_DIR/include/vorbis -DHARFBUZZ_INCLUDEDIR=$SYSROOT_DIR/include -DMBEDTLS_INCLUDE_DIRS=$SYSROOT_DIR/include/mbedtls -DMBEDCRYPTO_LIBRARY=$SYSROOT_DIR/lib/libmbedcrypto.a -DFREETYPE_INCLUDE_DIRS=$SYSROOT_DIR/include/freetype2
	cmake -S stk-code -B stk-code/build --toolchain=/opt/webrogue-sdk/share/cmake/wasi-sdk-p1-pthread.cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Debug -DUSE_GLES2=ON -DUSE_MOJOAL=ON -DNO_SHADERC=ON -DUSE_WIIUSE=OFF -DUSE_CRYPTO_OPENSSL=OFF -DJPEG_INCLUDE_DIR=$SYSROOT_DIR/include/jpeg # -DZLIB_INCLUDE_DIR=$SYSROOT_DIR/include -DLIBSAMPLERATE_INCLUDEDIR=$SYSROOT_DIR/include -DOGGVORBIS_OGG_INCLUDE_DIR=$SYSROOT_DIR/include/ogg -DOGGVORBIS_VORBIS_INCLUDE_DIR=$SYSROOT_DIR/include/vorbis -DHARFBUZZ_INCLUDEDIR=$SYSROOT_DIR/include -DMBEDTLS_INCLUDE_DIRS=$SYSROOT_DIR/include/mbedtls -DMBEDCRYPTO_LIBRARY=$SYSROOT_DIR/lib/libmbedcrypto.a -DFREETYPE_INCLUDE_DIRS=$SYSROOT_DIR/include/freetype2
	cmake --build stk-code/build --target=supertuxkart -j4

stk-assets:
	svn co https://svn.code.sf.net/p/supertuxkart/code/stk-assets stk-assets

clean:
	rm -rf stk-code/build
