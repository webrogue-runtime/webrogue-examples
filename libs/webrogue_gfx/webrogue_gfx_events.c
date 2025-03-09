// GENERATED BY webrogue-event-apigen. DO NOT EDIT MANUALLY
#include "webrogue_gfx.h"
#include <stdlib.h>

__attribute__((import_name("poll")))
__attribute__((import_module("webrogue-gfx")))
uint32_t imported_webrogue_gfx_poll();

__attribute__((import_name("poll-read")))
__attribute__((import_module("webrogue-gfx")))
void imported_webrogue_gfx_poll_read(void *buf);
#define BUF_SIZE(LEN) if(buffer_len < LEN) {\
    free(buffer_data);\
     result.type = webrogue_event_type_invalid;\
    return result;\
}
#define RETURN free(buffer_data); return result;
#define GET(TYPE, OFFSET) *((TYPE*)(((char*)buffer_data) + OFFSET));

webrogue_event webrogue_gfx_poll() {
    webrogue_event result;
    uint32_t buffer_len = imported_webrogue_gfx_poll();
    void* buffer_data = malloc(buffer_len);
    BUF_SIZE(4);
    imported_webrogue_gfx_poll_read(buffer_data);
    result.type = GET(uint32_t, 0);
    switch (result.type) {
        case webrogue_event_type_mouse: {
            BUF_SIZE(12);
            result.inner.mouse.x = GET(uint32_t, 4);
            result.inner.mouse.y = GET(uint32_t, 8);
            RETURN;
        }
        default: {
            result.type = webrogue_event_type_invalid;
            RETURN;
        }
    }
}
#undef BUF_SIZE
#undef RETURN
#undef GET
