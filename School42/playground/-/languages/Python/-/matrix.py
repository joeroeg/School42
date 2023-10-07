import random

# generate two random matrices
matrix_a = [[random.randint(0, 10) for i in range(1000)] for j in range(1000)]
matrix_b = [[random.randint(0, 10) for i in range(1000)] for j in range(1000)]

# initialize result matrix with all zeros
result_matrix = [[0 for i in range(1000)] for j in range(1000)]

# perform matrix multiplication
for i in range(1000):
    for j in range(1000):
        for k in range(1000):
            result_matrix[i][j] += matrix_a[i][k] * matrix_b[k][j]

import numpy as np
from numba import cuda
import random

# generate two random matrices
matrix_a = np.array([[random.randint(0, 10) for i in range(1000)] for j in range(1000)])
matrix_b = np.array([[random.randint(0, 10) for i in range(1000)] for j in range(1000)])

# initialize result matrix with all zeros
result_matrix = np.zeros((1000, 1000))

# define the kernel function to perform matrix multiplication
@cuda.jit
def matrix_multiplication_kernel(matrix_a, matrix_b, result_matrix):
    i, j, k = cuda.grid(3)
    if i < matrix_a.shape[0] and j < matrix_b.shape[1] and k < matrix_a.shape[1]:
        result_matrix[i][j] += matrix_a[i][k] * matrix_b[k][j]

# set up the CUDA device
device = cuda.get_current_device()
threads_per_block = (16, 16, 1)
blocks_per_grid_x = int(np.ceil(matrix_a.shape[0] / threads_per_block[0]))
blocks_per_grid_y = int(np.ceil(matrix_b.shape[1] / threads_per_block[1]))
blocks_per_grid = (blocks_per_grid_x, blocks_per_grid_y, 1)

# perform matrix multiplication using CUDA
matrix_multiplication_kernel[blocks_per_grid, threads_per_block](matrix_a, matrix_b, result_matrix)

# wait for kernel to finish
cuda.synchronize()

# print the result
print(result_matrix)

