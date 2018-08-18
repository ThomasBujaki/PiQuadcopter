#!/bin/bash

gcc -lm -lpng -o convert_to_png.out convert_to_png.c
chmod +x convert_to_png.out
./convert_to_png.out $1

UNAME=$(uname | tr "[:upper:]" "[:lower:]")
if [ "$UNAME" == "linux" ]; then
	xdg-open out.png
else
	open out.png
fi
