CC = arm-none-eabi-gcc
CFLAGS = -Wno-int-conversion -shared -fpic -marm -nostdlib -mfloat-abi=hard
TARGET := libX11.so.6

.PHONY: clean move

$(TARGET):
	$(CC) $(CFLAGS) x11.c -o $@

clean:
	$(RM) $(TARGET)

move:
	mv $(TARGET) ../../natives/lib/$(TARGET)
