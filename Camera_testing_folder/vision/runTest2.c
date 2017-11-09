#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "greyscale_image.h"
#include "image_processing.h"
#include "rgb_image.h"

#include "matrix.h"
#include "gaussian_matrix.h"

int main()
{
    matrix m;
    init_matrix(&m, 5,5);
    print_matrix(&m);
    matrix gaussian_matrix = gauss_matrix(1, 5);
    print_matrix(&gaussian_matrix);
    return 0;
}
