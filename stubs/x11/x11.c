#include <string.h>

#include "../syscall.h"

typedef void Display;
typedef unsigned long Window;
typedef void Visual;
typedef int Bool;
typedef unsigned long Colormap;
typedef void Screen;

int XTranslateCoordinates(Display *display, Window src_w, Window dest_w, int src_x, int src_y, int *dest_x_return, int *dest_y_return, Window *child_return) {
  uint32_t s[4] = { src_x, src_y, (uint32_t) dest_x_return, (uint32_t) dest_y_return };
  return SYSCALL(&s);
}

int XGetWindowAttributes(Display *display, Window w, void* window_attributes_return) {
  uint32_t s[1] = { (uint32_t) window_attributes_return };
  return SYSCALL(&s);
}
