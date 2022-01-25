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
void transform_2D_to_4D(long, long, long, long, long, long, long, long, float**, float**);


//Memory Macros
#define seq1(i) seq1[i]
#define seq2(i) seq2[i]
#define S1(i,j) S1[i][j]
#define S2(i,j) S2[i][j]
#define FTable_4D(i1,j1,i2,j2) FTable_4D[i1][j1][i2][j2]
#define FTable_2D(i,j) FTable_2D[i][j]
#define FTable_C(i2,j2,i3,j3) FTable_C[i2][j2][i3][j3]

void bpmax_elementwise_ops(long M, long N, long N_sec, long N_tile, long MR, long NR, long I1, long J1, int* seq1, int* seq2, float** S1, float** S2, float**** FTable_4D, float**** FTable_C){
	///Parameter checking
	if (!((M >= 16 && N >= 96 && N_sec >= 1 && N_tile >= 96 && MR >= 1 && NR >= 1 && I1 >= 0 && J1 >= I1 && M >= J1+1))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	//Memory Allocation
	int mz1, mz2;
	
	float* _lin_FTable_2D = (float*)malloc(sizeof(float)*((N) * (N)));
	mallocCheck(_lin_FTable_2D, ((N) * (N)), float);
	float** FTable_2D = (float**)malloc(sizeof(float*)*(N));
	mallocCheck(FTable_2D, (N), float*);
	for (mz1=0;mz1 < N; mz1++) {
		FTable_2D[mz1] = &_lin_FTable_2D[(mz1*(N))];
	}
	#define S0(i,j,i2,i3) FTable_2D(j,i2) = e_inter_score(seq1(I1),seq2(-j+N-1))
	#define S_1(i,j,i2,i3) FTable_2D(j,i2) = __max_float((FTable_4D(I1+1,J1-1,j,i2))+(e_intra_score(seq1(I1),seq1(J1))),(S1(I1,J1))+(S2(j,i2)))
	#define S_2(i,j,i2,i3) FTable_2D(j,i2) = __max_float(0,(S1(I1,J1))+(S2(j,i2)))
	#define S3(i,j,i2,i3) transform_2D_to_4D(M,N,N_sec,N_tile,MR,NR,j,i2,FTable_2D,FTable_C[j][i2])
	{
		//Domain
		//{i,j,i2,i3|i3==0 && i2==j && i==0 && J1==I1 && M>=16 && N>=96 && N_sec>=1 && N_tile>=96 && MR>=1 && NR>=1 && I1>=0 && M>=I1+1 && j>=0 && N>=j+1}
		//{i,j,i2,i3|i3==0 && i==0 && M>=16 && N>=96 && N_sec>=1 && N_tile>=96 && MR>=1 && NR>=1 && I1>=0 && J1>=I1+4 && M>=J1+1 && i2>=j && J1+i2>=I1+j+1 && M>=I1+1 && J1>=0 && N>=i2+1 && j>=0}
		//{i,j,i2,i3|i3==0 && i==0 && M>=16 && N>=96 && N_sec>=1 && N_tile>=96 && MR>=1 && NR>=1 && I1>=0 && J1>=I1 && M>=J1+1 && I1>=J1-3 && i2>=j && J1+i2>=I1+j+1 && j>=0 && N>=i2+1}
		//{i,j,i2,i3|i3==0 && i==1 && j>=0 && i2>=j && N_sec>=i2+1 && M>=16 && N>=96 && N_sec>=1 && N_tile>=96 && MR>=1 && NR>=1 && I1>=0 && J1>=I1 && M>=J1+1}
		int c2,c3;
		if ((I1 <= J1-4)) {
			{
				for(c2=0;c2 <= N-1;c2+=1)
				 {
				 	for(c3=c2;c3 <= N-1;c3+=1)
				 	 {
				 	 	S_1((0),(c2),(c3),(0));
				 	 }
				 }
			}
		}
		if ((I1 == J1)) {
			{
				for(c2=0;c2 <= N-2;c2+=1)
				 {
				 	S0((0),(c2),(c2),(0));
				 	for(c3=c2+1;c3 <= N-1;c3+=1)
				 	 {
				 	 	S_2((0),(c2),(c3),(0));
				 	 }
				 }
			}
		}
		if ((I1 >= J1-3 && I1 <= J1-1)) {
			{
				for(c2=0;c2 <= N-1;c2+=1)
				 {
				 	for(c3=c2;c3 <= N-1;c3+=1)
				 	 {
				 	 	S_2((0),(c2),(c3),(0));
				 	 }
				 }
			}
		}
		if ((I1 == J1)) {
			{
				S0((0),(N-1),(N-1),(0));
			}
		}
		for(c2=0;c2 <= N_sec-1;c2+=1)
		 {
		 	for(c3=c2;c3 <= N_sec-1;c3+=1)
		 	 {
		 	 	S3((1),(c2),(c3),(0));
		 	 }
		 }
	}
	#undef S0
	#undef S_1
	#undef S_2
	#undef S3
	
	//Memory Free
	free(_lin_FTable_2D);
	free(FTable_2D);
}

//Memory Macros
#undef seq1
#undef seq2
#undef S1
#undef S2
#undef FTable_4D
#undef FTable_2D
#undef FTable_C


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
