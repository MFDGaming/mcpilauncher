#include <stdio.h>

#include "../syscall.h"

typedef void Display;
typedef unsigned long Window;
typedef void XWindowAttributes;

int XTranslateCoordinates(int a, int b, int c, int d, int e, int f, int g, int h) {
  void* args[8] = { a, b, c, d, e, f, g, h };
  SYSCALL(args);
  printf("XTranslateCoordinates()\n");
}

int XGetWindowAttributes(int a, int b, int c) {
  void* args[3] = { a, b, c };
  SYSCALL(args);
  printf("XGetWindowAttributes()\n");
}
