CXX = g++
DEBUGGER = gdb
AARCH64DEBUGGER = aarch64-linux-gnu-gdb
APITRACE = apitrace

DIR = `pwd`
NATIVES = $(DIR)/natives
MINECRAFT = $(DIR)/minecraft-pi

QEMU = $(DIR)/qemu/build/arm-linux-user/qemu-arm
QFLAGS = -L $(NATIVES)

.PHONY: qemu stubs strace run gdb connect

all: stubs qemu

qemu:
	@cd $(DIR)/qemu/build; make

stubs:
	@cd $(DIR)/stubs; make clean; make all; make move

strace:
	@$(QEMU) -strace $(QFLAGS) $(MINECRAFT)

run:
	@$(QEMU) $(QFLAGS) $(MINECRAFT)

trace:
	$(APITRACE) trace --api egl $(QEMU) $(QFLAGS) $(MINECRAFT)

gdb:
	@$(DEBUGGER) --args $(QEMU) -g 1337 $(QFLAGS) $(MINECRAFT)

connect:
	@$(AARCH64DEBUGGER) -ex "file $(MINECRAFT)" -ex "target remote :1337"
