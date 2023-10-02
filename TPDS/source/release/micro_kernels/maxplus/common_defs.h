#define min(a, b) ((a) < (b))? (a) :(b)
#define max(a, b) ((a) > (b))? (a) :(b)
//icc  -std=c++11 -Ofast -xhost -xCORE-AVX2 -ipo micro_kernel_fma_3_32.cpp
#define A(i, j) A[ (i * ldA) + j]
#define B(i, j) B[ (i * ldB) + j]
#define C(i, j) C[ (i * ldC) + j]
#define C_Fast(i, j) C_Fast[ (i * ldC) + j]



template <int mr, int nr>
void register_tile (int ldK, float *A, float *B, float *C, int ldA, int ldB, int ldC); 

