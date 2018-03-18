#pragma once

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

#define SYSCALL(ptr) ___syscall(__FUNCTION__, ptr);
