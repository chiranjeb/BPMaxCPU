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





//Local Function Declarations
float reduce_bpmax_single_strand_s1_S1_1(long, int, int, float**);

//Memory Macros
#define seq1(i) seq1[i]
#define S1(i,j) S1[i][j]

void bpmax_single_strand_s1(long M, int* seq1, float** S1){
	///Parameter checking
	if (!((M >= 3))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	//Memory Allocation
	
	#define S0(i,j) S1(i,j) = 0
	#define S_1(i,j) S1(i,j) = __max_float((S1(i+1,j-1))+(e_intra_score(seq1(i),seq1(j))),reduce_bpmax_single_strand_s1_S1_1(M,i,j,S1))
	{
		//Domain
		//{i,j|i>=j-3 && M>=3 && M>=j+1 && i>=0 && j>=i}
		//{i,j|j>=i+4 && M>=3 && i>=0 && M>=i+1 && M>=j+1 && j>=0}
		int c1,c2;
		for(c1=0;c1 <= M-5;c1+=1)
		 {
		 	for(c2=c1;c2 <= c1+3;c2+=1)
		 	 {
		 	 	S0((c1),(c2));
		 	 }
		 	for(c2=c1+4;c2 <= M-1;c2+=1)
		 	 {
		 	 	S_1((c1),(c2));
		 	 }
		 }
		for(c1=max(0,M-4);c1 <= M-1;c1+=1)
		 {
		 	for(c2=c1;c2 <= M-1;c2+=1)
		 	 {
		 	 	S0((c1),(c2));
		 	 }
		 }
	}
	#undef S0
	#undef S_1
	
	//Memory Free
}
float reduce_bpmax_single_strand_s1_S1_1(long M, int ip, int jp, float** S1){
	float reduceVar = 0;
	#define S2(i,j,k) reduceVar = (reduceVar)+((S1(i,k))+(S1(k+1,j)))
	{
		//Domain
		//{i,j,k|M>=jp+1 && M>=3 && ip>=0 && jp>=ip+4 && M>=ip+1 && jp>=0 && j>=k+1 && j>=i+4 && i>=0 && k>=i && M>=k+1 && M>=j+1 && k>=-1 && j>=0 && M>=i+1 && ip==i && jp==j}
		int c3;
		for(c3=ip;c3 <= jp-1;c3+=1)
		 {
		 	S2((ip),(jp),(c3));
		 }
	}
	#undef S2
	return reduceVar;
}

//Memory Macros
#undef seq1
#undef S1


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
