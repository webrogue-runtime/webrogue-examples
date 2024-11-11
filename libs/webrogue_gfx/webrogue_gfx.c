#include <stdint.h>

__attribute__((import_name("present")))
__attribute__((import_module("webrogue-gfx"))) void
imported_webrogue_gfx_present();

void webrogue_gfx_present() { imported_webrogue_gfx_present(); }

__attribute__((import_name("make-window")))
__attribute__((import_module("webrogue-gfx"))) void
imported_webrogue_gfx_make_window();

void webrogue_gfx_make_window() { imported_webrogue_gfx_make_window(); }

__attribute__((import_name("get-window-width")))
__attribute__((import_module("webrogue-gfx"))) uint32_t
imported_webrogue_gfx_get_window_width();

__attribute__((import_name("get-window-height")))
__attribute__((import_module("webrogue-gfx"))) uint32_t
imported_webrogue_gfx_get_window_height();

void webrogue_gfx_window_size(int *width, int *height) {
  *width = imported_webrogue_gfx_get_window_width();
  *height = imported_webrogue_gfx_get_window_height();
}

__attribute__((import_name("get-gl-width")))
__attribute__((import_module("webrogue-gfx"))) uint32_t
imported_webrogue_gfx_get_gl_width();

__attribute__((import_name("get-gl-height")))
__attribute__((import_module("webrogue-gfx"))) uint32_t
imported_webrogue_gfx_get_gl_height();

void webrogue_gfx_gl_size(int *width, int *height) {
  *width = imported_webrogue_gfx_get_gl_width();
  *height = imported_webrogue_gfx_get_gl_height();
}
