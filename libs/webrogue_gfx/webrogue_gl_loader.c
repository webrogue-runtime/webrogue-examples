#include <GLES2/gl2.h>
#define GL_GLEXT_PROTOTYPES
#include <GLES2/gl2ext.h>
#include <stddef.h>
#include <string.h>

// clang-format off

__attribute__((import_name("init_ptrs")))
__attribute__((import_module("webrogue_gl"))) void
imported_init_ptrs();

void* webrogueGLLoader(const char* procname) {
  static char loaded = 0;
  if(!loaded) {
    imported_init_ptrs();
    loaded = 1;
  }
  if (strcmp(procname, "glActiveTexture") == 0)
    return (void *)glActiveTexture;
  if (strcmp(procname, "glAttachShader") == 0)
    return (void *)glAttachShader;
  if (strcmp(procname, "glBindAttribLocation") == 0)
    return (void *)glBindAttribLocation;
  if (strcmp(procname, "glBindBuffer") == 0)
    return (void *)glBindBuffer;
  if (strcmp(procname, "glBindFramebuffer") == 0)
    return (void *)glBindFramebuffer;
  if (strcmp(procname, "glBindRenderbuffer") == 0)
    return (void *)glBindRenderbuffer;
  if (strcmp(procname, "glBindTexture") == 0)
    return (void *)glBindTexture;
  if (strcmp(procname, "glBindVertexArrayOES") == 0)
    return (void *)glBindVertexArrayOES;
  if (strcmp(procname, "glBlendColor") == 0)
    return (void *)glBlendColor;
  if (strcmp(procname, "glBlendEquation") == 0)
    return (void *)glBlendEquation;
  if (strcmp(procname, "glBlendEquationSeparate") == 0)
    return (void *)glBlendEquationSeparate;
  if (strcmp(procname, "glBlendFunc") == 0)
    return (void *)glBlendFunc;
  if (strcmp(procname, "glBlendFuncSeparate") == 0)
    return (void *)glBlendFuncSeparate;
  if (strcmp(procname, "glBufferData") == 0)
    return (void *)glBufferData;
  if (strcmp(procname, "glBufferSubData") == 0)
    return (void *)glBufferSubData;
  if (strcmp(procname, "glCheckFramebufferStatus") == 0)
    return (void *)glCheckFramebufferStatus;
  if (strcmp(procname, "glClear") == 0)
    return (void *)glClear;
  if (strcmp(procname, "glClearColor") == 0)
    return (void *)glClearColor;
  if (strcmp(procname, "glClearDepthf") == 0)
    return (void *)glClearDepthf;
  if (strcmp(procname, "glClearStencil") == 0)
    return (void *)glClearStencil;
  if (strcmp(procname, "glColorMask") == 0)
    return (void *)glColorMask;
  if (strcmp(procname, "glCompileShader") == 0)
    return (void *)glCompileShader;
  if (strcmp(procname, "glCompressedTexImage2D") == 0)
    return (void *)glCompressedTexImage2D;
  if (strcmp(procname, "glCompressedTexSubImage2D") == 0)
    return (void *)glCompressedTexSubImage2D;
  if (strcmp(procname, "glCopyTexImage2D") == 0)
    return (void *)glCopyTexImage2D;
  if (strcmp(procname, "glCopyTexSubImage2D") == 0)
    return (void *)glCopyTexSubImage2D;
  if (strcmp(procname, "glCreateProgram") == 0)
    return (void *)glCreateProgram;
  if (strcmp(procname, "glCreateShader") == 0)
    return (void *)glCreateShader;
  if (strcmp(procname, "glCullFace") == 0)
    return (void *)glCullFace;
  if (strcmp(procname, "glDeleteBuffers") == 0)
    return (void *)glDeleteBuffers;
  if (strcmp(procname, "glDeleteFramebuffers") == 0)
    return (void *)glDeleteFramebuffers;
  if (strcmp(procname, "glDeleteProgram") == 0)
    return (void *)glDeleteProgram;
  if (strcmp(procname, "glDeleteRenderbuffers") == 0)
    return (void *)glDeleteRenderbuffers;
  if (strcmp(procname, "glDeleteShader") == 0)
    return (void *)glDeleteShader;
  if (strcmp(procname, "glDeleteTextures") == 0)
    return (void *)glDeleteTextures;
  if (strcmp(procname, "glDeleteVertexArraysOES") == 0)
    return (void *)glDeleteVertexArraysOES;
  if (strcmp(procname, "glDepthFunc") == 0)
    return (void *)glDepthFunc;
  if (strcmp(procname, "glDepthMask") == 0)
    return (void *)glDepthMask;
  if (strcmp(procname, "glDepthRangef") == 0)
    return (void *)glDepthRangef;
  if (strcmp(procname, "glDetachShader") == 0)
    return (void *)glDetachShader;
  if (strcmp(procname, "glDisable") == 0)
    return (void *)glDisable;
  if (strcmp(procname, "glDisableVertexAttribArray") == 0)
    return (void *)glDisableVertexAttribArray;
  if (strcmp(procname, "glDrawArrays") == 0)
    return (void *)glDrawArrays;
  if (strcmp(procname, "glDrawElements") == 0)
    return (void *)glDrawElements;
  if (strcmp(procname, "glEnable") == 0)
    return (void *)glEnable;
  if (strcmp(procname, "glEnableVertexAttribArray") == 0)
    return (void *)glEnableVertexAttribArray;
  if (strcmp(procname, "glFinish") == 0)
    return (void *)glFinish;
  if (strcmp(procname, "glFlush") == 0)
    return (void *)glFlush;
  if (strcmp(procname, "glFramebufferRenderbuffer") == 0)
    return (void *)glFramebufferRenderbuffer;
  if (strcmp(procname, "glFramebufferTexture2D") == 0)
    return (void *)glFramebufferTexture2D;
  if (strcmp(procname, "glFrontFace") == 0)
    return (void *)glFrontFace;
  if (strcmp(procname, "glGenBuffers") == 0)
    return (void *)glGenBuffers;
  if (strcmp(procname, "glGenFramebuffers") == 0)
    return (void *)glGenFramebuffers;
  if (strcmp(procname, "glGenRenderbuffers") == 0)
    return (void *)glGenRenderbuffers;
  if (strcmp(procname, "glGenTextures") == 0)
    return (void *)glGenTextures;
  if (strcmp(procname, "glGenVertexArraysOES") == 0)
    return (void *)glGenVertexArraysOES;
  if (strcmp(procname, "glGenerateMipmap") == 0)
    return (void *)glGenerateMipmap;
  if (strcmp(procname, "glGetActiveAttrib") == 0)
    return (void *)glGetActiveAttrib;
  if (strcmp(procname, "glGetActiveUniform") == 0)
    return (void *)glGetActiveUniform;
  if (strcmp(procname, "glGetAttachedShaders") == 0)
    return (void *)glGetAttachedShaders;
  if (strcmp(procname, "glGetAttribLocation") == 0)
    return (void *)glGetAttribLocation;
  if (strcmp(procname, "glGetBooleanv") == 0)
    return (void *)glGetBooleanv;
  if (strcmp(procname, "glGetBufferParameteriv") == 0)
    return (void *)glGetBufferParameteriv;
  if (strcmp(procname, "glGetError") == 0)
    return (void *)glGetError;
  if (strcmp(procname, "glGetFloatv") == 0)
    return (void *)glGetFloatv;
  if (strcmp(procname, "glGetFramebufferAttachmentParameteriv") == 0)
    return (void *)glGetFramebufferAttachmentParameteriv;
  if (strcmp(procname, "glGetIntegerv") == 0)
    return (void *)glGetIntegerv;
  if (strcmp(procname, "glGetProgramInfoLog") == 0)
    return (void *)glGetProgramInfoLog;
  if (strcmp(procname, "glGetProgramiv") == 0)
    return (void *)glGetProgramiv;
  if (strcmp(procname, "glGetRenderbufferParameteriv") == 0)
    return (void *)glGetRenderbufferParameteriv;
  if (strcmp(procname, "glGetShaderInfoLog") == 0)
    return (void *)glGetShaderInfoLog;
  if (strcmp(procname, "glGetShaderPrecisionFormat") == 0)
    return (void *)glGetShaderPrecisionFormat;
  if (strcmp(procname, "glGetShaderSource") == 0)
    return (void *)glGetShaderSource;
  if (strcmp(procname, "glGetShaderiv") == 0)
    return (void *)glGetShaderiv;
  if (strcmp(procname, "glGetString") == 0)
    return (void *)glGetString;
  if (strcmp(procname, "glGetTexParameterfv") == 0)
    return (void *)glGetTexParameterfv;
  if (strcmp(procname, "glGetTexParameteriv") == 0)
    return (void *)glGetTexParameteriv;
  if (strcmp(procname, "glGetUniformLocation") == 0)
    return (void *)glGetUniformLocation;
  if (strcmp(procname, "glGetUniformfv") == 0)
    return (void *)glGetUniformfv;
  if (strcmp(procname, "glGetUniformiv") == 0)
    return (void *)glGetUniformiv;
  if (strcmp(procname, "glGetVertexAttribPointerv") == 0)
    return (void *)glGetVertexAttribPointerv;
  if (strcmp(procname, "glGetVertexAttribfv") == 0)
    return (void *)glGetVertexAttribfv;
  if (strcmp(procname, "glGetVertexAttribiv") == 0)
    return (void *)glGetVertexAttribiv;
  if (strcmp(procname, "glHint") == 0)
    return (void *)glHint;
  if (strcmp(procname, "glIsBuffer") == 0)
    return (void *)glIsBuffer;
  if (strcmp(procname, "glIsEnabled") == 0)
    return (void *)glIsEnabled;
  if (strcmp(procname, "glIsFramebuffer") == 0)
    return (void *)glIsFramebuffer;
  if (strcmp(procname, "glIsProgram") == 0)
    return (void *)glIsProgram;
  if (strcmp(procname, "glIsRenderbuffer") == 0)
    return (void *)glIsRenderbuffer;
  if (strcmp(procname, "glIsShader") == 0)
    return (void *)glIsShader;
  if (strcmp(procname, "glIsTexture") == 0)
    return (void *)glIsTexture;
  if (strcmp(procname, "glIsVertexArrayOES") == 0)
    return (void *)glIsVertexArrayOES;
  if (strcmp(procname, "glLineWidth") == 0)
    return (void *)glLineWidth;
  if (strcmp(procname, "glLinkProgram") == 0)
    return (void *)glLinkProgram;
  if (strcmp(procname, "glPixelStorei") == 0)
    return (void *)glPixelStorei;
  if (strcmp(procname, "glPolygonOffset") == 0)
    return (void *)glPolygonOffset;
  if (strcmp(procname, "glReadPixels") == 0)
    return (void *)glReadPixels;
  if (strcmp(procname, "glReleaseShaderCompiler") == 0)
    return (void *)glReleaseShaderCompiler;
  if (strcmp(procname, "glRenderbufferStorage") == 0)
    return (void *)glRenderbufferStorage;
  if (strcmp(procname, "glSampleCoverage") == 0)
    return (void *)glSampleCoverage;
  if (strcmp(procname, "glScissor") == 0)
    return (void *)glScissor;
  if (strcmp(procname, "glShaderBinary") == 0)
    return (void *)glShaderBinary;
  if (strcmp(procname, "glShaderSource") == 0)
    return (void *)glShaderSource;
  if (strcmp(procname, "glStencilFunc") == 0)
    return (void *)glStencilFunc;
  if (strcmp(procname, "glStencilFuncSeparate") == 0)
    return (void *)glStencilFuncSeparate;
  if (strcmp(procname, "glStencilMask") == 0)
    return (void *)glStencilMask;
  if (strcmp(procname, "glStencilMaskSeparate") == 0)
    return (void *)glStencilMaskSeparate;
  if (strcmp(procname, "glStencilOp") == 0)
    return (void *)glStencilOp;
  if (strcmp(procname, "glStencilOpSeparate") == 0)
    return (void *)glStencilOpSeparate;
  if (strcmp(procname, "glTexImage2D") == 0)
    return (void *)glTexImage2D;
  if (strcmp(procname, "glTexParameterf") == 0)
    return (void *)glTexParameterf;
  if (strcmp(procname, "glTexParameterfv") == 0)
    return (void *)glTexParameterfv;
  if (strcmp(procname, "glTexParameteri") == 0)
    return (void *)glTexParameteri;
  if (strcmp(procname, "glTexParameteriv") == 0)
    return (void *)glTexParameteriv;
  if (strcmp(procname, "glTexSubImage2D") == 0)
    return (void *)glTexSubImage2D;
  if (strcmp(procname, "glUniform1f") == 0)
    return (void *)glUniform1f;
  if (strcmp(procname, "glUniform1fv") == 0)
    return (void *)glUniform1fv;
  if (strcmp(procname, "glUniform1i") == 0)
    return (void *)glUniform1i;
  if (strcmp(procname, "glUniform1iv") == 0)
    return (void *)glUniform1iv;
  if (strcmp(procname, "glUniform2f") == 0)
    return (void *)glUniform2f;
  if (strcmp(procname, "glUniform2fv") == 0)
    return (void *)glUniform2fv;
  if (strcmp(procname, "glUniform2i") == 0)
    return (void *)glUniform2i;
  if (strcmp(procname, "glUniform2iv") == 0)
    return (void *)glUniform2iv;
  if (strcmp(procname, "glUniform3f") == 0)
    return (void *)glUniform3f;
  if (strcmp(procname, "glUniform3fv") == 0)
    return (void *)glUniform3fv;
  if (strcmp(procname, "glUniform3i") == 0)
    return (void *)glUniform3i;
  if (strcmp(procname, "glUniform3iv") == 0)
    return (void *)glUniform3iv;
  if (strcmp(procname, "glUniform4f") == 0)
    return (void *)glUniform4f;
  if (strcmp(procname, "glUniform4fv") == 0)
    return (void *)glUniform4fv;
  if (strcmp(procname, "glUniform4i") == 0)
    return (void *)glUniform4i;
  if (strcmp(procname, "glUniform4iv") == 0)
    return (void *)glUniform4iv;
  if (strcmp(procname, "glUniformMatrix2fv") == 0)
    return (void *)glUniformMatrix2fv;
  if (strcmp(procname, "glUniformMatrix3fv") == 0)
    return (void *)glUniformMatrix3fv;
  if (strcmp(procname, "glUniformMatrix4fv") == 0)
    return (void *)glUniformMatrix4fv;
  if (strcmp(procname, "glUseProgram") == 0)
    return (void *)glUseProgram;
  if (strcmp(procname, "glValidateProgram") == 0)
    return (void *)glValidateProgram;
  if (strcmp(procname, "glVertexAttrib1f") == 0)
    return (void *)glVertexAttrib1f;
  if (strcmp(procname, "glVertexAttrib1fv") == 0)
    return (void *)glVertexAttrib1fv;
  if (strcmp(procname, "glVertexAttrib2f") == 0)
    return (void *)glVertexAttrib2f;
  if (strcmp(procname, "glVertexAttrib2fv") == 0)
    return (void *)glVertexAttrib2fv;
  if (strcmp(procname, "glVertexAttrib3f") == 0)
    return (void *)glVertexAttrib3f;
  if (strcmp(procname, "glVertexAttrib3fv") == 0)
    return (void *)glVertexAttrib3fv;
  if (strcmp(procname, "glVertexAttrib4f") == 0)
    return (void *)glVertexAttrib4f;
  if (strcmp(procname, "glVertexAttrib4fv") == 0)
    return (void *)glVertexAttrib4fv;
  if (strcmp(procname, "glVertexAttribPointer") == 0)
    return (void *)glVertexAttribPointer;
  if (strcmp(procname, "glViewport") == 0)
    return (void *)glViewport;
  return NULL;
}
        