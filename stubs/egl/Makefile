CC = arm-none-eabi-gcc

TARGET := libEGL.so

.PHONY: clean move

$(TARGET):
	$(CC) -Wall egl.c -shared -fpic -marm -nostdlib -o $@ -mfloat-abi=hard

clean:
	$(RM) $(TARGET)

move:
	mv $(TARGET) ../../natives/lib/$(TARGET)
