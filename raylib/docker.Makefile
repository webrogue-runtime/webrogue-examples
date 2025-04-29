raylib_:
	cmake -S . -B build --toolchain=/opt/webrogue-sdk/share/cmake/wasi-sdk-p1-pthread.cmake -DCMAKE_BUILD_TYPE=Release -DCUSTOMIZE_BUILD=ON -DSUPPORT_MODULE_RAUDIO=OFF -DUSE_AUDIO=OFF -DSUPPORT_QUADS_DRAW_MODE=ON -DOPENGL_VERSION="ES 3.0" -DOPENGL_INCLUDE_DIR=/opt/wasip1/include -DPLATFORM=SDL -DUSE_EXTERNAL_GLFW=ON -Dglfw3_DIR=/opt/wasip1/lib/cmake/glfw3 -DSDL2_DIR=/opt/wasip1/lib/cmake/SDL2
	cmake --build build --target=webrogue_raylib_example --parallel

clean:
	rm -rf build
