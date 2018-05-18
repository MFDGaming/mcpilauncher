#include <SDL/SDL.h>
#include <SDL/SDL_syswm.h>
#include <EGL/egl.h>
#include <GLES/gl.h>
#include <X11/Xlib.h>
#include <dlfcn.h>

// 4919

#define TRACE() (printf("`%s()` called!\n", name))
#define CAST(type, name) (*((type*)&name))

#define ARGUMENT_i(a, b) int a = arguments[b]
#define ARGUMENT_f(a, b) float a = CAST(float, arguments[b])

#define FUNCTION_1() ARGUMENT_i(a, 0)
#define FUNCTION_2() FUNCTION_1(); ARGUMENT_i(b, 1)
#define FUNCTION_3() FUNCTION_2(); ARGUMENT_i(c, 2)
#define FUNCTION_4() FUNCTION_3(); ARGUMENT_i(d, 3)
#define FUNCTION_5() FUNCTION_4(); ARGUMENT_i(e, 4)
#define FUNCTION_6() FUNCTION_5(); ARGUMENT_i(f, 5)
#define FUNCTION_7() FUNCTION_6(); ARGUMENT_i(g, 6)
#define FUNCTION_8() FUNCTION_7(); ARGUMENT_i(h, 7)
#define FUNCTION_9() FUNCTION_8(); ARGUMENT_i(i, 8)

#define FUNCTION_f1() ARGUMENT_f(a, 0)
#define FUNCTION_f2() FUNCTION_f1(); ARGUMENT_f(b, 1)
#define FUNCTION_f3() FUNCTION_f2(); ARGUMENT_f(c, 2)
#define FUNCTION_f4() FUNCTION_f3(); ARGUMENT_f(d, 3)

#define HANDLE(f) else if(strcmp(f, name) == 0)

#define FAKE(f) HANDLE(f) { ret = 0; }

EGLDisplay eDisplay;
EGLConfig eConfig;
EGLContext eContext;
EGLSurface eSurface;

void (*_x_lock_function)(void);
void (*_x_unlock_function)(void);

Display* xDisplay;
Window xWindow;
Window xRootWindow;

static void* (*g2h)(uint32_t);
void set_guest_to_host_handle(void* (*handle)(uint32_t)) {
    g2h = handle;
}

