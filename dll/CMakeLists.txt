cmake_minimum_required(VERSION 3.1)

set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_C_FLAGS "-Wno-int-conversion -shared -fpic -marm -nostdlib -mfloat-abi=hard")

add_library(bcm_host SHARED bcm_host.c)
add_library(EGL SHARED EGL.c)
add_library(GLESv2 SHARED GLESv2.c)

# Add custom suffix to SDL
add_library(SDL-1.2 SHARED SDL.c)
set_target_properties(SDL-1.2 PROPERTIES SUFFIX .so.0)

# Add custom suffix to X11
add_library(X11 SHARED X11.c)
set_target_properties(X11 PROPERTIES SUFFIX .so.6)
