#include<iostream>
#include<immintrin.h>
#include <time.h>
#include <sys/time.h>
#include "common_defs.h"
#include <limits.h>
#include "math.h"

int _M, _N, _K, _MC, _NC, _KC, _MR, _NR;
#if 1
float *m_PackA;
float *m_PackB;
#else
float m_PackA[600*600] __attribute__((aligned(32)));
float m_PackB[600 * 600] __attribute__((aligned(32)));
#endif
float *A, *B, *C, *C_Fast;
double _GFLOPS = 0;

void PackA(int ib, int kb, const float *A, int ldA, float *pack)
{
   //printf("Pack start\n");
   for( int ii = 0; ii < ib; ii+=_MR)
   {
      for( int k = 0; k< kb; k++)
      {
        for(int iii = 0; iii< _MR; iii++ )
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
   for( int jj = 0; jj < kb; jj+=_NR)
   {  
      for ( int ii = 0; ii< ib; ii++ )
      {
         const float *bptr = &B(ii, jj);    
         for (int jjj = 0; jjj < _NR; jjj++)
         {  
           *pack++ = *bptr++;
         }
       }
   }
   //printf("Pack Done\n");
}



void compute_patch(int ib, int jb, int kb, float *A, float *B, float *C, int ldA, int ldB, int ldC)
{
    PackB(ib, kb, B, ldB); 
    for ( int jj=0; jj<jb; jj+=_NR )
    { 
        for ( int ii=0; ii<ib; ii+=_MR )
        { 
            if ( _MR == 2 && _NR == 32)
            {   
              register_tile<2,32>( kb, &m_PackA[ii*kb], &m_PackB[jj*kb], &C( ii,jj ), ldA, ldB, ldC );
            }
            else if ( _MR == 2 && _NR == 24)
            {   
              register_tile<2,24>( kb, &m_PackA[ii*kb], &m_PackB[jj*kb], &C( ii,jj ), ldA, ldB, ldC );
            }
            else if ( _MR == 3 && _NR == 16)
            {   
              register_tile<3,16>( kb, &m_PackA[ii*kb], &m_PackB[jj*kb], &C( ii,jj ), ldA, ldB, ldC );
            }
            else if ( _MR == 3 && _NR == 24)
            {   
              register_tile<3,24>( kb, &m_PackA[ii*kb], &m_PackB[jj*kb], &C( ii,jj ), ldA, ldB, ldC );
            }
            else if ( _MR == 4 && _NR == 16)
            {   
              register_tile<4,16>( kb, &m_PackA[ii*kb], &m_PackB[jj*kb], &C( ii,jj ), ldA, ldB, ldC );
            }
            
         }
     } 
}

void RunBase();
void RunNew();
int readMNKMCKCNCMRNR(int argc, char** argv, int *_M, int *_N, int *_K, int *_MC, int *_NC, int *_KC, int *_MR, int *_NR); 

void AllocateMemory()
{
    printf ("\nIntializing matrix data...");
    A      = (float *) malloc( _M * _K * sizeof(float));
    B      = (float *) malloc( _K * _N * sizeof(float));
    C      = (float *) malloc( _M * _N * sizeof(float));
    C_Fast = (float *) malloc( _M * _N * sizeof(float));

    for (int i = 0; i < (_M*_K); i++) {
        A[i] = float(i+1);
    }

    for (int i = 0; i < (_K*_N); i++) {
        B[i] = float(-i-1);
    }

    for (int i = 0; i < (_M*_N); i++) {
        C[i] = -99999999999;
    }
    
    for (int i = 0; i < (_M*_N); i++) {
        C_Fast[i] = -99999999999;
    }
}

void Verify()
{
    int ldA = _K;
    int ldB = _N;
    int ldC = _N;


    printf("\nComparing the matrices");
    for ( volatile int i = 0; i < _M; ++i)
    {
      for ( volatile int j = 0; j< _N; ++j)
      {
          //printf("\n%f, %f\n",1-(C(i, j)/C_Fast(i, j)), 1.401298464324817E-45);   
          volatile float val = (C(i, j)/C_Fast(i, j)); 
          if ( fabsf(1.0f - val) > 1.0E-9 )
           {
              printf("...[FAIL], (i:%d, j:%d), C(i, j):%g, C_Fast(i, j):%g\n", i, j, C(i, j), C_Fast(i, j));
              return;
           } 
      }
    }

   printf("...[PASS]\n");


}


int main(int argc, char *argv[])
{
    readMNKMCKCNCMRNR(argc, argv, &_M, &_N, &_K, &_MC, &_NC, &_KC, &_MR, &_NR);
    //m_PackA = (float *)malloc(sizeof(float)*_MC*_KC);
    //m_PackB = (float *)malloc(sizeof(float)*_KC*_NC);
    m_PackA = (float *) _mm_malloc (sizeof(float)*_MC*_KC, 32);
    m_PackB = (float *)_mm_malloc(sizeof(float)*_KC*_NC, 32);
    _GFLOPS = 2.0 * (_M) * (_N) * (_K) * 1E-9;
    printf("\n M : %5d, N :%5d, K :%5d:", _M, _N, _K);
    printf("\n MC: %5d, NC:%5d, KC:%5d", _MC, _NC, _KC);
    printf("\n MR: %5d, NR:%5d", _MR, _NR);
    printf("\n Total GFLOPS:%lf\n", _GFLOPS);

    AllocateMemory();
    RunBase();
    RunNew();
    Verify();
}

void RunNew()
{
    printf ("\nRunning optimized version.\n");
    
    //printf("\n\t(register tilling (i, j) = (%d %d), (ldA, ldB, ldC)=(%d,%d,%d)\n", i, j, ldA, ldB, ldC);
    int ldA = _K;
    int ldB = _N;
    int ldC = _N;

    struct timeval time;
    double elapsed_time;

    int num_patch = 0;
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
    #elif 0
        for ( int i=0; i<_M; i+=_MC ) {
          int ib = min( _MC, _M-i ); /* Last block may not be a full block */
          for ( int p=i; p<_K; p+=_KC ) {
              int pb = min( _KC, _K-p ); /* Last block may not be a full block */
              PackA(ib, pb, &A(i,p), ldA, &m_PackA[0]);
              for ( int j=p; j<_N; j+=_NC ) {
                int jb = min( _NC, _N-j ); /* Last block may not be a full block */
                 //printf("i, j , k) = %d, %d, %d\n", i, j, p); 
                 compute_patch(ib, jb, pb ,&m_PackA[0], &B( p,j ), &C_Fast( i,j ), ldA, ldB, ldC );
              }
          }
        }
    #else
        for ( int i=0; i<_M; i+=_MC ) {
          int ib = min( _MC, _M-i ); /* Last block may not be a full block */
          for ( int p=0; p<_K; p+=_KC ) {
              int pb = min( _KC, _K-p ); /* Last block may not be a full block */
              PackA(ib, pb, &A(i,p), ldA, &m_PackA[0]); 
              for ( int j=0; j<_N; j+=_NC ) {
                int jb = min( _NC, _N-j ); /* Last block may not be a full block */
                 //printf("i, j , k) = %d, %d, %d\n", i, j, p); 
                 compute_patch(ib, jb, pb ,&m_PackA[0], &B( p,j ), &C_Fast( i,j ), ldA, ldB, ldC );         
              }
          }
        }
     #endif


    gettimeofday(&time, NULL);
    elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000) - elapsed_time;
    printf("Execution time : %lf sec. GFLOPS: %f\n", elapsed_time, _GFLOPS/ elapsed_time);

    printf ("\n bottom right corner of matrix C_Fast: \n");
    for (int i=_M-6; i<_M; i++) {
      for (int j=_N-6; j<_N; j++) {
        printf ("%4.2G", C_Fast(i,j));
      }
      printf ("\n");
    }



}


void RunBase()
{
    printf ("\nRunning base version.");
    int ldA = _K;
    int ldB = _N;
    int ldC = _N;
    printf ("[Starting]...\n");

    struct timeval time;
    double elapsed_time;

    gettimeofday(&time, NULL);
    elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000);
    //printf("A range : 0x%x, 0x%x\n", &A(0,0), &A((M),(K)));
    int i, j, k;
    for (i = 0; i < _M; i++)
    {
       for ( j = 0; j < _N; j++)
       {
         for ( k = 0; k < _K; k++)
         {
            * &C(i, j) = max((C(i, j)),  (A(i, k) + B(k, j)));
         }
       }
     }

    gettimeofday(&time, NULL);
    elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000) - elapsed_time;
    //printf("Execution time : %lf sec.\n", elapsed_time);
    
    printf("Execution time : %lf sec. GFLOPS: %f\n", elapsed_time, _GFLOPS/ elapsed_time);

    printf ("\n bottom right corner of matrix C: \n");
    for (int i=_M-6; i<_M; i++) {
      for (int j=_N-6; j<_N; j++) {
        printf ("%4.2G", C(i,j));
      }
     printf("\n");
   }
}




int readMNKMCKCNCMRNR(int argc, char** argv, int *_M, int *_N, int *_K, int *_MC, int *_NC, int *_KC, int *_MR, int *_NR) 
{
     //Check number of args
     if (argc <= 8) 
     {
           printf("Number of argument is smaller than expected.\n");
           printf("Expecting M, N, K, MC, NC, KC, MR, NR \n");
           exit(0);
     }
     
     *_M  = atoi(argv[1]);
     *_N  = atoi(argv[2]);
     *_K  = atoi(argv[3]);
     *_MC = atoi(argv[4]);
     *_NC = atoi(argv[5]);
     *_KC = atoi(argv[6]);
     *_MR = atoi(argv[7]);
     *_NR = atoi(argv[8]);
    if ( *_M % *_MC  || *_N % *_NC || *_K % *_KC || *_MC % *_MR || *_NC % *_NR)
    {
       printf("MC, KC, NC , MR, NR are not fully aligned with M, N and K\n");
       //exit(0);
    }
  return 0; 
}
