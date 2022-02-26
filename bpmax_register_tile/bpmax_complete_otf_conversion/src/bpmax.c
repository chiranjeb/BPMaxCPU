// This file is generated from test alphabets program by code generator in alphaz
// To compile this code, use -lm option for math library.

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <omp.h>
#include <immintrin.h>
#include <malloc.h>

#include "external_functions.h"

// Common Macros
#define max(x, y)   ((x)>(y) ? (x) : (y))
#define MAX(x, y)	((x)>(y) ? (x) : (y))
#define min(x, y)   ((x)>(y) ? (y) : (x))
#define MIN(x, y)	((x)>(y) ? (y) : (x))
#define CEILD(n,d)  (int)ceil(((double)(n))/((double)(d)))
#define ceild(n,d)  (int)ceil(((double)(n))/((double)(d)))
#define FLOORD(n,d) (int)floor(((double)(n))/((double)(d)))
#define floord(n,d) (int)floor(((double)(n))/((double)(d)))
#define CDIV(x,y)    CEILD((x),(y))
#define div(x,y)    CDIV((x),(y))
#define FDIV(x,y)    FLOORD((x),(y))
#define LB_SHIFT(b,s)  ((int)ceild(b,s) * s)
#define MOD(i,j)   ((i)%(j))
#define mallocCheck(v,s,d) if ((v) == NULL) { printf("Failed to allocate memory for %s : size=%lu\n", "sizeof(d)*(s)", sizeof(d)*(s)); exit(-1); }
// Reduction Operators
#define RADD(x,y)    ((x)+=(y))
#define RMUL(x,y)    ((x)*=(y))
#define RMAX(x,y)    ((x)=MAX((x),(y)))
#define RMIN(x,y)    ((x)=MIN((x),(y)))

// Common functions for min and max
//functions for integer max
inline int __max_int(int x, int y){
	return ((x)>(y) ? (x) : (y));
}

inline short __max_short(short x, short y){
	return ((x)>(y) ? (x) : (y));
}

inline long __max_long(long x, long y){
	return ((x)>(y) ? (x) : (y));
}

inline unsigned int __max_unsigned_int(unsigned int x, unsigned int y){
	return ((x)>(y) ? (x) : (y));
}

inline unsigned short __max_unsigned_short(unsigned short x, unsigned short y){
	return ((x)>(y) ? (x) : (y));
}

//function for float max
inline float __max_float(float x, float y){
	return ((x)>(y) ? (x) : (y));
}

//function for double max
inline double __max_double(double x, double y){
	return ((x)>(y) ? (x) : (y));
}

//function for integer min
inline int __min_int(int x, int y){
	return ((x)>(y) ? (y) : (x));
}

inline short __min_short(short x, short y){
	return ((x)>(y) ? (y) : (x));
}

inline long __min_long(long x, long y){
	return ((x)>(y) ? (y) : (x));
}

inline unsigned int __min_unsigned_int(unsigned int x, unsigned int y){
	return ((x)>(y) ? (y) : (x));
}

inline unsigned short __min_unsigned_short(unsigned short x, unsigned short y){
	return ((x)>(y) ? (y) : (x));
}

inline unsigned long __min_unsigned_long(unsigned long x, unsigned long y){
	return ((x)>(y) ? (y) : (x));
}

inline float __min_float(float x, float y){
	return ((x)>(y) ? (y) : (x));
}

inline double __min_double(double x, double y){
	return ((x)>(y) ? (y) : (x));
}




//SubSystem Function Declarations
void bpmax_single_strand_s1(long, int*, float**);
void transform_reverse_1D_to_2D(long, long, long, long, long, int*, int*);
void bpmax_single_strand_s2_tile(long, long, long, long, long, long, int**, float****, float****, float****);
void bpmax_outer_reductions(long, long, long, long, long, long, long, long, long, long, int*, float**, float****, float****, float******, float****);
void bpmax_init(long, long, long, long, long, long, long, int*, int**, float**, float****, float****);
void bpmax_inner_reductions(long, long, long, long, long, long, long, long, long, int**, float****, float****, float****, float****, float****, float****);


