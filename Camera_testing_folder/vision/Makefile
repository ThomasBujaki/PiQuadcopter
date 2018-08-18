CC = gcc
src = $(wildcard *.c)
obj = $(src:.c=.o)

LDFLAGS = -lGL -lglut -lpng -lz -lm -std=c11

build: $(obj)
	$(CC) -o $@ $^ $(LDFLAGS)

run: clean build
	./runTest.out
	./convert_to_png.sh

.PHONY: clean
clean:
	rm -f $(obj) myprog

