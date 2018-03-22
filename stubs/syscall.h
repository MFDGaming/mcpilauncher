#pragma once

#include <sys/types.h>

// Courtesy of JayFoxRox
static uint32_t ___syscall(const char* name, void* ptr) {
  uint32_t ret;
  asm volatile("mov r0, %[name]\n"
               "mov r1, %[ptr]\n"
               "svc #0x901337\n"
               "mov %[ret], r0"
               : [ret] "=r" (ret)
               : [name] "r" (name),
                 [ptr] "r" (ptr)
               : "r0", "r1", "memory"); \
  return ret;
}

// Call the syscall function with the name of the function as an argument
#define SYSCALL(ptr) ___syscall(__FUNCTION__, ptr);

// TODO
#define ARGS_1() void* _a[1] = { a };
#define ARGS_2() void* _a[2] = { a, b };
#define ARGS_3() void* _a[3] = { a, b, c };
#define ARGS_4() void* _a[4] = { a, b, c, d };
#define ARGS_5() void* _a[5] = { a, b, c, d, e };
#define ARGS_6() void* _a[6] = { a, b, c, d, e, f };
#define ARGS_7() void* _a[7] = { a, b, c, d, e, f, g };
#define ARGS_8() void* _a[8] = { a, b, c, d, e, f, g, h };

#define FUNCTION_0(x) int x(void) { return SYSCALL(NULL); }
#define FUNCTION_1(x) int x(int a) { ARGS_1(); return SYSCALL(_a); }
#define FUNCTION_2(x) int x(int a, int b) { ARGS_2(); return SYSCALL(_a); }
#define FUNCTION_3(x) int x(int a, int b, int c) { ARGS_3(); return SYSCALL(_a); }
#define FUNCTION_4(x) int x(int a, int b, int c, int d) { ARGS_4(); return SYSCALL(_a); }
#define FUNCTION_5(x) int x(int a, int b, int c, int d, int e) { ARGS_5(); return SYSCALL(_a); }
#define FUNCTION_6(x) int x(int a, int b, int c, int d, int e, int f) { ARGS_6(); return SYSCALL(_a); }
#define FUNCTION_7(x) int x(int a, int b, int c, int d, int e, int f, int g) { ARGS_7(); return SYSCALL(_a); }
#define FUNCTION_8(x) int x(int a, int b, int c, int d, int e, int f, int g, int h) { ARGS_8(); return SYSCALL(_a); }

#define TRACE() (printf("%s()\n", __FUNCTION__))
