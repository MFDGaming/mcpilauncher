// XXX
#include <stdio.h>
#include <stdint.h>

#include "../syscall.h"

typedef struct SDL_version
{
    uint8_t major;        /**< major version */
    uint8_t minor;        /**< minor version */
    uint8_t patch;        /**< update version */
} SDL_version;

typedef struct {
  SDL_version version;
  int data;
} SDL_SysWMinfo;

void* h2g(void* a) {
  return SYSCALL(a);
}

int SDL_Quit(void) {
  return SYSCALL(NULL);
}

int SDL_PollEvent(int a) {
  void* args[1] = { a };
  return SYSCALL(args);
}

int SDL_Init(int a) {
  void* args[1] = { a };
  return SYSCALL(args);
}

int SDL_SetVideoMode(int a, int b, int c, int d) {
  void* args[4] = { a, b, c, d };
  return SYSCALL(args);
}

int SDL_WM_SetCaption(int a, int b) {
  void* args[2] = { a, b };
  return SYSCALL(args);
}

int SDL_WM_GrabInput(int a) {
  void* args[1] = { a };
  return SYSCALL(args);
}

int SDL_GetWMInfo(int a) {
  void* args[1] = { a };
  int result = SYSCALL(args);
  SDL_SysWMinfo* info = (SDL_SysWMinfo*) args[0];
  printf("(result: %d) Guest, %d.%d.%d\n", result, info->version.major, info->version.minor, info->version.patch);
  return result;
}

int SDL_ShowCursor(int a) {
  void* args[1] = { a };
  return SYSCALL(args);
}
