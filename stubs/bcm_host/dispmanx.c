// XXX
#include <stdio.h>

int vc_dispmanx_element_add(int a, int b, int c, int d, int e, int f) {
  printf("vc_dispmanx_element_add(%d, %d, %d, %d, %d, %d)\n", a, b, c, d, e, f);
}

int vc_dispmanx_display_open(int a) {
  printf("vc_dispmanx_display_open(%d)\n", a);
}

int vc_dispmanx_update_start(int a) {
  printf("vc_dispmanx_update_start(%d)\n", a);
}

int vc_dispmanx_update_submit_sync(int a) {
  printf("vc_dispmanx_update_submit_sync(%d)\n", a);
}
