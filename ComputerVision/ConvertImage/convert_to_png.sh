#!/bin/bash

gcc -std=c11 -o convert_to_png.out convert_to_png.c -lm -lpng
chmod +x convert_to_png.out
./convert_to_png.out $1

UNAME=$(uname | tr "[:upper:]" "[:lower:]")
if [ "$UNAME" == "linux" ]; then
	xdg-open out.png
else
	open out.png
fi
