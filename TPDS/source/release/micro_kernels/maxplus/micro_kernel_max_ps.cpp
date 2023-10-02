#include<iostream>
#include<immintrin.h>
#include <time.h>
#include <sys/time.h>

#define min(a, b) ((a) <(b))? (a) :(b)
#define max(a, b) ((a) >(b))? (a) :(b)
//icc  -std=c++11 -Ofast -xhost -xCORE-AVX2 -ipo micro_kernel_fma_3_32.cpp
#define A(i, j) A[ (i * ldA) + j]
#define B(i, j) B[ (i * ldB) + j]
#define C(i, j) C[ (i * ldC) + j]


#define MR 3
//#define NR 32 
#define NR 24 

/*
#define M  (3 * 4)
#define N  (96 * 4)
#define K  128
*/

/*
#define M  (3 * 128)
#define N  (32 * 8)
#define K  256
*/
#define MC  96 
#define NC  96 
#define KC  96 

#define M   MR * 96 * 10  
#define N   NR * MR * MR * 10 
#define K   MR * MR * NR * 10 

template <int mr, int nr>
void register_tile (int ldK, float *A, float *B, float *C, int ldA, int ldB, int ldC) 
{
}

//3, 4
//3, 3



template<>
void register_tile<3,32>(int ldK, float *A, float *B, float *C, int ldA, int ldB, int ldC)
{
    int i = 0, j =0;
    //printf("\n\t(register tilling (i, j) = (%d %d), (ldA, ldB, ldC)=(%d,%d,%d)\n", i, j, ldA, ldB, ldC);

    __m256 c_patch_00 = _mm256_loadu_ps( &C( 0,0 ) );
    __m256 c_patch_01 = _mm256_loadu_ps( &C( 0,8 ) );
    __m256 c_patch_02 = _mm256_loadu_ps( &C( 0,16) );
    //__m256 c_patch_03 = _mm256_loadu_ps( &C( 0,24) );
  
    __m256 c_patch_10 = _mm256_loadu_ps( &C( 1,0 ) );
    __m256 c_patch_11 = _mm256_loadu_ps( &C( 1,8 ) );
    __m256 c_patch_12 = _mm256_loadu_ps( &C( 1,16) );
    //__m256 c_patch_13 = _mm256_loadu_ps( &C( 1,24) );
  
    __m256 c_patch_20 = _mm256_loadu_ps( &C( 2, 0 ) );
    __m256 c_patch_21 = _mm256_loadu_ps( &C( 2, 8 ) );
    __m256 c_patch_22 = _mm256_loadu_ps( &C( 2, 16) );
    //__m256 c_patch_23 = _mm256_loadu_ps( &C( 2, 24) );
   float *aptr = A;
   float *bptr = B; 

   // 

    for ( int k = 0; k < ldK; k++)
    {
        //if (k == 0)
        //printf("0x%x, 0x%x, 0x%x\n", &A(0,k), &A(2,k), &A(3,k));
        __m256 aa1, aa2, aa3;
        __m256 cc1, cc2, cc3;
        
        //__m256 bb = _mm256_loadu_ps(&B(k , 0));
        __m256 bb = _mm256_loadu_ps(bptr);

        aa1  = _mm256_broadcast_ss(aptr++);
        cc1        =  _mm256_add_ps( aa1, bb );          // cc = aa1 +  bb;
        c_patch_00 =  _mm256_max_ps( cc1, c_patch_00 );   // c_patch_00 = max(cc, c_patch0);


        aa2  = _mm256_broadcast_ss(aptr++);
        cc2 = _mm256_add_ps( aa2, bb);  //c_patch_10 += aa2 * bb;
        c_patch_10 =  _mm256_max_ps( cc2, c_patch_10 );   // c_patch_00 = max(cc, c_patch0);
  
        aa3  = _mm256_broadcast_ss(aptr++);
        cc3 = _mm256_add_ps( aa3, bb );                        //c_patch_20 += aa2 * bb;
        c_patch_20 =  _mm256_max_ps( cc3, c_patch_20 );        //c_patch_00 = max(cc, c_patch0);
        //c_patch_20 =  _mm256_fmadd_ps( aa3, bb, c_patch_20 );  //c_patch_20 += aa3 * bb;

        //bb = _mm256_loadu_ps(&B(k, 8));
        bb  = _mm256_loadu_ps(bptr+8);
        cc1 = _mm256_add_ps( aa1, bb );
        c_patch_01 = _mm256_max_ps( cc1, c_patch_01 );
        cc2 = _mm256_add_ps( aa2, bb );
        c_patch_11 = _mm256_max_ps( cc2, c_patch_11 );
        cc3 = _mm256_add_ps( aa3, bb );
        c_patch_21 = _mm256_max_ps( cc3, c_patch_21 );

        //c_patch_01 = _mm256_fmadd_ps( aa1, bb, c_patch_01 );  //c_patch_01 += aa1 * bb;
        //c_patch_11 = _mm256_fmadd_ps( aa2, bb, c_patch_11 );  //c_patch_11 += aa2 * bb;
        //c_patch_21 = _mm256_fmadd_ps( aa3, bb, c_patch_21 );  //c_patch_21 += aa3 * bb;

        //bb = _mm256_loadu_ps(&B(k, 16));
        bb = _mm256_loadu_ps(bptr+16);
        cc1 = _mm256_add_ps( aa1, bb );
        c_patch_02 = _mm256_max_ps( cc1, c_patch_02 );
        cc2 = _mm256_add_ps( aa2, bb );
        c_patch_12 = _mm256_max_ps( cc2, c_patch_12 );
        cc3 = _mm256_add_ps( aa3, bb );
        c_patch_22 = _mm256_max_ps( cc3, c_patch_22 );
        //c_patch_02 = _mm256_fmadd_ps( aa1, bb, c_patch_02 );  //c_patch_02 += aa1 * bb;
        //c_patch_12 = _mm256_fmadd_ps( aa2, bb, c_patch_12 );  //c_patch_12 += aa2 * bb;
        //c_patch_22 = _mm256_fmadd_ps( aa3, bb, c_patch_22 );  //c_patch_22 += aa3 * bb;
        bptr+= 24;

        //bb = _mm256_loadu_ps(&B(k, 24));
        //bb = _mm256_loadu_ps(bptr+24);
        //c_patch_03 = _mm256_fmadd_ps( aa1, bb, c_patch_03 );  //c_patch_03 += aa1 * bb;
        //c_patch_13 = _mm256_fmadd_ps( aa2, bb, c_patch_13 );  //c_patch_13 += aa2 * bb;
        //c_patch_23 = _mm256_fmadd_ps( aa3, bb, c_patch_23 );  //c_patch_23 += aa3 * bb;
         // bptr+= 32;
    }

    _mm256_storeu_ps( &C(0, 0), c_patch_00  );
    _mm256_storeu_ps( &C(1, 0), c_patch_10  );
    _mm256_storeu_ps( &C(2, 0), c_patch_20  );
      
    _mm256_storeu_ps( &C(0, 8), c_patch_01  );
    _mm256_storeu_ps( &C(1, 8), c_patch_11  );
    _mm256_storeu_ps( &C(2, 8), c_patch_21  );
      
    _mm256_storeu_ps( &C(0, 16), c_patch_02 );
    _mm256_storeu_ps( &C(1, 16), c_patch_12 );
    _mm256_storeu_ps( &C(2, 16), c_patch_22 );
  
    //_mm256_storeu_ps( &C(0, 24), c_patch_03 );
   // _mm256_storeu_ps( &C(1, 24), c_patch_13 );
   // _mm256_storeu_ps( &C(2, 24), c_patch_23 );

    //printf("Here\n");
}


