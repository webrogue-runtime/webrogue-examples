#include <GLES2/gl2.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "gl2.inc"

__attribute__((import_name("glGetStringData")))
__attribute__((import_module("webrogue_gl"))) void
imported_glGetStringData(unsigned int name, unsigned char *data_ptr);

__attribute__((import_name("glGetStringLen")))
__attribute__((import_module("webrogue_gl"))) int
imported_glGetStringLen(unsigned int name);

struct StrList {
  struct StrList *next;
  GLubyte *str;
};

const GLubyte *glGetString(GLenum name) {
  int len = imported_glGetStringLen(name);
  if (len == -1) {
    return NULL;
  }
  if (!len)
    return (const GLubyte *)"";
  GLubyte *data = malloc(len);
  imported_glGetStringData(name, data);
  static struct StrList *stored_strings = NULL;
  struct StrList *current_str = stored_strings;
  while (current_str) {
    if (strcmp((char *)current_str->str, (char *)data) == 0) {
      free(data);
      return current_str->str;
    }
    current_str = current_str->next;
  }
  struct StrList *new_str = malloc(sizeof(struct StrList));
  new_str->str = data;
  new_str->next = NULL;
  if (!stored_strings) {
    stored_strings = new_str;
    return data;
  }
  current_str = stored_strings;
  while (1) {
    if (current_str->next == NULL) {
      current_str->next = new_str;
      return data;
    }
    current_str = current_str->next;
  }
}
