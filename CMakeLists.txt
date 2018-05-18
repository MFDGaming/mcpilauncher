cmake_minimum_required(VERSION 3.1)
include(ExternalProject)

ExternalProject_Add(
    minecraft
    URL https://s3.amazonaws.com/assets.minecraft.net/pi/minecraft-pi-0.1.1.tar.gz
    URL_HASH SHA1=f3911003dd607edfa4c8801096d860b5f9ad3802
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
)

set(NATIVES_DIRECTORY ${CMAKE_SOURCE_DIR}/natives/lib)
set(DLL_BUILD_DIRECTORY ${CMAKE_BINARY_DIR}/dll)
set(QEMU_DIRECTORY ${CMAKE_SOURCE_DIR}/qemu)
set(QEMU_BUILD_DIRECTORY ${QEMU_DIRECTORY}/build)

add_subdirectory(dll)
add_subdirectory(trampoline)

add_custom_target(qemu
    COMMAND cmake -E make_directory ${QEMU_BUILD_DIRECTORY}
    COMMAND cmake -E chdir ${QEMU_BUILD_DIRECTORY} ${QEMU_DIRECTORY}/configure --target-list=arm-linux-user --extra-ldflags=-ldl
    COMMAND cmake -E chdir ${QEMU_BUILD_DIRECTORY} make
)

add_custom_target(setup_all_natives
    COMMAND cmake -E copy_if_different ${DLL_BUILD_DIRECTORY}/libbcm_host.so ${NATIVES_DIRECTORY}
    COMMAND cmake -E copy_if_different ${DLL_BUILD_DIRECTORY}/libEGL.so ${NATIVES_DIRECTORY}
    COMMAND cmake -E copy_if_different ${DLL_BUILD_DIRECTORY}/libGLESv2.so ${NATIVES_DIRECTORY}
    COMMAND cmake -E copy_if_different ${DLL_BUILD_DIRECTORY}/libSDL-1.2.so.0 ${NATIVES_DIRECTORY}
    COMMAND cmake -E copy_if_different ${DLL_BUILD_DIRECTORY}/libX11.so.6 ${NATIVES_DIRECTORY}
)

add_dependencies(setup_all_natives bcm_host EGL GLESv2 SDL-1.2 X11)

add_custom_target(start
    COMMAND cmake -E env LD_PRELOAD=${CMAKE_BINARY_DIR}/trampoline/libtrampoline.so ${QEMU_BUILD_DIRECTORY}/arm-linux-user/qemu-arm -L ${CMAKE_SOURCE_DIR}/natives/ ${CMAKE_BINARY_DIR}/minecraft-prefix/src/minecraft/minecraft-pi
)

add_dependencies(start qemu minecraft trampoline setup_all_natives)
