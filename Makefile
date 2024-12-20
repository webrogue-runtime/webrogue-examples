all: build_simple build_gears build_glfw build_raylib build_libs

build_libs:
	cd libs && $(MAKE)

# apps
build_simple: build_libs
	cd simple && $(MAKE)

build_gears: build_libs
	cd gears && $(MAKE)

build_glfw: build_libs
	cd glfw && $(MAKE)

build_raylib: build_libs
	cd raylib && $(MAKE)

clean:
	cd libs && $(MAKE) clean
	cd simple && $(MAKE) clean
	cd gears && $(MAKE) clean
	cd glfw && $(MAKE) clean
	cd raylib && $(MAKE) clean
