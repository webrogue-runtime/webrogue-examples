all: build_raylib build_simple build_stk

CURRENT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))

# apps
build_simple:
	$(MAKE) -C simple

build_gears:
	cd gears && $(MAKE)

build_glfw:
	cd glfw && $(MAKE)

build_raylib:
	$(MAKE) -C raylib

build_stk:
	$(MAKE) -C stk

clean:
	cd libs && $(MAKE) clean
	cd simple && $(MAKE) clean
	cd gears && $(MAKE) clean
	cd glfw && $(MAKE) clean
	$(MAKE) -C raylib clean