//Memory Macros
#define seq1(i) seq1[i]
#define seq2(i) seq2[i]
#define S1(k,i,j) S1[k][i][j]
#define S2_A(k,i2,j2,i3,j3) S2_A[k][i2][j2][i3][j3]
#define S2_B(k,i2,j2,i3,j3) S2_B[k][i2][j2][i3][j3]
#define S2_C(k,i2,j2,i3,j3) S2_C[k][i2][j2][i3][j3]
#define seq2_t(i,j) seq2_t[i][j]
#define FTable_A(i1,j1,i2,j2,i3,j3) FTable_A[i1][j1][i2][j2][i3][j3]
#define FTable_B(i1,j1,i2,j2,i3,j3) FTable_B[i1][j1][i2][j2][i3][j3]
#define FTable_outer(i1,j1,k1,i2,j2,i3,j3) FTable_outer[i1][j1][k1][i2][j2][i3][j3]
#define FTable(i1,j1,i2,j2,i3,j3) FTable[i1][j1][i2][j2][i3][j3]

void bpmax(long M, long N, long N_sec, long N_tile, long R, long MR, long NR, int* seq1, int* seq2, float****** FTable){
	///Parameter checking
	if (!((M >= 1 && N >= 8 && N_sec >= 2 && N_tile >= 4 && R >= 0 && N_tile >= R+1 && MR >= 1 && NR >= 1))) {
		printf("bpmax:The value of parameters are not valid.\n");
		exit(-1);
	}
	//Memory Allocation
	int mz1, mz2, mz3, mz4, mz5, mz6, mz7;
	
	float* _lin_S1 = (float*)malloc(sizeof(float)*((M) * (M)));
	mallocCheck(_lin_S1, ((M) * (M)), float);
	float*** S1 = (float***)malloc(sizeof(float**)*(1));
	mallocCheck(S1, (1), float**);
	for (mz1=0;mz1 < 1; mz1++) {
		S1[mz1] = (float**)malloc(sizeof(float*)*(M));
		mallocCheck(S1[mz1], (M), float*);
		for (mz2=0;mz2 < M; mz2++) {
			S1[mz1][mz2] = &_lin_S1[(mz1*((M) * (M))) + (mz2*(M))];
		}
	}
	
	float* _lin_S2_A = (float*)malloc(sizeof(float)*((N_sec) * (N_sec) * (N_tile) * (N_tile)));
	mallocCheck(_lin_S2_A, ((N_sec) * (N_sec) * (N_tile) * (N_tile)), float);
	float***** S2_A = (float*****)malloc(sizeof(float****)*(1));
	mallocCheck(S2_A, (1), float****);
	for (mz1=0;mz1 < 1; mz1++) {
		S2_A[mz1] = (float****)malloc(sizeof(float***)*(N_sec));
		mallocCheck(S2_A[mz1], (N_sec), float***);
		for (mz2=0;mz2 < N_sec; mz2++) {
			S2_A[mz1][mz2] = (float***)malloc(sizeof(float**)*(N_sec));
			mallocCheck(S2_A[mz1][mz2], (N_sec), float**);
			for (mz3=0;mz3 < N_sec; mz3++) {
				S2_A[mz1][mz2][mz3] = (float**)malloc(sizeof(float*)*(N_tile));
				mallocCheck(S2_A[mz1][mz2][mz3], (N_tile), float*);
				for (mz4=0;mz4 < N_tile; mz4++) {
					S2_A[mz1][mz2][mz3][mz4] = &_lin_S2_A[(mz1*((N_sec) * (N_sec) * (N_tile) * (N_tile))) + (mz2*((N_sec) * (N_tile) * (N_tile))) + (mz3*((N_tile) * (N_tile))) + (mz4*(N_tile))];
				}
			}
		}
	}
	
	float* _lin_S2_B = (float*)malloc(sizeof(float)*((N_sec) * (N_sec) * (N_tile) * (N_tile)));
	mallocCheck(_lin_S2_B, ((N_sec) * (N_sec) * (N_tile) * (N_tile)), float);
	float***** S2_B = (float*****)malloc(sizeof(float****)*(1));
	mallocCheck(S2_B, (1), float****);
	for (mz1=0;mz1 < 1; mz1++) {
		S2_B[mz1] = (float****)malloc(sizeof(float***)*(N_sec));
		mallocCheck(S2_B[mz1], (N_sec), float***);
		for (mz2=0;mz2 < N_sec; mz2++) {
			S2_B[mz1][mz2] = (float***)malloc(sizeof(float**)*(N_sec));
			mallocCheck(S2_B[mz1][mz2], (N_sec), float**);
			for (mz3=0;mz3 < N_sec; mz3++) {
				S2_B[mz1][mz2][mz3] = (float**)malloc(sizeof(float*)*(N_tile));
				mallocCheck(S2_B[mz1][mz2][mz3], (N_tile), float*);
				for (mz4=0;mz4 < N_tile; mz4++) {
					S2_B[mz1][mz2][mz3][mz4] = &_lin_S2_B[(mz1*((N_sec) * (N_sec) * (N_tile) * (N_tile))) + (mz2*((N_sec) * (N_tile) * (N_tile))) + (mz3*((N_tile) * (N_tile))) + (mz4*(N_tile))];
				}
			}
		}
	}
	
	float* _lin_S2_C = (float*)malloc(sizeof(float)*((N_sec) * (N_sec) * (N_tile+1) * (N_tile)));
	mallocCheck(_lin_S2_C, ((N_sec) * (N_sec) * (N_tile+1) * (N_tile)), float);
	float***** S2_C = (float*****)malloc(sizeof(float****)*(1));
	mallocCheck(S2_C, (1), float****);
	for (mz1=0;mz1 < 1; mz1++) {
		S2_C[mz1] = (float****)malloc(sizeof(float***)*(N_sec));
		mallocCheck(S2_C[mz1], (N_sec), float***);
		for (mz2=0;mz2 < N_sec; mz2++) {
			S2_C[mz1][mz2] = (float***)malloc(sizeof(float**)*(N_sec));
			mallocCheck(S2_C[mz1][mz2], (N_sec), float**);
			for (mz3=0;mz3 < N_sec; mz3++) {
				S2_C[mz1][mz2][mz3] = (float**)malloc(sizeof(float*)*(N_tile+1));
				mallocCheck(S2_C[mz1][mz2][mz3], (N_tile+1), float*);
				for (mz4=0;mz4 < N_tile+1; mz4++) {
					S2_C[mz1][mz2][mz3][mz4] = &_lin_S2_C[(mz1*((N_sec) * (N_sec) * (N_tile+1) * (N_tile))) + (mz2*((N_sec) * (N_tile+1) * (N_tile))) + (mz3*((N_tile+1) * (N_tile))) + (mz4*(N_tile))];
				}
			}
		}
	}
	
	int* _lin_seq2_t = (int*)malloc(sizeof(int)*((N_sec) * (N_tile)));
	mallocCheck(_lin_seq2_t, ((N_sec) * (N_tile)), int);
	int** seq2_t = (int**)malloc(sizeof(int*)*(N_sec));
	mallocCheck(seq2_t, (N_sec), int*);
	for (mz1=0;mz1 < N_sec; mz1++) {
		seq2_t[mz1] = &_lin_seq2_t[(mz1*(N_tile))];
	}
	
	float* _lin_FTable_A = (float*)_mm_malloc(sizeof(float)*((M) * (M) * (N_sec) * (N_sec) * (N_tile) * (N_tile)), 32);
	mallocCheck(_lin_FTable_A, ((M) * (M) * (N_sec) * (N_sec) * (N_tile) * (N_tile)), float);
	float****** FTable_A = (float******)malloc(sizeof(float*****)*(M));
	mallocCheck(FTable_A, (M), float*****);
	for (mz1=0;mz1 < M; mz1++) {
		FTable_A[mz1] = (float*****)malloc(sizeof(float****)*(M));
		mallocCheck(FTable_A[mz1], (M), float****);
		for (mz2=0;mz2 < M; mz2++) {
			FTable_A[mz1][mz2] = (float****)malloc(sizeof(float***)*(N_sec));
			mallocCheck(FTable_A[mz1][mz2], (N_sec), float***);
			for (mz3=0;mz3 < N_sec; mz3++) {
				FTable_A[mz1][mz2][mz3] = (float***)malloc(sizeof(float**)*(N_sec));
				mallocCheck(FTable_A[mz1][mz2][mz3], (N_sec), float**);
				for (mz4=0;mz4 < N_sec; mz4++) {
					FTable_A[mz1][mz2][mz3][mz4] = (float**)malloc(sizeof(float*)*(N_tile));
					mallocCheck(FTable_A[mz1][mz2][mz3][mz4], (N_tile), float*);
					for (mz5=0;mz5 < N_tile; mz5++) {
						FTable_A[mz1][mz2][mz3][mz4][mz5] = &_lin_FTable_A[(mz1*((M) * (N_sec) * (N_sec) * (N_tile) * (N_tile))) + (mz2*((N_sec) * (N_sec) * (N_tile) * (N_tile))) + (mz3*((N_sec) * (N_tile) * (N_tile))) + (mz4*((N_tile) * (N_tile))) + (mz5*(N_tile))];
					}
				}
			}
		}
	}
	
	float* _lin_FTable_B = (float*)_mm_malloc(sizeof(float)*((M) * (M) * (N_sec) * (N_sec) * (N_tile) * (N_tile)), 32);
	mallocCheck(_lin_FTable_B, ((M) * (M) * (N_sec) * (N_sec) * (N_tile) * (N_tile)), float);
	float****** FTable_B = (float******)malloc(sizeof(float*****)*(M));
	mallocCheck(FTable_B, (M), float*****);
	for (mz1=0;mz1 < M; mz1++) {
		FTable_B[mz1] = (float*****)malloc(sizeof(float****)*(M));
		mallocCheck(FTable_B[mz1], (M), float****);
		for (mz2=0;mz2 < M; mz2++) {
			FTable_B[mz1][mz2] = (float****)malloc(sizeof(float***)*(N_sec));
			mallocCheck(FTable_B[mz1][mz2], (N_sec), float***);
			for (mz3=0;mz3 < N_sec; mz3++) {
				FTable_B[mz1][mz2][mz3] = (float***)malloc(sizeof(float**)*(N_sec));
				mallocCheck(FTable_B[mz1][mz2][mz3], (N_sec), float**);
				for (mz4=0;mz4 < N_sec; mz4++) {
					FTable_B[mz1][mz2][mz3][mz4] = (float**)malloc(sizeof(float*)*(N_tile));
					mallocCheck(FTable_B[mz1][mz2][mz3][mz4], (N_tile), float*);
					for (mz5=0;mz5 < N_tile; mz5++) {
						FTable_B[mz1][mz2][mz3][mz4][mz5] = &_lin_FTable_B[(mz1*((M) * (N_sec) * (N_sec) * (N_tile) * (N_tile))) + (mz2*((N_sec) * (N_sec) * (N_tile) * (N_tile))) + (mz3*((N_sec) * (N_tile) * (N_tile))) + (mz4*((N_tile) * (N_tile))) + (mz5*(N_tile))];
					}
				}
			}
		}
	}

#if OUTER_REDUCTIONS_TIMING
    struct timeval time;
    double elapsed_time;
    gettimeofday(&time, NULL);
    elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000);
