#include <exception>        // for std::terminate
#include <string.h>         // for memset
#include  <stddef.h>

extern "C" {
void *__cxa_allocate_exception(size_t thrown_size) throw() {
    std::terminate();
}

void
__cxa_throw(void *thrown_object, std::type_info *tinfo, void *dest) {
    std::terminate();
}


void __cxa_rethrow() {}

// void
// __cxa_throw(void *thrown_object, std::type_info *tinfo, void *(_LIBCXXABI_DTOR_FUNC *dest)(void *)) {
// // __cxa_throw(void *thrown_object, std::type_info *tinfo, void (_LIBCXXABI_DTOR_FUNC *dest)(void *)) {
//     std::terminate();
// }

} // extern "C"
