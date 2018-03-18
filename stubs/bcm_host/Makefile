CC = arm-none-eabi-gcc

TARGET := libbcm_host.so

.PHONY: clean move

$(TARGET):
	$(CC) -Wall bcm_host.c dispmanx.c -shared -fpic -marm -nostdlib -o $@ -mfloat-abi=hard

clean:
	$(RM) $(TARGET)

move:
	mv $(TARGET) ../../natives/lib/$(TARGET)
