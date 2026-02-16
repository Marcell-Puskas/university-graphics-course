#include "stdio.h"
#include "matrix.h"
#define _USE_MATH_DEFINES
#include "math.h"

int main(int argc, char* argv[])
{
	float a[3][3] = {
        { 1.0f, -2.0f,  3.0f},
        { 5.0f, -3.0f,  0.0f},
        {-2.0f,  1.0f, -4.0f}
    };
	float b[3][3];
	float c[3][3];

    init_zero_matrix(b);
    b[1][1] =  8.0f;
    b[2][0] = -3.0f;
    b[2][2] =  5.0f;
    
    printf("A matrix:\n");
    print_matrix(a);
    
    printf("B matrix:\n");
    print_matrix(b);
    
    add_matrices(a, b, c);
    
    printf("C matrix:\n");
    print_matrix(c);
    
    multiply_matrices(a, b, c);
    
    
    printf("Multiplied matrix:\n");
    print_matrix(c);

    float p[3] = { 1.0f, 2.0f, 3.0f };

    printf("Original point: [ %f, %f %f ]\n", p[0], p[1], p[2]);

    float pt[3];
    transform_point(p, a, pt);

    printf("Transformed point: [ %f, %f %f ]\n", pt[0], pt[1], pt[2]);

    scale_matrix(c, 2.0f, 2.0f);
    
    printf("Scaled matrix:\n");
    print_matrix(c);
    
    shift_matrix(c, 5, 6);

    printf("Shifted matrix:\n");
    print_matrix(c);

    rotate_matrix(c, M_PI / 2.0f);

    printf("Rotated matrix:\n");
    print_matrix(c);

	return 0;
}

