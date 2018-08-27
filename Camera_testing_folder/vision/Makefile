CC = gcc -std=c11
src = $(wildcard *.c)
obj = $(src:.c=.o)

LDFLAGS = -lm -lpng #-std=c11

build: $(obj)
	$(CC) -o $@ $^ $(LDFLAGS) 

run: clean build
	./build
	cd ConvertImage; ./convert_to_png.sh

.PHONY: clean
clean:
	rm -f $(obj) myprog