int trampoline(const char* name, uint32_t* arguments) {
    int ret;

    // SDL
    // -----------------------------------------------------------------------------
    if(strcmp("SDL_Init", name) == 0) { ret = 0; }

    HANDLE("SDL_SetVideoMode") { ret = 1; }

    HANDLE("SDL_WM_SetCaption") {
      if(SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init failed\n");
        return -1;
      }

      SDL_SetVideoMode(848, 480, 32, 16);
      SDL_WM_SetCaption("Minecraft", NULL);

      SDL_SysWMinfo info;
      SDL_VERSION(&info.version);
      SDL_GetWMInfo(&info);

      _x_lock_function = info.info.x11.lock_func;
      _x_unlock_function = info.info.x11.unlock_func;

      xDisplay = info.info.x11.display;
      xWindow = info.info.x11.window;
      xRootWindow = RootWindow(xDisplay, DefaultScreen(xDisplay));

      eDisplay = eglGetDisplay((EGLNativeDisplayType) xDisplay);

      eglInitialize(eDisplay, NULL, NULL);

      EGLint number_of_config;
      eglChooseConfig(eDisplay, g2h(0x102208), &eConfig, 1, &number_of_config);

      eglBindAPI(EGL_OPENGL_ES_API);

      eContext = eglCreateContext(eDisplay, eConfig, EGL_NO_CONTEXT, NULL);
      eSurface = eglCreateWindowSurface(eDisplay, eConfig, (NativeWindowType) xWindow, NULL);

      eglMakeCurrent(eDisplay, eSurface, eSurface, eContext);
      ret = 0;
    }

    HANDLE("SDL_WM_GrabInput") {
      // FIXME removed because it locks you in and doesn't let you leave
      // the window!
      // FUNCTION_1();
      // ret = SDL_WM_GrabInput(a);
      ret = 1;
    }

    HANDLE("SDL_ShowCursor") {
      FUNCTION_1();
      ret = SDL_ShowCursor(a);
    }

    HANDLE("SDL_PollEvent") {
      typedef struct {
        uint8_t scancode;
        uint16_t sym;
        uint16_t mod;
        uint16_t unicode;
      } sKeysym;

      typedef struct {
        uint8_t type;
        uint8_t which;
        uint8_t state;
        sKeysym keysym;
      } sKeyboardEvent;

      typedef struct {
        uint8_t type;
      } sQuitEvent;

      typedef struct {
        uint8_t type;
        uint8_t gain;
        uint8_t state;
      } sActiveEvent;

      typedef struct {
        uint8_t type;
        uint8_t which;
        uint8_t state;
        uint16_t x, y;
        int16_t xrel;
        int16_t yrel;
      } sMouseMotionEvent;

      typedef struct {
        uint8_t type;
        uint8_t which;
        uint8_t button;
        uint8_t state;
        int16_t x, y;
      } sMouseButtonEvent;

      typedef union {
        uint8_t type;
        sQuitEvent quit;
        sActiveEvent active;
        sKeyboardEvent key;
        sMouseMotionEvent motion;
        sMouseButtonEvent button;
      } sHostEvent;

      sHostEvent* a = g2h(arguments[0]);
      SDL_Event event;
      ret = SDL_PollEvent(&event);

      switch(event.type) {
        case SDL_QUIT:
          a->quit.type = SDL_QUIT;
          eglDestroyContext(eDisplay, eContext);
          eglDestroySurface(eDisplay, eSurface);
          eglTerminate(eDisplay);
          SDL_Quit();
          exit(0); // XXX
          break;
    case SDL_VIDEORESIZE:
      // SDL reset the video state
      SDL_SetVideoMode(event.resize.w, event.resize.h, 32, 16);

      // OpenGL state modification for resizing
      glViewport(0, 0, event.resize.w, event.resize.h);
      glMatrixMode(GL_PROJECTION);
         glOrthox(0, event.resize.w, 0, event.resize.h, -1, 1);
         glLoadIdentity();
         glMatrixMode(GL_MODELVIEW);
         glLoadIdentity();
         glClear(GL_COLOR_BUFFER_BIT);
         glLoadIdentity();

      break;
    case SDL_ACTIVEEVENT:
          a->active.type = SDL_ACTIVEEVENT;
          a->active.gain = event.active.gain;
          a->active.state = event.active.state;
          break;
        case SDL_KEYDOWN:
        case SDL_KEYUP:
          a->key.type = event.type;
          a->key.which = event.key.which;
          a->key.state = event.key.state;
          a->key.keysym.scancode = event.key.keysym.scancode;
          a->key.keysym.sym = event.key.keysym.sym;
          a->key.keysym.mod = event.key.keysym.mod;
          a->key.keysym.unicode = event.key.keysym.unicode;
          break;
        case SDL_MOUSEMOTION:
          a->motion.type = event.type;
          a->motion.which = event.motion.which;
          a->motion.state = event.motion.state;
          a->motion.x = event.motion.x;
          a->motion.y = event.motion.y;
          a->motion.xrel = event.motion.xrel;
          a->motion.yrel = event.motion.yrel;
          break;
        case SDL_MOUSEBUTTONDOWN:
        case SDL_MOUSEBUTTONUP:
          a->button.type = event.type;
          a->button.which = event.button.which;
          a->button.button = event.button.button;
          a->button.state = event.button.state;
          a->button.x = event.button.x;
          a->button.y = event.button.y;
          break;
        default: // FIXME
          ret = 0;
          break;
      }
    }
    // -----------------------------------------------------------------------------

    // X11
    // -----------------------------------------------------------------------------
    HANDLE("x_lock_function") {
      _x_lock_function();
      ret = 0;
    }

    HANDLE("x_unlock_function") {
      _x_unlock_function();
      ret = 0;
    }

    // int XTranslateCoordinates(Display *display, Window src_w, Window dest_w, int src_x, int src_y, int *dest_x_return, int *dest_y_return, Window *child_return) {
    HANDLE("XTranslateCoordinates") {
      int src_x = arguments[0];
      int src_y = arguments[1];
      int* dest_x_return = g2h(arguments[2]);
      int* dest_y_return = g2h(arguments[3]);

      Window fake;

      ret = XTranslateCoordinates(xDisplay, xWindow, xRootWindow, src_x, src_y, dest_x_return, dest_y_return, &fake);
    }

    // int XGetWindowAttributes(Display *display, Window w, XWindowAttributes *window_attributes_return) {
    HANDLE("XGetWindowAttributes") {
      typedef struct {
        uint32_t x, y;
        uint32_t width, height;
        uint8_t unused[76];
      } sWindowAttributes;

      sWindowAttributes* window_attributes_return = g2h(arguments[0]);
      memset(window_attributes_return, 0, sizeof(sWindowAttributes));

      XWindowAttributes xWindowAttributes;
      ret = XGetWindowAttributes(xDisplay, xWindow, &xWindowAttributes);

      window_attributes_return->width = xWindowAttributes.width;
      window_attributes_return->height = xWindowAttributes.height;

      window_attributes_return->x = xWindowAttributes.x;
      window_attributes_return->y = xWindowAttributes.y;
    }
    // -----------------------------------------------------------------------------

    // GL
    // -----------------------------------------------------------------------------
    // void glBufferData(unsigned int target, ssize_t size, const void *data, unsigned int usage)
    HANDLE("glBufferData") {
      unsigned int target = arguments[0];
      unsigned int size = arguments[1];
      void* data = g2h(arguments[2]);
      unsigned int usage = arguments[3];

      glBufferData(target, size, data, usage);
      ret = 0;
    }

    // void glDeleteBuffers(int n, const unsigned int *buffers)
    HANDLE("glDeleteBuffers") {
      int n = arguments[0];
      unsigned int* buffers = g2h(arguments[1]);

      glDeleteBuffers(n, buffers);
      ret = 0;
    }

    // void glColorPointer(int size, unsigned int type, int stride, const void *ptr)
    HANDLE("glColorPointer") {
      int size = arguments[0];
      unsigned int type = arguments[1];
      int stride = arguments[2];
      void* ptr = CAST(void*, arguments[3]);

      glColorPointer(size, type, stride, ptr);
      ret = 0;
    }

    // void glDeleteTextures(int n, const unsigned int *textures)
    HANDLE("glDeleteTextures") {
      int n = arguments[0];
      unsigned int* textures = g2h(arguments[1]);

      glDeleteTextures(n, textures);
      ret = 0;
    }

    // void glGenTextures(int n, unsigned int *textures)
    HANDLE("glGenTextures") {
      int n = arguments[0];
      unsigned int* textures = g2h(arguments[1]);

      glGenTextures(n, textures);
      ret = 0;
    }

    // void glTexCoordPointer(int size, unsigned int type, int stride, const void *ptr)
    HANDLE("glTexCoordPointer") {
      int size = arguments[0];
      unsigned int type = arguments[1];
      int stride = arguments[2];
      void* ptr = CAST(void*, arguments[3]);

      glTexCoordPointer(size, type, stride, ptr);
      ret = 0;
    }

    // void glTexImage2D(unsigned int target, int level, int internalFormat, int width, int height, int border, unsigned int format, unsigned int type, const void *pixels)
    HANDLE("glTexImage2D") {
      unsigned int target = arguments[0];
      int level = arguments[1];
      int internalFormat = arguments[2];
      int width = arguments[3];
      int height = arguments[4];
      int border = arguments[5];
      unsigned int format = arguments[6];
      unsigned int type = arguments[7];
      void* pixels = g2h(arguments[8]);

      glTexImage2D(target, level, internalFormat, width, height, border, format, type, pixels);
      ret = 0;
    }

    // void glVertexPointer(int size, unsigned int type, int stride, const void *ptr)
    HANDLE("glVertexPointer") {
      int size = arguments[0];
      unsigned int type = arguments[1];
      int stride = arguments[2];
      void* ptr = CAST(void*, arguments[3]);

      glVertexPointer(size, type, stride, ptr);
      ret = 0;
    }

    // void glMultMatrixf(const float *m)
    HANDLE("glMultMatrixf") {
      float* m = g2h(arguments[0]);

      glMultMatrixf(m);
      ret = 0;
    }

    // void glGetFloatv(unsigned int pname, float *params)
    HANDLE("glGetFloatv") {
      unsigned int pname = arguments[0];
      float* params = g2h(arguments[1]);

      glGetFloatv(pname, params);
      ret = 0;
    }

    // void glFogfv(unsigned int pname, const float *params)
    HANDLE("glFogfv") {
      unsigned int pname = arguments[0];
      float* params = g2h(arguments[1]);

      glFogfv(pname, params);
      ret = 0;
    }

    // void glAlphaFunc(unsigned int func, float ref)
    HANDLE("glAlphaFunc") {
      unsigned int func = arguments[0];
      float ref = CAST(float, arguments[1]);

      glAlphaFunc(func, ref);
      ret = 0;
    }

    // void glFogf(unsigned int pname, float param)
    HANDLE("glFogf") {
      unsigned int pname = arguments[0];
      float param = CAST(float, arguments[1]);

      glFogf(pname, param);
      ret = 0;
    }

    // void glClearColor(float red, float green, float blue, float alpha)
    HANDLE("glClearColor") {
      float red = CAST(float, arguments[0]);
      float green = CAST(float, arguments[1]);
      float blue = CAST(float, arguments[2]);
      float alpha = CAST(float, arguments[3]);

      glClearColor(red, green, blue, alpha);
      ret = 0;
    }

    // void glColor4f(float red, float green, float blue, float alpha)
    HANDLE("glColor4f") {
      float red = CAST(float, arguments[0]);
      float green = CAST(float, arguments[1]);
      float blue = CAST(float, arguments[2]);
      float alpha = CAST(float, arguments[3]);

      glColor4f(red, green, blue, alpha);
      ret = 0;
    }

    // void glLineWidth(float width)
    HANDLE("glLineWidth") {
      float width = CAST(float, arguments[0]);

      glLineWidth(width);
      ret = 0;
    }

    // void glNormal3f(float nx, float ny, float nz)
    HANDLE("glNormal3f") {
      float nx = CAST(float, arguments[0]);
      float ny = CAST(float, arguments[1]);
      float nz = CAST(float, arguments[2]);

      glNormal3f(nx, ny, nz);
      ret = 0;
    }

    // void glPolygonOffset(float factor, float units)
    HANDLE("glPolygonOffset") {
      float factor = CAST(float, arguments[0]);
      float units = CAST(float, arguments[1]);

      glPolygonOffset(factor, units);
      ret = 0;
    }

    // void glRotatef(float angle, float x, float y, float z)
    HANDLE("glRotatef") {
      float angle = CAST(float, arguments[0]);
      float x = CAST(float, arguments[1]);
      float y = CAST(float, arguments[2]);
      float z = CAST(float, arguments[3]);

      glRotatef(angle, x, y, z);
      ret = 0;
    }

    // void glScalef(float x, float y, float z)
    HANDLE("glScalef") {
      float x = CAST(float, arguments[0]);
      float y = CAST(float, arguments[1]);
      float z = CAST(float, arguments[2]);

      glScalef(x, y, z);
      ret = 0;
    }

    // void glTranslatef(float x, float y, float z)
    HANDLE("glTranslatef") {
      float x = CAST(float, arguments[0]);
      float y = CAST(float, arguments[1]);
      float z = CAST(float, arguments[2]);

      glTranslatef(x, y, z);
      ret = 0;
    }

    // void glDepthRangef(float near, float far)
    HANDLE("glDepthRangef") {
      float near = CAST(float, arguments[0]);
      float far = CAST(float, arguments[1]);

      glDepthRangef(near, far);
      ret = 0;
    }

    // void glOrthof(float left, float right, float bottom, float top, float near, float far)
    HANDLE("glOrthof") {
      float left = CAST(float, arguments[0]);
      float right = CAST(float, arguments[1]);
      float bottom = CAST(float, arguments[2]);
      float top = CAST(float, arguments[3]);
      float near = CAST(float, arguments[4]);
      float far = CAST(float, arguments[5]);

      glOrthof(left, right, bottom, top, near, far);
      ret = 0;
    }

    // void glBindBuffer(unsigned int target, unsigned int buffer)
    HANDLE("glBindBuffer") {
      FUNCTION_2();
      glBindBuffer(a, b);
      ret = 0;
    }

    // void glFogx(unsigned int pname, int param);
    HANDLE("glFogx") {
      FUNCTION_2();
      glFogx(a, b);
      ret = 0;
    }

    // void glBindTexture(unsigned int target, unsigned int texture)
    HANDLE("glBindTexture") {
      FUNCTION_2();
      glBindTexture(a, b);
      ret = 0;
    }

    // void glBlendFunc(unsigned int sfactor, unsigned int dfactor)
    HANDLE("glBlendFunc") {
      FUNCTION_2();
      glBlendFunc(a, b);
      ret = 0;
    }

    // void glClear(unsigned int mask)
    HANDLE("glClear") {
      FUNCTION_1();
      glClear(a);
      ret = 0;
    }

    // void glColorMask(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
    HANDLE("glColorMask") {
      FUNCTION_4();
      glColorMask((unsigned char) a, (unsigned char) b, (unsigned char) c, (unsigned char) d);
      ret = 0;
    }

    // void glCullFace(unsigned int mode)
    HANDLE("glCullFace") {
      FUNCTION_1();
      glCullFace(a);
      ret = 0;
    }

    // void glDepthFunc(unsigned int func)
    HANDLE("glDepthFunc") {
      FUNCTION_1();
      glDepthFunc(a);
      ret = 0;
    }

    // void glDepthMask(unsigned char flag)
    HANDLE("glDepthMask") {
      FUNCTION_1();
      glDepthMask((unsigned char) a);
      ret = 0;
    }

    // void glDisable(unsigned int cap)
    HANDLE("glDisable") {
      FUNCTION_1();
      glDisable(a);
      ret = 0;
    }

    // void glDisableClientState(unsigned int cap)
    HANDLE("glDisableClientState") {
      FUNCTION_1();
      glDisableClientState(a);
      ret = 0;
    }

    // void glDrawArrays(unsigned int mode, int first, int count)
    HANDLE("glDrawArrays") {
      FUNCTION_3();
      glDrawArrays(a, b, c);
      ret = 0;
    }

    // void glEnable(unsigned int cap)
    HANDLE("glEnable") {
      FUNCTION_1();
      glEnable(a);
      ret = 0;
    }

    // void glEnableClientState(unsigned int cap)
    HANDLE("glEnableClientState") {
      FUNCTION_1();
      glEnableClientState(a);
      ret = 0;
    }

    // void glHint(unsigned int target, unsigned int mode)
    HANDLE("glHint") {
      FUNCTION_2();
      glHint(a, b);
      ret = 0;
    }

    // void glLoadIdentity(void)
    HANDLE("glLoadIdentity") {
      glLoadIdentity();
      ret = 0;
    }

    // void glMatrixMode(unsigned int mode)
    HANDLE("glMatrixMode") {
      FUNCTION_1();
      glMatrixMode(a);
      ret = 0;
    }

    // void glPopMatrix(void)
    HANDLE("glPopMatrix") {
      glPopMatrix();
      ret = 0;
    }

    // void glPushMatrix(void)
    HANDLE("glPushMatrix") {
      glPushMatrix();
      ret = 0;
    }

    // void glScissor(int x, int y, int width, int height)
    HANDLE("glScissor") {
      FUNCTION_4();
      glScissor(a, b, c, d);
      ret = 0;
    }

    // void glShadeModel(unsigned int mode)
    HANDLE("glShadeModel") {
      FUNCTION_1();
      glShadeModel(a);
      ret = 0;
    }

    // void glTexParameteri(unsigned int target, unsigned int pname, int param)
    HANDLE("glTexParameteri") {
      FUNCTION_3();
      glTexParameteri(a, b, c);
      ret = 0;
    }

    // void glViewport(int x, int y, int width, int height)
    HANDLE("glViewport") {
      FUNCTION_4();
      glViewport(a, b, c, d);
      ret = 0;
    }

    // -----------------------------------------------------------------------------

    // EGL
    // -----------------------------------------------------------------------------
    FAKE("eglGetDisplay")
    FAKE("eglInitialize")
    FAKE("eglChooseConfig")
    FAKE("eglBindAPI")
    FAKE("eglCreateContext")
    FAKE("eglCreateWindowSurface")
    FAKE("eglMakeCurrent")

    HANDLE("eglSwapBuffers") {
      ret = eglSwapBuffers(eDisplay, eSurface);
    }

    // XXX these are handled in the SDL_PollEvent implementation
    FAKE("eglDestroySurface")
    FAKE("eglTerminate")
    // -----------------------------------------------------------------------------

    else {
      ret = -1;
    }

    return ret;
}
