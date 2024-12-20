all: copy_glad copy_gles2 copy_gles3 copy_khr build_webrogue_gfx build_SDL2 build_glfw build_raylib   

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

clean: clean_webrogue_gfx clean_SDL2 clean_glfw clean_raylib
	rm -rf $(CURRENT_DIR)/../dest/include
	rm -rf $(CURRENT_DIR)/../dest/lib
