# mcpilauncher

Launch Minecraft: PI Edition on Linux

1. Make sure you have `cmake`, an ARM-32 toolchain (`arm-none-eabi-gcc`), SDL 1.2 and GLES installed
2. Ensure that `qemu` is checked out (i.e.: `git submodule update --init`, or clone with `--recursive`)
3. Apply the QEMU patch using `git apply qemu.patch`
4. `mkdir build && cmake .. && make start`
