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

void ospsq_float(long M, long N, long ts4_l1, long ts5_l1, long ts6_l1, int* seq1, int* seq2, float**** FTable){
	///Parameter checking
	if (!((M >= 3 && N >= 3 && ts4_l1 > 0 && ts5_l1 > 0 && ts6_l1 > 0))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	//Memory Allocation
	
	#define S0(i1,j1,i2,j2,i4,i5) FTable(j1,i1+j1,j2,i5) = seq2(j2)
	#define S1(i1,j1,i2,j2,i4,i5) FTable(j1,i1+j1,j2,i5) = seq1(j1)
	#define S2(i1,j1,i2,j2,i4,i5) FTable(j1,i1+j1,j2,i5) = FTable(j1,i1+j1,j2,i5)
	#define S4(i1,j1,i2,j2,i4,i5) FTable(j1,i1+j1,j2,i5) = 0.0
	#define S3(i0,i1,i2,i3,i4,i5) FTable(i1,i0+i1,i3,i5) = (FTable(i1,i0+i1,i3,i5))+((FTable(i1,i2,i3,i4))*(FTable(i2+1,i0+i1,i4+1,i5)))
	{
		//Domain
		//{i1,j1,i2,j2,i4,i5|i4==j2 && i2==j1 && i1==0 && M>=3 && N>=3 && j2>=0 && N>=j2+1 && N>=i5+1 && i5>=j2 && M>=j1+1 && j1>=0}
		//{i1,j1,i2,j2,i4,i5|i5==j2 && i4==j2 && i2==i1+j1 && i1>=1 && M>=3 && N>=3 && j1>=0 && M>=j1+1 && N>=j2+1 && M>=i1+j1+1 && j2>=0}
		//{i1,j1,i2,j2,i4,i5|i4==j2 && i2==i1+j1 && i1>=1 && i5>=j2+1 && M>=3 && N>=3 && M>=i1+j1+1 && N>=i5+1 && j2>=0 && j1>=0}
		//{i1,j1,i2,j2,i4,i5|i4==j2-1 && i2==j1-1 && M>=3 && N>=3 && ts4_l1>=1 && ts5_l1>=1 && ts6_l1>=1 && M>=i1+j1+1 && i1>=1 && j2>=0 && i5>=j2+1 && N>=i5+1 && j1>=0}
		//{i0,i1,i2,i3,i4,i5|i2>=i1 && i0+i1>=i2+1 && i4>=i3 && i5>=i4+1 && M>=3 && N>=3 && i1>=0 && N>=i5+1 && M>=i2+1 && i3>=0 && i4>=-1 && N>=i4+1 && M>=i0+i1+1 && i2>=-1 && i5>=i3+1 && i0>=1}
		int ti4_l1,ti5_l1,ti6_l1,c1,c2,c3,c4,c5,c6;
		for(c1=0;c1 <= 0;c1+=1)
		 {
		 	for(c2=0;c2 <= M-1;c2+=1)
		 	 {
		 	 	for(c3=c2;c3 <= c2;c3+=1)
		 	 	 {
#pragma omp parallel for private(c4,c5,c6, ti4_l1, ti5_l1, ti6_l1) schedule(dynamic)
		 	 	 	for(ti4_l1=(ceild((-ts4_l1+1),(ts4_l1))) * (ts4_l1);ti4_l1 <= N-1;ti4_l1+=ts4_l1)
		 	 	 	 {
		 	 	 	 	for(ti5_l1=(ceild((ti4_l1-ts5_l1+1),(ts5_l1))) * (ts5_l1);ti5_l1 <= ti4_l1+ts4_l1-1;ti5_l1+=ts5_l1)
		 	 	 	 	 {
		 	 	 	 	 	for(ti6_l1=(ceild((ti4_l1-ts6_l1+1),(ts6_l1))) * (ts6_l1);ti6_l1 <= N-1;ti6_l1+=ts6_l1)
		 	 	 	 	 	 {
		 	 	 	 	 	 	{
		 	 	 	 	 	 		for(c4=max(ti4_l1,0);c4 <= min(ti4_l1+ts4_l1-1,N-1);c4+=1)
		 	 	 	 	 	 		 {
		 	 	 	 	 	 		 	for(c5=max(ti5_l1,c4);c5 <= min(ti5_l1+ts5_l1-1,c4);c5+=1)
		 	 	 	 	 	 		 	 {
		 	 	 	 	 	 		 	 	for(c6=max(ti6_l1,c4);c6 <= min(ti6_l1+ts6_l1-1,N-1);c6+=1)
		 	 	 	 	 	 		 	 	 {
		 	 	 	 	 	 		 	 	 	S0((0),(c2),(c2),(c4),(c4),(c6));
		 	 	 	 	 	 		 	 	 }
		 	 	 	 	 	 		 	 }
		 	 	 	 	 	 		 }
		 	 	 	 	 	 	}
		 	 	 	 	 	 }
		 	 	 	 	 }
		 	 	 	 }
		 	 	 }
		 	 }
		 }
		for(c1=1;c1 <= M-1;c1+=1)
		 {
		 	for(c2=0;c2 <= -c1+M-1;c2+=1)
		 	 {
		 	 	for(c3=c2-1;c3 <= c2-1;c3+=1)
		 	 	 {
#pragma omp parallel for private(c4,c5,c6, ti4_l1, ti5_l1, ti6_l1) schedule(dynamic)
		 	 	 	for(ti4_l1=(ceild((-ts4_l1+1),(ts4_l1))) * (ts4_l1);ti4_l1 <= N-2;ti4_l1+=ts4_l1)
		 	 	 	 {
		 	 	 	 	for(ti5_l1=(ceild((ti4_l1-ts5_l1+0),(ts5_l1))) * (ts5_l1);ti5_l1 <= ti4_l1+ts4_l1-2;ti5_l1+=ts5_l1)
		 	 	 	 	 {
		 	 	 	 	 	for(ti6_l1=(ceild((ti4_l1-ts6_l1+2),(ts6_l1))) * (ts6_l1);ti6_l1 <= N-1;ti6_l1+=ts6_l1)
		 	 	 	 	 	 {
		 	 	 	 	 	 	{
		 	 	 	 	 	 		for(c4=max(ti4_l1,0);c4 <= min(ti4_l1+ts4_l1-1,N-2);c4+=1)
		 	 	 	 	 	 		 {
		 	 	 	 	 	 		 	for(c5=max(ti5_l1,c4-1);c5 <= min(ti5_l1+ts5_l1-1,c4-1);c5+=1)
		 	 	 	 	 	 		 	 {
		 	 	 	 	 	 		 	 	for(c6=max(ti6_l1,c4+1);c6 <= min(ti6_l1+ts6_l1-1,N-1);c6+=1)
		 	 	 	 	 	 		 	 	 {
		 	 	 	 	 	 		 	 	 	S4((c1),(c2),(c2-1),(c4),(c4-1),(c6));
		 	 	 	 	 	 		 	 	 }
		 	 	 	 	 	 		 	 }
		 	 	 	 	 	 		 }
		 	 	 	 	 	 	}
		 	 	 	 	 	 }
		 	 	 	 	 }
		 	 	 	 }
		 	 	 }
		 	 	for(c3=c2;c3 <= c1+c2-1;c3+=1)
		 	 	 {
#pragma omp parallel for private(c4,c5,c6, ti4_l1, ti5_l1, ti6_l1) schedule(dynamic)
		 	 	 	for(ti4_l1=(ceild((-ts4_l1+1),(ts4_l1))) * (ts4_l1);ti4_l1 <= N-2;ti4_l1+=ts4_l1)
		 	 	 	 {
		 	 	 	 	for(ti5_l1=(ceild((ti4_l1-ts5_l1+1),(ts5_l1))) * (ts5_l1);ti5_l1 <= N-2;ti5_l1+=ts5_l1)
		 	 	 	 	 {
		 	 	 	 	 	for(ti6_l1=(ceild((ti5_l1-ts6_l1+2),(ts6_l1))) * (ts6_l1);ti6_l1 <= N-1;ti6_l1+=ts6_l1)
		 	 	 	 	 	 {
		 	 	 	 	 	 	{
		 	 	 	 	 	 		for(c4=max(ti4_l1,0);c4 <= min(ti4_l1+ts4_l1-1,N-2);c4+=1)
		 	 	 	 	 	 		 {
		 	 	 	 	 	 		 	for(c5=max(ti5_l1,c4);c5 <= min(ti5_l1+ts5_l1-1,N-2);c5+=1)
		 	 	 	 	 	 		 	 {
						                    #pragma ivdep
                                            #pragma vector always
                                            #pragma simd
		 	 	 	 	 	 		 	 	for(c6=max(ti6_l1,c5+1);c6 <= min(ti6_l1+ts6_l1-1,N-1);c6+=1)
		 	 	 	 	 	 		 	 	 {
		 	 	 	 	 	 		 	 	 	S3((c1),(c2),(c3),(c4),(c5),(c6));
		 	 	 	 	 	 		 	 	 }
		 	 	 	 	 	 		 	 }
		 	 	 	 	 	 		 }
		 	 	 	 	 	 	}
		 	 	 	 	 	 }
		 	 	 	 	 }
		 	 	 	 }
		 	 	 }
		 	 	for(c3=c1+c2;c3 <= c1+c2;c3+=1)
		 	 	 {
#pragma omp parallel for private(c4,c5,c6, ti4_l1, ti5_l1, ti6_l1) schedule(dynamic)
		 	 	 	for(ti4_l1=(ceild((-ts4_l1+1),(ts4_l1))) * (ts4_l1);ti4_l1 <= N-1;ti4_l1+=ts4_l1)
		 	 	 	 {
		 	 	 	 	for(ti5_l1=(ceild((min(ti4_l1,N-1) + -ts5_l1+1),(ts5_l1))) * (ts5_l1);ti5_l1 <= max(ti4_l1+ts4_l1-1,N-1);ti5_l1+=ts5_l1)
		 	 	 	 	 {
		 	 	 	 	 	for(ti6_l1=(ceild((min(ti4_l1,N-1) + -ts6_l1+1),(ts6_l1))) * (ts6_l1);ti6_l1 <= N-1;ti6_l1+=ts6_l1)
		 	 	 	 	 	 {
		 	 	 	 	 	 	{
		 	 	 	 	 	 		for(c4=max(ti4_l1,0);c4 <= min(ti4_l1+ts4_l1-1,N-2);c4+=1)
		 	 	 	 	 	 		 {
		 	 	 	 	 	 		 	for(c5=max(ti5_l1,c4);c5 <= min(ti5_l1+ts5_l1-1,c4);c5+=1)
		 	 	 	 	 	 		 	 {
		 	 	 	 	 	 		 	 	for(c6=max(ti6_l1,c4);c6 <= min(ti6_l1+ts6_l1-1,c4);c6+=1)
		 	 	 	 	 	 		 	 	 {
		 	 	 	 	 	 		 	 	 	S1((c1),(c2),(c1+c2),(c4),(c4),(c4));
		 	 	 	 	 	 		 	 	 }
		 	 	 	 	 	 		 	 	for(c6=max(ti6_l1,c4+1);c6 <= min(ti6_l1+ts6_l1-1,N-1);c6+=1)
		 	 	 	 	 	 		 	 	 {
		 	 	 	 	 	 		 	 	 	S2((c1),(c2),(c1+c2),(c4),(c4),(c6));
		 	 	 	 	 	 		 	 	 }
		 	 	 	 	 	 		 	 }
		 	 	 	 	 	 		 }
		 	 	 	 	 	 		for(c4=max(ti4_l1,N-1);c4 <= min(ti4_l1+ts4_l1-1,N-1);c4+=1)
		 	 	 	 	 	 		 {
		 	 	 	 	 	 		 	for(c5=max(ti5_l1,N-1);c5 <= min(ti5_l1+ts5_l1-1,N-1);c5+=1)
		 	 	 	 	 	 		 	 {
		 	 	 	 	 	 		 	 	for(c6=max(ti6_l1,N-1);c6 <= min(ti6_l1+ts6_l1-1,N-1);c6+=1)
		 	 	 	 	 	 		 	 	 {
		 	 	 	 	 	 		 	 	 	S1((c1),(c2),(c1+c2),(N-1),(N-1),(N-1));
		 	 	 	 	 	 		 	 	 }
		 	 	 	 	 	 		 	 }
		 	 	 	 	 	 		 }
		 	 	 	 	 	 	}
		 	 	 	 	 	 }
		 	 	 	 	 }
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
