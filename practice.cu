#include <iostream>
#include <cmath>
#include <cuda_runtime.h>


// CUDA kernel for matrix multiplication
__global__ void matrixMultiply(float *a, float *b, float *c, int width) {
    int col = blockIdx.x * blockDim.x + threadIdx.x;
    int row = blockIdx.y * blockDim.y + threadIdx.y;

    float sum = 0.0f;
    for (int i = 0; i < width; ++i) {
        sum += a[row * width + i] * b[i * width + col];
    }

    c[row * width + col] = sum;
}

int main() {
    int width = 1024;
    int size = width * width * sizeof(float);

    // float *h_a = new float[size];
    float *h_b = new float[size];
    float *h_c = new float[size];

// Initialize matrices h_a and h_b with non-zero values
for (int i = 0; i < width * width; ++i) {
    h_a[i] = static_cast<float>(i % width) + 1.0f;
    h_b[i] = static_cast<float>(i % width) + 1.0f;
}


    float *d_a, *d_b, *d_c;
    cudaMalloc((void**)&d_a, size);
    cudaMalloc((void**)&d_b, size);
    cudaMalloc((void**)&d_c, size);

    cudaMemcpy(d_a, h_a, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, h_b, size, cudaMemcpyHostToDevice);

    dim3 dimGrid(width / 16, width / 16);
    dim3 dimBlock(16, 16);

    matrixMultiply<<<dimGrid, dimBlock>>>(d_a, d_b, d_c, width);

    cudaMemcpy(h_c, d_c, size, cudaMemcpyDeviceToHost);

    // After cudaMemcpy and kernel launch
    cudaError_t cudaStatus = cudaGetLastError();
    if (cudaStatus != cudaSuccess) {
        std::cerr << "CUDA error: " << cudaGetErrorString(cudaStatus) << std::endl;
        // Handle error appropriately, possibly exit the program
    }

	// Print the top-left 4x4 elements of the resulting matrix
	std::cout << "Top-left 4x4 elements of the resulting matrix:" << std::endl;
	for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
        std::cout << h_c[i * width + j] << " ";
    }
    std::cout << std::endl;
}


    // Your cleanup code
    delete[] h_a;
    delete[] h_b;
    delete[] h_c;

    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);

    return 0;
}
