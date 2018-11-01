CC = gcc -std=c11
src = $(wildcard *.c)
obj = $(src:.c=.o)

LDFLAGS = -lm -lpng #-std=c11

build: $(obj)
	$(CC) -o build.out $^ $(LDFLAGS) 

run: clean build
	./build.out
	cd ConvertImage; ./convert_to_png.sh

.PHONY: clean
clean:
	rm -f $(obj) myprog

