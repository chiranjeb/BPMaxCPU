#include<iostream>
#include<immintrin.h>
#include <time.h>
#include <sys/time.h>
#include "common_defs.h"
//icc  -std=c++11 -Ofast -xhost -xCORE-AVX2 -ipo micro_kernel_fma_3_32.cpp
#define C(i, j) C[ (i * ldC) + j]
#define A(i, j) A[ (i * ldA) + j]
#define B(i, j) B[ (i * ldB) + j]

void register_tile_2_16(long ldK, float *A, float *B, float *C, int ldC);
void register_tile_2_24(long ldK, float *A, float *B, float *C, int ldC);
void register_tile_3_24(long ldK, float *A, float *B, float *C, int ldC);

void RunNew();
int main()
{
  RunNew();
}

void RunNew()
{
    float A[100] __attribute__((aligned(32)));
    float B[100] __attribute__((aligned(32)));
    float C[100] __attribute__((aligned(32)));
    
    int M, N, n;
    double count;
    printf("Please enter M, N, and numbe of multiplication iterationis:\n");
    std::cin >> M >> N >> count;

    printf (" Intializing  data \n\n");
    for (int i = 0; i < M * 1; i++) {
        A[i] = float(i+1);
    }

    for (int i = 0; i < 1 * N; i++) {
        B[i] = float(-i-1);
    }
    for (int i = 0; i < M * N; i++) {
        C[i] = -999999999;
    }


    struct timeval time;
    double elapsed_time;

    printf (" Starting program \n\n");
    gettimeofday(&time, NULL);
    elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000);
   
    if ( M == 2 && N == 16) 
    	register_tile_2_16(count, A, B, C, N);
    if ( M == 2 && N == 24) 
    	register_tile_2_24(count, A, B, C, N);
    if ( M == 3 && N == 24) 
    	register_tile_3_24(count, A, B, C, N);

    
    gettimeofday(&time, NULL);
    elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000) - elapsed_time;
    double gflop = 2 * M * N * count * 1E-9;
    printf("gflop:%lf\n", gflop);
    double gflops = (gflop/elapsed_time);
    printf("Count: %lf, Execution time : %lf sec, gflops : %lf.\n", count, elapsed_time, gflops);


   printf("\n Register tiled matrix\n");
   int ldC = N;
   for ( int i = 0; i < M; ++i)
   {
     for ( int j = 0; j < N; j++)
     {
       printf("%3.4g ", C(i, j));
     }  
     printf("\n");
   }

    for (int i = 0; i < M * N; i++) {
        C[i] = -999999999;
    }


    printf("\n");

    gettimeofday(&time, NULL);
    elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000);
    int K = 1;
    int ldA = 1;
    int ldB = N;
    for (int i = 0; i < M; i++)
    {
       for ( int k = 0; k < K; k++)
       {
         for (int j = 0; j < N; j++)
         {
            for(double l = 0; l < count; l++)     
            * &C(i, j) = max( C(i, j),  A(i, k) + B(k, j));
         }
       }
     }
  gettimeofday(&time, NULL);
  elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000) - elapsed_time;
  gflops = (gflop/elapsed_time);
  printf("Count: %lf, Execution time : %lf sec, gflops : %lf.\n", count, elapsed_time, gflops);
   for ( int i = 0; i < M; ++i)
   {
     for ( int j = 0; j < N; j++)
     {
       printf("%3.4g ", C(i, j));
     }
     printf("\n");
   }



}
