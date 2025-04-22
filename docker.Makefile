all: build_raylib build_cppcmakeguide build_stk build_empty build_simple

CURRENT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))

# apps
build_empty:
	$(MAKE) -C empty -f docker.Makefile

build_simple:
	$(MAKE) -C simple -f docker.Makefile

build_gears:
	$(MAKE) -C gears -f docker.Makefile

build_glfw:
	$(MAKE) -C glfw -f docker.Makefile

build_raylib:
	$(MAKE) -C raylib -f docker.Makefile

build_stk:
	$(MAKE) -C stk -f docker.Makefile

build_cppcmakeguide:
	$(MAKE) -C cppcmakeguide -f docker.Makefile

clean:
	$(MAKE) -C libs clean
	$(MAKE) -C simple clean
	$(MAKE) -C gears clean
	$(MAKE) -C glfw clean
	$(MAKE) -C raylib clean
