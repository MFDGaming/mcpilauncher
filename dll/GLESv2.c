#include "dll.h"

// XXX GL functions that use pointers
// -----------------------------------------------------------------------------
// void glBufferData(unsigned int target, ssize_t size, const void *data, unsigned int usage)
void glBufferData(unsigned int a, ssize_t b, const void* c, unsigned int d) {
  uint32_t s[4] = { a, (uint32_t) b, (uint32_t) c, d};
  SYSCALL(&s);
}

// void glDeleteBuffers(int n, const unsigned int *buffers)
void glDeleteBuffers(int a, const unsigned int* b) {
  uint32_t s[2] = { a, (uint32_t) b };
  SYSCALL(&s);
}

// void glColorPointer(int size, unsigned int type, int stride, const void *ptr)
void glColorPointer(int a, unsigned int b, int c, const void* d) {
  uint32_t s[4] = { a, b, c, (uint32_t) d };
  SYSCALL(&s);
}

// void glDeleteTextures(int n, const unsigned int *textures)
void glDeleteTextures(int a, const unsigned int* b) {
  uint32_t s[2] = { a, (uint32_t) b };
  SYSCALL(&s);
}

// void glGenTextures(int n, unsigned int *textures)
void glGenTextures(int a, unsigned int* b) {
  uint32_t s[2] = { a, (uint32_t) b };
  SYSCALL(&s);
}

// void glTexCoordPointer(int size, unsigned int type, int stride, const void *ptr)
void glTexCoordPointer(int a, unsigned int b, int c, const void* d) {
  uint32_t s[4] = { a, b, c, (uint32_t) d };
  SYSCALL(&s);
}

// void glTexImage2D(unsigned int target, int level, int internalFormat, int width, int height, int border, unsigned int format, unsigned int type, const void *pixels)
void glTexImage2D(unsigned int a, int b, int c, int d, int e, int f, unsigned int g, unsigned int h, const void* i) {
  uint32_t s[9] = { a, b, c, d, e, f, g, h, (uint32_t) i };
  SYSCALL(&s);
}

// void glVertexPointer(int size, unsigned int type, int stride, const void *ptr)
void glVertexPointer(int a, unsigned int b, int c, const void* d) {
  uint32_t s[4] = { a, b, c, (uint32_t) d };
  SYSCALL(&s);
}

// void glMultMatrixf(const float *m)
void glMultMatrixf(const float* a) {
  uint32_t s[1] = { (uint32_t*) a };
  SYSCALL(&s);
}

// void glGetFloatv(unsigned int pname, float *params)
void glGetFloatv(unsigned int a, float* b) {
  uint32_t s[2] = { a, (uint32_t*) b };
  SYSCALL(&s);
}

// void glFogfv(unsigned int pname, const float *params)
void glFogfv(unsigned int a, const float* b) {
  uint32_t s[2] = { a, (uint32_t*) b };
  SYSCALL(&s);
}
// -----------------------------------------------------------------------------

// XXX GL functions that use floats (dirty)
// -----------------------------------------------------------------------------
// void glAlphaFunc(unsigned int func, float ref)
void glAlphaFunc(unsigned int func, float ref) {
  uint32_t s[2] = { func, *(uint32_t*) &ref };
  SYSCALL(&s);
}

// void glFogf(unsigned int pname, float param)
void glFogf(unsigned int pname, float param) {
  CONVERT(b, param);
  uint32_t s[2] = { pname, (uint32_t) b };
  SYSCALL(&s);
}
// -----------------------------------------------------------------------------

// XXX GL functions that use floats (pure)
// -----------------------------------------------------------------------------
// void glClearColor(float red, float green, float blue, float alpha)
FUNCTION_f4(glClearColor)

// void glColor4f(float red, float green, float blue, float alpha)
FUNCTION_f4(glColor4f)

// void glLineWidth(float width)
FUNCTION_f1(glLineWidth)

// void glNormal3f(float nx, float ny, float nz)
FUNCTION_f3(glNormal3f)

// void glPolygonOffset(float factor, float units)
FUNCTION_f3(glPolygonOffset)

// void glRotatef(float angle, float x, float y, float z)
FUNCTION_f4(glRotatef)

// void glScalef(float x, float y, float z)
FUNCTION_f3(glScalef)

// void glTranslatef(float x, float y, float z)
FUNCTION_f3(glTranslatef)

// void glDepthRangef(float near, float far)
FUNCTION_f2(glDepthRangef)

// void glOrthof(float left, float right, float bottom, float top, float near, float far)
FUNCTION_f6(glOrthof)
// -----------------------------------------------------------------------------

// XXX GL integer operations
// -----------------------------------------------------------------------------
// void glBindBuffer(unsigned int target, unsigned int buffer)
FUNCTION_2(glBindBuffer)

// void glFogx(unsigned int pname, int param);
FUNCTION_2(glFogx)

// void glBindTexture(unsigned int target, unsigned int texture)
FUNCTION_2(glBindTexture)

// void glBlendFunc(unsigned int sfactor, unsigned int dfactor)
FUNCTION_2(glBlendFunc)

// void glClear(unsigned int mask)
FUNCTION_1(glClear)

// void glColorMask(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
void glColorMask(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha) {
  uint32_t s[4] = { (uint32_t) red, (uint32_t) green, (uint32_t) blue, (uint32_t) alpha };
  SYSCALL(&s);
}

// void glCullFace(unsigned int mode)
FUNCTION_1(glCullFace)

// void glDepthFunc(unsigned int func)
FUNCTION_1(glDepthFunc)

// void glDepthMask(unsigned char flag)
void glDepthMask(unsigned char flag) {
  uint32_t s[1] = { (uint32_t) flag };
  SYSCALL(&s);
}

// void glDisable(unsigned int cap)
FUNCTION_1(glDisable)

// void glDisableClientState(unsigned int cap)
FUNCTION_1(glDisableClientState)

// void glDrawArrays(unsigned int mode, int first, int count)
FUNCTION_3(glDrawArrays)

// void glEnable(unsigned int cap)
FUNCTION_1(glEnable)

// void glEnableClientState(unsigned int cap)
FUNCTION_1(glEnableClientState)

// void glHint(unsigned int target, unsigned int mode)
FUNCTION_2(glHint)

// void glLoadIdentity(void)
FUNCTION_0(glLoadIdentity)

// void glMatrixMode(unsigned int mode)
FUNCTION_1(glMatrixMode)

// void glPopMatrix(void)
FUNCTION_0(glPopMatrix)

// void glPushMatrix(void)
FUNCTION_0(glPushMatrix)

// void glScissor(int x, int y, int width, int height)
FUNCTION_4(glScissor)

// void glShadeModel(unsigned int mode)
FUNCTION_1(glShadeModel)

// void glTexParameteri(unsigned int target, unsigned int pname, int param)
FUNCTION_3(glTexParameteri)

// void glViewport(int x, int y, int width, int height)
FUNCTION_4(glViewport)
