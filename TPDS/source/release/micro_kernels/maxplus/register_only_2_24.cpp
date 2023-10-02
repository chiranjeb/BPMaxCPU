#include<iostream>
#include<immintrin.h>
#include <time.h>
#include <sys/time.h>
#include "common_defs.h"
//icc  -std=c++11 -Ofast -xhost -xCORE-AVX2 -ipo micro_kernel_fma_3_32.cpp
#define C(i, j) C[ (i * ldC) + j]
#define A(i, j) A[ (i * ldA) + j]
#define B(i, j) B[ (i * ldB) + j]

void register_tile_2_24(long ldK, float *A, float *B, float *C, int ldC)
{
    int i = 0, j =0;
    __m256 c_patch_00 = _mm256_loadu_ps( &C( 0,0 ) );
    __m256 c_patch_01 = _mm256_loadu_ps( &C( 0,8 ) );
    __m256 c_patch_02 = _mm256_loadu_ps( &C( 0,16 ) );

    __m256 c_patch_10 = _mm256_loadu_ps( &C( 1,0 ) );
    __m256 c_patch_11 = _mm256_loadu_ps( &C( 1,8 ) );
    __m256 c_patch_12 = _mm256_loadu_ps( &C( 1,16 ) );


    float *aptr = A;
    float *bptr = B; 
   
    __m256 aa1 = _mm256_broadcast_ss(aptr);
    __m256 aa2 = _mm256_broadcast_ss(aptr+1);

    __m256 bb1,bb2, bb3 ;
    bb1  = _mm256_loadu_ps(bptr);
    bb2  = _mm256_loadu_ps(bptr+8);
    bb3  = _mm256_loadu_ps(bptr+16);

    for ( long k = 0; k < ldK; k++)
    {
        __m256 cc1, cc2, cc3, cc4, cc5, cc6;
        cc1        =  _mm256_add_ps( aa1, bb1 );          // cc = aa1 +  bb;
        c_patch_00 =  _mm256_max_ps( cc1, c_patch_00 );   // c_patch_00 = max(cc, c_patch0);

        cc2 = _mm256_add_ps( aa2, bb1);  //c_patch_10 += aa2 * bb;
        c_patch_10 =  _mm256_max_ps( cc2, c_patch_10 );   // c_patch_00 = max(cc, c_patch0);


        cc3 = _mm256_add_ps( aa1, bb2 );
        c_patch_01 = _mm256_max_ps( cc3, c_patch_01 );

        cc4 = _mm256_add_ps( aa2, bb2 );
        c_patch_11 = _mm256_max_ps( cc4, c_patch_11 );
        
        cc5 = _mm256_add_ps( aa1, bb3 );
        c_patch_02 = _mm256_max_ps( cc5, c_patch_02 );

        cc6 = _mm256_add_ps( aa2, bb3 );
        c_patch_12 = _mm256_max_ps( cc6, c_patch_12 );
    }

    _mm256_storeu_ps( &C(0, 0) , c_patch_00  );
    _mm256_storeu_ps( &C(0, 8) , c_patch_01  );
    _mm256_storeu_ps( &C(0, 16), c_patch_02  );

    _mm256_storeu_ps( &C(1, 0),  c_patch_10  );
    _mm256_storeu_ps( &C(1, 8),  c_patch_11  );
    _mm256_storeu_ps( &C(1, 16), c_patch_12  );
}