#endif
	
	#define S0(i,i1,i2,i3,i4) bpmax_single_strand_s1(M,seq1,S1[i2])
	#define S_1(i,i1,i2,i3,i4) transform_reverse_1D_to_2D(N,N_sec,N_tile,i2,R,seq2,seq2_t[i2])
	#define S2(i,i1,i2,i3,i4) bpmax_single_strand_s2_tile(N,N_sec,N_tile,R,MR,NR,seq2_t,S2_A[i2],S2_B[i2],S2_C[i2])
	#define S3(i,j,k,i3,i4) bpmax_outer_reductions(M,N,N_sec,N_tile,R,MR,NR,k,j+k,i3,seq1,S1[0],FTable_A[k][i3],FTable_B[i3+1][j+k],FTable,FTable[k][j+k])
	#define S4(i,j,i2,i3,i4) bpmax_init(M,N,N_sec,N_tile,R,i2,j+i2,seq1,seq2_t,S1[0],S2_C[0],FTable[i2][j+i2])
	#define S5(i,j,i2,i3,i4) bpmax_inner_reductions(M,N,N_sec,N_tile,R,MR,NR,i4,j+i4,seq2_t,S2_A[0],S2_B[0],S2_C[0],FTable[i4][j+i4],FTable_A[i4][j+i4],FTable_B[i4][j+i4])
	{
		//Domain
		//{i,i1,i2,i3,i4|i4==0 && i3==0 && i2==0 && i1==0 && i==0 && M>=1 && N>=8 && N_sec>=2 && N_tile>=4 && R>=0 && N_tile>=R+1 && MR>=1 && NR>=1}
		//{i,i1,i2,i3,i4|i4==0 && i3==0 && i1==1 && i==0 && i2>=0 && N_sec>=i2+1 && M>=1 && N>=8 && N_sec>=2 && N_tile>=4 && R>=0 && N_tile>=R+1 && MR>=1 && NR>=1}
		//{i,i1,i2,i3,i4|i4==0 && i3==0 && i2==0 && i1==2 && i==0 && M>=1 && N>=8 && N_sec>=2 && N_tile>=4 && R>=0 && N_tile>=R+1 && MR>=1 && NR>=1}
		//{i,j,k,i3,i4|i4==2 && i==2 && k>=0 && j>=1 && M>=j+k+1 && i3>=k && j+k>=i3+1 && M>=1 && N>=8 && N_sec>=2 && N_tile>=4 && R>=0 && N_tile>=R+1 && MR>=1 && NR>=1}
		//{i,j,i2,i3,i4|i4==1 && i3==0 && i==2 && i2>=0 && j>=0 && M>=j+i2+1 && M>=1 && N>=8 && N_sec>=2 && N_tile>=4 && R>=0 && N_tile>=R+1 && MR>=1 && NR>=1}
		//{i,j,i2,i3,i4|i3==0 && i2==M && i==2 && i4>=0 && j>=0 && M>=j+i4+1 && M>=1 && N>=8 && N_sec>=2 && N_tile>=4 && R>=0 && N_tile>=R+1 && MR>=1 && NR>=1}
		int c2,c3,c4,c5;
		S0((0),(0),(0),(0),(0));
		for(c3=0;c3 <= N_sec-1;c3+=1)
		 {
		 	S_1((0),(1),(c3),(0),(0));
		 }
		S2((0),(2),(0),(0),(0));
		for(c3=0;c3 <= M-1;c3+=1)
		 {
		 	S4((2),(0),(c3),(0),(1));
		 }
		#pragma omp parallel for schedule(static, 1) 
		for(c5=0;c5 <= M-1;c5+=1)
		 {
		 	S5((2),(0),(M),(0),(c5));
		 }
		for(c2=1;c2 <= M-1;c2+=1)
		 {
		 	for(c3=0;c3 <= -c2+M-1;c3+=1)
		 	 {
		 	 	S4((2),(c2),(c3),(0),(1));
		 	 	for(c4=c3;c4 <= c2+c3-1;c4+=1)
		 	 	 {
		 	 	 	S3((2),(c2),(c3),(c4),(2));
		 	 	 }
		 	 }
		 	#pragma omp parallel for schedule(static, 1)  
		 	for(c5=0;c5 <= -c2+M-1;c5+=1)
		 	 {
		 	 	S5((2),(c2),(M),(0),(c5));
		 	 }
		 }
	}
        Dump4D(N_sec, N_tile+1, N_tile, FTable[0][0], "Ftable Computed");  
