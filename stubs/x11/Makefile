CC = arm-none-eabi-gcc

TARGET := libX11.so.6

.PHONY: clean move

$(TARGET):
	$(CC) -Wall x11.c -shared -fpic -marm -nostdlib -o $@ -mfloat-abi=hard

clean:
	$(RM) $(TARGET)

move:
	mv $(TARGET) ../../natives/lib/$(TARGET)