float m_PackA[MC*KC];
float m_PackB[KC*MC];
void PackA(int ib, int kb, const float *A, int ldA, float *pack)
{
   //printf("Pack start\n");
   for( int ii = 0; ii < ib; ii+=MR)
   {
      for( int k = 0; k< kb; k++)
      {
        for(int iii = 0; iii< MR; iii++ )
        {
           *pack++ = A((ii+iii), k); 
          // printf("%d, ", A(0, k));
        } 
      }
    }
   //printf("Pack Done\n");
}


void PackB(int ib, int kb, const float *B, int ldB)
{  
   //printf("Pack start\n");
   float *pack = &m_PackB[0];
   for( int jj = 0; jj < kb; jj+=NR)
   {  
      for ( int ii = 0; ii< ib; ii++ )
      {
         const float *bptr = &B(ii, jj);    
         for (int jjj = 0; jjj < NR; jjj++)
         {  
           *pack++ = *bptr++;
         }
       }
   }
   //printf("Pack Done\n");
}



void compute_patch(int ib, int jb, int kb, float *A, float *B, float *C, int ldA, int ldB, int ldC)
{
   
    //for(int i=0; i< MC * KC; ++i)
    {
        //if( i% (KC*MR) == 0) printf("\n");
        //printf("%f, ", m_PackA[i]);
    }
    //int op;scanf("%d", op);


    PackB(ib, kb, B, ldB); 
    for ( int jj=0; jj<jb; jj+=NR ){ /* m is assumed to be a multiple of MR */
    for ( int ii=0; ii<ib; ii+=MR ){ /* n is assumed to be a multiple of NR */
       register_tile<3,32>( kb, &m_PackA[ii*kb], &m_PackB[jj*kb], &C( ii,jj ), ldA, ldB, ldC );
      }
     } 
        
}

