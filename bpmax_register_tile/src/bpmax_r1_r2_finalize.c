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
#define seq2(i) seq2[i]
#define S2_A(i2,j2,i3,j3) S2_A[i2][j2][i3][j3]
#define S2_B(i2,j2,i3,j3) S2_B[i2][j2][i3][j3]
#define FTable_4D(i2,j2,i3,j3) FTable_4D[i2][j2][i3][j3]
#define NR_FTable_4D_section(i3,j3) NR_FTable_4D_section[i3][j3]
#define NR_FTable_4D_section_1(i3,j3) NR_FTable_4D_section_1[i3][j3]
#define FTable_4D_section(i2,j2) FTable_4D_section[i2][j2]

void bpmax_r1_r2_finalize(long M, long N, long N_sec, long N_tile, long MR, long NR, long I2, long J2, int* seq2, float**** S2_A, float**** S2_B, float**** FTable_4D, float** FTable_4D_section){
	///Parameter checking
	if (!((M >= 16 && N >= 96 && N_sec >= 1 && N_tile >= 96 && MR >= 1 && NR >= 1 && I2 >= 0 && J2 >= I2 && N_sec >= J2+1))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	//Memory Allocation
	int mz1, mz2;
	
	float* _lin_NR_FTable_4D_section = (float*)malloc(sizeof(float)*((N_tile-1) * (N_tile)));
	mallocCheck(_lin_NR_FTable_4D_section, ((N_tile-1) * (N_tile)), float);
	float** NR_FTable_4D_section = (float**)malloc(sizeof(float*)*(N_tile-1));
	mallocCheck(NR_FTable_4D_section, (N_tile-1), float*);
	for (mz1=0;mz1 < N_tile-1; mz1++) {
		NR_FTable_4D_section[mz1] = &_lin_NR_FTable_4D_section[(mz1*(N_tile))];
	}
	
	float* _lin_NR_FTable_4D_section_1 = (float*)malloc(sizeof(float)*((N_tile-1) * (N_tile)));
	mallocCheck(_lin_NR_FTable_4D_section_1, ((N_tile-1) * (N_tile)), float);
	float** NR_FTable_4D_section_1 = (float**)malloc(sizeof(float*)*(N_tile-1));
	mallocCheck(NR_FTable_4D_section_1, (N_tile-1), float*);
	for (mz1=0;mz1 < N_tile-1; mz1++) {
		NR_FTable_4D_section_1[mz1] = &_lin_NR_FTable_4D_section_1[(mz1*(N_tile))];
	}
	#define S0(i,j,i2) FTable_4D_section(-i,j) = FTable_4D_section(-i,j)
	#define S1(i,j,i2) FTable_4D_section(-i,j) = __max_float(FTable_4D_section(-i,j),__max_float(FTable_4D_section(-i+1,j-1),__max_float(NR_FTable_4D_section(-i,j),NR_FTable_4D_section_1(-i,j))))
	#define S2(i,j,i2) FTable_4D_section(-i,j) = __max_float(FTable_4D_section(-i,j),__max_float(0,__max_float(NR_FTable_4D_section(-i,j),NR_FTable_4D_section_1(-i,j))))
	#define S5(i,j,i2) NR_FTable_4D_section(-i,j) = 1.401298464324817E-45
	#define S6(i,j,i2) NR_FTable_4D_section_1(-i,j) = 1.401298464324817E-45
	#define S3(i0,i1,i2) {float __temp__ = (FTable_4D_section(-i0,i1))+(S2_A(I2,J2,i1+1,i2)); NR_FTable_4D_section(-i0,i2) = __max_float(NR_FTable_4D_section(-i0,i2),__temp__); }
	#define S4(i0,i1,i2) {float __temp__ = (S2_A(I2,J2,-i0,i1))+(FTable_4D_section(i1+1,i2)); NR_FTable_4D_section_1(-i0,i2) = __max_float(NR_FTable_4D_section_1(-i0,i2),__temp__); }
	{
		//Domain
		//{i,j,i2|i2==j+1 && M>=16 && N>=96 && N_sec>=1 && N_tile>=96 && MR>=1 && NR>=1 && I2>=0 && J2>=I2 && N_sec>=J2+1 && 0>=i+j && 0>=i && N_tile+i>=1 && j>=0 && N_tile>=j+1}
		//{i,j,i2|i2==j+1 && M>=16 && N>=96 && N_sec>=1 && N_tile>=96 && MR>=1 && NR>=1 && I2>=0 && J2>=I2 && N_sec>=J2+1 && i+j>=4 && 0>=i && N_tile+i>=2 && j>=1 && N_tile>=j+1}
		//{i,j,i2|i2==j+1 && M>=16 && N>=96 && N_sec>=1 && N_tile>=96 && MR>=1 && NR>=1 && I2>=0 && J2>=I2 && N_sec>=J2+1 && 0>=i+j-3 && i+j>=1 && 0>=i && N_tile+i>=1 && j>=0 && N_tile>=j+1}
		//{i,j,i2|i2==j && M>=16 && N>=96 && N_sec>=1 && N_tile>=96 && MR>=1 && NR>=1 && I2>=0 && J2>=I2 && N_sec>=J2+1 && 0>=i && i+j>=1 && N_tile>=j+1}
		//{i,j,i2|i2==j && M>=16 && N>=96 && N_sec>=1 && N_tile>=96 && MR>=1 && NR>=1 && I2>=0 && J2>=I2 && N_sec>=J2+1 && 0>=i && i+j>=1 && N_tile>=j+1}
		//{i0,i1,i2|i0+i1>=0 && i2>=i1+1 && M>=16 && N>=96 && N_sec>=1 && N_tile>=96 && MR>=1 && NR>=1 && I2>=0 && J2>=I2 && N_sec>=J2+1 && 0>=i0 && N_tile+i0>=1 && i1>=0 && N_tile>=i1+2 && i2>=0 && N_tile>=i2+1 && i0+i2>=1}
		//{i0,i1,i2|i0+i1>=0 && i2>=i1+1 && M>=16 && N>=96 && N_sec>=1 && N_tile>=96 && MR>=1 && NR>=1 && I2>=0 && J2>=I2 && N_sec>=J2+1 && i2>=0 && N_tile>=i2+1 && N_tile>=i1+2 && 0>=i0 && N_tile+i0>=1 && i1>=0 && i0+i2>=1}
		int c1,c2,c3;
		for(c2=0;c2 <= N_tile-1;c2+=1)
		 {
		 	S0((-N_tile+1),(c2),(c2+1));
		 }
		for(c2=0;c2 <= N_tile-2;c2+=1)
		 {
		 	S0((-N_tile+2),(c2),(c2+1));
		 }
		S3((-N_tile+2),(N_tile-2),(N_tile-1));
		S4((-N_tile+2),(N_tile-2),(N_tile-1));
		S5((-N_tile+2),(N_tile-1),(N_tile-1));
		S6((-N_tile+2),(N_tile-1),(N_tile-1));
		S2((-N_tile+2),(N_tile-1),(N_tile));
		for(c1=-N_tile+3;c1 <= -N_tile+4;c1+=1)
		 {
		 	for(c2=0;c2 <= -c1;c2+=1)
		 	 {
		 	 	S0((c1),(c2),(c2+1));
		 	 }
		 	for(c3=-c1+1;c3 <= N_tile-1;c3+=1)
		 	 {
		 	 	S3((c1),(-c1),(c3));
		 	 	S4((c1),(-c1),(c3));
		 	 }
		 	for(c2=-c1+1;c2 <= N_tile-2;c2+=1)
		 	 {
		 	 	S5((c1),(c2),(c2));
		 	 	S6((c1),(c2),(c2));
		 	 	S2((c1),(c2),(c2+1));
		 	 	for(c3=c2+1;c3 <= N_tile-1;c3+=1)
		 	 	 {
		 	 	 	S3((c1),(c2),(c3));
		 	 	 	S4((c1),(c2),(c3));
		 	 	 }
		 	 }
		 	S5((c1),(N_tile-1),(N_tile-1));
		 	S6((c1),(N_tile-1),(N_tile-1));
		 	S2((c1),(N_tile-1),(N_tile));
		 }
		for(c2=0;c2 <= N_tile-5;c2+=1)
		 {
		 	S0((-N_tile+5),(c2),(c2+1));
		 }
		for(c3=N_tile-4;c3 <= N_tile-1;c3+=1)
		 {
		 	S3((-N_tile+5),(N_tile-5),(c3));
		 	S4((-N_tile+5),(N_tile-5),(c3));
		 }
		for(c2=N_tile-4;c2 <= N_tile-2;c2+=1)
		 {
		 	S5((-N_tile+5),(c2),(c2));
		 	S6((-N_tile+5),(c2),(c2));
		 	S2((-N_tile+5),(c2),(c2+1));
		 	for(c3=c2+1;c3 <= N_tile-1;c3+=1)
		 	 {
		 	 	S3((-N_tile+5),(c2),(c3));
		 	 	S4((-N_tile+5),(c2),(c3));
		 	 }
		 }
		S5((-N_tile+5),(N_tile-1),(N_tile-1));
		S6((-N_tile+5),(N_tile-1),(N_tile-1));
		S1((-N_tile+5),(N_tile-1),(N_tile));
		for(c1=-N_tile+6;c1 <= 0;c1+=1)
		 {
		 	for(c2=0;c2 <= -c1;c2+=1)
		 	 {
		 	 	S0((c1),(c2),(c2+1));
		 	 }
		 	for(c3=-c1+1;c3 <= N_tile-1;c3+=1)
		 	 {
		 	 	S3((c1),(-c1),(c3));
		 	 	S4((c1),(-c1),(c3));
		 	 }
		 	for(c2=-c1+1;c2 <= -c1+3;c2+=1)
		 	 {
		 	 	S5((c1),(c2),(c2));
		 	 	S6((c1),(c2),(c2));
		 	 	S2((c1),(c2),(c2+1));
		 	 	for(c3=c2+1;c3 <= N_tile-1;c3+=1)
		 	 	 {
		 	 	 	S3((c1),(c2),(c3));
		 	 	 	S4((c1),(c2),(c3));
		 	 	 }
		 	 }
		 	for(c2=-c1+4;c2 <= N_tile-2;c2+=1)
		 	 {
		 	 	S5((c1),(c2),(c2));
		 	 	S6((c1),(c2),(c2));
		 	 	S1((c1),(c2),(c2+1));
		 	 	for(c3=c2+1;c3 <= N_tile-1;c3+=1)
		 	 	 {
		 	 	 	S3((c1),(c2),(c3));
		 	 	 	S4((c1),(c2),(c3));
		 	 	 }
		 	 }
		 	S5((c1),(N_tile-1),(N_tile-1));
		 	S6((c1),(N_tile-1),(N_tile-1));
		 	S1((c1),(N_tile-1),(N_tile));
		 }
	}
	#undef S0
	#undef S1
	#undef S2
	#undef S5
	#undef S6
	#undef S3
	#undef S4
	
	//Memory Free
	free(_lin_NR_FTable_4D_section);
	free(NR_FTable_4D_section);
	
	free(_lin_NR_FTable_4D_section_1);
	free(NR_FTable_4D_section_1);
}

//Memory Macros
#undef seq2
#undef S2_A
#undef S2_B
#undef FTable_4D
#undef NR_FTable_4D_section
#undef NR_FTable_4D_section_1
#undef FTable_4D_section


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
