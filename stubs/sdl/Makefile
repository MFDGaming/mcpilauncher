CC = arm-none-eabi-gcc
CFLAGS = -Wno-int-conversion -shared -fpic -marm -nostdlib -mfloat-abi=hard
TARGET := libSDL-1.2.so.0

.PHONY: clean move

$(TARGET):
	$(CC) $(CFLAGS) sdl.c -o $@

clean:
	$(RM) $(TARGET)

move:
	mv $(TARGET) ../../natives/lib/$(TARGET)
