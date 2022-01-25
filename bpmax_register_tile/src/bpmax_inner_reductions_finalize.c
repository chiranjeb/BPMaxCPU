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






//Memory Macros
#define seq2_t(i,j) seq2_t[i][j]
#define A(i2,j2,i3,j3) A[i2][j2][i3][j3]
#define B(i2,j2,i3,j3) B[i2][j2][i3][j3]
#define C(i2,j2,i3,j3) C[i2][j2][i3][j3]
#define FTable_C_section(i2,j2) FTable_C_section[i2][j2]
#define NR_FTable1(i2) NR_FTable1[i2]
#define NR_FTable2(i2) NR_FTable2[i2]

void bpmax_inner_reductions_finalize(long M, long N, long N_sec, long N_tile, long MR, long NR, long I2, long J2, int** seq2_t, float**** A, float**** B, float**** C, float** FTable_C_section){
	///Parameter checking
	if (!((M >= 16 && N >= 96 && N_sec >= 1 && N_tile >= 96 && MR >= 1 && NR >= 1 && I2 >= 0 && J2 >= I2+1 && N_sec >= J2+1))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	//Memory Allocation
	int mz1;
	
	float* NR_FTable1 = (float*)malloc(sizeof(float)*(N_tile));
	mallocCheck(NR_FTable1, (N_tile), float);
	
	float* NR_FTable2 = (float*)malloc(sizeof(float)*(N_tile));
	mallocCheck(NR_FTable2, (N_tile), float);
	#define S0(i,j,i2,i3) FTable_C_section(-i,i2) = C(I2+1,J2,-i,i2)
	#define S1(i,j,i2,i3) FTable_C_section(-i,i2) = __max_float(0,FTable_C_section(-i,i2))
	#define S2(i,j,i2,i3) FTable_C_section(-i,i2) = __max_float((C(I2,J2-1,-i,N_tile-1))+(e_intra_score(seq2_t(I2,-i),seq2_t(J2,i2))),FTable_C_section(-i,i2))
	#define S3(i,j,i2,i3) FTable_C_section(-i,i2) = __max_float((C(I2,J2,-i+1,i2-1))+(e_intra_score(seq2_t(I2,-i),seq2_t(J2,i2))),FTable_C_section(-i,i2))
	#define S4(i,j,i2,i3) FTable_C_section(-i,i2) = 0
	#define S5(i,j,i2,i3) FTable_C_section(-i,i2) = __max_float(FTable_C_section(-i,i2),__max_float(NR_FTable1(i2),NR_FTable2(i2)))
	#define S6(i,j,i2,i3) FTable_C_section(-i,i2) = __max_float(FTable_C_section(-i,i2),__max_float(NR_FTable1(i2),0))
	#define S9(i,j,i2,i3) NR_FTable1(i3) = 1.401298464324817E-45
	#define S10(i,j,i2,i3) NR_FTable2(i3) = 3.4028234663852886E38
	#define S7(i0,i1,i2,i3) {float __temp__ = (A(I2,J2,-i0,i2))+(C(I2,J2,i2+1,i3)); NR_FTable1(i3) = __max_float(NR_FTable1(i3),__temp__); }
	#define S8(i0,i1,i2,i3) {float __temp__ = (C(I2,J2,-i0,i2))+(B(I2,J2,i2+1,i3)); NR_FTable2(i3) = __min_float(NR_FTable2(i3),__temp__); }
	{
		//Domain
		//{i,j,i2,i3|i3==i2 && j==0 && N_tile+i==0 && M>=16 && N>=96 && N_sec>=1 && N_tile>=96 && MR>=1 && NR>=1 && I2>=0 && J2>=I2+1 && N_sec>=J2+1 && N_tile>=i2+1 && i2>=0}
		//{i,j,i2,i3|i3==i2 && j==0 && J2==I2+1 && 0>=N_tile+i+i2-3 && M>=16 && N>=96 && N_sec>=1 && N_tile>=96 && MR>=1 && NR>=1 && I2>=0 && N_sec>=I2+2 && N_tile+i>=1 && N_tile>=i2+1 && i2>=0 && 0>=i}
		//{i,j,i2,i3|i3==0 && i2==0 && j==0 && J2==I2+1 && M>=16 && N>=96 && N_tile>=96 && MR>=1 && NR>=1 && I2>=0 && N_sec>=I2+2 && 0>=i && N_tile+i>=4} || {i,j,i2,i3|i3==0 && i2==0 && j==0 && M>=16 && N>=96 && N_tile>=96 && MR>=1 && NR>=1 && I2>=0 && J2>=I2+2 && N_sec>=J2+1 && 0>=i && N_tile+i>=1}
		//{i,j,i2,i3|i3==i2 && j==0 && J2==I2+1 && M>=16 && N>=96 && N_tile>=96 && MR>=1 && NR>=1 && I2>=0 && N_sec>=I2+2 && 0>=i && N_tile+i>=1 && i2>=1 && N_tile>=i2+1 && N_tile+i+i2>=4} || {i,j,i2,i3|i3==i2 && j==0 && M>=16 && N>=96 && N_tile>=96 && MR>=1 && NR>=1 && I2>=0 && J2>=I2+2 && N_sec>=J2+1 && 0>=i && N_tile+i>=1 && i2>=1 && N_tile>=i2+1}
		//{i,j,i2,i3|i3==i2+1 && j==2 && N_tile+i==0 && M>=16 && N>=96 && N_sec>=1 && N_tile>=96 && MR>=1 && NR>=1 && I2>=0 && J2>=I2+1 && N_sec>=J2+1 && N_tile>=i2+1 && i2>=0}
		//{i,j,i2,i3|i3==i2+1 && j==2 && M>=16 && N>=96 && N_sec>=1 && N_tile>=96 && MR>=1 && NR>=1 && I2>=0 && J2>=I2+1 && N_sec>=J2+1 && i2>=1 && N_tile+i>=1 && 0>=i && N_tile>=i2+1}
		//{i,j,i2,i3|i3==1 && i2==0 && j==2 && M>=16 && N>=96 && N_sec>=1 && N_tile>=96 && MR>=1 && NR>=1 && I2>=0 && J2>=I2+1 && N_sec>=J2+1 && N_tile+i>=1 && 0>=i}
		//{i,j,i2,i3|i2==-1 && j==1 && M>=16 && N>=96 && N_sec>=1 && N_tile>=96 && MR>=1 && NR>=1 && I2>=0 && J2>=I2+1 && N_sec>=J2+1 && N_tile+i>=1 && 0>=i && i3>=0 && N_tile>=i3+1}
		//{i,j,i2,i3|i2==-1 && j==2 && M>=16 && N>=96 && N_sec>=1 && N_tile>=96 && MR>=1 && NR>=1 && I2>=0 && J2>=I2+1 && N_sec>=J2+1 && N_tile+i>=1 && i3>=1 && 0>=i && N_tile>=i3+1}
		//{i0,i1,i2,i3|i1==1 && i0+i2>=0 && N_tile>=i2+1 && M>=16 && N>=96 && N_sec>=1 && N_tile>=96 && MR>=1 && NR>=1 && I2>=0 && J2>=I2+1 && N_sec>=J2+1 && i3>=0 && N_tile>=i3+1 && i2>=0 && 0>=i0 && N_tile+i0>=1}
		//{i0,i1,i2,i3|i1==2 && i2>=0 && i3>=i2+1 && M>=16 && N>=96 && N_sec>=1 && N_tile>=96 && MR>=1 && NR>=1 && I2>=0 && J2>=I2+1 && N_sec>=J2+1 && i3>=1 && N_tile>=i3+1 && N_tile>=i2+2 && 0>=i0 && N_tile+i0>=1}
		int c1,c3,c4;
		for(c3=0;c3 <= N_tile-1;c3+=1)
		 {
		 	S0((-N_tile),(0),(c3),(c3));
		 }
		for(c3=0;c3 <= N_tile-1;c3+=1)
		 {
		 	S4((-N_tile),(2),(c3),(c3+1));
		 }
		if ((I2 <= J2-2)) {
			{
				for(c1=-N_tile+1;c1 <= 0;c1+=1)
				 {
				 	S2((c1),(0),(0),(0));
				 	for(c3=1;c3 <= N_tile-1;c3+=1)
				 	 {
				 	 	S3((c1),(0),(c3),(c3));
				 	 }
				 	for(c4=0;c4 <= N_tile-1;c4+=1)
				 	 {
				 	 	S9((c1),(1),(-1),(c4));
				 	 }
				 	for(c3=-c1;c3 <= N_tile-1;c3+=1)
				 	 {
				 	 	for(c4=0;c4 <= N_tile-1;c4+=1)
				 	 	 {
				 	 	 	S7((c1),(1),(c3),(c4));
				 	 	 }
				 	 }
				 	for(c4=1;c4 <= N_tile-1;c4+=1)
				 	 {
				 	 	S10((c1),(2),(-1),(c4));
				 	 }
				 	S6((c1),(2),(0),(1));
				 	for(c4=1;c4 <= N_tile-1;c4+=1)
				 	 {
				 	 	S8((c1),(2),(0),(c4));
				 	 }
				 	for(c3=1;c3 <= N_tile-2;c3+=1)
				 	 {
				 	 	S5((c1),(2),(c3),(c3+1));
				 	 	for(c4=c3+1;c4 <= N_tile-1;c4+=1)
				 	 	 {
				 	 	 	S8((c1),(2),(c3),(c4));
				 	 	 }
				 	 }
				 	S5((c1),(2),(N_tile-1),(N_tile));
				 }
			}
		}
		if ((I2 == J2-1)) {
			{
				for(c1=-N_tile+1;c1 <= -N_tile+3;c1+=1)
				 {
				 	for(c3=0;c3 <= -c1-N_tile+3;c3+=1)
				 	 {
				 	 	S1((c1),(0),(c3),(c3));
				 	 }
				 	for(c3=-c1-N_tile+4;c3 <= N_tile-1;c3+=1)
				 	 {
				 	 	S3((c1),(0),(c3),(c3));
				 	 }
				 	for(c4=0;c4 <= N_tile-1;c4+=1)
				 	 {
				 	 	S9((c1),(1),(-1),(c4));
				 	 }
				 	for(c3=-c1;c3 <= N_tile-1;c3+=1)
				 	 {
				 	 	for(c4=0;c4 <= N_tile-1;c4+=1)
				 	 	 {
				 	 	 	S7((c1),(1),(c3),(c4));
				 	 	 }
				 	 }
				 	for(c4=1;c4 <= N_tile-1;c4+=1)
				 	 {
				 	 	S10((c1),(2),(-1),(c4));
				 	 }
				 	S6((c1),(2),(0),(1));
				 	for(c4=1;c4 <= N_tile-1;c4+=1)
				 	 {
				 	 	S8((c1),(2),(0),(c4));
				 	 }
				 	for(c3=1;c3 <= N_tile-2;c3+=1)
				 	 {
				 	 	S5((c1),(2),(c3),(c3+1));
				 	 	for(c4=c3+1;c4 <= N_tile-1;c4+=1)
				 	 	 {
				 	 	 	S8((c1),(2),(c3),(c4));
				 	 	 }
				 	 }
				 	S5((c1),(2),(N_tile-1),(N_tile));
				 }
			}
		}
		if ((I2 == J2-1)) {
			{
				for(c1=-N_tile+4;c1 <= 0;c1+=1)
				 {
				 	S2((c1),(0),(0),(0));
				 	for(c3=1;c3 <= N_tile-1;c3+=1)
				 	 {
				 	 	S3((c1),(0),(c3),(c3));
				 	 }
				 	for(c4=0;c4 <= N_tile-1;c4+=1)
				 	 {
				 	 	S9((c1),(1),(-1),(c4));
				 	 }
				 	for(c3=-c1;c3 <= N_tile-1;c3+=1)
				 	 {
				 	 	for(c4=0;c4 <= N_tile-1;c4+=1)
				 	 	 {
				 	 	 	S7((c1),(1),(c3),(c4));
				 	 	 }
				 	 }
				 	for(c4=1;c4 <= N_tile-1;c4+=1)
				 	 {
				 	 	S10((c1),(2),(-1),(c4));
				 	 }
				 	S6((c1),(2),(0),(1));
				 	for(c4=1;c4 <= N_tile-1;c4+=1)
				 	 {
				 	 	S8((c1),(2),(0),(c4));
				 	 }
				 	for(c3=1;c3 <= N_tile-2;c3+=1)
				 	 {
				 	 	S5((c1),(2),(c3),(c3+1));
				 	 	for(c4=c3+1;c4 <= N_tile-1;c4+=1)
				 	 	 {
				 	 	 	S8((c1),(2),(c3),(c4));
				 	 	 }
				 	 }
				 	S5((c1),(2),(N_tile-1),(N_tile));
				 }
			}
		}
	}
	#undef S0
	#undef S1
	#undef S2
	#undef S3
	#undef S4
	#undef S5
	#undef S6
	#undef S9
	#undef S10
	#undef S7
	#undef S8
	
	//Memory Free
	free(NR_FTable1);
	free(NR_FTable2);
}

//Memory Macros
#undef seq2_t
#undef A
#undef B
#undef C
#undef FTable_C_section
#undef NR_FTable1
#undef NR_FTable2


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
