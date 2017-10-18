#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "greyscale_image.h"
#include "image_processing.h"
#include "rgb_image.h"

void convert_raw_to_image(FILE *file, rgb_image *image, long length)
{
    init_rgb_image(image, 480, 640);
    fread(image->pixel, 1, length, file);
}

int main()
{
    // Read file.
    long length;
    FILE *f = fopen("still-640x480.data", "rb");

    if (!f)
    {
        return -1;
    }

    fseek(f, 0, SEEK_END);
    length = ftell(f);
    fseek(f, 0, SEEK_SET);

    rgb_image raw_image;
    convert_raw_to_image(f, &raw_image, length);
    fclose(f);

    // Run processing
    greyscale_image *image = image_processing(&raw_image);

    // Save file
    FILE *pFile = fopen("greyscale.data", "wb");
    if (pFile)
    {
        fwrite(image, (length * 2 / 3), 1, pFile);
        fclose(pFile);
    }

    destroy_rgb_image(&raw_image);
    destroy_greyscale_image(image);
    free(image);
    return 0;
}
