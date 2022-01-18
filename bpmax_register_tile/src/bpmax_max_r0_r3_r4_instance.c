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
void bpmax_r0_section(long, long, long, long, long, long, long, long, long, long, long, float****, float****, float**);
void bpmax_r3_section(long, long, long, long, long, long, long, long, long, float**, float**, float**);
void bpmax_r4_section(long, long, long, long, long, long, long, long, long, float**, float**, float**);


//Memory Macros
#define FTable_A(i2,j2,i3,j3) FTable_A[i2][j2][i3][j3]
#define FTable_B(i2,j2,i3,j3) FTable_B[i2][j2][i3][j3]
#define FTable_C(i2,j2,i3,j3) FTable_C[i2][j2][i3][j3]
#define S1(i,j) S1[i][j]
#define FTable_C_section_1(i2,j2,i3,j3) FTable_C_section_1[i2][j2][i3][j3]
#define FTable_C_section_2(i2,j2,i3,j3) FTable_C_section_2[i2][j2][i3][j3]
#define FTable_C_section_3(i2,j2,i3,j3) FTable_C_section_3[i2][j2][i3][j3]
#define FTable_4D(i2,j2,i3,j3) FTable_4D[i2][j2][i3][j3]

void bpmax_max_r0_r3_r4_instance(long M, long N, long N_sec, long N_tile, long MR, long NR, long I1, long J1, long K1, float**** FTable_A, float**** FTable_B, float**** FTable_C, float** S1, float**** FTable_4D){
	///Parameter checking
	if (!((M >= 16 && N >= 96 && N_sec >= 1 && N_tile >= 96 && MR >= 1 && NR >= 1 && I1 >= 0 && J1 >= I1 && M >= J1+1 && K1 >= I1 && J1 >= K1+1))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	//Memory Allocation
	int mz1, mz2, mz3, mz4;
	
	float* _lin_FTable_C_section_1 = (float*)malloc(sizeof(float)*((N_sec) * (N_sec) * (N_tile) * (N_tile)));
	mallocCheck(_lin_FTable_C_section_1, ((N_sec) * (N_sec) * (N_tile) * (N_tile)), float);
	float**** FTable_C_section_1 = (float****)malloc(sizeof(float***)*(N_sec));
	mallocCheck(FTable_C_section_1, (N_sec), float***);
	for (mz1=0;mz1 < N_sec; mz1++) {
		FTable_C_section_1[mz1] = (float***)malloc(sizeof(float**)*(N_sec));
		mallocCheck(FTable_C_section_1[mz1], (N_sec), float**);
		for (mz2=0;mz2 < N_sec; mz2++) {
			FTable_C_section_1[mz1][mz2] = (float**)malloc(sizeof(float*)*(N_tile));
			mallocCheck(FTable_C_section_1[mz1][mz2], (N_tile), float*);
			for (mz3=0;mz3 < N_tile; mz3++) {
				FTable_C_section_1[mz1][mz2][mz3] = &_lin_FTable_C_section_1[(mz1*((N_sec) * (N_tile) * (N_tile))) + (mz2*((N_tile) * (N_tile))) + (mz3*(N_tile))];
			}
		}
	}
	
	float* _lin_FTable_C_section_2 = (float*)malloc(sizeof(float)*((N_sec) * (N_sec) * (N_tile) * (N_tile)));
	mallocCheck(_lin_FTable_C_section_2, ((N_sec) * (N_sec) * (N_tile) * (N_tile)), float);
	float**** FTable_C_section_2 = (float****)malloc(sizeof(float***)*(N_sec));
	mallocCheck(FTable_C_section_2, (N_sec), float***);
	for (mz1=0;mz1 < N_sec; mz1++) {
		FTable_C_section_2[mz1] = (float***)malloc(sizeof(float**)*(N_sec));
		mallocCheck(FTable_C_section_2[mz1], (N_sec), float**);
		for (mz2=0;mz2 < N_sec; mz2++) {
			FTable_C_section_2[mz1][mz2] = (float**)malloc(sizeof(float*)*(N_tile));
			mallocCheck(FTable_C_section_2[mz1][mz2], (N_tile), float*);
			for (mz3=0;mz3 < N_tile; mz3++) {
				FTable_C_section_2[mz1][mz2][mz3] = &_lin_FTable_C_section_2[(mz1*((N_sec) * (N_tile) * (N_tile))) + (mz2*((N_tile) * (N_tile))) + (mz3*(N_tile))];
			}
		}
	}
	
	float* _lin_FTable_C_section_3 = (float*)malloc(sizeof(float)*((N_sec) * (N_sec) * (N_tile) * (N_tile)));
	mallocCheck(_lin_FTable_C_section_3, ((N_sec) * (N_sec) * (N_tile) * (N_tile)), float);
	float**** FTable_C_section_3 = (float****)malloc(sizeof(float***)*(N_sec));
	mallocCheck(FTable_C_section_3, (N_sec), float***);
	for (mz1=0;mz1 < N_sec; mz1++) {
		FTable_C_section_3[mz1] = (float***)malloc(sizeof(float**)*(N_sec));
		mallocCheck(FTable_C_section_3[mz1], (N_sec), float**);
		for (mz2=0;mz2 < N_sec; mz2++) {
			FTable_C_section_3[mz1][mz2] = (float**)malloc(sizeof(float*)*(N_tile));
			mallocCheck(FTable_C_section_3[mz1][mz2], (N_tile), float*);
			for (mz3=0;mz3 < N_tile; mz3++) {
				FTable_C_section_3[mz1][mz2][mz3] = &_lin_FTable_C_section_3[(mz1*((N_sec) * (N_tile) * (N_tile))) + (mz2*((N_tile) * (N_tile))) + (mz3*(N_tile))];
			}
		}
	}
	#define S0(i,j,i2) bpmax_r0_section(M,N,N_sec,N_tile,MR,NR,I1,J1,K1,i,j,FTable_A,FTable_B,FTable_C_section_1[i][j])
	#define S_1(i,j,i2) bpmax_r3_section(M,N,N_sec,N_tile,I1,J1,K1,i,j,S1,FTable_B[i][j],FTable_C_section_2[i][j])
	#define S2(i,j,i2) bpmax_r4_section(M,N,N_sec,N_tile,I1,J1,K1,i,j,FTable_A[i][j],S1,FTable_C_section_3[i][j])
	{
		//Domain
		//{i,j,i2|i2==2 && i>=0 && j>=i && N_sec>=j+1 && M>=16 && N>=96 && N_sec>=1 && N_tile>=96 && MR>=1 && NR>=1 && I1>=0 && J1>=I1 && M>=J1+1 && K1>=I1 && J1>=K1+1}
		//{i,j,i2|i2==0 && i>=0 && j>=i && N_sec>=j+1 && M>=16 && N>=96 && N_sec>=1 && N_tile>=96 && MR>=1 && NR>=1 && I1>=0 && J1>=I1 && M>=J1+1 && K1>=I1 && J1>=K1+1}
		//{i,j,i2|i2==1 && i>=0 && j>=i && N_sec>=j+1 && M>=16 && N>=96 && N_sec>=1 && N_tile>=96 && MR>=1 && NR>=1 && I1>=0 && J1>=I1 && M>=J1+1 && K1>=I1 && J1>=K1+1}
		int c1,c2;
		for(c1=0;c1 <= N_sec-1;c1+=1)
		 {
		 	for(c2=c1;c2 <= N_sec-1;c2+=1)
		 	 {
		 	 	S_1((c1),(c2),(0));
		 	 	S2((c1),(c2),(1));
		 	 	S0((c1),(c2),(2));
		 	 }
		 }
	}
	#undef S0
	#undef S_1
	#undef S2
	
	//Memory Free
	free(_lin_FTable_C_section_1);
	for (mz1=0;mz1 < N_sec; mz1++) {
		for (mz2=0;mz2 < N_sec; mz2++) {
			free(FTable_C_section_1[mz1][mz2]);
		}
		free(FTable_C_section_1[mz1]);
	}
	free(FTable_C_section_1);
	
	free(_lin_FTable_C_section_2);
	for (mz1=0;mz1 < N_sec; mz1++) {
		for (mz2=0;mz2 < N_sec; mz2++) {
			free(FTable_C_section_2[mz1][mz2]);
		}
		free(FTable_C_section_2[mz1]);
	}
	free(FTable_C_section_2);
	
	free(_lin_FTable_C_section_3);
	for (mz1=0;mz1 < N_sec; mz1++) {
		for (mz2=0;mz2 < N_sec; mz2++) {
			free(FTable_C_section_3[mz1][mz2]);
		}
		free(FTable_C_section_3[mz1]);
	}
	free(FTable_C_section_3);
}

//Memory Macros
#undef FTable_A
#undef FTable_B
#undef FTable_C
#undef S1
#undef FTable_C_section_1
#undef FTable_C_section_2
#undef FTable_C_section_3
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
