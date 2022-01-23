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
#define _InputOutput(i1,j1,i2,j2) _InputOutput[i1][j1][i2][j2]
#define _Output(i2,j2) _Output[i2][j2]

void Matrix_MaxPlus(long P, long M, long N, long I1, long J1, float**** _InputOutput, float** _Output){
	///Parameter checking
	if (!((P >= 101 && M >= 3 && N >= 5 && P >= M+1 && P >= N+1 && I1 >= 0 && M >= I1+1 && J1 >= 0 && M >= J1+1 && J1 >= I1+2))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	//Memory Allocation
	
	#define S0(i,j,i2,i3,i4) _Output(i3,i4) = _InputOutput(I1,J1,i3,i4)
	#define S1(i,j,i2,i3,i4) _Output(i3,i4) = _Output(i3,i4)
	#define S3(i,j,i2,i3,i4) _Output(i3,i4) = 3.4028234663852886E38
	#define S2(i0,i1,i2,i3,i4) {float __temp__ = (_InputOutput(I1,i1+1,i3,i2))+(_InputOutput(i1+1,J1,i2+1,i4)); _Output(i3,i4) = __min_float(_Output(i3,i4),__temp__); }
	{
		//Domain
		//{i,j,i2,i3,i4|i3==N && i2==N && j==M && i==1 && P>=101 && M>=3 && N>=5 && P>=M+1 && P>=N+1 && I1>=0 && M>=I1+1 && J1>=0 && M>=J1+1 && J1>=I1+2 && N>=i4+1 && i4>=0}
		//{i,j,i2,i3,i4|i2==N && j==M && i==1 && P>=101 && M>=3 && N>=5 && P>=M+1 && P>=N+1 && I1>=0 && M>=I1+1 && J1>=0 && M>=J1+1 && J1>=I1+2 && N>=i3+1 && N>=i4+1 && i4>=0 && i3>=0}
		//{i,j,i2,i3,i4|i2==0 && j==0 && i==-1 && P>=101 && M>=3 && N>=5 && P>=M+1 && P>=N+1 && I1>=0 && M>=I1+1 && J1>=0 && M>=J1+1 && J1>=I1+2 && N>=i4+1 && i4>=0 && N>=i3+1 && i3>=0}
		//{i0,i1,i2,i3,i4|i0==1 && i1>=I1 && J1>=i1+2 && i2>=0 && N>=i2+1 && P>=101 && M>=3 && N>=5 && P>=M+1 && P>=N+1 && I1>=0 && M>=I1+1 && J1>=0 && M>=J1+1 && J1>=I1+2 && i4>=0 && N>=i4+1 && M>=i1+2 && i3>=0 && N>=i3+1 && i1>=-1}
		int c2,c3,c4,c5;
		for(c4=0;c4 <= N-1;c4+=1)
		 {
		 	for(c5=0;c5 <= N-1;c5+=1)
		 	 {
		 	 	S3((-1),(0),(0),(c4),(c5));
		 	 }
		 }
		for(c2=I1;c2 <= J1-2;c2+=1)
		 {
		 	for(c3=0;c3 <= N-1;c3+=1)
		 	 {
		 	 	for(c4=0;c4 <= N-1;c4+=1)
		 	 	 {
		 	 	 	for(c5=0;c5 <= N-1;c5+=1)
		 	 	 	 {
		 	 	 	 	S2((1),(c2),(c3),(c4),(c5));
		 	 	 	 }
		 	 	 }
		 	 }
		 }
		for(c4=0;c4 <= N-1;c4+=1)
		 {
		 	for(c5=0;c5 <= N-1;c5+=1)
		 	 {
		 	 	S1((1),(M),(N),(c4),(c5));
		 	 }
		 }
		for(c5=0;c5 <= N-1;c5+=1)
		 {
		 	S0((1),(M),(N),(N),(c5));
		 }
	}
	#undef S0
	#undef S1
	#undef S3
	#undef S2
	
	//Memory Free
}

//Memory Macros
#undef _InputOutput
#undef _Output


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
