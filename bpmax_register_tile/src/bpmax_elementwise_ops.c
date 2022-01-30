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
#define seq1(i) seq1[i]
#define seq2(i) seq2[i]
#define S1(i,j) S1[i][j]
#define S2(i,j) S2[i][j]
#define FTable(i1,j1,i2,j2) FTable[i1][j1][i2][j2]
#define FTable_C(i2,j2,i3,j3) FTable_C[i2][j2][i3][j3]

void bpmax_elementwise_ops(long M, long N, long N_sec, long N_tile, long MR, long NR, long I1, long J1, int* seq1, int* seq2, float** S1, float** S2, float**** FTable, float**** FTable_C){
	///Parameter checking
	if (!((M >= 16 && N >= 96 && N_sec >= 1 && N_tile >= 96 && MR >= 1 && NR >= 1 && I1 >= 0 && J1 >= I1 && M >= J1+1))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	//Memory Allocation
	
	#define S0(i2,j2,i3,j3) FTable_C(i2,j2,i3,j3) = 0
	{
		//Domain
		//{i2,j2,i3,j3|M>=16 && N>=96 && N_sec>=1 && N_tile>=96 && MR>=1 && NR>=1 && I1>=0 && J1>=I1 && M>=J1+1 && i2>=0 && j2>=i2 && N_sec>=j2+1 && i3>=0 && N_tile>=i3+1 && j3>=0 && N_tile>=j3+1}
		int c1,c2,c3,c4;
		for(c1=0;c1 <= N_sec-1;c1+=1)
		 {
		 	for(c2=c1;c2 <= N_sec-1;c2+=1)
		 	 {
		 	 	for(c3=0;c3 <= N_tile-1;c3+=1)
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
	
	//Memory Free
}

//Memory Macros
#undef seq1
#undef seq2
#undef S1
#undef S2
#undef FTable
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
