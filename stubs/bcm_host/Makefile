CC = arm-none-eabi-gcc
CFLAGS = -Wno-int-conversion -shared -fpic -marm -nostdlib -mfloat-abi=hard
TARGET := libbcm_host.so

.PHONY: clean move

$(TARGET):
	$(CC) $(CFLAGS) bcm_host.c dispmanx.c -o $@
clean:
	$(RM) $(TARGET)

move:
	mv $(TARGET) ../../natives/lib/$(TARGET)
