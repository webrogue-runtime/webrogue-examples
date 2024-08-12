__attribute__((import_name("present")))
__attribute__((import_module("webrogue_gfx"))) void
imported_webrogue_gfx_present();

void webrogue_gfx_present() { imported_webrogue_gfx_present(); }

__attribute__((import_name("make_window")))
__attribute__((import_module("webrogue_gfx"))) void
imported_webrogue_gfx_make_window();

void webrogue_gfx_make_window() { imported_webrogue_gfx_make_window(); }
