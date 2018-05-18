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
               : "r0", "r1", "memory");

  return ret;
}

#define SYSCALL(ptr) ___syscall(__FUNCTION__, ptr)

// XXX
#define CONVERT(x, y) float x = *(uint32_t*) &y
#define CONVERT_1() CONVERT(a, x)
#define CONVERT_2() CONVERT_1(); CONVERT(b, y)
#define CONVERT_3() CONVERT_2(); CONVERT(c, z)
#define CONVERT_4() CONVERT_3(); CONVERT(d, w)
#define CONVERT_5() CONVERT_4(); CONVERT(e, u)
#define CONVERT_6() CONVERT_5(); CONVERT(f, v)

#define ARGS_1() uint32_t s[1] = { a }
#define ARGS_2() uint32_t s[2] = { a, b }
#define ARGS_3() uint32_t s[3] = { a, b, c }
#define ARGS_4() uint32_t s[4] = { a, b, c, d }
#define ARGS_5() uint32_t s[5] = { a, b, c, d, e }
#define ARGS_6() uint32_t s[6] = { a, b, c, d, e, f }
#define ARGS_7() uint32_t s[7] = { a, b, c, d, e, f, g }
#define ARGS_8() uint32_t s[8] = { a, b, c, d, e, f, g, h }
#define ARGS_9() uint32_t s[9] = { a, b, c, d, e, f, g, h, i }

#define FUNCTION_0(x) int x(void) { return SYSCALL(NULL); }
#define FUNCTION_1(x) int x(int a) { ARGS_1(); return SYSCALL(&s); }
#define FUNCTION_2(x) int x(int a, int b) { ARGS_2(); return SYSCALL(&s); }
#define FUNCTION_3(x) int x(int a, int b, int c) { ARGS_3(); return SYSCALL(&s); }
#define FUNCTION_4(x) int x(int a, int b, int c, int d) { ARGS_4(); return SYSCALL(&s); }
#define FUNCTION_5(x) int x(int a, int b, int c, int d, int e) { ARGS_5(); return SYSCALL(&s); }
#define FUNCTION_6(x) int x(int a, int b, int c, int d, int e, int f) { ARGS_6(); return SYSCALL(&s); }
#define FUNCTION_7(x) int x(int a, int b, int c, int d, int e, int f, int g) { ARGS_7(); return SYSCALL(&s); }
#define FUNCTION_8(x) int x(int a, int b, int c, int d, int e, int f, int g, int h) { ARGS_8(); return SYSCALL(&s); }
#define FUNCTION_9(x) int x(int a, int b, int c, int d, int e, int f, int g, int h, int i) { ARGS_9(); return SYSCALL(&s); }

#define FUNCTION_f0(f) int f(void) { return SYSCALL(NULL); }
#define FUNCTION_f1(f) int f(float x) { \
  CONVERT_1(); \
  ARGS_1(); \
  return SYSCALL(&s); }

#define FUNCTION_f2(f) int f(float x, float y) { \
  CONVERT_2(); \
  ARGS_2(); \
  return SYSCALL(&s); }

#define FUNCTION_f3(f) int f(float x, float y, float z) { \
  CONVERT_3(); \
  ARGS_3(); \
  return SYSCALL(&s); }

#define FUNCTION_f4(f) int f(float x, float y, float z, float w) { \
  CONVERT_4(); \
  ARGS_4(); \
  return SYSCALL(&s); }

#define FUNCTION_f6(f) int f(float x, float y, float z, float w, float u, float v) { \
  CONVERT_6(); \
  ARGS_6(); \
  return SYSCALL(&s); }
