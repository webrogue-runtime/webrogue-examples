BUILD_TYPE=Release

stk: data
	cmake -S stk-code -B stk-code/build --toolchain=/opt/webrogue-sdk/share/cmake/wasi-sdk-p1-pthread.cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=$(BUILD_TYPE) -DUSE_GLES2=ON -DUSE_MOJOAL=ON -DNO_SHADERC=ON -DUSE_WIIUSE=OFF -DUSE_CRYPTO_OPENSSL=OFF -DJPEG_INCLUDE_DIR=$SYSROOT_DIR/include/jpeg
	cmake -S stk-code -B stk-code/build --toolchain=/opt/webrogue-sdk/share/cmake/wasi-sdk-p1-pthread.cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=$(BUILD_TYPE) -DUSE_GLES2=ON -DUSE_MOJOAL=ON -DNO_SHADERC=ON -DUSE_WIIUSE=OFF -DUSE_CRYPTO_OPENSSL=OFF -DJPEG_INCLUDE_DIR=$SYSROOT_DIR/include/jpeg
	cmake --build stk-code/build --target=supertuxkart --parallel $(nproc)

stk-assets:
	svn co https://svn.code.sf.net/p/supertuxkart/code/stk-assets stk-assets

data: stk-code/data/karts stk-code/data/library stk-code/data/models stk-code/data/music stk-code/data/sfx stk-code/data/textures stk-code/data/tracks

stk-code/data/karts: stk-assets
	cp -r stk-assets/karts stk-code/data/karts

stk-code/data/library: stk-assets
	cp -r stk-assets/library stk-code/data/library

stk-code/data/models: stk-assets
	cp -r stk-assets/models stk-code/data/models

stk-code/data/music: stk-assets
	cp -r stk-assets/music stk-code/data/music

stk-code/data/sfx: stk-assets
	cp -r stk-assets/sfx stk-code/data/sfx

stk-code/data/textures: stk-assets
	cp -r stk-assets/textures stk-code/data/textures

stk-code/data/tracks: stk-assets
	cp -r stk-assets/tracks stk-code/data/tracks

clean:
	rm -rf stk-code/build
