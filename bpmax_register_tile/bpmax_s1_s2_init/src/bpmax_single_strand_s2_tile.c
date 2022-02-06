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
void bpmax_single_strand_diagonal_tile(long, long, long, long, long, long, long, long, int**, float**);
void matrix_max_plus_section(long, long, long, long, long, long, long, long, long, float**, float**, float**);
void bpmax_single_strand_finalize(long, long, long, long, long, long, long, long, int**, float****, float**);
void transform_section_like_A_for_register_tile(long, long, long, long, long, long, long, long, float**, float**);
void transform_section_like_B_for_register_tile(long, long, long, long, long, long, long, long, float**, float**);


//Memory Macros
#define seq2_t(i,j) seq2_t[i][j]
#define S_C_1(i2,j2,i3,j3) S_C_1[i2][j2][i3][j3]
#define S_C_2(i2,j2,k2,i3,j3) S_C_2[i2][j2][k2][i3][j3]
#define S_C_3(i2,j2,i3,j3) S_C_3[i2][j2][i3][j3]
#define S_A(i2,j2,i3,j3) S_A[i2][j2][i3][j3]
#define S_B(i2,j2,i3,j3) S_B[i2][j2][i3][j3]
#define S_C(i2,j2,i3,j3) S_C[i2][j2][i3][j3]

