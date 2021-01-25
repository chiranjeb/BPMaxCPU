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
void bpmax_k1_reductions(long, long, long, long, long, long, long, double****, double**, double**);

//Local Function Declarations
double reduce_bpmax_S1_1(long, long, long, long, long, int, int, double**);
double reduce_bpmax_S2_1(long, long, long, long, long, int, int, double**);

//Memory Macros
#define seq1(i) seq1[i]
#define seq2(i) seq2[i]
#define S1(i,j) S1[i][j]
#define S2(i,j) S2[i][j]
#define FTable_outer_k1_k2(i1,j1,i2,j2) FTable_outer_k1_k2[i1][j1][i2][j2]
#define NR_FTable(i1,j1,i2,j2) NR_FTable[i1][j1][i2][j2]
#define NR_FTable_1(i1,j1,i2,j2) NR_FTable_1[i1][j1][i2][j2]
#define FTable(i1,j1,i2,j2) FTable[i1][j1][i2][j2]

void bpmax(long M, long N, long T1, long T2, long T3, int* seq1, int* seq2, double**** FTable){
	///Parameter checking
	if (!((M >= 3 && N >= 3 && T1 >= 1 && T2 >= 1 && T3 >= 1))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	//Memory Allocation
	int mz1, mz2, mz3, mz4;
	
	double* _lin_S1 = (double*)malloc(sizeof(double)*((M) * (M)));
	mallocCheck(_lin_S1, ((M) * (M)), double);
	double** S1 = (double**)malloc(sizeof(double*)*(M));
	mallocCheck(S1, (M), double*);
	for (mz1=0;mz1 < M; mz1++) {
		S1[mz1] = &_lin_S1[(mz1*(M))];
	}
	
	double* _lin_S2 = (double*)malloc(sizeof(double)*((N) * (N)));
	mallocCheck(_lin_S2, ((N) * (N)), double);
	double** S2 = (double**)malloc(sizeof(double*)*(N));
	mallocCheck(S2, (N), double*);
	for (mz1=0;mz1 < N; mz1++) {
		S2[mz1] = &_lin_S2[(mz1*(N))];
	}
	
	double* _lin_FTable_outer_k1_k2 = (double*)malloc(sizeof(double)*((M) * (M) * (N) * (N)));
	mallocCheck(_lin_FTable_outer_k1_k2, ((M) * (M) * (N) * (N)), double);
	double**** FTable_outer_k1_k2 = (double****)malloc(sizeof(double***)*(M));
	mallocCheck(FTable_outer_k1_k2, (M), double***);
	for (mz1=0;mz1 < M; mz1++) {
		FTable_outer_k1_k2[mz1] = (double***)malloc(sizeof(double**)*(M));
		mallocCheck(FTable_outer_k1_k2[mz1], (M), double**);
		for (mz2=0;mz2 < M; mz2++) {
			FTable_outer_k1_k2[mz1][mz2] = (double**)malloc(sizeof(double*)*(N));
			mallocCheck(FTable_outer_k1_k2[mz1][mz2], (N), double*);
			for (mz3=0;mz3 < N; mz3++) {
				FTable_outer_k1_k2[mz1][mz2][mz3] = &_lin_FTable_outer_k1_k2[(mz1*((M) * (N) * (N))) + (mz2*((N) * (N))) + (mz3*(N))];
			}
		}
	}
	
	double* _lin_NR_FTable = (double*)malloc(sizeof(double)*((M) * (M) * (N-1) * (N)));
	mallocCheck(_lin_NR_FTable, ((M) * (M) * (N-1) * (N)), double);
	double**** NR_FTable = (double****)malloc(sizeof(double***)*(M));
	mallocCheck(NR_FTable, (M), double***);
	for (mz1=0;mz1 < M; mz1++) {
		NR_FTable[mz1] = (double***)malloc(sizeof(double**)*(M));
		mallocCheck(NR_FTable[mz1], (M), double**);
		for (mz2=0;mz2 < M; mz2++) {
			NR_FTable[mz1][mz2] = (double**)malloc(sizeof(double*)*(N-1));
			mallocCheck(NR_FTable[mz1][mz2], (N-1), double*);
			for (mz3=0;mz3 < N-1; mz3++) {
				NR_FTable[mz1][mz2][mz3] = &_lin_NR_FTable[(mz1*((M) * (N-1) * (N))) + (mz2*((N-1) * (N))) + (mz3*(N))];
			}
		}
	}
	
	double* _lin_NR_FTable_1 = (double*)malloc(sizeof(double)*((M) * (M) * (N-1) * (N)));
	mallocCheck(_lin_NR_FTable_1, ((M) * (M) * (N-1) * (N)), double);
	double**** NR_FTable_1 = (double****)malloc(sizeof(double***)*(M));
	mallocCheck(NR_FTable_1, (M), double***);
	for (mz1=0;mz1 < M; mz1++) {
		NR_FTable_1[mz1] = (double***)malloc(sizeof(double**)*(M));
		mallocCheck(NR_FTable_1[mz1], (M), double**);
		for (mz2=0;mz2 < M; mz2++) {
			NR_FTable_1[mz1][mz2] = (double**)malloc(sizeof(double*)*(N-1));
			mallocCheck(NR_FTable_1[mz1][mz2], (N-1), double*);
			for (mz3=0;mz3 < N-1; mz3++) {
				NR_FTable_1[mz1][mz2][mz3] = &_lin_NR_FTable_1[(mz1*((M) * (N-1) * (N))) + (mz2*((N-1) * (N))) + (mz3*(N))];
			}
		}
	}
	#define S0(i,j,i2,i3,i4,i5,i6) S1(i2,j+i2) = 0
	#define S_1(i,j,i2,i3,i4,i5,i6) S1(i2,j+i2) = __max_double((S1(i2+1,j+i2-1))+(e_intra_score(seq1(i2),seq1(j+i2))),reduce_bpmax_S1_1(M,N,T1,T2,T3,i2,j+i2,S1))
	#define S_2(i,j,i2,i3,i4,i5,i6) S2(i2,j+i2) = 0
	#define S3(i,j,i2,i3,i4,i5,i6) S2(i2,j+i2) = __max_double((S2(i2+1,j+i2-1))+(e_intra_score(seq2(-i2+N-1),seq2(-j-i2+N-1))),reduce_bpmax_S2_1(M,N,T1,T2,T3,i2,j+i2,S2))
	#define S4(i1,j1,i2,j2,i4,i5,i6) FTable(j2,j1+j2,-i4,i5) = e_inter_score(seq1(j2),seq2(i4+N-1))
	#define S5(i1,j1,i2,j2,i4,i5,i6) FTable(j2,j1+j2,-i4,i5) += ((((((FTable(j2+1,j1+j2-1,-i4,i5))+(e_intra_score(seq1(j2),seq1(j1+j2))))+((FTable(j2,j1+j2,-i4+1,i5-1))+(e_intra_score(seq2(i4+N-1),seq2(-i5+N-1)))))+(S1(j2,j1+j2)))+(S2(-i4,i5)))+(NR_FTable(j2,j1+j2,-i4,i5)))+(NR_FTable_1(j2,j1+j2,-i4,i5))
	#define S6(i1,j1,i2,j2,i4,i5,i6) FTable(j2,j1+j2,-i4,i5) += ((((((FTable(j2+1,j1+j2-1,-i4,i5))+(e_intra_score(seq1(j2),seq1(j1+j2))))+(0))+(S1(j2,j1+j2)))+(S2(-i4,i5)))+(NR_FTable(j2,j1+j2,-i4,i5)))+(NR_FTable_1(j2,j1+j2,-i4,i5))
	#define S7(i1,j1,i2,j2,i4,i5,i6) FTable(j2,j1+j2,-i4,i5) += ((((((FTable(j2+1,j1+j2-1,-i4,i5))+(e_intra_score(seq1(j2),seq1(j1+j2))))+(0))+(S1(j2,j1+j2)))+(S2(-i4,i5)))+(0))+(0)
	#define S8(i1,j1,i2,j2,i4,i5,i6) FTable(j2,j1+j2,-i4,i5) += (((((0)+((FTable(j2,j1+j2,-i4+1,i5-1))+(e_intra_score(seq2(i4+N-1),seq2(-i5+N-1)))))+(S1(j2,j1+j2)))+(S2(-i4,i5)))+(NR_FTable(j2,j1+j2,-i4,i5)))+(NR_FTable_1(j2,j1+j2,-i4,i5))
	#define S9(i1,j1,i2,j2,i4,i5,i6) FTable(j2,j1+j2,-i4,i5) += (((((0)+(0))+(S1(j2,j1+j2)))+(S2(-i4,i5)))+(NR_FTable(j2,j1+j2,-i4,i5)))+(NR_FTable_1(j2,j1+j2,-i4,i5))
	#define S10(i1,j1,i2,j2,i4,i5,i6) FTable(j2,j1+j2,-i4,i5) += (((((0)+(0))+(S1(j2,j1+j2)))+(S2(-i4,i5)))+(0))+(0) 
	#define S13(i1,j1,i2,j2,i4,i5,i6) NR_FTable(j2,j1+j2,-i4,i6) = 0.0
	#define S14(i1,j1,i2,j2,i4,i5,i6) NR_FTable_1(j2,j1+j2,-i4,i6) = 0.0
	#define S15(i1,j1,i2,i3,i4,i5,i6) bpmax_k1_reductions(M,N,-j1+i2,i2,T1,T2,T3,FTable,S1,FTable[-j1+i2][i2])
	#define S11(i0,i1,i2,i3,i4,i5,i6) NR_FTable(i3,i1+i3,-i4,i6) = (NR_FTable(i3,i1+i3,-i4,i6))+((FTable(i3,i1+i3,-i4,i5))+(S2(i5+1,i6)))
	#define S12(i0,i1,i2,i3,i4,i5,i6) NR_FTable_1(i3,i1+i3,-i4,i6) = (NR_FTable_1(i3,i1+i3,-i4,i6))+((S2(-i4,i5))+(FTable(i3,i1+i3,i5+1,i6)))
	{
		//Domain
		//{i,j,i2,i3,i4,i5,i6|i6==0 && i5==0 && i4==0 && i3==0 && i==0 && M>=3 && N>=3 && T1>=1 && T2>=1 && T3>=1 && 0>=j-3 && M>=j+i2+1 && i2>=0 && j>=0}
		//{i,j,i2,i3,i4,i5,i6|i6==0 && i5==0 && i4==0 && i3==0 && i==0 && M>=3 && N>=3 && T1>=1 && T2>=1 && T3>=1 && j>=4 && i2>=0 && M>=i2+1 && M>=j+i2+1 && j+i2>=0}
		//{i,j,i2,i3,i4,i5,i6|i6==0 && i5==0 && i4==0 && i3==0 && i==0 && M>=3 && N>=3 && T1>=1 && T2>=1 && T3>=1 && 0>=j-3 && N>=j+i2+1 && i2>=0 && j>=0}
		//{i,j,i2,i3,i4,i5,i6|i6==0 && i5==0 && i4==0 && i3==0 && i==0 && M>=3 && N>=3 && T1>=1 && T2>=1 && T3>=1 && j>=4 && i2>=0 && j+i2>=0 && N>=j+i2+1 && N>=i2+1}
		//{i1,j1,i2,j2,i4,i5,i6|i6==0 && i4+i5==0 && i2==M && j1==0 && i1==1 && M>=3 && N>=3 && T1>=1 && T2>=1 && T3>=1 && j2>=0 && M>=j2+1 && 0>=i4 && N+i4>=1}
		//{i1,j1,i2,j2,i4,i5,i6|i6==0 && i2==M && i1==1 && M>=3 && N>=3 && T1>=1 && T2>=1 && T3>=1 && j1>=4 && i4+i5>=4 && j2>=0 && j1+i4+i5>=1 && M>=j1+j2+1 && 0>=i4 && N+i4>=1 && N>=i5+1 && i5>=0 && M>=j2+1 && j1+j2>=0}
		//{i1,j1,i2,j2,i4,i5,i6|i6==0 && i2==M && i1==1 && M>=3 && N>=3 && T1>=1 && T2>=1 && T3>=1 && j1>=4 && 0>=i4+i5-3 && i4+i5>=1 && j2>=0 && j1+i4+i5>=1 && M>=j1+j2+1 && 0>=i4 && M>=j2+1 && N>=i5+1 && j1+j2>=0}
		//{i1,j1,i2,j2,i4,i5,i6|i6==0 && i4+i5==0 && i2==M && i1==1 && M>=3 && N>=3 && T1>=1 && T2>=1 && T3>=1 && j1>=4 && j2>=0 && M>=j2+1 && M>=j1+j2+1 && 0>=i4 && j1+j2>=0 && N+i4>=1}
		//{i1,j1,i2,j2,i4,i5,i6|i6==0 && i2==M && i1==1 && M>=3 && T1>=1 && T2>=1 && T3>=1 && 0>=j1-3 && j1>=0 && j2>=0 && M>=j1+j2+1 && 0>=i4 && i4+i5>=4 && N>=i5+1}
		//{i1,j1,i2,j2,i4,i5,i6|i6==0 && i2==M && i1==1 && M>=3 && N>=3 && T1>=1 && T2>=1 && T3>=1 && 0>=j1-3 && j1>=0 && j2>=0 && M>=j1+j2+1 && 0>=i4 && 0>=i4+i5-3 && i4+i5>=1 && N>=i5+1}
		//{i1,j1,i2,j2,i4,i5,i6|i6==0 && i4+i5==0 && i2==M && i1==1 && M>=3 && N>=3 && T1>=1 && T2>=1 && T3>=1 && 0>=j1-3 && j1>=1 && N+i4>=1 && j2>=0 && 0>=i4 && M>=j1+j2+1}
		//{i1,j1,i2,j2,i4,i5,i6|i4+i5==-1 && i2==M && i1==1 && M>=3 && N>=3 && T1>=1 && T2>=1 && T3>=1 && N>=i6+1 && i4+i6>=1 && j1+i4+i6>=1 && 0>=i4 && M>=j1+j2+1 && j1>=0 && j2>=0}
		//{i1,j1,i2,j2,i4,i5,i6|i4+i5==-1 && i2==M && i1==1 && M>=3 && N>=3 && T1>=1 && T2>=1 && T3>=1 && M>=j1+j2+1 && i4+i6>=1 && j1+i4+i6>=1 && j2>=0 && j1>=0 && N>=i6+1 && 0>=i4}
		//{i1,j1,i2,i3,i4,i5,i6|i6==0 && i5==0 && i4==0 && i3==i2-4 && i1==1 && i2>=j1 && M>=i2+1 && j1>=1 && M>=3 && N>=3 && T1>=1 && T2>=1 && T3>=1}
		//{i0,i1,i2,i3,i4,i5,i6|i2==M && i0==1 && i4+i5>=0 && i6>=i5+1 && M>=3 && N>=3 && T1>=1 && T2>=1 && T3>=1 && i3>=0 && i1>=0 && M>=i1+i3+1 && 0>=i4 && N>=i6+1 && N>=i5+1 && i5>=-1 && i1+i4+i6>=1 && i4+i6>=1}
		//{i0,i1,i2,i3,i4,i5,i6|i2==M && i0==1 && i4+i5>=0 && i6>=i5+1 && M>=3 && N>=3 && T1>=1 && T2>=1 && T3>=1 && 0>=i4 && N>=i6+1 && N>=i5+1 && i5>=-1 && M>=i1+i3+1 && i1>=0 && i3>=0 && i1+i4+i6>=1 && i4+i6>=1}
		int c2,c3,c4,c5,c6,c7;
		if ((M >= N+1)) {
			{
				for(c2=0;c2 <= min(3,N-1);c2+=1)
				 {
				 	for(c3=0;c3 <= -c2+N-1;c3+=1)
				 	 {
				 	 	S0((0),(c2),(c3),(0),(0),(0),(0));
				 	 	S_2((0),(c2),(c3),(0),(0),(0),(0));
				 	 }
				 	for(c3=-c2+N;c3 <= -c2+M-1;c3+=1)
				 	 {
				 	 	S0((0),(c2),(c3),(0),(0),(0),(0));
				 	 }
				 }
			}
		}
		if ((M <= N-1)) {
			{
				for(c2=0;c2 <= min(3,M-1);c2+=1)
				 {
				 	for(c3=0;c3 <= -c2+M-1;c3+=1)
				 	 {
				 	 	S0((0),(c2),(c3),(0),(0),(0),(0));
				 	 	S_2((0),(c2),(c3),(0),(0),(0),(0));
				 	 }
				 	for(c3=-c2+M;c3 <= -c2+N-1;c3+=1)
				 	 {
				 	 	S_2((0),(c2),(c3),(0),(0),(0),(0));
				 	 }
				 }
			}
		}
		if ((M == N)) {
			{
				for(c2=0;c2 <= min(3,M-1);c2+=1)
				 {
				 	for(c3=0;c3 <= -c2+M-1;c3+=1)
				 	 {
				 	 	S0((0),(c2),(c3),(0),(0),(0),(0));
				 	 	S_2((0),(c2),(c3),(0),(0),(0),(0));
				 	 }
				 }
			}
		}
		if ((M >= 4 && N == 3)) {
			{
				for(c3=0;c3 <= M-4;c3+=1)
				 {
				 	S0((0),(3),(c3),(0),(0),(0),(0));
				 }
			}
		}
		if ((M == 3 && N >= 4)) {
			{
				for(c3=0;c3 <= N-4;c3+=1)
				 {
				 	S_2((0),(3),(c3),(0),(0),(0),(0));
				 }
			}
		}
		if ((M >= N+1)) {
			{
				for(c2=4;c2 <= N-1;c2+=1)
				 {
				 	for(c3=0;c3 <= -c2+N-1;c3+=1)
				 	 {
				 	 	S_1((0),(c2),(c3),(0),(0),(0),(0));
				 	 	S3((0),(c2),(c3),(0),(0),(0),(0));
				 	 }
				 	for(c3=-c2+N;c3 <= -c2+M-1;c3+=1)
				 	 {
				 	 	S_1((0),(c2),(c3),(0),(0),(0),(0));
				 	 }
				 }
			}
		}
		if ((M <= N-1)) {
			{
				for(c2=4;c2 <= M-1;c2+=1)
				 {
				 	for(c3=0;c3 <= -c2+M-1;c3+=1)
				 	 {
				 	 	S_1((0),(c2),(c3),(0),(0),(0),(0));
				 	 	S3((0),(c2),(c3),(0),(0),(0),(0));
				 	 }
				 	for(c3=-c2+M;c3 <= -c2+N-1;c3+=1)
				 	 {
				 	 	S3((0),(c2),(c3),(0),(0),(0),(0));
				 	 }
				 }
			}
		}
		if ((M == N)) {
			{
				for(c2=4;c2 <= M-1;c2+=1)
				 {
				 	for(c3=0;c3 <= -c2+M-1;c3+=1)
				 	 {
				 	 	S_1((0),(c2),(c3),(0),(0),(0),(0));
				 	 	S3((0),(c2),(c3),(0),(0),(0),(0));
				 	 }
				 }
			}
		}
		for(c2=max(4,N);c2 <= M-1;c2+=1)
		 {
		 	for(c3=0;c3 <= -c2+M-1;c3+=1)
		 	 {
		 	 	S_1((0),(c2),(c3),(0),(0),(0),(0));
		 	 }
		 }
		for(c2=max(4,M);c2 <= N-1;c2+=1)
		 {
		 	for(c3=0;c3 <= -c2+N-1;c3+=1)
		 	 {
		 	 	S3((0),(c2),(c3),(0),(0),(0),(0));
		 	 }
		 }
		if ((N >= 6)) {
			{
				#pragma omp parallel for private(c5,c6,c7)
				for(c4=0;c4 <= M-1;c4+=1)
				 {
				 	S4((1),(0),(M),(c4),(-N+1),(N-1),(0));
				 	S13((1),(0),(M),(c4),(-N+2),(N-3),(N-1));
				 	S14((1),(0),(M),(c4),(-N+2),(N-3),(N-1));
				 	S4((1),(0),(M),(c4),(-N+2),(N-2),(0));
				 	S11((1),(0),(M),(c4),(-N+2),(N-2),(N-1));
				 	S12((1),(0),(M),(c4),(-N+2),(N-2),(N-1));
				 	S9((1),(0),(M),(c4),(-N+2),(N-1),(0));
				 	for(c5=-N+3;c5 <= -N+4;c5+=1)
				 	 {
				 	 	for(c7=-c5+1;c7 <= N-1;c7+=1)
				 	 	 {
				 	 	 	S13((1),(0),(M),(c4),(c5),(-c5-1),(c7));
				 	 	 	S14((1),(0),(M),(c4),(c5),(-c5-1),(c7));
				 	 	 }
				 	 	S4((1),(0),(M),(c4),(c5),(-c5),(0));
				 	 	for(c7=-c5+1;c7 <= N-1;c7+=1)
				 	 	 {
				 	 	 	S11((1),(0),(M),(c4),(c5),(-c5),(c7));
				 	 	 	S12((1),(0),(M),(c4),(c5),(-c5),(c7));
				 	 	 }
				 	 	for(c6=-c5+1;c6 <= N-2;c6+=1)
				 	 	 {
				 	 	 	S9((1),(0),(M),(c4),(c5),(c6),(0));
				 	 	 	for(c7=c6+1;c7 <= N-1;c7+=1)
				 	 	 	 {
				 	 	 	 	S11((1),(0),(M),(c4),(c5),(c6),(c7));
				 	 	 	 	S12((1),(0),(M),(c4),(c5),(c6),(c7));
				 	 	 	 }
				 	 	 }
				 	 	S9((1),(0),(M),(c4),(c5),(N-1),(0));
				 	 }
				 	for(c7=N-4;c7 <= N-1;c7+=1)
				 	 {
				 	 	S13((1),(0),(M),(c4),(-N+5),(N-6),(c7));
				 	 	S14((1),(0),(M),(c4),(-N+5),(N-6),(c7));
				 	 }
				 	S4((1),(0),(M),(c4),(-N+5),(N-5),(0));
				 	for(c7=N-4;c7 <= N-1;c7+=1)
				 	 {
				 	 	S11((1),(0),(M),(c4),(-N+5),(N-5),(c7));
				 	 	S12((1),(0),(M),(c4),(-N+5),(N-5),(c7));
				 	 }
				 	for(c6=N-4;c6 <= N-2;c6+=1)
				 	 {
				 	 	S9((1),(0),(M),(c4),(-N+5),(c6),(0));
				 	 	for(c7=c6+1;c7 <= N-1;c7+=1)
				 	 	 {
				 	 	 	S11((1),(0),(M),(c4),(-N+5),(c6),(c7));
				 	 	 	S12((1),(0),(M),(c4),(-N+5),(c6),(c7));
				 	 	 }
				 	 }
				 	S8((1),(0),(M),(c4),(-N+5),(N-1),(0));
				 	for(c5=-N+6;c5 <= 0;c5+=1)
				 	 {
				 	 	for(c7=-c5+1;c7 <= N-1;c7+=1)
				 	 	 {
				 	 	 	S13((1),(0),(M),(c4),(c5),(-c5-1),(c7));
				 	 	 	S14((1),(0),(M),(c4),(c5),(-c5-1),(c7));
				 	 	 }
				 	 	S4((1),(0),(M),(c4),(c5),(-c5),(0));
				 	 	for(c7=-c5+1;c7 <= N-1;c7+=1)
				 	 	 {
				 	 	 	S11((1),(0),(M),(c4),(c5),(-c5),(c7));
				 	 	 	S12((1),(0),(M),(c4),(c5),(-c5),(c7));
				 	 	 }
				 	 	for(c6=-c5+1;c6 <= -c5+3;c6+=1)
				 	 	 {
				 	 	 	S9((1),(0),(M),(c4),(c5),(c6),(0));
				 	 	 	for(c7=c6+1;c7 <= N-1;c7+=1)
				 	 	 	 {
				 	 	 	 	S11((1),(0),(M),(c4),(c5),(c6),(c7));
				 	 	 	 	S12((1),(0),(M),(c4),(c5),(c6),(c7));
				 	 	 	 }
				 	 	 }
				 	 	for(c6=-c5+4;c6 <= N-2;c6+=1)
				 	 	 {
				 	 	 	S8((1),(0),(M),(c4),(c5),(c6),(0));
				 	 	 	for(c7=c6+1;c7 <= N-1;c7+=1)
				 	 	 	 {
				 	 	 	 	S11((1),(0),(M),(c4),(c5),(c6),(c7));
				 	 	 	 	S12((1),(0),(M),(c4),(c5),(c6),(c7));
				 	 	 	 }
				 	 	 }
				 	 	S8((1),(0),(M),(c4),(c5),(N-1),(0));
				 	 }
				 }
			}
		}
		if ((N == 5)) {
			{
				#pragma omp parallel for private(c5,c6,c7)
				for(c4=0;c4 <= M-1;c4+=1)
				 {
				 	S4((1),(0),(M),(c4),(-4),(4),(0));
				 	S13((1),(0),(M),(c4),(-3),(2),(4));
				 	S14((1),(0),(M),(c4),(-3),(2),(4));
				 	S4((1),(0),(M),(c4),(-3),(3),(0));
				 	S11((1),(0),(M),(c4),(-3),(3),(4));
				 	S12((1),(0),(M),(c4),(-3),(3),(4));
				 	S9((1),(0),(M),(c4),(-3),(4),(0));
				 	for(c5=-2;c5 <= -1;c5+=1)
				 	 {
				 	 	for(c7=-c5+1;c7 <= 4;c7+=1)
				 	 	 {
				 	 	 	S13((1),(0),(M),(c4),(c5),(-c5-1),(c7));
				 	 	 	S14((1),(0),(M),(c4),(c5),(-c5-1),(c7));
				 	 	 }
				 	 	S4((1),(0),(M),(c4),(c5),(-c5),(0));
				 	 	for(c7=-c5+1;c7 <= 4;c7+=1)
				 	 	 {
				 	 	 	S11((1),(0),(M),(c4),(c5),(-c5),(c7));
				 	 	 	S12((1),(0),(M),(c4),(c5),(-c5),(c7));
				 	 	 }
				 	 	for(c6=-c5+1;c6 <= 3;c6+=1)
				 	 	 {
				 	 	 	S9((1),(0),(M),(c4),(c5),(c6),(0));
				 	 	 	for(c7=c6+1;c7 <= 4;c7+=1)
				 	 	 	 {
				 	 	 	 	S11((1),(0),(M),(c4),(c5),(c6),(c7));
				 	 	 	 	S12((1),(0),(M),(c4),(c5),(c6),(c7));
				 	 	 	 }
				 	 	 }
				 	 	S9((1),(0),(M),(c4),(c5),(4),(0));
				 	 }
				 	for(c7=1;c7 <= 4;c7+=1)
				 	 {
				 	 	S13((1),(0),(M),(c4),(0),(-1),(c7));
				 	 	S14((1),(0),(M),(c4),(0),(-1),(c7));
				 	 }
				 	S4((1),(0),(M),(c4),(0),(0),(0));
				 	for(c7=1;c7 <= 4;c7+=1)
				 	 {
				 	 	S11((1),(0),(M),(c4),(0),(0),(c7));
				 	 	S12((1),(0),(M),(c4),(0),(0),(c7));
				 	 }
				 	for(c6=1;c6 <= 3;c6+=1)
				 	 {
				 	 	S9((1),(0),(M),(c4),(0),(c6),(0));
				 	 	for(c7=c6+1;c7 <= 4;c7+=1)
				 	 	 {
				 	 	 	S11((1),(0),(M),(c4),(0),(c6),(c7));
				 	 	 	S12((1),(0),(M),(c4),(0),(c6),(c7));
				 	 	 }
				 	 }
				 	S8((1),(0),(M),(c4),(0),(4),(0));
				 }
			}
		}
		if ((N >= 6)) {
			{
				for(c2=1;c2 <= min(3,M-1);c2+=1)
				 {
				 	for(c3=c2;c3 <= M-1;c3+=1)
				 	 {
				 	 	S15((1),(c2),(c3),(c3-4),(0),(0),(0));
				 	 }
				 	#pragma omp parallel for private(c5,c6,c7)
				 	for(c4=0;c4 <= -c2+M-1;c4+=1)
				 	 {
				 	 	S10((1),(c2),(M),(c4),(-N+1),(N-1),(0));
				 	 	S13((1),(c2),(M),(c4),(-N+2),(N-3),(N-1));
				 	 	S14((1),(c2),(M),(c4),(-N+2),(N-3),(N-1));
				 	 	S10((1),(c2),(M),(c4),(-N+2),(N-2),(0));
				 	 	S11((1),(c2),(M),(c4),(-N+2),(N-2),(N-1));
				 	 	S12((1),(c2),(M),(c4),(-N+2),(N-2),(N-1));
				 	 	S9((1),(c2),(M),(c4),(-N+2),(N-1),(0));
				 	 	for(c5=-N+3;c5 <= -N+4;c5+=1)
				 	 	 {
				 	 	 	for(c7=-c5+1;c7 <= N-1;c7+=1)
				 	 	 	 {
				 	 	 	 	S13((1),(c2),(M),(c4),(c5),(-c5-1),(c7));
				 	 	 	 	S14((1),(c2),(M),(c4),(c5),(-c5-1),(c7));
				 	 	 	 }
				 	 	 	S10((1),(c2),(M),(c4),(c5),(-c5),(0));
				 	 	 	for(c7=-c5+1;c7 <= N-1;c7+=1)
				 	 	 	 {
				 	 	 	 	S11((1),(c2),(M),(c4),(c5),(-c5),(c7));
				 	 	 	 	S12((1),(c2),(M),(c4),(c5),(-c5),(c7));
				 	 	 	 }
				 	 	 	for(c6=-c5+1;c6 <= N-2;c6+=1)
				 	 	 	 {
				 	 	 	 	S9((1),(c2),(M),(c4),(c5),(c6),(0));
				 	 	 	 	for(c7=c6+1;c7 <= N-1;c7+=1)
				 	 	 	 	 {
				 	 	 	 	 	S11((1),(c2),(M),(c4),(c5),(c6),(c7));
				 	 	 	 	 	S12((1),(c2),(M),(c4),(c5),(c6),(c7));
				 	 	 	 	 }
				 	 	 	 }
				 	 	 	S9((1),(c2),(M),(c4),(c5),(N-1),(0));
				 	 	 }
				 	 	for(c7=N-4;c7 <= N-1;c7+=1)
				 	 	 {
				 	 	 	S13((1),(c2),(M),(c4),(-N+5),(N-6),(c7));
				 	 	 	S14((1),(c2),(M),(c4),(-N+5),(N-6),(c7));
				 	 	 }
				 	 	S10((1),(c2),(M),(c4),(-N+5),(N-5),(0));
				 	 	for(c7=N-4;c7 <= N-1;c7+=1)
				 	 	 {
				 	 	 	S11((1),(c2),(M),(c4),(-N+5),(N-5),(c7));
				 	 	 	S12((1),(c2),(M),(c4),(-N+5),(N-5),(c7));
				 	 	 }
				 	 	for(c6=N-4;c6 <= N-2;c6+=1)
				 	 	 {
				 	 	 	S9((1),(c2),(M),(c4),(-N+5),(c6),(0));
				 	 	 	for(c7=c6+1;c7 <= N-1;c7+=1)
				 	 	 	 {
				 	 	 	 	S11((1),(c2),(M),(c4),(-N+5),(c6),(c7));
				 	 	 	 	S12((1),(c2),(M),(c4),(-N+5),(c6),(c7));
				 	 	 	 }
				 	 	 }
				 	 	S8((1),(c2),(M),(c4),(-N+5),(N-1),(0));
				 	 	for(c5=-N+6;c5 <= 0;c5+=1)
				 	 	 {
				 	 	 	for(c7=-c5+1;c7 <= N-1;c7+=1)
				 	 	 	 {
				 	 	 	 	S13((1),(c2),(M),(c4),(c5),(-c5-1),(c7));
				 	 	 	 	S14((1),(c2),(M),(c4),(c5),(-c5-1),(c7));
				 	 	 	 }
				 	 	 	S10((1),(c2),(M),(c4),(c5),(-c5),(0));
				 	 	 	for(c7=-c5+1;c7 <= N-1;c7+=1)
				 	 	 	 {
				 	 	 	 	S11((1),(c2),(M),(c4),(c5),(-c5),(c7));
				 	 	 	 	S12((1),(c2),(M),(c4),(c5),(-c5),(c7));
				 	 	 	 }
				 	 	 	for(c6=-c5+1;c6 <= -c5+3;c6+=1)
				 	 	 	 {
				 	 	 	 	S9((1),(c2),(M),(c4),(c5),(c6),(0));
				 	 	 	 	for(c7=c6+1;c7 <= N-1;c7+=1)
				 	 	 	 	 {
				 	 	 	 	 	S11((1),(c2),(M),(c4),(c5),(c6),(c7));
				 	 	 	 	 	S12((1),(c2),(M),(c4),(c5),(c6),(c7));
				 	 	 	 	 }
				 	 	 	 }
				 	 	 	for(c6=-c5+4;c6 <= N-2;c6+=1)
				 	 	 	 {
				 	 	 	 	S8((1),(c2),(M),(c4),(c5),(c6),(0));
				 	 	 	 	for(c7=c6+1;c7 <= N-1;c7+=1)
				 	 	 	 	 {
				 	 	 	 	 	S11((1),(c2),(M),(c4),(c5),(c6),(c7));
				 	 	 	 	 	S12((1),(c2),(M),(c4),(c5),(c6),(c7));
				 	 	 	 	 }
				 	 	 	 }
				 	 	 	S8((1),(c2),(M),(c4),(c5),(N-1),(0));
				 	 	 }
				 	 }
				 }
			}
		}
		if ((N == 5)) {
			{
				for(c2=1;c2 <= min(3,M-1);c2+=1)
				 {
				 	for(c3=c2;c3 <= M-1;c3+=1)
				 	 {
				 	 	S15((1),(c2),(c3),(c3-4),(0),(0),(0));
				 	 }
				 	#pragma omp parallel for private(c5,c6,c7)
				 	for(c4=0;c4 <= -c2+M-1;c4+=1)
				 	 {
				 	 	S10((1),(c2),(M),(c4),(-4),(4),(0));
				 	 	S13((1),(c2),(M),(c4),(-3),(2),(4));
				 	 	S14((1),(c2),(M),(c4),(-3),(2),(4));
				 	 	S10((1),(c2),(M),(c4),(-3),(3),(0));
				 	 	S11((1),(c2),(M),(c4),(-3),(3),(4));
				 	 	S12((1),(c2),(M),(c4),(-3),(3),(4));
				 	 	S9((1),(c2),(M),(c4),(-3),(4),(0));
				 	 	for(c5=-2;c5 <= -1;c5+=1)
				 	 	 {
				 	 	 	for(c7=-c5+1;c7 <= 4;c7+=1)
				 	 	 	 {
				 	 	 	 	S13((1),(c2),(M),(c4),(c5),(-c5-1),(c7));
				 	 	 	 	S14((1),(c2),(M),(c4),(c5),(-c5-1),(c7));
				 	 	 	 }
				 	 	 	S10((1),(c2),(M),(c4),(c5),(-c5),(0));
				 	 	 	for(c7=-c5+1;c7 <= 4;c7+=1)
				 	 	 	 {
				 	 	 	 	S11((1),(c2),(M),(c4),(c5),(-c5),(c7));
				 	 	 	 	S12((1),(c2),(M),(c4),(c5),(-c5),(c7));
				 	 	 	 }
				 	 	 	for(c6=-c5+1;c6 <= 3;c6+=1)
				 	 	 	 {
				 	 	 	 	S9((1),(c2),(M),(c4),(c5),(c6),(0));
				 	 	 	 	for(c7=c6+1;c7 <= 4;c7+=1)
				 	 	 	 	 {
				 	 	 	 	 	S11((1),(c2),(M),(c4),(c5),(c6),(c7));
				 	 	 	 	 	S12((1),(c2),(M),(c4),(c5),(c6),(c7));
				 	 	 	 	 }
				 	 	 	 }
				 	 	 	S9((1),(c2),(M),(c4),(c5),(4),(0));
				 	 	 }
				 	 	for(c7=1;c7 <= 4;c7+=1)
				 	 	 {
				 	 	 	S13((1),(c2),(M),(c4),(0),(-1),(c7));
				 	 	 	S14((1),(c2),(M),(c4),(0),(-1),(c7));
				 	 	 }
				 	 	S10((1),(c2),(M),(c4),(0),(0),(0));
				 	 	for(c7=1;c7 <= 4;c7+=1)
				 	 	 {
				 	 	 	S11((1),(c2),(M),(c4),(0),(0),(c7));
				 	 	 	S12((1),(c2),(M),(c4),(0),(0),(c7));
				 	 	 }
				 	 	for(c6=1;c6 <= 3;c6+=1)
				 	 	 {
				 	 	 	S9((1),(c2),(M),(c4),(0),(c6),(0));
				 	 	 	for(c7=c6+1;c7 <= 4;c7+=1)
				 	 	 	 {
				 	 	 	 	S11((1),(c2),(M),(c4),(0),(c6),(c7));
				 	 	 	 	S12((1),(c2),(M),(c4),(0),(c6),(c7));
				 	 	 	 }
				 	 	 }
				 	 	S8((1),(c2),(M),(c4),(0),(4),(0));
				 	 }
				 }
			}
		}
		if ((N <= 4)) {
			{
				#pragma omp parallel for private(c5,c6,c7)
				for(c4=0;c4 <= M-1;c4+=1)
				 {
				 	S4((1),(0),(M),(c4),(-N+1),(N-1),(0));
				 	S13((1),(0),(M),(c4),(-N+2),(N-3),(N-1));
				 	S14((1),(0),(M),(c4),(-N+2),(N-3),(N-1));
				 	S4((1),(0),(M),(c4),(-N+2),(N-2),(0));
				 	S11((1),(0),(M),(c4),(-N+2),(N-2),(N-1));
				 	S12((1),(0),(M),(c4),(-N+2),(N-2),(N-1));
				 	S9((1),(0),(M),(c4),(-N+2),(N-1),(0));
				 	for(c5=-N+3;c5 <= 0;c5+=1)
				 	 {
				 	 	for(c7=-c5+1;c7 <= N-1;c7+=1)
				 	 	 {
				 	 	 	S13((1),(0),(M),(c4),(c5),(-c5-1),(c7));
				 	 	 	S14((1),(0),(M),(c4),(c5),(-c5-1),(c7));
				 	 	 }
				 	 	S4((1),(0),(M),(c4),(c5),(-c5),(0));
				 	 	for(c7=-c5+1;c7 <= N-1;c7+=1)
				 	 	 {
				 	 	 	S11((1),(0),(M),(c4),(c5),(-c5),(c7));
				 	 	 	S12((1),(0),(M),(c4),(c5),(-c5),(c7));
				 	 	 }
				 	 	for(c6=-c5+1;c6 <= N-2;c6+=1)
				 	 	 {
				 	 	 	S9((1),(0),(M),(c4),(c5),(c6),(0));
				 	 	 	for(c7=c6+1;c7 <= N-1;c7+=1)
				 	 	 	 {
				 	 	 	 	S11((1),(0),(M),(c4),(c5),(c6),(c7));
				 	 	 	 	S12((1),(0),(M),(c4),(c5),(c6),(c7));
				 	 	 	 }
				 	 	 }
				 	 	S9((1),(0),(M),(c4),(c5),(N-1),(0));
				 	 }
				 }
			}
		}
		if ((N <= 4)) {
			{
				for(c2=1;c2 <= min(3,M-1);c2+=1)
				 {
				 	for(c3=c2;c3 <= M-1;c3+=1)
				 	 {
				 	 	S15((1),(c2),(c3),(c3-4),(0),(0),(0));
				 	 }
				 	#pragma omp parallel for private(c5,c6,c7)
				 	for(c4=0;c4 <= -c2+M-1;c4+=1)
				 	 {
				 	 	S10((1),(c2),(M),(c4),(-N+1),(N-1),(0));
				 	 	S13((1),(c2),(M),(c4),(-N+2),(N-3),(N-1));
				 	 	S14((1),(c2),(M),(c4),(-N+2),(N-3),(N-1));
				 	 	S10((1),(c2),(M),(c4),(-N+2),(N-2),(0));
				 	 	S11((1),(c2),(M),(c4),(-N+2),(N-2),(N-1));
				 	 	S12((1),(c2),(M),(c4),(-N+2),(N-2),(N-1));
				 	 	S9((1),(c2),(M),(c4),(-N+2),(N-1),(0));
				 	 	for(c5=-N+3;c5 <= 0;c5+=1)
				 	 	 {
				 	 	 	for(c7=-c5+1;c7 <= N-1;c7+=1)
				 	 	 	 {
				 	 	 	 	S13((1),(c2),(M),(c4),(c5),(-c5-1),(c7));
				 	 	 	 	S14((1),(c2),(M),(c4),(c5),(-c5-1),(c7));
				 	 	 	 }
				 	 	 	S10((1),(c2),(M),(c4),(c5),(-c5),(0));
				 	 	 	for(c7=-c5+1;c7 <= N-1;c7+=1)
				 	 	 	 {
				 	 	 	 	S11((1),(c2),(M),(c4),(c5),(-c5),(c7));
				 	 	 	 	S12((1),(c2),(M),(c4),(c5),(-c5),(c7));
				 	 	 	 }
				 	 	 	for(c6=-c5+1;c6 <= N-2;c6+=1)
				 	 	 	 {
				 	 	 	 	S9((1),(c2),(M),(c4),(c5),(c6),(0));
				 	 	 	 	for(c7=c6+1;c7 <= N-1;c7+=1)
				 	 	 	 	 {
				 	 	 	 	 	S11((1),(c2),(M),(c4),(c5),(c6),(c7));
				 	 	 	 	 	S12((1),(c2),(M),(c4),(c5),(c6),(c7));
				 	 	 	 	 }
				 	 	 	 }
				 	 	 	S9((1),(c2),(M),(c4),(c5),(N-1),(0));
				 	 	 }
				 	 }
				 }
			}
		}
		if ((N >= 6)) {
			{
				for(c2=4;c2 <= M-1;c2+=1)
				 {
				 	for(c3=c2;c3 <= M-1;c3+=1)
				 	 {
				 	 	S15((1),(c2),(c3),(c3-4),(0),(0),(0));
				 	 }
				 	#pragma omp parallel for private(c5,c6,c7)
				 	for(c4=0;c4 <= -c2+M-1;c4+=1)
				 	 {
				 	 	S7((1),(c2),(M),(c4),(-N+1),(N-1),(0));
				 	 	S13((1),(c2),(M),(c4),(-N+2),(N-3),(N-1));
				 	 	S14((1),(c2),(M),(c4),(-N+2),(N-3),(N-1));
				 	 	S7((1),(c2),(M),(c4),(-N+2),(N-2),(0));
				 	 	S11((1),(c2),(M),(c4),(-N+2),(N-2),(N-1));
				 	 	S12((1),(c2),(M),(c4),(-N+2),(N-2),(N-1));
				 	 	S6((1),(c2),(M),(c4),(-N+2),(N-1),(0));
				 	 	for(c5=-N+3;c5 <= -N+4;c5+=1)
				 	 	 {
				 	 	 	for(c7=-c5+1;c7 <= N-1;c7+=1)
				 	 	 	 {
				 	 	 	 	S13((1),(c2),(M),(c4),(c5),(-c5-1),(c7));
				 	 	 	 	S14((1),(c2),(M),(c4),(c5),(-c5-1),(c7));
				 	 	 	 }
				 	 	 	S7((1),(c2),(M),(c4),(c5),(-c5),(0));
				 	 	 	for(c7=-c5+1;c7 <= N-1;c7+=1)
				 	 	 	 {
				 	 	 	 	S11((1),(c2),(M),(c4),(c5),(-c5),(c7));
				 	 	 	 	S12((1),(c2),(M),(c4),(c5),(-c5),(c7));
				 	 	 	 }
				 	 	 	for(c6=-c5+1;c6 <= N-2;c6+=1)
				 	 	 	 {
				 	 	 	 	S6((1),(c2),(M),(c4),(c5),(c6),(0));
				 	 	 	 	for(c7=c6+1;c7 <= N-1;c7+=1)
				 	 	 	 	 {
				 	 	 	 	 	S11((1),(c2),(M),(c4),(c5),(c6),(c7));
				 	 	 	 	 	S12((1),(c2),(M),(c4),(c5),(c6),(c7));
				 	 	 	 	 }
				 	 	 	 }
				 	 	 	S6((1),(c2),(M),(c4),(c5),(N-1),(0));
				 	 	 }
				 	 	for(c7=N-4;c7 <= N-1;c7+=1)
				 	 	 {
				 	 	 	S13((1),(c2),(M),(c4),(-N+5),(N-6),(c7));
				 	 	 	S14((1),(c2),(M),(c4),(-N+5),(N-6),(c7));
				 	 	 }
				 	 	S7((1),(c2),(M),(c4),(-N+5),(N-5),(0));
				 	 	for(c7=N-4;c7 <= N-1;c7+=1)
				 	 	 {
				 	 	 	S11((1),(c2),(M),(c4),(-N+5),(N-5),(c7));
				 	 	 	S12((1),(c2),(M),(c4),(-N+5),(N-5),(c7));
				 	 	 }
				 	 	for(c6=N-4;c6 <= N-2;c6+=1)
				 	 	 {
				 	 	 	S6((1),(c2),(M),(c4),(-N+5),(c6),(0));
				 	 	 	for(c7=c6+1;c7 <= N-1;c7+=1)
				 	 	 	 {
				 	 	 	 	S11((1),(c2),(M),(c4),(-N+5),(c6),(c7));
				 	 	 	 	S12((1),(c2),(M),(c4),(-N+5),(c6),(c7));
				 	 	 	 }
				 	 	 }
				 	 	S5((1),(c2),(M),(c4),(-N+5),(N-1),(0));
				 	 	for(c5=-N+6;c5 <= 0;c5+=1)
				 	 	 {
				 	 	 	for(c7=-c5+1;c7 <= N-1;c7+=1)
				 	 	 	 {
				 	 	 	 	S13((1),(c2),(M),(c4),(c5),(-c5-1),(c7));
				 	 	 	 	S14((1),(c2),(M),(c4),(c5),(-c5-1),(c7));
				 	 	 	 }
				 	 	 	S7((1),(c2),(M),(c4),(c5),(-c5),(0));
				 	 	 	for(c7=-c5+1;c7 <= N-1;c7+=1)
				 	 	 	 {
				 	 	 	 	S11((1),(c2),(M),(c4),(c5),(-c5),(c7));
				 	 	 	 	S12((1),(c2),(M),(c4),(c5),(-c5),(c7));
				 	 	 	 }
				 	 	 	for(c6=-c5+1;c6 <= -c5+3;c6+=1)
				 	 	 	 {
				 	 	 	 	S6((1),(c2),(M),(c4),(c5),(c6),(0));
				 	 	 	 	for(c7=c6+1;c7 <= N-1;c7+=1)
				 	 	 	 	 {
				 	 	 	 	 	S11((1),(c2),(M),(c4),(c5),(c6),(c7));
				 	 	 	 	 	S12((1),(c2),(M),(c4),(c5),(c6),(c7));
				 	 	 	 	 }
				 	 	 	 }
				 	 	 	for(c6=-c5+4;c6 <= N-2;c6+=1)
				 	 	 	 {
				 	 	 	 	S5((1),(c2),(M),(c4),(c5),(c6),(0));
				 	 	 	 	for(c7=c6+1;c7 <= N-1;c7+=1)
				 	 	 	 	 {
				 	 	 	 	 	S11((1),(c2),(M),(c4),(c5),(c6),(c7));
				 	 	 	 	 	S12((1),(c2),(M),(c4),(c5),(c6),(c7));
				 	 	 	 	 }
				 	 	 	 }
				 	 	 	S5((1),(c2),(M),(c4),(c5),(N-1),(0));
				 	 	 }
				 	 }
				 }
			}
		}
		if ((N == 5)) {
			{
				for(c2=4;c2 <= M-1;c2+=1)
				 {
				 	for(c3=c2;c3 <= M-1;c3+=1)
				 	 {
				 	 	S15((1),(c2),(c3),(c3-4),(0),(0),(0));
				 	 }
				 	#pragma omp parallel for private(c5,c6,c7)
				 	for(c4=0;c4 <= -c2+M-1;c4+=1)
				 	 {
				 	 	S7((1),(c2),(M),(c4),(-4),(4),(0));
				 	 	S13((1),(c2),(M),(c4),(-3),(2),(4));
				 	 	S14((1),(c2),(M),(c4),(-3),(2),(4));
				 	 	S7((1),(c2),(M),(c4),(-3),(3),(0));
				 	 	S11((1),(c2),(M),(c4),(-3),(3),(4));
				 	 	S12((1),(c2),(M),(c4),(-3),(3),(4));
				 	 	S6((1),(c2),(M),(c4),(-3),(4),(0));
				 	 	for(c5=-2;c5 <= -1;c5+=1)
				 	 	 {
				 	 	 	for(c7=-c5+1;c7 <= 4;c7+=1)
				 	 	 	 {
				 	 	 	 	S13((1),(c2),(M),(c4),(c5),(-c5-1),(c7));
				 	 	 	 	S14((1),(c2),(M),(c4),(c5),(-c5-1),(c7));
				 	 	 	 }
				 	 	 	S7((1),(c2),(M),(c4),(c5),(-c5),(0));
				 	 	 	for(c7=-c5+1;c7 <= 4;c7+=1)
				 	 	 	 {
				 	 	 	 	S11((1),(c2),(M),(c4),(c5),(-c5),(c7));
				 	 	 	 	S12((1),(c2),(M),(c4),(c5),(-c5),(c7));
				 	 	 	 }
				 	 	 	for(c6=-c5+1;c6 <= 3;c6+=1)
				 	 	 	 {
				 	 	 	 	S6((1),(c2),(M),(c4),(c5),(c6),(0));
				 	 	 	 	for(c7=c6+1;c7 <= 4;c7+=1)
				 	 	 	 	 {
				 	 	 	 	 	S11((1),(c2),(M),(c4),(c5),(c6),(c7));
				 	 	 	 	 	S12((1),(c2),(M),(c4),(c5),(c6),(c7));
				 	 	 	 	 }
				 	 	 	 }
				 	 	 	S6((1),(c2),(M),(c4),(c5),(4),(0));
				 	 	 }
				 	 	for(c7=1;c7 <= 4;c7+=1)
				 	 	 {
				 	 	 	S13((1),(c2),(M),(c4),(0),(-1),(c7));
				 	 	 	S14((1),(c2),(M),(c4),(0),(-1),(c7));
				 	 	 }
				 	 	S7((1),(c2),(M),(c4),(0),(0),(0));
				 	 	for(c7=1;c7 <= 4;c7+=1)
				 	 	 {
				 	 	 	S11((1),(c2),(M),(c4),(0),(0),(c7));
				 	 	 	S12((1),(c2),(M),(c4),(0),(0),(c7));
				 	 	 }
				 	 	for(c6=1;c6 <= 3;c6+=1)
				 	 	 {
				 	 	 	S6((1),(c2),(M),(c4),(0),(c6),(0));
				 	 	 	for(c7=c6+1;c7 <= 4;c7+=1)
				 	 	 	 {
				 	 	 	 	S11((1),(c2),(M),(c4),(0),(c6),(c7));
				 	 	 	 	S12((1),(c2),(M),(c4),(0),(c6),(c7));
				 	 	 	 }
				 	 	 }
				 	 	S5((1),(c2),(M),(c4),(0),(4),(0));
				 	 }
				 }
			}
		}
		if ((N <= 4)) {
			{
				for(c2=4;c2 <= M-1;c2+=1)
				 {
				 	for(c3=c2;c3 <= M-1;c3+=1)
				 	 {
				 	 	S15((1),(c2),(c3),(c3-4),(0),(0),(0));
				 	 }
				 	#pragma omp parallel for private(c5,c6,c7)
				 	for(c4=0;c4 <= -c2+M-1;c4+=1)
				 	 {
				 	 	S7((1),(c2),(M),(c4),(-N+1),(N-1),(0));
				 	 	S13((1),(c2),(M),(c4),(-N+2),(N-3),(N-1));
				 	 	S14((1),(c2),(M),(c4),(-N+2),(N-3),(N-1));
				 	 	S7((1),(c2),(M),(c4),(-N+2),(N-2),(0));
				 	 	S11((1),(c2),(M),(c4),(-N+2),(N-2),(N-1));
				 	 	S12((1),(c2),(M),(c4),(-N+2),(N-2),(N-1));
				 	 	S6((1),(c2),(M),(c4),(-N+2),(N-1),(0));
				 	 	for(c5=-N+3;c5 <= 0;c5+=1)
				 	 	 {
				 	 	 	for(c7=-c5+1;c7 <= N-1;c7+=1)
				 	 	 	 {
				 	 	 	 	S13((1),(c2),(M),(c4),(c5),(-c5-1),(c7));
				 	 	 	 	S14((1),(c2),(M),(c4),(c5),(-c5-1),(c7));
				 	 	 	 }
				 	 	 	S7((1),(c2),(M),(c4),(c5),(-c5),(0));
				 	 	 	for(c7=-c5+1;c7 <= N-1;c7+=1)
				 	 	 	 {
				 	 	 	 	S11((1),(c2),(M),(c4),(c5),(-c5),(c7));
				 	 	 	 	S12((1),(c2),(M),(c4),(c5),(-c5),(c7));
				 	 	 	 }
				 	 	 	for(c6=-c5+1;c6 <= N-2;c6+=1)
				 	 	 	 {
				 	 	 	 	S6((1),(c2),(M),(c4),(c5),(c6),(0));
				 	 	 	 	for(c7=c6+1;c7 <= N-1;c7+=1)
				 	 	 	 	 {
				 	 	 	 	 	S11((1),(c2),(M),(c4),(c5),(c6),(c7));
				 	 	 	 	 	S12((1),(c2),(M),(c4),(c5),(c6),(c7));
				 	 	 	 	 }
				 	 	 	 }
				 	 	 	S6((1),(c2),(M),(c4),(c5),(N-1),(0));
				 	 	 }
				 	 }
				 }
			}
		}
	}
	#undef S0
	#undef S_1
	#undef S_2
	#undef S3
	#undef S4
	#undef S5
	#undef S6
	#undef S7
	#undef S8
	#undef S9
	#undef S10
	#undef S13
	#undef S14
	#undef S15
	#undef S11
	#undef S12
	
	//Memory Free
	free(_lin_S1);
	free(S1);
	
	free(_lin_S2);
	free(S2);
	
	free(_lin_FTable_outer_k1_k2);
	for (mz1=0;mz1 < M; mz1++) {
		for (mz2=0;mz2 < M; mz2++) {
			free(FTable_outer_k1_k2[mz1][mz2]);
		}
		free(FTable_outer_k1_k2[mz1]);
	}
	free(FTable_outer_k1_k2);
	
	free(_lin_NR_FTable);
	for (mz1=0;mz1 < M; mz1++) {
		for (mz2=0;mz2 < M; mz2++) {
			free(NR_FTable[mz1][mz2]);
		}
		free(NR_FTable[mz1]);
	}
	free(NR_FTable);
	
	free(_lin_NR_FTable_1);
	for (mz1=0;mz1 < M; mz1++) {
		for (mz2=0;mz2 < M; mz2++) {
			free(NR_FTable_1[mz1][mz2]);
		}
		free(NR_FTable_1[mz1]);
	}
	free(NR_FTable_1);
}
double reduce_bpmax_S1_1(long M, long N, long T1, long T2, long T3, int ip, int jp, double** S1){
	double reduceVar = 0;
	#define S_2(i,j,k) reduceVar = (reduceVar)+((S1(i,k))+(S1(k+1,j)))
	{
		//Domain
		//{i,j,k|M>=3 && N>=3 && T1>=1 && T2>=1 && T3>=1 && M>=jp+1 && ip>=0 && jp>=ip+4 && jp>=0 && M>=ip+1 && j>=i+4 && j>=0 && M>=i+1 && k>=-1 && M>=j+1 && j>=k+1 && i>=0 && k>=i && M>=k+1 && ip==i && jp==j}
		int c3;
		for(c3=ip;c3 <= jp-1;c3+=1)
		 {
		 	S_2((ip),(jp),(c3));
		 }
	}
	#undef S_2
	return reduceVar;
}
double reduce_bpmax_S2_1(long M, long N, long T1, long T2, long T3, int ip, int jp, double** S2){
	double reduceVar = 0;
	#define S4(i,j,k) reduceVar = (reduceVar)+((S2(i,k))+(S2(k+1,j)))
	{
		//Domain
		//{i,j,k|M>=3 && N>=3 && T1>=1 && T2>=1 && T3>=1 && N>=jp+1 && ip>=0 && jp>=ip+4 && N>=ip+1 && jp>=0 && j>=i+4 && N>=i+1 && j>=0 && k>=-1 && N>=j+1 && j>=k+1 && i>=0 && k>=i && N>=k+1 && ip==i && jp==j}
		int c3;
		for(c3=ip;c3 <= jp-1;c3+=1)
		 {
		 	S4((ip),(jp),(c3));
		 }
	}
	#undef S4
	return reduceVar;
}

//Memory Macros
#undef seq1
#undef seq2
#undef S1
#undef S2
#undef FTable_outer_k1_k2
#undef NR_FTable
#undef NR_FTable_1
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
