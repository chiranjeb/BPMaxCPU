#include<iostream>
#include<immintrin.h>
#include <time.h>
#include <sys/time.h>
#include "external_functions.h"


void register_tile_2_32(int ldK, float *A, float *B, float *C_p, int ldA, int ldB, int ldC)
{
    int i = 0, j =0;
    //printf("\n\t(register tilling (i, j) = (%d %d), (ldA, ldB, ldC)=(%d,%d,%d)\n", i, j, ldA, ldB, ldC);

    __m256 c_patch_00 = _mm256_loadu_ps( &C_p( 0,0 ) );
    __m256 c_patch_01 = _mm256_loadu_ps( &C_p( 0,8 ) );
    __m256 c_patch_02 = _mm256_loadu_ps( &C_p( 0,16) );
    __m256 c_patch_03 = _mm256_loadu_ps( &C_p( 0,24) );
  
    __m256 c_patch_10 = _mm256_loadu_ps( &C_p( 1,0 ) );
    __m256 c_patch_11 = _mm256_loadu_ps( &C_p( 1,8 ) );
    __m256 c_patch_12 = _mm256_loadu_ps( &C_p( 1,16) );
    __m256 c_patch_13 = _mm256_loadu_ps( &C_p( 1,24) );
  
   float *aptr = A;
   float *bptr = B; 

   //printf("%f, %f\n", *aptr, *(aptr+1));
   //for( int i = 0; i < ldB;i++)
   // printf("%f ", *(bptr + i ));
  //printf("\n");

   // 

    for ( int k = 0; k < ldK; k++)
    {
        //if (k == 0)
        //printf("0x%x, 0x%x, 0x%x\n", &A(0,k), &A(2,k), &A(3,k));
        __m256 aa1, aa2;
        __m256 cc1, cc2, cc3, cc4, cc5,cc6, cc7, cc8;
        __m256 bb1, bb2, bb3, bb4;
        
        //_mm_prefetch (aptr,0); 
        //_mm_prefetch (aptr+1,0); 
        bb1 = _mm256_loadu_ps(bptr);
        //_mm_prefetch (bptr+8,0); 
        //_mm_prefetch (bptr+16,0); 
        //_mm_prefetch (bptr+24,0); 

        aa1  = _mm256_broadcast_ss(aptr);
        cc1        =  _mm256_add_ps( aa1, bb1 );          // cc = aa1 +  bb;
        c_patch_00 =  _mm256_max_ps( cc1, c_patch_00 );   // c_patch_00 = max(cc, c_patch0);


        aa2  = _mm256_broadcast_ss(aptr+1);
        cc2 = _mm256_add_ps( aa2, bb1);  //c_patch_10 += aa2 * bb;
        c_patch_10 =  _mm256_max_ps( cc2, c_patch_10 );   // c_patch_00 = max(cc, c_patch0);
        

        bb2 = _mm256_loadu_ps(bptr+8);
        cc3 = _mm256_add_ps( aa1, bb2 );
        c_patch_01 = _mm256_max_ps( cc3, c_patch_01 );
        cc4 = _mm256_add_ps( aa2, bb2 );
        c_patch_11 = _mm256_max_ps( cc4, c_patch_11 );

        bb3 = _mm256_loadu_ps(bptr+16);
        cc5 = _mm256_add_ps( aa1, bb3 );
        c_patch_02 = _mm256_max_ps( cc5, c_patch_02 );
        cc6 = _mm256_add_ps( aa2, bb3 );
        c_patch_12 = _mm256_max_ps( cc6, c_patch_12 );

        bb4 = _mm256_loadu_ps(bptr+24);
        cc7 = _mm256_add_ps( aa1, bb4 );
        c_patch_03 = _mm256_max_ps( cc7, c_patch_03);  //c_patch_03 += aa1 * bb;
        cc8 = _mm256_add_ps( aa2, bb4 );
        c_patch_13 = _mm256_max_ps( cc8, c_patch_13 );
        bptr+= 32;
        aptr+=2;
    }

    _mm256_storeu_ps( &C_p(0, 0), c_patch_00  );
    _mm256_storeu_ps( &C_p(0, 8), c_patch_01  );
    _mm256_storeu_ps( &C_p(0, 16), c_patch_02 );
    _mm256_storeu_ps( &C_p(0, 24), c_patch_03 );

    _mm256_storeu_ps( &C_p(1, 0), c_patch_10  );
    _mm256_storeu_ps( &C_p(1, 8), c_patch_11  );
    _mm256_storeu_ps( &C_p(1, 16), c_patch_12 );
    _mm256_storeu_ps( &C_p(1, 24), c_patch_13 );

}
