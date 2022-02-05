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
#define NR_S_C_I2_J2(i3,j3) NR_S_C_I2_J2[i3][j3]
#define S_C_I2_J2(i2,j2) S_C_I2_J2[i2][j2]

void bpmax_single_strand_diagonal_tile(long M, long N, long N_sec, long N_tile, long MR, long NR, long I2, long J2, int** seq2_t, float** S_C_I2_J2){
	///Parameter checking
	if (!((M >= 3 && N >= 8 && N_sec >= 2 && N_tile >= 4 && MR >= 1 && NR >= 1 && I2 >= 0 && J2 >= I2 && N_sec >= J2+1))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	//Memory Allocation
	int mz1, mz2;
	
	float* _lin_NR_S_C_I2_J2 = (float*)malloc(sizeof(float)*((N_tile-4) * (N_tile)));
	mallocCheck(_lin_NR_S_C_I2_J2, ((N_tile-4) * (N_tile)), float);
	float** NR_S_C_I2_J2 = (float**)malloc(sizeof(float*)*(N_tile-4));
	mallocCheck(NR_S_C_I2_J2, (N_tile-4), float*);
	for (mz1=0;mz1 < N_tile-4; mz1++) {
		NR_S_C_I2_J2[mz1] = &_lin_NR_S_C_I2_J2[(mz1*(N_tile))];
	}
	#define S0(i,j,i2) S_C_I2_J2(-i,j) = 0
	#define S1(i,j,i2) S_C_I2_J2(-i,j) = __max_float((S_C_I2_J2(-i+1,j-1))+(e_intra_score(seq2_t(I2,-i),seq2_t(J2,j))),NR_S_C_I2_J2(-i,j))
	#define S3(i,j,i2) NR_S_C_I2_J2(-i,i2) = 1.401298464324817E-45
	#define S2(i0,i1,i2) {float __temp__ = (S_C_I2_J2(-i0,i1))+(S_C_I2_J2(i1+1,i2)); NR_S_C_I2_J2(-i0,i2) = __max_float(NR_S_C_I2_J2(-i0,i2),__temp__); }
	{
		//Domain
		//{i,j,i2|i2==j+1 && M>=3 && N>=8 && N_sec>=2 && N_tile>=4 && MR>=1 && NR>=1 && I2>=0 && J2>=I2 && N_sec>=J2+1 && 0>=i && N_tile+i>=0 && 0>=i+j-3 && j>=0 && N_tile>=j+1}
		//{i,j,i2|i2==j+1 && N_tile+i>=1 && i+j>=4 && M>=3 && N>=8 && N_sec>=2 && N_tile>=4 && MR>=1 && NR>=1 && I2>=0 && J2>=I2 && N_sec>=J2+1 && 0>=i && N_sec>=I2+1 && j>=1 && N_tile>=j+1 && J2>=0}
		//{i,j,i2|i+j==-1 && M>=3 && N>=8 && N_sec>=2 && N_tile>=4 && MR>=1 && NR>=1 && I2>=0 && J2>=I2 && N_sec>=J2+1 && N_tile>=i2+1 && i+i2>=4 && J2>=0 && i2>=1 && N_tile+i>=1 && N_sec>=I2+1 && 0>=i}
		//{i0,i1,i2|i0+i1>=0 && i2>=i1+1 && M>=3 && N>=8 && N_sec>=2 && N_tile>=4 && MR>=1 && NR>=1 && I2>=0 && J2>=I2 && N_sec>=J2+1 && 0>=i0 && N_tile+i0>=1 && i1>=0 && N_tile>=i1+1 && i2>=1 && N_tile>=i2+1 && N_sec>=I2+1 && i0+i2>=4 && J2>=0}
		int c1,c2,c3;
		for(c1=-N_tile;c1 <= -N_tile+4;c1+=1)
		 {
		 	for(c2=0;c2 <= N_tile-1;c2+=1)
		 	 {
		 	 	S0((c1),(c2),(c2+1));
		 	 }
		 }
		if ((N_tile >= 7)) {
			{
				for(c2=0;c2 <= N_tile-7;c2+=1)
				 {
				 	S0((-N_tile+5),(c2),(c2+1));
				 }
				S0((-N_tile+5),(N_tile-6),(N_tile-5));
				S3((-N_tile+5),(N_tile-6),(N_tile-1));
				for(c2=N_tile-5;c2 <= N_tile-2;c2+=1)
				 {
				 	S0((-N_tile+5),(c2),(c2+1));
				 	S2((-N_tile+5),(c2),(N_tile-1));
				 }
				S1((-N_tile+5),(N_tile-1),(N_tile));
			}
		}
		if ((N_tile == 5)) {
			{
				S3((0),(-1),(4));
				for(c2=0;c2 <= 3;c2+=1)
				 {
				 	S0((0),(c2),(c2+1));
				 	S2((0),(c2),(4));
				 }
				S1((0),(4),(5));
			}
		}
		if ((N_tile == 6)) {
			{
				S0((-1),(0),(1));
				S3((-1),(0),(5));
				for(c2=1;c2 <= 4;c2+=1)
				 {
				 	S0((-1),(c2),(c2+1));
				 	S2((-1),(c2),(5));
				 }
				S1((-1),(5),(6));
			}
		}
		for(c1=-N_tile+6;c1 <= -2;c1+=1)
		 {
		 	for(c2=0;c2 <= -c1-2;c2+=1)
		 	 {
		 	 	S0((c1),(c2),(c2+1));
		 	 }
		 	S0((c1),(-c1-1),(-c1));
		 	for(c3=-c1+4;c3 <= N_tile-1;c3+=1)
		 	 {
		 	 	S3((c1),(-c1-1),(c3));
		 	 }
		 	for(c2=-c1;c2 <= -c1+3;c2+=1)
		 	 {
		 	 	S0((c1),(c2),(c2+1));
		 	 	for(c3=-c1+4;c3 <= N_tile-1;c3+=1)
		 	 	 {
		 	 	 	S2((c1),(c2),(c3));
		 	 	 }
		 	 }
		 	for(c2=-c1+4;c2 <= N_tile-2;c2+=1)
		 	 {
		 	 	S1((c1),(c2),(c2+1));
		 	 	for(c3=c2+1;c3 <= N_tile-1;c3+=1)
		 	 	 {
		 	 	 	S2((c1),(c2),(c3));
		 	 	 }
		 	 }
		 	S1((c1),(N_tile-1),(N_tile));
		 }
		if ((N_tile >= 7)) {
			{
				S0((-1),(0),(1));
				for(c3=5;c3 <= N_tile-1;c3+=1)
				 {
				 	S3((-1),(0),(c3));
				 }
				for(c2=1;c2 <= 4;c2+=1)
				 {
				 	S0((-1),(c2),(c2+1));
				 	for(c3=5;c3 <= N_tile-1;c3+=1)
				 	 {
				 	 	S2((-1),(c2),(c3));
				 	 }
				 }
				for(c2=5;c2 <= N_tile-2;c2+=1)
				 {
				 	S1((-1),(c2),(c2+1));
				 	for(c3=c2+1;c3 <= N_tile-1;c3+=1)
				 	 {
				 	 	S2((-1),(c2),(c3));
				 	 }
				 }
				S1((-1),(N_tile-1),(N_tile));
			}
		}
		if ((N_tile >= 6)) {
			{
				for(c3=4;c3 <= N_tile-1;c3+=1)
				 {
				 	S3((0),(-1),(c3));
				 }
				for(c2=0;c2 <= 3;c2+=1)
				 {
				 	S0((0),(c2),(c2+1));
				 	for(c3=4;c3 <= N_tile-1;c3+=1)
				 	 {
				 	 	S2((0),(c2),(c3));
				 	 }
				 }
				for(c2=4;c2 <= N_tile-2;c2+=1)
				 {
				 	S1((0),(c2),(c2+1));
				 	for(c3=c2+1;c3 <= N_tile-1;c3+=1)
				 	 {
				 	 	S2((0),(c2),(c3));
				 	 }
				 }
				S1((0),(N_tile-1),(N_tile));
			}
		}
	}
	#undef S0
	#undef S1
	#undef S3
	#undef S2
        #if 0 
        printf ("I2:%d, J2:%d\n", I2, J2);
        for ( int i = 0; i < N_sec; ++i)
         {
            for ( int j = 0; j < N_tile;++j)
             printf ("%7.2f ", S_C_I2_J2[i][j]);
             printf ("\n");
         }
         #endif
	
	//Memory Free
	free(_lin_NR_S_C_I2_J2);
	free(NR_S_C_I2_J2);
}

//Memory Macros
#undef seq2_t
#undef NR_S_C_I2_J2
#undef S_C_I2_J2


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