void bpmax_single_strand_s2_tile(long M, long N, long N_sec, long N_tile, long MR, long NR, int** seq2_t, float**** S_A, float**** S_B, float**** S_C){
	///Parameter checking
	if (!((M >= 3 && N >= 8 && N_sec >= 2 && N_tile >= 4 && MR >= 1 && NR >= 1))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	//Memory Allocation
	int mz1, mz2, mz3, mz4, mz5;
	
	float* _lin_S_C_1 = (float*)malloc(sizeof(float)*((N_sec) * (N_sec) * (N_tile+1) * (N_tile)));
	mallocCheck(_lin_S_C_1, ((N_sec) * (N_sec) * (N_tile+1) * (N_tile)), float);
	float**** S_C_1 = (float****)malloc(sizeof(float***)*(N_sec));
	mallocCheck(S_C_1, (N_sec), float***);
	for (mz1=0;mz1 < N_sec; mz1++) {
		S_C_1[mz1] = (float***)malloc(sizeof(float**)*(N_sec));
		mallocCheck(S_C_1[mz1], (N_sec), float**);
		for (mz2=0;mz2 < N_sec; mz2++) {
			S_C_1[mz1][mz2] = (float**)malloc(sizeof(float*)*(N_tile+1));
			mallocCheck(S_C_1[mz1][mz2], (N_tile+1), float*);
			for (mz3=0;mz3 < N_tile+1; mz3++) {
				S_C_1[mz1][mz2][mz3] = &_lin_S_C_1[(mz1*((N_sec) * (N_tile+1) * (N_tile))) + (mz2*((N_tile+1) * (N_tile))) + (mz3*(N_tile))];
			}
		}
	}
	
	float* _lin_S_C_2 = (float*)malloc(sizeof(float)*((N_sec-2) * (N_sec) * (N_sec-1) * (N_tile) * (N_tile)));
	mallocCheck(_lin_S_C_2, ((N_sec-2) * (N_sec) * (N_sec-1) * (N_tile) * (N_tile)), float);
	float***** S_C_2 = (float*****)malloc(sizeof(float****)*(N_sec-2));
	mallocCheck(S_C_2, (N_sec-2), float****);
	for (mz1=0;mz1 < N_sec-2; mz1++) {
		S_C_2[mz1] = (float****)malloc(sizeof(float***)*(N_sec));
		mallocCheck(S_C_2[mz1], (N_sec), float***);
		for (mz2=0;mz2 < N_sec; mz2++) {
			S_C_2[mz1][mz2] = (float***)malloc(sizeof(float**)*(N_sec-1));
			mallocCheck(S_C_2[mz1][mz2], (N_sec-1), float**);
			for (mz3=0;mz3 < N_sec-1; mz3++) {
				S_C_2[mz1][mz2][mz3] = (float**)malloc(sizeof(float*)*(N_tile));
				mallocCheck(S_C_2[mz1][mz2][mz3], (N_tile), float*);
				for (mz4=0;mz4 < N_tile; mz4++) {
					S_C_2[mz1][mz2][mz3][mz4] = &_lin_S_C_2[(mz1*((N_sec) * (N_sec-1) * (N_tile) * (N_tile))) + (mz2*((N_sec-1) * (N_tile) * (N_tile))) + (mz3*((N_tile) * (N_tile))) + (mz4*(N_tile))];
				}
			}
		}
	}
	
	float* _lin_S_C_3 = (float*)malloc(sizeof(float)*((N_sec-1) * (N_sec) * (N_tile+1) * (N_tile)));
	mallocCheck(_lin_S_C_3, ((N_sec-1) * (N_sec) * (N_tile+1) * (N_tile)), float);
	float**** S_C_3 = (float****)malloc(sizeof(float***)*(N_sec-1));
	mallocCheck(S_C_3, (N_sec-1), float***);
	for (mz1=0;mz1 < N_sec-1; mz1++) {
		S_C_3[mz1] = (float***)malloc(sizeof(float**)*(N_sec));
		mallocCheck(S_C_3[mz1], (N_sec), float**);
		for (mz2=0;mz2 < N_sec; mz2++) {
			S_C_3[mz1][mz2] = (float**)malloc(sizeof(float*)*(N_tile+1));
			mallocCheck(S_C_3[mz1][mz2], (N_tile+1), float*);
			for (mz3=0;mz3 < N_tile+1; mz3++) {
				S_C_3[mz1][mz2][mz3] = &_lin_S_C_3[(mz1*((N_sec) * (N_tile+1) * (N_tile))) + (mz2*((N_tile+1) * (N_tile))) + (mz3*(N_tile))];
			}
		}
	}
	#define S0(i,j,i2,i3) bpmax_single_strand_diagonal_tile(M,N,N_sec,N_tile,MR,NR,-i,j,seq2_t,S_C[-i][j])
	#define S1(i,j,k,i3) matrix_max_plus_section(M,N,N_sec,N_tile,MR,NR,-i,i3,j,S_A[-i][j],S_B[j][i3],S_C[-i][i3])
	#define S2(i,j,i2,i3) bpmax_single_strand_finalize(M,N,N_sec,N_tile,MR,NR,-i,j,seq2_t,S_C,S_C[-i][j])
	#define S3(i,j,i2,i3) transform_section_like_A_for_register_tile(M,N,N_sec,N_tile,MR,NR,-i,j,S_C[-i][j],S_A[-i][j])
	#define S4(i,j,i2,i3) transform_section_like_B_for_register_tile(M,N,N_sec,N_tile,MR,NR,-i,j,S_C[-i][j],S_B[-i][j])
	{
		//Domain
		//{i,j,i2,i3|i+i3==0 && i2==0 && i+j==0 && 0>=i && N_sec+i>=1 && M>=3 && N>=8 && N_sec>=2 && N_tile>=4 && MR>=1 && NR>=1}
		//{i,j,k,i3|k==3 && 0>=i && i+i3>=1 && N_sec>=i3+1 && i+j>=1 && i3>=j+1 && M>=3 && N>=8 && N_sec>=2 && N_tile>=4 && MR>=1 && NR>=1}
		//{i,j,i2,i3|i3==j && i2==0 && 0>=i && i+j>=1 && N_sec>=j+1 && M>=3 && N>=8 && N_sec>=2 && N_tile>=4 && MR>=1 && NR>=1}
		//{i,j,i2,i3|i3==j && i2==2 && 0>=i && i+j>=0 && N_sec>=j+1 && M>=3 && N>=8 && N_sec>=2 && N_tile>=4 && MR>=1 && NR>=1}
		//{i,j,i2,i3|i3==j && i2==1 && 0>=i && i+j>=0 && N_sec>=j+1 && M>=3 && N>=8 && N_sec>=2 && N_tile>=4 && MR>=1 && NR>=1}
		int c1,c2,c4;
		S0((-N_sec+1),(N_sec-1),(0),(N_sec-1));
		S4((-N_sec+1),(N_sec-1),(1),(N_sec-1));
		S3((-N_sec+1),(N_sec-1),(2),(N_sec-1));
		S0((-N_sec+2),(N_sec-2),(0),(N_sec-2));
		S4((-N_sec+2),(N_sec-2),(1),(N_sec-2));
		S3((-N_sec+2),(N_sec-2),(2),(N_sec-2));
		S2((-N_sec+2),(N_sec-1),(0),(N_sec-1));
		S4((-N_sec+2),(N_sec-1),(1),(N_sec-1));
		S3((-N_sec+2),(N_sec-1),(2),(N_sec-1));
		for(c1=-N_sec+3;c1 <= 0;c1+=1)
		 {
		 	S0((c1),(-c1),(0),(-c1));
		 	S4((c1),(-c1),(1),(-c1));
		 	S3((c1),(-c1),(2),(-c1));
		 	for(c2=-c1+1;c2 <= N_sec-2;c2+=1)
		 	 {
		 	 	S2((c1),(c2),(0),(c2));
		 	 	S4((c1),(c2),(1),(c2));
		 	 	S3((c1),(c2),(2),(c2));
		 	 	for(c4=c2+1;c4 <= N_sec-1;c4+=1)
		 	 	 {
		 	 	 	S1((c1),(c2),(3),(c4));
		 	 	 }
		 	 }
		 	S2((c1),(N_sec-1),(0),(N_sec-1));
		 	S4((c1),(N_sec-1),(1),(N_sec-1));
		 	S3((c1),(N_sec-1),(2),(N_sec-1));
		 }
	}
	#undef S0
	#undef S1
	#undef S2
	#undef S3
	#undef S4
        Dump4D(N_sec, N_tile+1, N_tile,  S_C, "Computed");
	
	//Memory Free
	free(_lin_S_C_1);
	for (mz1=0;mz1 < N_sec; mz1++) {
		for (mz2=0;mz2 < N_sec; mz2++) {
			free(S_C_1[mz1][mz2]);
		}
		free(S_C_1[mz1]);
	}
	free(S_C_1);
	
	free(_lin_S_C_2);
	for (mz1=0;mz1 < N_sec-2; mz1++) {
		for (mz2=0;mz2 < N_sec; mz2++) {
			for (mz3=0;mz3 < N_sec-1; mz3++) {
				free(S_C_2[mz1][mz2][mz3]);
			}
			free(S_C_2[mz1][mz2]);
		}
		free(S_C_2[mz1]);
	}
	free(S_C_2);
	
	free(_lin_S_C_3);
	for (mz1=0;mz1 < N_sec-1; mz1++) {
		for (mz2=0;mz2 < N_sec; mz2++) {
			free(S_C_3[mz1][mz2]);
		}
		free(S_C_3[mz1]);
	}
	free(S_C_3);
}

//Memory Macros
#undef seq2_t
#undef S_C_1
#undef S_C_2
#undef S_C_3
#undef S_A
#undef S_B
#undef S_C


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