#if OUTER_REDUCTIONS_TIMING
        gettimeofday(&time, NULL);
        elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000) - elapsed_time;
        printf("==> BPMax End: Execution time : %lf sec. GFLOPS: %f\n", elapsed_time, ((double)2*N*N*N*1E-9)/ (6*elapsed_time)); fflush(stdout);
        elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000);
#endif
	#undef S0
	#undef S_1
	#undef S2
	#undef S3
	#undef S4
	#undef S5
	
#if OUTER_REDUCTIONS_TIMING
       gettimeofday(&time, NULL);
       elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000) - elapsed_time;
       printf("==> BPMax End: Conversion Execution time : %lf sec. GFLOPS: %f\n", elapsed_time, ((double)2*N*N*N*1E-9)/ (6*elapsed_time)); fflush(stdout);
       elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000);
#endif	
	//Memory Free
	free(_lin_S1);
	for (mz1=0;mz1 < 1; mz1++) {
		free(S1[mz1]);
	}
	free(S1);
	
	free(_lin_S2_A);
	for (mz1=0;mz1 < 1; mz1++) {
		for (mz2=0;mz2 < N_sec; mz2++) {
			for (mz3=0;mz3 < N_sec; mz3++) {
				free(S2_A[mz1][mz2][mz3]);
			}
			free(S2_A[mz1][mz2]);
		}
		free(S2_A[mz1]);
	}
	free(S2_A);
	
	free(_lin_S2_B);
	for (mz1=0;mz1 < 1; mz1++) {
		for (mz2=0;mz2 < N_sec; mz2++) {
			for (mz3=0;mz3 < N_sec; mz3++) {
				free(S2_B[mz1][mz2][mz3]);
			}
			free(S2_B[mz1][mz2]);
		}
		free(S2_B[mz1]);
	}
	free(S2_B);
	
	free(_lin_S2_C);
	for (mz1=0;mz1 < 1; mz1++) {
		for (mz2=0;mz2 < N_sec; mz2++) {
			for (mz3=0;mz3 < N_sec; mz3++) {
				free(S2_C[mz1][mz2][mz3]);
			}
			free(S2_C[mz1][mz2]);
		}
		free(S2_C[mz1]);
	}
	free(S2_C);
	
	free(_lin_seq2_t);
	free(seq2_t);
	
	_mm_free(_lin_FTable_A);
	for (mz1=0;mz1 < M; mz1++) {
		for (mz2=0;mz2 < M; mz2++) {
			for (mz3=0;mz3 < N_sec; mz3++) {
				for (mz4=0;mz4 < N_sec; mz4++) {
					free(FTable_A[mz1][mz2][mz3][mz4]);
				}
				free(FTable_A[mz1][mz2][mz3]);
			}
			free(FTable_A[mz1][mz2]);
		}
		free(FTable_A[mz1]);
	}
	free(FTable_A);
	
	_mm_free(_lin_FTable_B);
	for (mz1=0;mz1 < M; mz1++) {
		for (mz2=0;mz2 < M; mz2++) {
			for (mz3=0;mz3 < N_sec; mz3++) {
				for (mz4=0;mz4 < N_sec; mz4++) {
					free(FTable_B[mz1][mz2][mz3][mz4]);
				}
				free(FTable_B[mz1][mz2][mz3]);
			}
			free(FTable_B[mz1][mz2]);
		}
		free(FTable_B[mz1]);
	}
	free(FTable_B);
#if OUTER_REDUCTIONS_TIMING
        gettimeofday(&time, NULL);
        elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000) - elapsed_time;
        printf("==> Memory Free End: Execution time : %lf sec. GFLOPS: %f\n", elapsed_time, ((double)2*N*N*N*1E-9)/ (6*elapsed_time)); fflush(stdout);
#endif	
}

//Memory Macros
#undef seq1
#undef seq2
#undef S1
#undef S2_A
#undef S2_B
#undef S2_C
#undef seq2_t
#undef FTable_A
#undef FTable_B
#undef FTable


//Common Macro undefs
#undef max
#undef MAX
#undef min
#undef MIN
#undef CEILD
#undef ceild
#undef FLOORD
#undef floord
#undef CDIV
#undef FDIV
#undef LB_SHIFT
#undef MOD
#undef RADD
#undef RMUL
#undef RMAX
#undef RMIN
