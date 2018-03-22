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

// EGL
FUNCTION_1(eglGetDisplay)
FUNCTION_0(eglInitialize)
FUNCTION_5(eglChooseConfig)
FUNCTION_1(eglBindAPI)
FUNCTION_4(eglCreateContext);
FUNCTION_4(eglCreateWindowSurface);
FUNCTION_4(eglMakeCurrent);
FUNCTION_2(eglSwapBuffers);
FUNCTION_2(eglDestroySurface);
FUNCTION_1(eglTerminate);

// EGLSurface eglCreateWindowSurface(EGLDisplay dpy, EGLConfig config, EGLNativeWindowType win, const EGLint *attrib_list) { TRACE(); }
// EGLBoolean eglBindAPI(EGLenum api) { TRACE(); }
// EGLContext eglCreateContext(EGLDisplay dpy, EGLConfig config, EGLContext share_context, const EGLint *attrib_list) { TRACE(); }
// EGLBoolean eglMakeCurrent(EGLDisplay dpy, EGLSurface draw, EGLSurface read, EGLContext ctx) { TRACE(); }
// EGLBoolean eglDestroySurface(EGLDisplay dpy, EGLSurface surface) { TRACE(); }
// EGLDisplay eglGetDisplay(EGLNativeDisplayType display_id) { TRACE(); }
// EGLBoolean eglChooseConfig(EGLDisplay dpy, const EGLint *attrib_list, EGLConfig *configs, EGLint config_size, EGLint *num_config) { TRACE(); }
// EGLBoolean eglInitialize(EGLDisplay dpy, EGLint *major, EGLint *minor) { /* XXX Minecraft appears to call this with void */ }
// EGLBoolean eglSwapBuffers(EGLDisplay dpy, EGLSurface surface) { TRACE(); }
// EGLBoolean eglTerminate(EGLDisplay dpy) { TRACE(); }

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

// XXX GL
int glBindBuffer(GLenum target, GLuint buffer) { TRACE(); }
int glBufferData(GLenum target, GLsizeiptr size, const GLvoid* data, GLenum usage) { TRACE(); }
int glDeleteBuffers(GLsizei n, const GLuint* buffers) { TRACE(); }
int glFogx(GLenum pname, GLfixed param) { TRACE(); }

int glDepthRangef(void) { TRACE(); }
int glOrthof(void) { TRACE(); }
void glAlphaFunc(GLenum func, GLclampf ref) { TRACE(); }
void glBindTexture(GLenum target, GLuint texture) { TRACE(); }
void glBlendFunc(GLenum sfactor, GLenum dfactor) { TRACE(); }
void glClear(GLbitfield mask) { TRACE(); }
void glClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) { TRACE(); }
void glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) { TRACE(); }
void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) { TRACE(); }
void glColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *ptr) { TRACE(); }
void glCullFace(GLenum mode) { TRACE(); }
void glDeleteTextures(GLsizei n, const GLuint *textures) { TRACE(); }
void glDepthFunc(GLenum func) { TRACE(); }
void glDepthMask(GLboolean flag) { TRACE(); }
void glDisable(GLenum cap) { TRACE(); }
void glDisableClientState(GLenum cap) { TRACE(); }
void glDrawArrays(GLenum mode, GLint first, GLsizei count) { TRACE(); }
void glEnable(GLenum cap) { TRACE(); }
void glEnableClientState(GLenum cap) { TRACE(); }
void glFogf(GLenum pname, GLfloat param) { TRACE(); }
void glFogfv(GLenum pname, const GLfloat *params) { TRACE(); }
void glGenTextures(GLsizei n, GLuint *textures) { TRACE(); }
void glGetFloatv(GLenum pname, GLfloat *params) { TRACE(); }
void glHint(GLenum target, GLenum mode) { TRACE(); }
void glLineWidth(GLfloat width) { TRACE(); }
void glLoadIdentity(void) { TRACE(); }
void glMatrixMode(GLenum mode) { TRACE(); }
void glMultMatrixf(const GLfloat *m) { TRACE(); }
void glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz) { TRACE(); }
void glPolygonOffset(GLfloat factor, GLfloat units) { TRACE(); }
void glPopMatrix(void) { TRACE(); }
void glPushMatrix(void) { TRACE(); }
void glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z) { TRACE(); }
void glScalef(GLfloat x, GLfloat y, GLfloat z) { TRACE(); }
void glScissor(GLint x, GLint y, GLsizei width, GLsizei height) { TRACE(); }
void glShadeModel(GLenum mode) { TRACE(); }
void glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *ptr) { TRACE(); }
void glTexImage2D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels) { TRACE(); }
void glTexParameteri(GLenum target, GLenum pname, GLint param) { TRACE(); }
void glTranslatef(GLfloat x, GLfloat y, GLfloat z) { TRACE(); }
void glVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *ptr) { TRACE(); }
void glViewport(GLint x, GLint y, GLsizei width, GLsizei height) { TRACE(); }
