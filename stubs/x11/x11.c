#include <string.h>

#include "../syscall.h"

typedef void Display;
typedef unsigned long Window;
typedef void Visual;
typedef int Bool;
typedef unsigned long Colormap;
typedef void Screen;

typedef struct {
  int x, y;
  int width, height;
  int border_width;
  int depth;
  Visual *visual;
  Window root;
  int class;
  int bit_gravity;
  int win_gravity;
  int backing_store;
  unsigned long backing_planes;
  unsigned long backing_pixel;
  Bool save_under;
  Colormap colormap;
  Bool map_installed;
  int map_state;
  long all_event_masks;
  long your_event_mask;
  long do_not_propagate_mask;
  Bool override_redirect;
  Screen *screen;
} XWindowAttributes;

int XTranslateCoordinates(Display *display, Window src_w, Window dest_w, int src_x, int src_y, int *dest_x_return, int *dest_y_return, Window *child_return) {
  *dest_x_return = src_x;
  *dest_y_return = src_y;
  *child_return = 0xdeadbeef;

  return 1;
}

int XGetWindowAttributes(Display *display, Window w, XWindowAttributes *window_attributes_return) {
  memset(window_attributes_return, 0, sizeof(XWindowAttributes));

  window_attributes_return->width = 848;
  window_attributes_return->height = 480;

  window_attributes_return->visual = 0xdeadbeef;
  window_attributes_return->screen = 0xdeadbeef;

  return 1;
}
