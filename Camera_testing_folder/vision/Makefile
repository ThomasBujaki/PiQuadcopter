
runTest:
	gcc runTest.c image_processing.c greyscale.c greyscale_image.c rgb_image.c gaussian_blur.c matrix.c gaussian_matrix.c -lm -o runTest.out -std=c11

pipeline: clean runTest
	./runTest.out
	./convert_to_png.sh

clean:
	rm -f grayscale.out
	rm -f out.png
	rm -f runTest.out
