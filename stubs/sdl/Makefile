CC = arm-none-eabi-gcc

TARGET := libSDL-1.2.so.0

.PHONY: clean move

$(TARGET):
	$(CC) -Wall sdl.c -shared -fpic -marm -nostdlib -o $@ -mfloat-abi=hard

clean:
	$(RM) $(TARGET)

move:
	mv $(TARGET) ../../natives/lib/$(TARGET)
