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
void bpmax_max_r0_r3_r4_instance(long, long, long, long, long, long, long, float**, float******, float****);


//Memory Macros
#define S1(i,j) S1[i][j]
#define FTable_6D(i1,j1,i2,j2,i3,j3) FTable_6D[i1][j1][i2][j2][i3][j3]
#define FTable_4D_dummy(k,i2,j2,i3,j3) FTable_4D_dummy[k][i2][j2][i3][j3]
#define FTable_4D(i2,j2,i3,j3) FTable_4D[i2][j2][i3][j3]

void bpmax_outer_reductions(long M, long N, long N_sec, long N_tile, long I1, long J1, long i3_offset, long j3_offset, float** S1, float****** FTable_6D, float**** FTable_4D){
	///Parameter checking
	if (!((M >= 16 && N >= 96 && N_sec >= 1 && N_tile >= 96 && I1 >= 0 && J1 >= I1 && M >= J1+1))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	//Memory Allocation
	int mz1, mz2, mz3, mz4, mz5;
	
	float* _lin_FTable_4D_dummy = (float*)malloc(sizeof(float)*((J1) * (N_sec) * (N_sec) * (N_tile+1) * (N_tile)));
	mallocCheck(_lin_FTable_4D_dummy, ((J1) * (N_sec) * (N_sec) * (N_tile+1) * (N_tile)), float);
	float***** FTable_4D_dummy = (float*****)malloc(sizeof(float****)*(J1));
	mallocCheck(FTable_4D_dummy, (J1), float****);
	for (mz1=0;mz1 < J1; mz1++) {
		FTable_4D_dummy[mz1] = (float****)malloc(sizeof(float***)*(N_sec));
		mallocCheck(FTable_4D_dummy[mz1], (N_sec), float***);
		for (mz2=0;mz2 < N_sec; mz2++) {
			FTable_4D_dummy[mz1][mz2] = (float***)malloc(sizeof(float**)*(N_sec));
			mallocCheck(FTable_4D_dummy[mz1][mz2], (N_sec), float**);
			for (mz3=0;mz3 < N_sec; mz3++) {
				FTable_4D_dummy[mz1][mz2][mz3] = (float**)malloc(sizeof(float*)*(N_tile+1));
				mallocCheck(FTable_4D_dummy[mz1][mz2][mz3], (N_tile+1), float*);
				for (mz4=0;mz4 < N_tile+1; mz4++) {
					FTable_4D_dummy[mz1][mz2][mz3][mz4] = &_lin_FTable_4D_dummy[(mz1*((N_sec) * (N_sec) * (N_tile+1) * (N_tile))) + (mz2*((N_sec) * (N_tile+1) * (N_tile))) + (mz3*((N_tile+1) * (N_tile))) + (mz4*(N_tile))];
				}
			}
		}
	}
	#define S0(i2,j2,i3,j3) FTable_4D(i2,j2,i3,j3) = 0
	#define S_1(i,i1,i2,i3) bpmax_max_r0_r3_r4_instance(M,N,N_sec,N_tile,I1,J1,i1,S1,FTable_6D,FTable_4D_dummy[i1])
	{
		//Domain
		//{i2,j2,i3,j3|M>=16 && N>=96 && N_sec>=1 && N_tile>=96 && I1>=0 && J1>=I1 && M>=J1+1 && i2>=0 && j2>=i2 && N_sec>=j2+1 && i3>=0 && N_tile>=i3 && j3>=0 && N_tile>=j3+1}
		//{i,i1,i2,i3|i3==0 && i2==0 && i==-1 && i1>=I1 && J1>=i1+1 && M>=16 && N>=96 && N_sec>=1 && N_tile>=96 && I1>=0 && J1>=I1 && M>=J1+1}
		int c1,c2,c3,c4;
		if ((I1 <= J1-1)) {
			{
				for(c2=I1;c2 <= J1-1;c2+=1)
				 {
				 	S_1((-1),(c2),(0),(0));
				 }
			}
		}
		for(c1=0;c1 <= N_sec-1;c1+=1)
		 {
		 	for(c2=c1;c2 <= N_sec-1;c2+=1)
		 	 {
		 	 	for(c3=0;c3 <= N_tile;c3+=1)
		 	 	 {
		 	 	 	for(c4=0;c4 <= N_tile-1;c4+=1)
		 	 	 	 {
		 	 	 	 	S0((c1),(c2),(c3),(c4));
		 	 	 	 }
		 	 	 }
		 	 }
		 }
	}
	#undef S0
	#undef S_1
	
	//Memory Free
	free(_lin_FTable_4D_dummy);
	for (mz1=0;mz1 < J1; mz1++) {
		for (mz2=0;mz2 < N_sec; mz2++) {
			for (mz3=0;mz3 < N_sec; mz3++) {
				free(FTable_4D_dummy[mz1][mz2][mz3]);
			}
			free(FTable_4D_dummy[mz1][mz2]);
		}
		free(FTable_4D_dummy[mz1]);
	}
	free(FTable_4D_dummy);
}

//Memory Macros
#undef S1
#undef FTable_6D
#undef FTable_4D_dummy
#undef FTable_4D


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
