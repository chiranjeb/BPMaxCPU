#include<iostream>
#include<immintrin.h>
#include <time.h>
#include <sys/time.h>
#include "external_functions.h"
#include<stdlib.h>
#include<string.h>

void register_tile_3_24(int ldK, float *A, float *B, float *C_p, int ldA, int ldB, int ldC)
{
    int i = 0, j =0;
    //printf("Register Tile Entry:\n"); 
   //printf("\n\t(register tilling (i, j) = (%d %d), (ldA, ldB, ldC)=(%d,%d,%d)\n", i, j, ldA, ldB, ldC);

    __m256 c_patch_00 = _mm256_loadu_ps( &C_p( 0,0 ) );
    __m256 c_patch_01 = _mm256_loadu_ps( &C_p( 0,8 ) );
    __m256 c_patch_02 = _mm256_loadu_ps( &C_p( 0,16) );
  
    __m256 c_patch_10 = _mm256_loadu_ps( &C_p( 1,0 ) );
    __m256 c_patch_11 = _mm256_loadu_ps( &C_p( 1,8 ) );
    __m256 c_patch_12 = _mm256_loadu_ps( &C_p( 1,16) );

    __m256 c_patch_20 = _mm256_loadu_ps( &C_p( 2,0 ) );
    __m256 c_patch_21 = _mm256_loadu_ps( &C_p( 2,8 ) );
    __m256 c_patch_22 = _mm256_loadu_ps( &C_p( 2,16) ); 

 
   float *aptr = A;
   float *bptr = B; 

    for ( int k = 0; k < ldK; k++)
    {
        //if (k == 0)
        //printf("0x%x, 0x%x, 0x%x\n", &A(0,k), &A(2,k), &A(3,k));
        __m256 aa1, aa2, aa3;
        __m256 cc1, cc2, cc3;
        __m256 bb1;
        
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
  

        bb1 = _mm256_loadu_ps(bptr+8);
        cc1 = _mm256_add_ps( aa1, bb1 );
        c_patch_01 = _mm256_max_ps( cc1, c_patch_01 );
        cc2 = _mm256_add_ps( aa2, bb1 );
        c_patch_11 = _mm256_max_ps( cc2, c_patch_11 );
        cc3 = _mm256_add_ps( aa3, bb1 );
        c_patch_21 = _mm256_max_ps( cc3, c_patch_21 );


        bb1 = _mm256_loadu_ps(bptr+16);
        cc1 = _mm256_add_ps( aa1, bb1 );
        c_patch_02 = _mm256_max_ps( cc1, c_patch_02 );
        cc2 = _mm256_add_ps( aa2, bb1 );
        c_patch_12 = _mm256_max_ps( cc2, c_patch_12 );
        cc3 = _mm256_add_ps( aa3, bb1 );
        c_patch_22 = _mm256_max_ps( cc3, c_patch_22 );

        bptr+= 24;
        aptr+=3;
    }

    _mm256_storeu_ps( &C_p(0, 0), c_patch_00  );
    _mm256_storeu_ps( &C_p(0, 8), c_patch_01  );
    _mm256_storeu_ps( &C_p(0, 16), c_patch_02 );

    _mm256_storeu_ps( &C_p(1, 0),  c_patch_10  );
    _mm256_storeu_ps( &C_p(1, 8),  c_patch_11  );
    _mm256_storeu_ps( &C_p(1, 16), c_patch_12 );

    _mm256_storeu_ps( &C_p(2, 0),  c_patch_20  );
    _mm256_storeu_ps( &C_p(2, 8),  c_patch_21  );
    _mm256_storeu_ps( &C_p(2, 16), c_patch_22 );
}
