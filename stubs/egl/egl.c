#include <sys/types.h>
#include <stdio.h>

#include "../syscall.h"

#define TRACE() (printf("%s()\n", __FUNCTION__))

#define _FA(x) int x

#define FA_I() _FA(a)
#define A_I() a

#define FA_II() _FA(a), _FA(b)
#define A_II() a, b

#define FA_III() _FA(a), _FA(b), _FA(c)
#define A_III() a, b, c

#define FA_IIII() _FA(a), _FA(b), _FA(c), _FA(d)
#define A_IIII() a, b, c, d

#define FA_IIIII() _FA(a), _FA(b), _FA(c), _FA(d), _FA(e)
#define A_IIIII() a, b, c, d, e

#define FUNC_I(x) int x(FA_I()) { void* args[1] = { A_I() }; SYSCALL(args); }
#define FUNC_II(x) int x(FA_II()) { void* args[2] = { A_II() }; SYSCALL(args); }
#define FUNC_III(x) int x(FA_III()) { void* args[3] = { A_III() }; SYSCALL(args); }
#define FUNC_IIII(x) int x(FA_IIII()) { void* args[4] = { A_IIII() }; SYSCALL(args); }
#define FUNC_IIIII(x) int x(FA_IIII()) { void* args[5] = { A_IIII() }; SYSCALL(args); }

typedef void* EGLDisplay;
typedef void* EGLConfig;
typedef void* EGLSurface;
typedef void* EGLContext;
typedef void* EGLNativeWindowType;
typedef void *EGLClientBuffer;
typedef void *EGLNativeDisplayType;
typedef unsigned int EGLint;
typedef unsigned int EGLenum;
typedef unsigned int EGLBoolean;

// EGL
// FUNC(eglGetDisplay, ARG_I());
FUNC_I(eglGetDisplay);

int eglInitialize() {
  return SYSCALL(NULL);
}

FUNC_IIIII(eglChooseConfig);
FUNC_I(eglBindAPI);
FUNC_IIII(eglCreateContext);
FUNC_IIII(eglCreateWindowSurface);
FUNC_IIII(eglMakeCurrent);

// TODO
FUNC_II(eglSwapBuffers);
FUNC_II(eglDestroySurface);
FUNC_I(eglTerminate);
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
// int glFogx(GLenum pname, GLfixed param) { TRACE(); }
FUNC_II(glFogx);

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
