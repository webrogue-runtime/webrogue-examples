cppsdl:
	cmake -S . -B build --toolchain=/opt/webrogue-sdk/share/cmake/wasi-sdk-p1-pthread.cmake -DCMAKE_BUILD_TYPE=Debug
	cmake --build build --target=sdl_dev --parallel

clean:
	rm -rf build
