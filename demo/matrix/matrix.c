#include "matrix.h"

#include <stdio.h>
#include <math.h>
#include <string.h>

void init_zero_matrix(float matrix[3][3])
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            matrix[i][j] = 0.0;
        }
    }
}

void init_identity_matrix(float matrix[3][3])
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == j)
                matrix[i][j] = 1.0;
            else
                matrix[i][j] = 0.0;
        }
    }
}

void print_matrix(const float matrix[3][3])
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%4.4f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void add_matrices(const float a[3][3], const float b[3][3], float c[3][3])
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiply_matrices(const float a[3][3], const float b[3][3], float c[3][3])
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            c[i][j] = 
                a[i][0] * b[0][j] +
                a[i][1] * b[1][j] +
                a[i][2] * b[2][j] ;
        }
    }
}

void transform_point(const float p[3], const float M[3][3], float p_transformed[3])
{
    for (int i = 0; i < 3; ++i) {
        p_transformed[i] = 
            p[0] * M[0][i] + 
            p[1] * M[1][i] + 
            p[2] * M[2][i];
    }
}

/**
 * Scaling matrix
 * 
 * ⎡ sx  0  0 ⎤   ⎡ a1 a2 a3 ⎤   ⎡ sx*a1 sx*a2 sx*a3 ⎤
 * ⎢  0 sy  0 ⎥ * ⎢ a4 a5 a6 ⎥ = ⎢ sy*a4 sy*a5 sy*a6 ⎥
 * ⎣  0  0  1 ⎦   ⎣ a7 a8 a9 ⎦   ⎣    a7    a8    a9 ⎦
 */
void scale_matrix(float M[3][3], float sx, float sy)
{
    for (int i = 0; i < 3; ++i) {
        M[0][i] *= sx;
        M[1][i] *= sy;
    }
} 

/**
 * Scaling matrix
 * 
 * ⎡  1  0 dx ⎤   ⎡ a1 a2 a3 ⎤   ⎡ a1+dx*a7 a2+dx*a8 a3+dx*a9 ⎤
 * ⎢  0  1 dy ⎥ * ⎢ a4 a5 a6 ⎥ = ⎢ a4+dy*a7 a5+dy*a8 a6+dy*a9 ⎥
 * ⎣  0  0  1 ⎦   ⎣ a7 a8 a9 ⎦   ⎣       a7       a8       a9 ⎦
 */
void shift_matrix(float M[3][3], float dx, float dy)
{
    for (int i = 0; i < 3; ++i) {
        M[0][i] += dx * M[2][i];
        M[1][i] += dx * M[2][i];
    }
}

/**
 * Scaling matrix
 * 
 * ⎡  cos(a) -sin(a)       0 ⎤   ⎡ a1 a2 a3 ⎤   ⎡ cos(a)*a1-sin(a)*a4 cos(a)*a2-sin(a)*a5 cos(a)*a3-sin(a)*a6 ⎤
 * ⎢  sin(a)  cos(a)       0 ⎥ * ⎢ a4 a5 a6 ⎥ = ⎢ sin(a)*a1+cos(a)*a4 sin(a)*a2+cos(a)*a5 sin(a)*a3+cos(a)*a6 ⎥
 * ⎣       0       0       1 ⎦   ⎣ a7 a7 a9 ⎦   ⎣                  a7                  a8                  a9 ⎦
 */
void rotate_matrix(float M[3][3], float a)
{
    const float sin_a = sin(a);
    const float cos_a = cos(a);
    float scale_matrix[3][3] = {
        { cos_a*M[0][0] - sin_a*M[0][1], cos_a*M[1][0] - sin_a*M[1][1], cos_a*M[2][0] - sin_a*M[2][1] },
        { sin_a*M[0][0] + cos_a*M[0][1], sin_a*M[1][0] + cos_a*M[1][1], sin_a*M[2][0] + cos_a*M[2][1] },
        { M[2][0], M[2][1], M[2][2] }
    };
    float M_copy[3][3];
    memcpy(M_copy, M, sizeof(M_copy));
    multiply_matrices(scale_matrix, M_copy, M);
}

