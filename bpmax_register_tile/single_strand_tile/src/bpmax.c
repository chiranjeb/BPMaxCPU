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
void bpmax_single_strand_s2_tile(long, long, long, long, long, long, int**, float****, float****, float****);
void transform_reverse_1D_to_2D(long, long, long, long, int*, int*);


//Memory Macros
#define seq2(i) seq2[i]
#define S2_A(k,i2,j2,i3,j3) S2_A[k][i2][j2][i3][j3]
#define S2_B(k,i2,j2,i3,j3) S2_B[k][i2][j2][i3][j3]
#define S2_C(k,i2,j2,i3,j3) S2_C[k][i2][j2][i3][j3]
#define seq2_t(i,j) seq2_t[i][j]
#define S2(k,i,j) S2[k][i][j]

void bpmax(long M, long N, long N_sec, long N_tile, long MR, long NR, int* seq2, float*** S2){
	///Parameter checking
	if (!((M >= 3 && N >= 16 && N_sec >= 4 && N_tile >= 4 && MR >= 1 && NR >= 1))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	//Memory Allocation
	int mz1, mz2, mz3, mz4, mz5;
	
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
	#define S0(i,i1,i2,i3,i4) bpmax_single_strand_s2_tile(M,N,N_sec,N_tile,MR,NR,seq2_t,S2_A[i2],S2_B[i2],S2_C[i2])
	#define S1(i,i1,i2,i3,i4) transform_reverse_1D_to_2D(N,N_sec,N_tile,i2,seq2,seq2_t[i2])
	{
		//Domain
		//{i,i1,i2,i3,i4|i4==0 && i3==0 && i2==0 && i1==2 && i==0 && M>=3 && N>=16 && N_sec>=4 && N_tile>=4 && MR>=1 && NR>=1}
		//{i,i1,i2,i3,i4|i4==0 && i3==0 && i1==0 && i==0 && i2>=0 && N_sec>=i2+1 && M>=3 && N>=16 && N_sec>=4 && N_tile>=4 && MR>=1 && NR>=1}
		int c3;
		for(c3=0;c3 <= N_sec-1;c3+=1)
		 {
		 	S1((0),(0),(c3),(0),(0));
		 }
		S0((0),(2),(0),(0),(0));
	}
	#undef S0
	#undef S1
	
	//Memory Free
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
}

//Memory Macros
#undef seq2
#undef S2_A
#undef S2_B
#undef S2_C
#undef seq2_t
#undef S2


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
