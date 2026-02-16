#ifndef MATRIX_H
#define MATRIX_H

/**
 * Initializes all elements of the matrix to zero.
 */
void init_zero_matrix(float matrix[3][3]);

/**
 * Initializes an identity matrix.
 */
void init_identity_matrix(float matrix[3][3]);

/**
 * Print the elements of the matrix.
 */
void print_matrix(const float matrix[3][3]);

/**
 * Add matrices.
 */
void add_matrices(const float a[3][3], const float b[3][3], float c[3][3]);

/**
 * Multiply matrices.
 */
void multiply_matrices(const float a[3][3], const float b[3][3], float c[3][3]);

/**
 * Transform point with the given M matrix.
 */
void transform_point(const float p[3], const float M[3][3], float p_transformed[3]);

/**
 * Scale a matrix with sx, sy parameter
 */
void scale_matrix(float M[3][3], float sx, float sy);

/**
 * Shift a matrix with dx, sy parameter 
 */
void shift_matrix(float M[3][3], float dx, float dy);

/**
 * Rotate a matrix with parameter the 'a' parameter
 */
void rotate_matrix(float M[3][3], float a);


#endif // MATRIX_H
