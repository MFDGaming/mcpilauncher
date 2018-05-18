add_library(trampoline SHARED trampoline.c)

set(PREFIX /usr/lib)

target_link_libraries(trampoline
    ${PREFIX}/libSDL-1.2.so.0
    ${PREFIX}/libEGL.so
    ${PREFIX}/libGLESv1_CM.so
    ${PREFIX}/libX11.so
)
