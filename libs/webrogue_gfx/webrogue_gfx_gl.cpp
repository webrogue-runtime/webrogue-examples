#include <GLES2/gl2.h>
#define GL_GLEXT_PROTOTYPES
#include <GLES2/gl2ext.h>
#include <GLES3/gl3.h>
#include <stddef.h>
#include <string.h>
#include "HostConnection.h"
#include "ThreadInfo.h"
#include "GL2Encoder.h"

// clang-format off

extern "C" void *__cxa_allocate_exception(size_t thrown_size) throw() {
    printf("__cxa_allocate_exception\n");
    size_t actual_size = thrown_size+1024;
    void* result = malloc(actual_size);
    ::memset(result, 0, actual_size);
    
    return ((char*)result)+512;
}

extern "C" void __cxa_throw(void *thrown_object, std::type_info *tinfo, void (*dest)(void *)) {
    printf("__cxa_throw\n");
    __builtin_unreachable();
    abort();
}

__attribute__((import_name("init-gl")))
__attribute__((import_module("webrogue-gfx"))) void
imported_init_gl();

extern "C" void* webrogueGLLoader(const char* procname) {
  if(!getEGLThreadInfo()->hostConn) {
    imported_init_gl();
    getEGLThreadInfo()->hostConn = HostConnection::createUnique();
    // TODO GLSharedGroup should be stored in getEGLThreadInfo()->currentContext->sharedGroup
    getEGLThreadInfo()->hostConn->gl2Encoder()->setSharedGroup(
      gfxstream::guest::GLSharedGroupPtr(
        new gfxstream::guest::GLSharedGroup()
      )
    );
    getEGLThreadInfo()->hostConn->gl2Encoder()->setClientState(
      new gfxstream::guest::GLClientState(2, 0)
    );
  }
  if (strcmp(procname, "glActiveTexture") == 0)
    return (void *)glActiveTexture;
  if (strcmp(procname, "glAttachShader") == 0)
    return (void *)glAttachShader;
  if (strcmp(procname, "glBeginQuery") == 0)
    return (void *)glBeginQuery;
  if (strcmp(procname, "glBeginTransformFeedback") == 0)
    return (void *)glBeginTransformFeedback;
  if (strcmp(procname, "glBindAttribLocation") == 0)
    return (void *)glBindAttribLocation;
  if (strcmp(procname, "glBindBuffer") == 0)
    return (void *)glBindBuffer;
  if (strcmp(procname, "glBindBufferBase") == 0)
    return (void *)glBindBufferBase;
  if (strcmp(procname, "glBindBufferRange") == 0)
    return (void *)glBindBufferRange;
  if (strcmp(procname, "glBindFramebuffer") == 0)
    return (void *)glBindFramebuffer;
  if (strcmp(procname, "glBindRenderbuffer") == 0)
    return (void *)glBindRenderbuffer;
  if (strcmp(procname, "glBindSampler") == 0)
    return (void *)glBindSampler;
  if (strcmp(procname, "glBindTexture") == 0)
    return (void *)glBindTexture;
  if (strcmp(procname, "glBindTransformFeedback") == 0)
    return (void *)glBindTransformFeedback;
  if (strcmp(procname, "glBindVertexArray") == 0)
    return (void *)glBindVertexArray;
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
  if (strcmp(procname, "glBlitFramebuffer") == 0)
    return (void *)glBlitFramebuffer;
  if (strcmp(procname, "glBufferData") == 0)
    return (void *)glBufferData;
  if (strcmp(procname, "glBufferSubData") == 0)
    return (void *)glBufferSubData;
  if (strcmp(procname, "glCheckFramebufferStatus") == 0)
    return (void *)glCheckFramebufferStatus;
  if (strcmp(procname, "glClear") == 0)
    return (void *)glClear;
  if (strcmp(procname, "glClearBufferfi") == 0)
    return (void *)glClearBufferfi;
  if (strcmp(procname, "glClearBufferfv") == 0)
    return (void *)glClearBufferfv;
  if (strcmp(procname, "glClearBufferiv") == 0)
    return (void *)glClearBufferiv;
  if (strcmp(procname, "glClearBufferuiv") == 0)
    return (void *)glClearBufferuiv;
  if (strcmp(procname, "glClearColor") == 0)
    return (void *)glClearColor;
  if (strcmp(procname, "glClearDepthf") == 0)
    return (void *)glClearDepthf;
  if (strcmp(procname, "glClearStencil") == 0)
    return (void *)glClearStencil;
  if (strcmp(procname, "glClientWaitSync") == 0)
    return (void *)glClientWaitSync;
  if (strcmp(procname, "glColorMask") == 0)
    return (void *)glColorMask;
  if (strcmp(procname, "glCompileShader") == 0)
    return (void *)glCompileShader;
  if (strcmp(procname, "glCompressedTexImage2D") == 0)
    return (void *)glCompressedTexImage2D;
  if (strcmp(procname, "glCompressedTexImage3D") == 0)
    return (void *)glCompressedTexImage3D;
  if (strcmp(procname, "glCompressedTexSubImage2D") == 0)
    return (void *)glCompressedTexSubImage2D;
  if (strcmp(procname, "glCompressedTexSubImage3D") == 0)
    return (void *)glCompressedTexSubImage3D;
  if (strcmp(procname, "glCopyBufferSubData") == 0)
    return (void *)glCopyBufferSubData;
  if (strcmp(procname, "glCopyTexImage2D") == 0)
    return (void *)glCopyTexImage2D;
  if (strcmp(procname, "glCopyTexSubImage2D") == 0)
    return (void *)glCopyTexSubImage2D;
  if (strcmp(procname, "glCopyTexSubImage3D") == 0)
    return (void *)glCopyTexSubImage3D;
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
  if (strcmp(procname, "glDeleteQueries") == 0)
    return (void *)glDeleteQueries;
  if (strcmp(procname, "glDeleteRenderbuffers") == 0)
    return (void *)glDeleteRenderbuffers;
  if (strcmp(procname, "glDeleteSamplers") == 0)
    return (void *)glDeleteSamplers;
  if (strcmp(procname, "glDeleteShader") == 0)
    return (void *)glDeleteShader;
  if (strcmp(procname, "glDeleteSync") == 0)
    return (void *)glDeleteSync;
  if (strcmp(procname, "glDeleteTextures") == 0)
    return (void *)glDeleteTextures;
  if (strcmp(procname, "glDeleteTransformFeedbacks") == 0)
    return (void *)glDeleteTransformFeedbacks;
  if (strcmp(procname, "glDeleteVertexArrays") == 0)
    return (void *)glDeleteVertexArrays;
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
  if (strcmp(procname, "glDrawArraysInstanced") == 0)
    return (void *)glDrawArraysInstanced;
  if (strcmp(procname, "glDrawBuffers") == 0)
    return (void *)glDrawBuffers;
  if (strcmp(procname, "glDrawElements") == 0)
    return (void *)glDrawElements;
  if (strcmp(procname, "glDrawElementsInstanced") == 0)
    return (void *)glDrawElementsInstanced;
  if (strcmp(procname, "glDrawRangeElements") == 0)
    return (void *)glDrawRangeElements;
  if (strcmp(procname, "glEnable") == 0)
    return (void *)glEnable;
  if (strcmp(procname, "glEnableVertexAttribArray") == 0)
    return (void *)glEnableVertexAttribArray;
  if (strcmp(procname, "glEndQuery") == 0)
    return (void *)glEndQuery;
  if (strcmp(procname, "glEndTransformFeedback") == 0)
    return (void *)glEndTransformFeedback;
  if (strcmp(procname, "glFenceSync") == 0)
    return (void *)glFenceSync;
  if (strcmp(procname, "glFinish") == 0)
    return (void *)glFinish;
  if (strcmp(procname, "glFlush") == 0)
    return (void *)glFlush;
  if (strcmp(procname, "glFlushMappedBufferRange") == 0)
    return (void *)glFlushMappedBufferRange;
  if (strcmp(procname, "glFramebufferRenderbuffer") == 0)
    return (void *)glFramebufferRenderbuffer;
  if (strcmp(procname, "glFramebufferTexture2D") == 0)
    return (void *)glFramebufferTexture2D;
  if (strcmp(procname, "glFramebufferTextureLayer") == 0)
    return (void *)glFramebufferTextureLayer;
  if (strcmp(procname, "glFrontFace") == 0)
    return (void *)glFrontFace;
  if (strcmp(procname, "glGenBuffers") == 0)
    return (void *)glGenBuffers;
  if (strcmp(procname, "glGenFramebuffers") == 0)
    return (void *)glGenFramebuffers;
  if (strcmp(procname, "glGenQueries") == 0)
    return (void *)glGenQueries;
  if (strcmp(procname, "glGenRenderbuffers") == 0)
    return (void *)glGenRenderbuffers;
  if (strcmp(procname, "glGenSamplers") == 0)
    return (void *)glGenSamplers;
  if (strcmp(procname, "glGenTextures") == 0)
    return (void *)glGenTextures;
  if (strcmp(procname, "glGenTransformFeedbacks") == 0)
    return (void *)glGenTransformFeedbacks;
  if (strcmp(procname, "glGenVertexArrays") == 0)
    return (void *)glGenVertexArrays;
  if (strcmp(procname, "glGenVertexArraysOES") == 0)
    return (void *)glGenVertexArraysOES;
  if (strcmp(procname, "glGenerateMipmap") == 0)
    return (void *)glGenerateMipmap;
  if (strcmp(procname, "glGetActiveAttrib") == 0)
    return (void *)glGetActiveAttrib;
  if (strcmp(procname, "glGetActiveUniform") == 0)
    return (void *)glGetActiveUniform;
  if (strcmp(procname, "glGetActiveUniformBlockName") == 0)
    return (void *)glGetActiveUniformBlockName;
  if (strcmp(procname, "glGetActiveUniformBlockiv") == 0)
    return (void *)glGetActiveUniformBlockiv;
  if (strcmp(procname, "glGetActiveUniformsiv") == 0)
    return (void *)glGetActiveUniformsiv;
  if (strcmp(procname, "glGetAttachedShaders") == 0)
    return (void *)glGetAttachedShaders;
  if (strcmp(procname, "glGetAttribLocation") == 0)
    return (void *)glGetAttribLocation;
  if (strcmp(procname, "glGetBooleanv") == 0)
    return (void *)glGetBooleanv;
  if (strcmp(procname, "glGetBufferParameteri64v") == 0)
    return (void *)glGetBufferParameteri64v;
  if (strcmp(procname, "glGetBufferParameteriv") == 0)
    return (void *)glGetBufferParameteriv;
  if (strcmp(procname, "glGetBufferPointerv") == 0)
    return (void *)glGetBufferPointerv;
  if (strcmp(procname, "glGetError") == 0)
    return (void *)glGetError;
  if (strcmp(procname, "glGetFloatv") == 0)
    return (void *)glGetFloatv;
  if (strcmp(procname, "glGetFragDataLocation") == 0)
    return (void *)glGetFragDataLocation;
  if (strcmp(procname, "glGetFramebufferAttachmentParameteriv") == 0)
    return (void *)glGetFramebufferAttachmentParameteriv;
  if (strcmp(procname, "glGetInteger64i_v") == 0)
    return (void *)glGetInteger64i_v;
  if (strcmp(procname, "glGetInteger64v") == 0)
    return (void *)glGetInteger64v;
  if (strcmp(procname, "glGetIntegeri_v") == 0)
    return (void *)glGetIntegeri_v;
  if (strcmp(procname, "glGetIntegerv") == 0)
    return (void *)glGetIntegerv;
  if (strcmp(procname, "glGetInternalformativ") == 0)
    return (void *)glGetInternalformativ;
  if (strcmp(procname, "glGetProgramBinary") == 0)
    return (void *)glGetProgramBinary;
  if (strcmp(procname, "glGetProgramInfoLog") == 0)
    return (void *)glGetProgramInfoLog;
  if (strcmp(procname, "glGetProgramiv") == 0)
    return (void *)glGetProgramiv;
  if (strcmp(procname, "glGetQueryObjectuiv") == 0)
    return (void *)glGetQueryObjectuiv;
  if (strcmp(procname, "glGetQueryiv") == 0)
    return (void *)glGetQueryiv;
  if (strcmp(procname, "glGetRenderbufferParameteriv") == 0)
    return (void *)glGetRenderbufferParameteriv;
  if (strcmp(procname, "glGetSamplerParameterfv") == 0)
    return (void *)glGetSamplerParameterfv;
  if (strcmp(procname, "glGetSamplerParameteriv") == 0)
    return (void *)glGetSamplerParameteriv;
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
  if (strcmp(procname, "glGetStringi") == 0)
    return (void *)glGetStringi;
  if (strcmp(procname, "glGetSynciv") == 0)
    return (void *)glGetSynciv;
  if (strcmp(procname, "glGetTexParameterfv") == 0)
    return (void *)glGetTexParameterfv;
  if (strcmp(procname, "glGetTexParameteriv") == 0)
    return (void *)glGetTexParameteriv;
  if (strcmp(procname, "glGetTransformFeedbackVarying") == 0)
    return (void *)glGetTransformFeedbackVarying;
  if (strcmp(procname, "glGetUniformBlockIndex") == 0)
    return (void *)glGetUniformBlockIndex;
  if (strcmp(procname, "glGetUniformIndices") == 0)
    return (void *)glGetUniformIndices;
  if (strcmp(procname, "glGetUniformLocation") == 0)
    return (void *)glGetUniformLocation;
  if (strcmp(procname, "glGetUniformfv") == 0)
    return (void *)glGetUniformfv;
  if (strcmp(procname, "glGetUniformiv") == 0)
    return (void *)glGetUniformiv;
  if (strcmp(procname, "glGetUniformuiv") == 0)
    return (void *)glGetUniformuiv;
  if (strcmp(procname, "glGetVertexAttribIiv") == 0)
    return (void *)glGetVertexAttribIiv;
  if (strcmp(procname, "glGetVertexAttribIuiv") == 0)
    return (void *)glGetVertexAttribIuiv;
  if (strcmp(procname, "glGetVertexAttribPointerv") == 0)
    return (void *)glGetVertexAttribPointerv;
  if (strcmp(procname, "glGetVertexAttribfv") == 0)
    return (void *)glGetVertexAttribfv;
  if (strcmp(procname, "glGetVertexAttribiv") == 0)
    return (void *)glGetVertexAttribiv;
  if (strcmp(procname, "glHint") == 0)
    return (void *)glHint;
  if (strcmp(procname, "glInvalidateFramebuffer") == 0)
    return (void *)glInvalidateFramebuffer;
  if (strcmp(procname, "glInvalidateSubFramebuffer") == 0)
    return (void *)glInvalidateSubFramebuffer;
  if (strcmp(procname, "glIsBuffer") == 0)
    return (void *)glIsBuffer;
  if (strcmp(procname, "glIsEnabled") == 0)
    return (void *)glIsEnabled;
  if (strcmp(procname, "glIsFramebuffer") == 0)
    return (void *)glIsFramebuffer;
  if (strcmp(procname, "glIsProgram") == 0)
    return (void *)glIsProgram;
  if (strcmp(procname, "glIsQuery") == 0)
    return (void *)glIsQuery;
  if (strcmp(procname, "glIsRenderbuffer") == 0)
    return (void *)glIsRenderbuffer;
  if (strcmp(procname, "glIsSampler") == 0)
    return (void *)glIsSampler;
  if (strcmp(procname, "glIsShader") == 0)
    return (void *)glIsShader;
  if (strcmp(procname, "glIsSync") == 0)
    return (void *)glIsSync;
  if (strcmp(procname, "glIsTexture") == 0)
    return (void *)glIsTexture;
  if (strcmp(procname, "glIsTransformFeedback") == 0)
    return (void *)glIsTransformFeedback;
  if (strcmp(procname, "glIsVertexArray") == 0)
    return (void *)glIsVertexArray;
  if (strcmp(procname, "glIsVertexArrayOES") == 0)
    return (void *)glIsVertexArrayOES;
  if (strcmp(procname, "glLineWidth") == 0)
    return (void *)glLineWidth;
  if (strcmp(procname, "glLinkProgram") == 0)
    return (void *)glLinkProgram;
  if (strcmp(procname, "glMapBufferRange") == 0)
    return (void *)glMapBufferRange;
  if (strcmp(procname, "glPauseTransformFeedback") == 0)
    return (void *)glPauseTransformFeedback;
  if (strcmp(procname, "glPixelStorei") == 0)
    return (void *)glPixelStorei;
  if (strcmp(procname, "glPolygonOffset") == 0)
    return (void *)glPolygonOffset;
  if (strcmp(procname, "glProgramBinary") == 0)
    return (void *)glProgramBinary;
  if (strcmp(procname, "glProgramParameteri") == 0)
    return (void *)glProgramParameteri;
  if (strcmp(procname, "glReadBuffer") == 0)
    return (void *)glReadBuffer;
  if (strcmp(procname, "glReadPixels") == 0)
    return (void *)glReadPixels;
  if (strcmp(procname, "glReleaseShaderCompiler") == 0)
    return (void *)glReleaseShaderCompiler;
  if (strcmp(procname, "glRenderbufferStorage") == 0)
    return (void *)glRenderbufferStorage;
  if (strcmp(procname, "glRenderbufferStorageMultisample") == 0)
    return (void *)glRenderbufferStorageMultisample;
  if (strcmp(procname, "glResumeTransformFeedback") == 0)
    return (void *)glResumeTransformFeedback;
  if (strcmp(procname, "glSampleCoverage") == 0)
    return (void *)glSampleCoverage;
  if (strcmp(procname, "glSamplerParameterf") == 0)
    return (void *)glSamplerParameterf;
  if (strcmp(procname, "glSamplerParameterfv") == 0)
    return (void *)glSamplerParameterfv;
  if (strcmp(procname, "glSamplerParameteri") == 0)
    return (void *)glSamplerParameteri;
  if (strcmp(procname, "glSamplerParameteriv") == 0)
    return (void *)glSamplerParameteriv;
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
  if (strcmp(procname, "glTexImage3D") == 0)
    return (void *)glTexImage3D;
  if (strcmp(procname, "glTexParameterf") == 0)
    return (void *)glTexParameterf;
  if (strcmp(procname, "glTexParameterfv") == 0)
    return (void *)glTexParameterfv;
  if (strcmp(procname, "glTexParameteri") == 0)
    return (void *)glTexParameteri;
  if (strcmp(procname, "glTexParameteriv") == 0)
    return (void *)glTexParameteriv;
  if (strcmp(procname, "glTexStorage2D") == 0)
    return (void *)glTexStorage2D;
  if (strcmp(procname, "glTexStorage3D") == 0)
    return (void *)glTexStorage3D;
  if (strcmp(procname, "glTexSubImage2D") == 0)
    return (void *)glTexSubImage2D;
  if (strcmp(procname, "glTexSubImage3D") == 0)
    return (void *)glTexSubImage3D;
  if (strcmp(procname, "glTransformFeedbackVaryings") == 0)
    return (void *)glTransformFeedbackVaryings;
  if (strcmp(procname, "glUniform1f") == 0)
    return (void *)glUniform1f;
  if (strcmp(procname, "glUniform1fv") == 0)
    return (void *)glUniform1fv;
  if (strcmp(procname, "glUniform1i") == 0)
    return (void *)glUniform1i;
  if (strcmp(procname, "glUniform1iv") == 0)
    return (void *)glUniform1iv;
  if (strcmp(procname, "glUniform1ui") == 0)
    return (void *)glUniform1ui;
  if (strcmp(procname, "glUniform1uiv") == 0)
    return (void *)glUniform1uiv;
  if (strcmp(procname, "glUniform2f") == 0)
    return (void *)glUniform2f;
  if (strcmp(procname, "glUniform2fv") == 0)
    return (void *)glUniform2fv;
  if (strcmp(procname, "glUniform2i") == 0)
    return (void *)glUniform2i;
  if (strcmp(procname, "glUniform2iv") == 0)
    return (void *)glUniform2iv;
  if (strcmp(procname, "glUniform2ui") == 0)
    return (void *)glUniform2ui;
  if (strcmp(procname, "glUniform2uiv") == 0)
    return (void *)glUniform2uiv;
  if (strcmp(procname, "glUniform3f") == 0)
    return (void *)glUniform3f;
  if (strcmp(procname, "glUniform3fv") == 0)
    return (void *)glUniform3fv;
  if (strcmp(procname, "glUniform3i") == 0)
    return (void *)glUniform3i;
  if (strcmp(procname, "glUniform3iv") == 0)
    return (void *)glUniform3iv;
  if (strcmp(procname, "glUniform3ui") == 0)
    return (void *)glUniform3ui;
  if (strcmp(procname, "glUniform3uiv") == 0)
    return (void *)glUniform3uiv;
  if (strcmp(procname, "glUniform4f") == 0)
    return (void *)glUniform4f;
  if (strcmp(procname, "glUniform4fv") == 0)
    return (void *)glUniform4fv;
  if (strcmp(procname, "glUniform4i") == 0)
    return (void *)glUniform4i;
  if (strcmp(procname, "glUniform4iv") == 0)
    return (void *)glUniform4iv;
  if (strcmp(procname, "glUniform4ui") == 0)
    return (void *)glUniform4ui;
  if (strcmp(procname, "glUniform4uiv") == 0)
    return (void *)glUniform4uiv;
  if (strcmp(procname, "glUniformBlockBinding") == 0)
    return (void *)glUniformBlockBinding;
  if (strcmp(procname, "glUniformMatrix2fv") == 0)
    return (void *)glUniformMatrix2fv;
  if (strcmp(procname, "glUniformMatrix2x3fv") == 0)
    return (void *)glUniformMatrix2x3fv;
  if (strcmp(procname, "glUniformMatrix2x4fv") == 0)
    return (void *)glUniformMatrix2x4fv;
  if (strcmp(procname, "glUniformMatrix3fv") == 0)
    return (void *)glUniformMatrix3fv;
  if (strcmp(procname, "glUniformMatrix3x2fv") == 0)
    return (void *)glUniformMatrix3x2fv;
  if (strcmp(procname, "glUniformMatrix3x4fv") == 0)
    return (void *)glUniformMatrix3x4fv;
  if (strcmp(procname, "glUniformMatrix4fv") == 0)
    return (void *)glUniformMatrix4fv;
  if (strcmp(procname, "glUniformMatrix4x2fv") == 0)
    return (void *)glUniformMatrix4x2fv;
  if (strcmp(procname, "glUniformMatrix4x3fv") == 0)
    return (void *)glUniformMatrix4x3fv;
  if (strcmp(procname, "glUnmapBuffer") == 0)
    return (void *)glUnmapBuffer;
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
  if (strcmp(procname, "glVertexAttribDivisor") == 0)
    return (void *)glVertexAttribDivisor;
  if (strcmp(procname, "glVertexAttribI4i") == 0)
    return (void *)glVertexAttribI4i;
  if (strcmp(procname, "glVertexAttribI4iv") == 0)
    return (void *)glVertexAttribI4iv;
  if (strcmp(procname, "glVertexAttribI4ui") == 0)
    return (void *)glVertexAttribI4ui;
  if (strcmp(procname, "glVertexAttribI4uiv") == 0)
    return (void *)glVertexAttribI4uiv;
  if (strcmp(procname, "glVertexAttribIPointer") == 0)
    return (void *)glVertexAttribIPointer;
  if (strcmp(procname, "glVertexAttribPointer") == 0)
    return (void *)glVertexAttribPointer;
  if (strcmp(procname, "glViewport") == 0)
    return (void *)glViewport;
  if (strcmp(procname, "glWaitSync") == 0)
    return (void *)glWaitSync;
  return NULL;
}
        