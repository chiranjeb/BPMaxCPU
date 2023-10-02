#include<iostream>
#include<immintrin.h>
#include <time.h>
#include <sys/time.h>
#include "common_defs.h"
//icc  -std=c++11 -Ofast -xhost -xCORE-AVX2 -ipo micro_kernel_fma_3_32.cpp
#define C(i, j) C[ (i * ldC) + j]
#define A(i, j) A[ (i * ldA) + j]
#define B(i, j) B[ (i * ldB) + j]

#if 1

void register_tile_2_16(long ldK, float *A, float *B, float *C, int ldC)
{
    int i = 0, j =0;
    __m256 c_patch_00 = _mm256_loadu_ps( &C( 0,0 ) );
    __m256 c_patch_01 = _mm256_loadu_ps( &C( 0,8 ) );
    __m256 c_patch_10 = _mm256_loadu_ps( &C( 1,0 ) );
    __m256 c_patch_11 = _mm256_loadu_ps( &C( 1,8 ) );


    float *aptr = A;
    float *bptr = B; 
   
    __m256 aa1 = _mm256_broadcast_ss(aptr);
    __m256 aa2 = _mm256_broadcast_ss(aptr+1);

    __m256 bb1,bb2 ;
    bb1  = _mm256_loadu_ps(bptr);
    bb2  = _mm256_loadu_ps(bptr+8);

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
    }
    _mm256_storeu_ps( &C(0, 0), c_patch_00  );
    _mm256_storeu_ps( &C(0, 8), c_patch_01  );

    _mm256_storeu_ps( &C(1, 0), c_patch_10  );
    _mm256_storeu_ps( &C(1, 8), c_patch_11  );

    //printf("Total number of operations:%ld\n", num_ops);

}
#else

void register_tile_2_16(long ldK, float *A, float *B, float *C, int ldC)
{   
    int i = 0, j =0;
    __m256 c_patch_00 = _mm256_loadu_ps( &C( 0,0 ) );
    __m256 c_patch_01 = _mm256_loadu_ps( &C( 0,8 ) );
    __m256 c_patch_10 = _mm256_loadu_ps( &C( 1,0 ) );
    __m256 c_patch_11 = _mm256_loadu_ps( &C( 1,8 ) );

    
    float *aptr = A;
    float *bptr = B;
    
    __m256 aa1 = _mm256_broadcast_ss(aptr);
    __m256 aa2 = _mm256_broadcast_ss(aptr+1);
    
    __m256 bb1,bb2 ;
    bb1  = _mm256_loadu_ps(bptr);
    bb2  = _mm256_loadu_ps(bptr+8);
    bb2  = _mm256_loadu_ps(bptr+8);
    
    for ( long k = 0; k < ldK; k++)
    {   
        __m256 cc1, cc2, cc3, cc4, cc5, cc6;
        cc1        =  _mm256_add_ps( aa1, bb1 );          // cc = aa1 +  bb;
        cc2 = _mm256_add_ps( aa2, bb1);  //c_patch_10 += aa2 * bb;
        cc3 = _mm256_add_ps( aa1, bb2 ); 
        cc4 = _mm256_add_ps( aa2, bb2 ); 
    }
    _mm256_storeu_ps( &C(0, 0), c_patch_00  );
    _mm256_storeu_ps( &C(1, 0), c_patch_10  );
    
    _mm256_storeu_ps( &C(0, 8), c_patch_01  );
    _mm256_storeu_ps( &C(1, 8), c_patch_11  );
    
    //printf("Total number of operations:%ld\n", num_ops);

}

#endif
#if 0
void register_tile_2_16(long ldK, float *A, float *B, float *C, int ldC)
{

__asm__(
"..L9: \n\t"
"        xorl      %eax, %eax                                    #30.18 \n\t"
"        movslq    %r8d, %r8                                     #12.1 \n\t"
"        testq     %rdi, %rdi                                    #30.27  \n\t"
"        vmovups   (%rcx), %ymm7                                 #14.43 \n\t"
"        vmovups   32(%rcx), %ymm6                               #15.43 \n\t"
"        vmovups   (%rdx), %ymm0                                 #27.28 \n\t"
"        vmovups   32(%rdx), %ymm9                               #28.28 \n\t"
"        vmovups   (%rcx,%r8,4), %ymm5                           #16.43 \n\t"
"        vmovups   32(%rcx,%r8,4), %ymm4                         #17.43 \n\t"
"        vbroadcastss (%rsi), %ymm1                              #23.18 \n\t"
"        vbroadcastss 4(%rsi), %ymm8                             #24.18 \n\t"
"        jle       ..B2.5        # Prob 10%                      #30.27 \n\t"
"                                # LOE rax rcx rbx rbp rdi r8 r12 r13 r14 r15 ymm0 ymm1 ymm4 ymm5 ymm6 ymm7 ymm8 ymm9 \n\t"
"..B2.2:                         # Preds ..B2.1 \n\t"
"                                # Execution count [9.00e-01] \n\t"
"        vaddps    %ymm0, %ymm1, %ymm3                           #33.38 \n\t"
"        vaddps    %ymm0, %ymm8, %ymm2                           #36.30 \n\t"
"        vaddps    %ymm9, %ymm1, %ymm1                           #40.30 \n\t"
"        vsubps    %ymm9, %ymm8, %ymm0                           #42.30 \n\t"
"                                # LOE rax rcx rbx rbp rdi r8 r12 r13 r14 r15 ymm0 ymm1 ymm2 ymm3 ymm4 ymm5 ymm6 ymm7 \n\t"
"..B2.3:                         # Preds ..B2.3 ..B2.2 \n\t"
"                                # Execution count [5.00e+00] \n\t"
"        incq      %rax                                          #30.32 \n\t"
"        vmaxps    %ymm7, %ymm3, %ymm7                           #34.23 \n\t"
"        vmaxps    %ymm5, %ymm2, %ymm5                           #37.23 \n\t"
"        vsubps    %ymm6, %ymm1, %ymm6                           #41.22 \n\t"
"        vsubps    %ymm4, %ymm0, %ymm4                           #43.22 \n\t"
"        cmpq      %rdi, %rax                                    #30.27 \n\t"
"        jl        ..B2.3        # Prob 82%                      #30.27 \n\t"
"                                # LOE rax rcx rbx rbp rdi r8 r12 r13 r14 r15 ymm0 ymm1 ymm2 ymm3 ymm4 ymm5 ymm6 ymm7 \n\t"
"..B2.5:                         # Preds ..B2.3 ..B2.1 \n\t"
"                                # Execution count [1.00e+00] \n\t"
"        vmovups   %ymm7, (%rcx)                                 #45.24 \n\t"
"        vmovups   %ymm5, (%rcx,%r8,4)                           #46.24 \n\t"
"        vmovups   %ymm6, 32(%rcx)                               #48.24 \n\t"
"        vmovups   %ymm4, 32(%rcx,%r8,4)                         #49.24 \n\t"
"        vzeroupper                                              #50.1 \n\t"
"        ret \n\t"
);
}

#endif
