#include <stdio.h>

#include "../syscall.h"

#define TRACE() (printf("%s()\n", __FUNCTION__))

typedef void* EGLDisplay;
typedef void* EGLConfig;
typedef void* EGLSurface;
typedef void* EGLContext;
typedef void* EGLNativeWindowType;
typedef void* EGLClientBuffer;
typedef void* EGLNativeDisplayType;
typedef unsigned int EGLint;
typedef unsigned int EGLenum;
typedef unsigned int EGLBoolean;

typedef int _DWORD;
typedef void GLvoid;
typedef unsigned int GLenum;
typedef unsigned char GLboolean;
typedef unsigned int GLbitfield;
typedef void GLvoid;
typedef signed char GLbyte;
typedef short GLshort;
typedef int GLint;
typedef unsigned char GLubyte;
typedef unsigned short GLushort;
typedef unsigned int GLuint;
typedef int GLsizei;
typedef float GLfloat;
typedef float GLclampf;
typedef double GLdouble;
typedef double GLclampd;
typedef ssize_t GLsizeiptr;
typedef int GLfixed;

// EGL
FUNCTION_1(eglGetDisplay);
FUNCTION_0(eglInitialize);
FUNCTION_5(eglChooseConfig);
FUNCTION_1(eglBindAPI);
FUNCTION_4(eglCreateContext);
FUNCTION_4(eglCreateWindowSurface);
FUNCTION_4(eglMakeCurrent);
FUNCTION_2(eglSwapBuffers);
FUNCTION_2(eglDestroySurface);
FUNCTION_1(eglTerminate);

// XXX GL
FUNCTION_2(glBindBuffer);
FUNCTION_4(glBufferData);
FUNCTION_2(glDeleteBuffers);
FUNCTION_2(glFogx);

// int glDepthRangef(void) { TRACE(); }
FUNCTION_2(glDepthRangef);

// int glOrthof(void) { TRACE(); }
FUNCTION_6(glOrthof);

// void glAlphaFunc(GLenum func, GLclampf ref) { TRACE(); }
FUNCTION_2(glAlphaFunc);

// void glBindTexture(GLenum target, GLuint texture) { TRACE(); }
FUNCTION_2(glBindTexture);

// void glBlendFunc(GLenum sfactor, GLenum dfactor) { TRACE(); }
FUNCTION_2(glBlendFunc);

// void glClear(GLbitfield mask) { TRACE(); }
FUNCTION_1(glClear);

// void glClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) { TRACE(); }
FUNCTION_4(glClearColor);

// void glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) { TRACE(); }
FUNCTION_4(glColor4f);

// void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) { TRACE(); }
FUNCTION_4(glColorMask);

// void glColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *ptr) { TRACE(); }
FUNCTION_4(glColorPointer);

// void glCullFace(GLenum mode) { TRACE(); }
FUNCTION_1(glCullFace);

// void glDeleteTextures(GLsizei n, const GLuint *textures) { TRACE(); }
FUNCTION_2(glDeleteTextures);

// void glDepthFunc(GLenum func) { TRACE(); }
FUNCTION_1(glDepthFunc);

// void glDepthMask(GLboolean flag) { TRACE(); }
FUNCTION_1(glDepthMask);

// void glDisable(GLenum cap) { TRACE(); }
FUNCTION_1(glDisable);

// void glDisableClientState(GLenum cap) { TRACE(); }
FUNCTION_1(glDisableClientState);

// void glDrawArrays(GLenum mode, GLint first, GLsizei count) { TRACE(); }
FUNCTION_3(glDrawArrays);

// void glEnable(GLenum cap) { TRACE(); }
FUNCTION_1(glEnable);

// void glEnableClientState(GLenum cap) { TRACE(); }
FUNCTION_1(glEnableClientState);

// void glFogf(GLenum pname, GLfloat param) { TRACE(); }
FUNCTION_2(glFogf);

// void glFogfv(GLenum pname, const GLfloat *params) { TRACE(); }
FUNCTION_2(glFogfv);

// void glGenTextures(GLsizei n, GLuint *textures) { TRACE(); }
FUNCTION_2(glGenTextures);

// void glGetFloatv(GLenum pname, GLfloat *params) { TRACE(); }
FUNCTION_2(glGetFloatv);

// void glHint(GLenum target, GLenum mode) { TRACE(); }
FUNCTION_2(glHint);

// void glLineWidth(GLfloat width) { TRACE(); }
FUNCTION_1(glLineWidth);

// void glLoadIdentity(void) { TRACE(); }
FUNCTION_0(glLoadIdentity);

// void glMatrixMode(GLenum mode) { TRACE(); }
FUNCTION_1(glMatrixMode);

// void glMultMatrixf(const GLfloat *m) { TRACE(); }
FUNCTION_1(glMultMatrixf);

// void glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz) { TRACE(); }
FUNCTION_3(glNormal3f);

// void glPolygonOffset(GLfloat factor, GLfloat units) { TRACE(); }
FUNCTION_3(glPolygonOffset);

// void glPopMatrix(void) { TRACE(); }
FUNCTION_0(glPopMatrix);

// void glPushMatrix(void) { TRACE(); }
FUNCTION_0(glPushMatrix);

// void glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z) { TRACE(); }
FUNCTION_4(glRotatef);

// void glScalef(GLfloat x, GLfloat y, GLfloat z) { TRACE(); }
FUNCTION_3(glScalef);

// void glScissor(GLint x, GLint y, GLsizei width, GLsizei height) { TRACE(); }
FUNCTION_4(glScissor);

// void glShadeModel(GLenum mode) { TRACE(); }
FUNCTION_1(glShadeModel);

// void glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *ptr) { TRACE(); }
FUNCTION_4(glTexCoordPointer);

// void glTexImage2D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels) { TRACE(); }
FUNCTION_9(glTexImage2D);

// void glTexParameteri(GLenum target, GLenum pname, GLint param) { TRACE(); }
FUNCTION_3(glTexParameteri);

// void glTranslatef(GLfloat x, GLfloat y, GLfloat z) { TRACE(); }
FUNCTION_3(glTranslatef);

// void glVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *ptr) { TRACE(); }
FUNCTION_4(glVertexPointer);

// void glViewport(GLint x, GLint y, GLsizei width, GLsizei height) { TRACE(); }
FUNCTION_4(glViewport);
