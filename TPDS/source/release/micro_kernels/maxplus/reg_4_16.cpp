#include<iostream>
#include<immintrin.h>
#include <time.h>
#include <sys/time.h>
#include "common_defs.h"


template<>
void register_tile<4,16>(int ldK, float *A, float *B, float *C, int ldA, int ldB, int ldC)
{
    int i = 0, j =0;
    //printf("\n\t(register tilling (i, j) = (%d %d), (ldA, ldB, ldC)=(%d,%d,%d)\n", i, j, ldA, ldB, ldC);

    __m256 c_patch_00 = _mm256_loadu_ps( &C( 0, 0 ) );
    __m256 c_patch_01 = _mm256_loadu_ps( &C( 0, 8 ) );
  
    __m256 c_patch_10 = _mm256_loadu_ps( &C( 1, 0 ) );
    __m256 c_patch_11 = _mm256_loadu_ps( &C( 1, 8 ) );
    

    __m256 c_patch_20 = _mm256_loadu_ps( &C( 2, 0) );
    __m256 c_patch_21 = _mm256_loadu_ps( &C( 2, 8) );
 
    __m256 c_patch_30 = _mm256_loadu_ps( &C( 3, 0) );
    __m256 c_patch_31 = _mm256_loadu_ps( &C( 3, 8) );

 
    float *aptr = A;
    float *bptr = B; 

    //#pragma unroll(3)
    for ( int k = 0; k < ldK; k++)
    {
        __m256 aa1, aa2, aa3, aa4;
        __m256 cc1, cc2, cc3, cc4;
        __m256 bb1, bb2;
        
        bb1 = _mm256_loadu_ps(bptr);

        aa1  = _mm256_broadcast_ss(aptr);
        cc1        =  _mm256_add_ps( aa1, bb1 );          // cc = aa1 +  bb;
        c_patch_00 =  _mm256_max_ps( cc1, c_patch_00 );   // c_patch_00 = max(cc, c_patch0);


        aa2  = _mm256_broadcast_ss(aptr+1);
        cc2 = _mm256_add_ps( aa2, bb1);  //c_patch_10 += aa2 * bb;
        c_patch_10 =  _mm256_max_ps( cc2, c_patch_10 );   // c_patch_00 = max(cc, c_patch0);
  

        aa3  = _mm256_broadcast_ss(aptr+2);
        cc3 = _mm256_add_ps( aa3, bb1);  //c_patch_10 += aa2 * bb;
        c_patch_20 =  _mm256_max_ps( cc3, c_patch_20 );   // c_patch_00 = max(cc, c_patch0);

        aa4  = _mm256_broadcast_ss(aptr+3);
        cc4 = _mm256_add_ps( aa4, bb1);  //c_patch_10 += aa2 * bb;
        c_patch_30 =  _mm256_max_ps( cc4, c_patch_30 );   // c_patch_00 = max(cc, c_patch0);  




        bb2 = _mm256_loadu_ps(bptr+8);
        cc1 = _mm256_add_ps( aa1, bb2 );
        c_patch_01 = _mm256_max_ps( cc1, c_patch_01 );
        cc2 = _mm256_add_ps( aa2, bb2 );
        c_patch_11 = _mm256_max_ps( cc2, c_patch_11 );
        cc3 = _mm256_add_ps( aa3, bb2 );
        c_patch_21 = _mm256_max_ps( cc3, c_patch_21 );
        cc4 = _mm256_add_ps( aa4, bb2 );
        c_patch_31 = _mm256_max_ps( cc4, c_patch_31 );

        bptr+= 16;
        aptr+=4;
    }

    _mm256_storeu_ps( &C(0, 0), c_patch_00 );
    _mm256_storeu_ps( &C(0, 8), c_patch_01 );
 
    _mm256_storeu_ps( &C(1, 0), c_patch_10 );
    _mm256_storeu_ps( &C(1, 8), c_patch_11 );
      
    _mm256_storeu_ps( &C(2, 0), c_patch_20 );
    _mm256_storeu_ps( &C(2, 8), c_patch_21 );

    _mm256_storeu_ps( &C(3, 0), c_patch_30 );
    _mm256_storeu_ps( &C(3, 8), c_patch_31 );


}
