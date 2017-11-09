#include <math.h>
#include <stdio.h>
#include "matrix.h"

matrix gauss_matrix(int variance, int matrix_size){
	matrix gaussian_matrix;
	init_matrix(&gaussian_matrix, matrix_size, matrix_size);
	float scaling_factor = ( 1 / ( 2 * M_PI * variance ));

	for (int x=0 ; x < matrix_size ; x++ ){
		int x_element = x-((matrix_size-1)/2);
		
		for (int y=0 ; y < matrix_size ; y++ ){	
			int y_element = y-((matrix_size-1)/2);
			
			float element_X = ( (-1 * pow( x_element, 2 )) / (2*variance ) );
			float element_Y = ( (-1 * pow( y_element, 2 )) / (2*variance ) );
			float matrix_value = scaling_factor*(exp(element_X+element_Y));
			if (x==0 && y==0){
				printf("%f %f %d %f %f %f %d\n",element_X, element_Y, variance, matrix_value,scaling_factor, exp(element_X+element_Y), matrix_size);
			}
			set_matrix_value(&gaussian_matrix, x, y, matrix_value);

		}

	}

	return gaussian_matrix;
}
