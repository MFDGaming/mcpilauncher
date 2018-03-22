#include <stdio.h>

#include "../syscall.h"

FUNCTION_0(SDL_Quit);
FUNCTION_1(SDL_PollEvent);
FUNCTION_1(SDL_Init);
FUNCTION_4(SDL_SetVideoMode);
FUNCTION_2(SDL_WM_SetCaption);
FUNCTION_1(SDL_WM_GrabInput);
FUNCTION_1(SDL_ShowCursor);

static void x_lock_function(void) {
  // printf("x_lock_function()\n");
}

static void x_unlock_function(void) {
  // printf("x_unlock_function()\n");
}

// From SDL
typedef enum {
  SDL_SYSWM_X11
} SDL_SYSWM_TYPE;

typedef struct {
  uint8_t major;
  uint8_t minor;
  uint8_t patch;
} SDL_version;

typedef unsigned long Window;

typedef struct {
  SDL_version version;
  SDL_SYSWM_TYPE subsystem;
  union {
    struct {
      void* display;
      Window window;

      void (*lock_func)(void);
      void (*unlock_func)(void);

      Window fswindow;
      Window wmwindow;

      void* gfxdisplay;
    } x11;
  } info;
} SDL_SysWMinfo;

int SDL_GetWMInfo(int a) {
  void* _a[1] = { a };
  int r = SYSCALL(_a);

  SDL_SysWMinfo* info = (SDL_SysWMinfo*) _a;

  info->info.x11.unlock_func = x_unlock_function;
  info->info.x11.lock_func = x_lock_function;

  return r;
}
