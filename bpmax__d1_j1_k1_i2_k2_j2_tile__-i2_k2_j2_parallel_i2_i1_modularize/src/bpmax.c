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
void bpmax_inner_reductions(long, long, long, long, long, long, long, float****, float**, int*, float**);
void bpmax_outer_reductions(long, long, long, long, long, long, long, float****, float**, float**);
void bpmax_single_strand_s1(long, int*, float**);
void bpmax_single_strand_s2(long, int*, float**);
void bpmax_elementwise_ops(long, long, long, long, int*, int*, float**, float**, float****, float**);


//Memory Macros
#define seq1(i) seq1[i]
#define seq2(i) seq2[i]
#define S1(k,i,j) S1[k][i][j]
#define S2(k,i,j) S2[k][i][j]
#define FTable_elementwise_ops(i1,j1,i2,j2) FTable_elementwise_ops[i1][j1][i2][j2]
#define FTable_outer_reductions(i1,j1,i2,j2) FTable_outer_reductions[i1][j1][i2][j2]
#define FTable_inner_reductions(i1,j1,i2,j2) FTable_inner_reductions[i1][j1][i2][j2]
#define FTable(i1,j1,i2,j2) FTable[i1][j1][i2][j2]

void bpmax(long M, long N, long T1, long T2, long T3, int* seq1, int* seq2, float**** FTable){
	///Parameter checking
	if (!((M >= 8 && N >= 8 && T1 >= 1 && T2 >= 1 && T3 >= 1))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	//Memory Allocation
	int mz1, mz2, mz3, mz4;
	
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
	
	float* _lin_S2 = (float*)malloc(sizeof(float)*((N) * (N)));
	mallocCheck(_lin_S2, ((N) * (N)), float);
	float*** S2 = (float***)malloc(sizeof(float**)*(1));
	mallocCheck(S2, (1), float**);
	for (mz1=0;mz1 < 1; mz1++) {
		S2[mz1] = (float**)malloc(sizeof(float*)*(N));
		mallocCheck(S2[mz1], (N), float*);
		for (mz2=0;mz2 < N; mz2++) {
			S2[mz1][mz2] = &_lin_S2[(mz1*((N) * (N))) + (mz2*(N))];
		}
	}
	
	float* _lin_FTable_elementwise_ops = (float*)malloc(sizeof(float)*((M) * (M) * (N) * (N)));
	mallocCheck(_lin_FTable_elementwise_ops, ((M) * (M) * (N) * (N)), float);
	float**** FTable_elementwise_ops = (float****)malloc(sizeof(float***)*(M));
	mallocCheck(FTable_elementwise_ops, (M), float***);
	for (mz1=0;mz1 < M; mz1++) {
		FTable_elementwise_ops[mz1] = (float***)malloc(sizeof(float**)*(M));
		mallocCheck(FTable_elementwise_ops[mz1], (M), float**);
		for (mz2=0;mz2 < M; mz2++) {
			FTable_elementwise_ops[mz1][mz2] = (float**)malloc(sizeof(float*)*(N));
			mallocCheck(FTable_elementwise_ops[mz1][mz2], (N), float*);
			for (mz3=0;mz3 < N; mz3++) {
				FTable_elementwise_ops[mz1][mz2][mz3] = &_lin_FTable_elementwise_ops[(mz1*((M) * (N) * (N))) + (mz2*((N) * (N))) + (mz3*(N))];
			}
		}
	}
	
	float* _lin_FTable_outer_reductions = (float*)malloc(sizeof(float)*((M-1) * (M) * (N) * (N)));
	mallocCheck(_lin_FTable_outer_reductions, ((M-1) * (M) * (N) * (N)), float);
	float**** FTable_outer_reductions = (float****)malloc(sizeof(float***)*(M-1));
	mallocCheck(FTable_outer_reductions, (M-1), float***);
	for (mz1=0;mz1 < M-1; mz1++) {
		FTable_outer_reductions[mz1] = (float***)malloc(sizeof(float**)*(M));
		mallocCheck(FTable_outer_reductions[mz1], (M), float**);
		for (mz2=0;mz2 < M; mz2++) {
			FTable_outer_reductions[mz1][mz2] = (float**)malloc(sizeof(float*)*(N));
			mallocCheck(FTable_outer_reductions[mz1][mz2], (N), float*);
			for (mz3=0;mz3 < N; mz3++) {
				FTable_outer_reductions[mz1][mz2][mz3] = &_lin_FTable_outer_reductions[(mz1*((M) * (N) * (N))) + (mz2*((N) * (N))) + (mz3*(N))];
			}
		}
	}
	
	float* _lin_FTable_inner_reductions = (float*)malloc(sizeof(float)*((M) * (M) * (N) * (N)));
	mallocCheck(_lin_FTable_inner_reductions, ((M) * (M) * (N) * (N)), float);
	float**** FTable_inner_reductions = (float****)malloc(sizeof(float***)*(M));
	mallocCheck(FTable_inner_reductions, (M), float***);
	for (mz1=0;mz1 < M; mz1++) {
		FTable_inner_reductions[mz1] = (float***)malloc(sizeof(float**)*(M));
		mallocCheck(FTable_inner_reductions[mz1], (M), float**);
		for (mz2=0;mz2 < M; mz2++) {
			FTable_inner_reductions[mz1][mz2] = (float**)malloc(sizeof(float*)*(N));
			mallocCheck(FTable_inner_reductions[mz1][mz2], (N), float*);
			for (mz3=0;mz3 < N; mz3++) {
				FTable_inner_reductions[mz1][mz2][mz3] = &_lin_FTable_inner_reductions[(mz1*((M) * (N) * (N))) + (mz2*((N) * (N))) + (mz3*(N))];
			}
		}
	}
	#define S0(i1,j1,i2,j2,i4) FTable(i2,j1+i2,j2,i4) = 0
	#define S_1(i1,j1,i2,i3,i4) bpmax_inner_reductions(M,N,i3,j1+i3,T1,T2,T3,FTable,S2[0],seq2,FTable_inner_reductions[i3][j1+i3])
	#define S_2(i1,j1,i2,i3,i4) bpmax_outer_reductions(M,N,i2,j1+i2,T1,T2,T3,FTable,S1[0],FTable_outer_reductions[i2][j1+i2])
	#define S3(i,i1,i2,i3,i4) bpmax_single_strand_s1(M,seq1,S1[i1])
	#define S4(i,i1,i2,i3,i4) bpmax_single_strand_s2(N,seq2,S2[i1])
	#define S5(i1,j1,i2,i3,i4) bpmax_elementwise_ops(M,N,i2,j1+i2,seq1,seq2,S1[0],S2[0],FTable,FTable_elementwise_ops[i2][j1+i2])
	{
		//Domain
		//{i1,j1,i2,j2,i4|M+i1==0 && M>=8 && N>=8 && T1>=1 && T2>=1 && T3>=1 && i2>=0 && j1>=0 && M>=j1+i2+1 && j2>=0 && i4>=j2 && N>=i4+1}
		//{i1,j1,i2,i3,i4|i4==1 && i2==M && i1==1 && i3>=0 && j1>=0 && M>=j1+i3+1 && M>=8 && N>=8 && T1>=1 && T2>=1 && T3>=1}
		//{i1,j1,i2,i3,i4|i4==0 && i3==1 && i1==1 && i2>=0 && M>=j1+i2+1 && j1>=1 && M>=8 && N>=8 && T1>=1 && T2>=1 && T3>=1}
		//{i,i1,i2,i3,i4|i4==0 && i3==0 && i2==0 && i1==0 && i==0 && M>=8 && N>=8 && T1>=1 && T2>=1 && T3>=1}
		//{i,i1,i2,i3,i4|i4==0 && i3==0 && i2==0 && i1==0 && i==0 && M>=8 && N>=8 && T1>=1 && T2>=1 && T3>=1}
		//{i1,j1,i2,i3,i4|i4==0 && i3==0 && i1==1 && i2>=0 && j1>=0 && M>=j1+i2+1 && M>=8 && N>=8 && T1>=1 && T2>=1 && T3>=1}
		int c2,c3,c4,c5;
		for(c2=0;c2 <= M-1;c2+=1)
		 {
		 	for(c3=0;c3 <= -c2+M-1;c3+=1)
		 	 {
		 	 	#pragma omp parallel for private(c5)
		 	 	for(c4=0;c4 <= N-1;c4+=1)
		 	 	 {
		 	 	 	for(c5=c4;c5 <= N-1;c5+=1)
		 	 	 	 {
		 	 	 	 	S0((-M),(c2),(c3),(c4),(c5));
		 	 	 	 }
		 	 	 }
		 	 }
		 }
		S3((0),(0),(0),(0),(0));
		S4((0),(0),(0),(0),(0));
		for(c3=0;c3 <= M-1;c3+=1)
		 {
		 	S5((1),(0),(c3),(0),(0));
		 }
		#pragma omp parallel for 
		for(c4=0;c4 <= M-1;c4+=1)
		 {
		 	S_1((1),(0),(M),(c4),(1));
		 }
		for(c2=1;c2 <= M-1;c2+=1)
		 {
		 	for(c3=0;c3 <= -c2+M-1;c3+=1)
		 	 {
		 	 	S5((1),(c2),(c3),(0),(0));
		 	 	S_2((1),(c2),(c3),(1),(0));
		 	 }
		 	#pragma omp parallel for 
		 	for(c4=0;c4 <= -c2+M-1;c4+=1)
		 	 {
		 	 	S_1((1),(c2),(M),(c4),(1));
		 	 }
		 }
	}
	#undef S0
	#undef S_1
	#undef S_2
	#undef S3
	#undef S4
	#undef S5
	
	//Memory Free
	free(_lin_S1);
	for (mz1=0;mz1 < 1; mz1++) {
		free(S1[mz1]);
	}
	free(S1);
	
	free(_lin_S2);
	for (mz1=0;mz1 < 1; mz1++) {
		free(S2[mz1]);
	}
	free(S2);
	
	free(_lin_FTable_elementwise_ops);
	for (mz1=0;mz1 < M; mz1++) {
		for (mz2=0;mz2 < M; mz2++) {
			free(FTable_elementwise_ops[mz1][mz2]);
		}
		free(FTable_elementwise_ops[mz1]);
	}
	free(FTable_elementwise_ops);
	
	free(_lin_FTable_outer_reductions);
	for (mz1=0;mz1 < M-1; mz1++) {
		for (mz2=0;mz2 < M; mz2++) {
			free(FTable_outer_reductions[mz1][mz2]);
		}
		free(FTable_outer_reductions[mz1]);
	}
	free(FTable_outer_reductions);
	
	free(_lin_FTable_inner_reductions);
	for (mz1=0;mz1 < M; mz1++) {
		for (mz2=0;mz2 < M; mz2++) {
			free(FTable_inner_reductions[mz1][mz2]);
		}
		free(FTable_inner_reductions[mz1]);
	}
	free(FTable_inner_reductions);
}

//Memory Macros
#undef seq1
#undef seq2
#undef S1
#undef S2
#undef FTable_elementwise_ops
#undef FTable_outer_reductions
#undef FTable_inner_reductions
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