void RunBase();
void RunNew();


int main()
{
  RunBase();
  RunNew();
}

void RunNew()
{
    float * A = (float *) malloc( M * K * sizeof(float));
    float * B = (float *) malloc( K * N * sizeof(float));
    float * C = (float *) malloc( M * N * sizeof(float));
    
    printf (" Intializing matrix data \n\n");
    for (int i = 0; i < (M*K); i++) {
        A[i] = float(i+1);
    }

    for (int i = 0; i < (K*N); i++) {
        B[i] = float(-i-1);
    }

    for (int i = 0; i < (M*N); i++) {
        C[i] = 0.0;
    }
    
    //printf("\n\t(register tilling (i, j) = (%d %d), (ldA, ldB, ldC)=(%d,%d,%d)\n", i, j, ldA, ldB, ldC);
    int ldA = K;
    int ldB = N;
    int ldC = N;

    struct timeval time;
    double elapsed_time;


    gettimeofday(&time, NULL);
    elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000);
    //printf("A range : 0x%x, 0x%x\n", &A(0,0), &A((M),(K)));
    #if 0
    for ( int i = 0; i < M; i+=MR)
    {
       for ( int j = 0; j < N; j+=NR)
       {
         //printf("\n(calling register tilling (i, j) = (%d %d), (ldA, ldB, ldC)=(%d,%d,%d)\n", i, j, ldA, ldB, ldC);
         register_tile<3,32>(K, &A(i,0), &B(0,j), &C(i, j), ldA, ldB, ldC);
       }
    }
    #else
        for ( int i=0; i<M; i+=MC ) {
          int ib = min( MC, M-i ); /* Last block may not be a full block */
          for ( int p=0; p<K; p+=KC ) {
              int pb = min( KC, K-p ); /* Last block may not be a full block */
              PackA(ib, pb, &A(i,p), ldA, &m_PackA[0]); 
              for ( int j=0; j<N; j+=NC ) {
                int jb = min( NC, N-j ); /* Last block may not be a full block */
                // printf("i, j) = %d, %d, %d\n", i, j, p); 
                compute_patch(ib, jb, pb ,&m_PackA[0], &B( p,j ), &C( i,j ), ldA, ldB, ldC );         
              }
          }
        }
     #endif


    gettimeofday(&time, NULL);
    elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000) - elapsed_time;
    printf("Execution time : %lf sec.\n", elapsed_time);


    printf ("\n Top left corner of matrix C: \n");
    for (int i=M-6; i<M; i++) {
      for (int j=N-6; j<N; j++) {
        printf ("%12.5G", C[j+i*N]);
      }
      printf ("\n");
    }
}



void RunBase()
{
    float * A = (float *) malloc( M * K * sizeof(float));
    float * B = (float *) malloc( K * N * sizeof(float));
    float * C = (float *) malloc( M * N * sizeof(float));

    printf (" Intializing matrix data \n\n");
    for (int i = 0; i < (M*K); i++) {
        A[i] = float(i+1);
    }

    for (int i = 0; i < (K*N); i++) {
        B[i] = float(-i-1);
    }

    for (int i = 0; i < (M*N); i++) {
        C[i] = 0.0;
    }

    int ldA = K;
    int ldB = N;
    int ldC = N;

    struct timeval time;
    double elapsed_time;


    gettimeofday(&time, NULL);
    elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000);
    //printf("A range : 0x%x, 0x%x\n", &A(0,0), &A((M),(K)));
    int i, j, k;
    for (i = 0; i < M; i++)
    {
       for ( k = 0; k < K; k++)
       {
         for ( j = 0; j < N; j++)
         {
               
            //* &C(i, j) += A(i, k) * B(k, j);
            * &C(i, j) = max( C(i, j),  A(i, k) + B(k, j));
         }
       }
     }

    gettimeofday(&time, NULL);
    elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000) - elapsed_time;
    printf("Execution time : %lf sec.\n", elapsed_time);

    printf ("\n Top left corner of matrix C: \n");
    for (int i=M-6; i<M; i++) {
      for (int j=N-6; j<N; j++) {
        printf ("%12.5G", C[j+i*N]);
      }
     printf("\n");
   }
}
