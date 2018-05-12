CC = arm-none-eabi-gcc
CFLAGS = -Wno-int-conversion -shared -fpic -marm -nostdlib -mfloat-abi=hard
TARGET := libGLESv2.so

.PHONY: clean move

$(TARGET):
	$(CC) $(CFLAGS) gl.c -o $@

clean:
	$(RM) $(TARGET)

move:
	mv $(TARGET) ../../natives/lib/$(TARGET)
