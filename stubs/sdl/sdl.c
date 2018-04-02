#include <stdio.h>
#include <string.h>

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
  SDL_version version; // 3
  SDL_SYSWM_TYPE subsystem; // 1
  union {
     struct {
      void* display; // 4
      Window window; // 4

      int filler;

      void (*lock_func)(void); // 4
      void (*unlock_func)(void); // 4

      Window fswindow;
      Window wmwindow;

      void* gfxdisplay;
    } x11;
  } info;
} SDL_SysWMinfo;

int SDL_GetWMInfo(void* a) {
  memset(a, 0, sizeof(SDL_SysWMinfo));
  SDL_SysWMinfo* info = (SDL_SysWMinfo*) a;

  info->info.x11.lock_func = x_lock_function;
  info->info.x11.unlock_func = x_unlock_function;

  return 1;
}
