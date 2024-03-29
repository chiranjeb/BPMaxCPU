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






//Memory Macros
#define seq1(i) seq1[i]
#define seq2(i) seq2[i]
#define FTable(i1,j1,i2,j2) FTable[i1][j1][i2][j2]

void ospsqmax_float(long M, long N, int* seq1, int* seq2, float**** FTable){
	///Parameter checking
	if (!((M >= 2 && N >= 2))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	//Memory Allocation
	
	#define S0(i1,j1,i2,j2,i4,i5) FTable(-i1,j1,-j2,i4) = seq2(-j2)
	#define S1(i1,j1,i2,j2,i4,i5) FTable(-i1,j1,-j2,i4) = seq1(-i1)
	#define S2(i1,j1,i2,j2,i4,i5) FTable(-i1,j1,-j2,i4) = FTable(-i1,j1,-j2,i4)
	#define S4(i1,j1,i2,j2,i4,i5) FTable(-i1,j1,-j2,i5) = 1.401298464324817E-45
	#define S3(i0,i1,i2,i3,i4,i5) {float __temp__ = (FTable(-i0,i2,-i3,i4))+(FTable(i2+1,i1,i4+1,i5)); FTable(-i0,i1,-i3,i5) = __max_float(FTable(-i0,i1,-i3,i5),__temp__); }
	{
		//Domain
		//{i1,j1,i2,j2,i4,i5|i5==i4 && i1+i2==0 && i1+j1==0 && M>=2 && N>=2 && 0>=j2 && N+j2>=1 && j2+i4>=0 && N>=i4+1 && 0>=i1 && M+i1>=1}
		//{i1,j1,i2,j2,i4,i5|j2+i5==0 && j2+i4==0 && i2==j1 && i1+j1>=1 && M>=2 && N>=2 && 0>=i1 && M+i1>=1 && M>=j1+1 && N+j2>=1 && 0>=j2}
		//{i1,j1,i2,j2,i4,i5|i5==i4 && i2==j1 && i1+j1>=1 && j2+i4>=1 && M>=2 && N>=2 && 0>=i1 && N>=i4+1 && M>=j1+1 && 0>=j2}
		//{i1,j1,i2,j2,i4,i5|j2+i4==-1 && i1+i2==-1 && M>=2 && N>=2 && 0>=i1 && i1+j1>=1 && M>=j1+1 && 0>=j2 && j2+i5>=1 && N>=i5+1}
		//{i0,i1,i2,i3,i4,i5|i0+i2>=0 && i1>=i2+1 && i3+i4>=0 && i5>=i4+1 && M>=2 && N>=2 && 0>=i0 && N>=i5+1 && M>=i2+1 && 0>=i3 && i4>=-1 && N>=i4+1 && M>=i1+1 && i2>=-1 && i3+i5>=1 && i0+i1>=1}
		int c1,c2,c3,c4,c5,c6;
		#pragma omp parallel for private(c5) schedule(dynamic)
		for(c4=-N+1;c4 <= 0;c4+=1)
		 {
		 	for(c5=-c4;c5 <= N-1;c5+=1)
		 	 {
		 	 	S0((-M+1),(M-1),(M-1),(c4),(c5),(c5));
		 	 }
		 }
		for(c1=-M+2;c1 <= 0;c1+=1)
		 {
		 	#pragma omp parallel for private(c5) schedule(dynamic)
		 	for(c4=-N+1;c4 <= 0;c4+=1)
		 	 {
		 	 	for(c5=-c4;c5 <= N-1;c5+=1)
		 	 	 {
		 	 	 	S0((c1),(-c1),(-c1),(c4),(c5),(c5));
		 	 	 }
		 	 }
		 	for(c2=-c1+1;c2 <= M-1;c2+=1)
		 	 {
		 	 	#pragma omp parallel for private(c6) schedule(dynamic)
		 	 	for(c4=-N+2;c4 <= 0;c4+=1)
		 	 	 {
		 	 	 	for(c6=-c4+1;c6 <= N-1;c6+=1)
		 	 	 	 {
		 	 	 	 	S4((c1),(c2),(-c1-1),(c4),(-c4-1),(c6));
		 	 	 	 }
		 	 	 }
		 	      // #pragma omp parallel//test
		 	 	for(c3=-c1;c3 <= c2-1;c3+=1)
		 	 	 {
		 	 	 	#pragma omp parallel for private(c5,c6) schedule(dynamic)
		 	 	 	for(c4=-N+2;c4 <= 0;c4+=1)
		 	 	 	 {
		 	 	 	 	for(c5=-c4;c5 <= N-2;c5+=1)
		 	 	 	 	 {
						    #pragma ivdep
                            			    #pragma vector always
                                                    #pragma simd
		 	 	 	 	 	for(c6=c5+1;c6 <= N-1;c6+=1)
		 	 	 	 	 	 {
		 	 	 	 	 	 	S3((c1),(c2),(c3),(c4),(c5),(c6));
		 	 	 	 	 	 }
		 	 	 	 	 }
		 	 	 	 }
		 	 	 }
		 	 	S1((c1),(c2),(c2),(-N+1),(N-1),(N-1));
		 	 	#pragma omp parallel for private(c5) schedule(dynamic)
		 	 	for(c4=-N+2;c4 <= 0;c4+=1)
		 	 	 {
		 	 	 	S1((c1),(c2),(c2),(c4),(-c4),(-c4));
		 	 	 	for(c5=-c4+1;c5 <= N-1;c5+=1)
		 	 	 	 {
		 	 	 	 	S2((c1),(c2),(c2),(c4),(c5),(c5));
		 	 	 	 }
		 	 	 }
		 	 }
		 }
	}
	#undef S0
	#undef S1
	#undef S2
	#undef S4
	#undef S3
	
	//Memory Free
}

//Memory Macros
#undef seq1
#undef seq2
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
