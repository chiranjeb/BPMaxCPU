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
#define FTable_4D(i1,j1,i2,j2) FTable_4D[i1][j1][i2][j2]
#define S1(i,j) S1[i][j]
#define FTable_2D(i2,j2) FTable_2D[i2][j2]

void bpmax_outer_reductions(long M, long N, long I1, long J1, long ts2_l1, long ts3_l1, long ts4_l1, float**** FTable_4D, float** S1, float** FTable_2D){
	///Parameter checking
	if (!((M >= 3 && N >= 3 && M >= J1+1 && I1 >= 0 && J1 >= I1+1 && ts2_l1 > 0 && ts3_l1 > 0 && ts4_l1 > 0))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	//Memory Allocation
	
	#define S0(i,j,i2,i3)  //FTable_2D(j,i2) = __max_float(FTable_2D(j,i2),__max_float(FTable_2D(j,i2),FTable_2D(j,i2)))
	#define S_1(i,j,i2,i3) //FTable_2D(j,i2) = __max_float(0,__max_float(FTable_2D(j,i2),FTable_2D(j,i2)))
	#define S5(i,j,i2,i3)  //FTable_2D(j,i3) = 1.401298464324817E-45
	#define S6(i,j,i2,i3)  //FTable_2D(j,i3) = 1.401298464324817E-45
	#define S7(i,j,i2,i3)  //FTable_2D(j,i3) = 1.401298464324817E-45
	#define S2(i0,i1,i2,i3) {float __temp__ = (FTable_4D(I1,i0,i1,i2))+(FTable_4D(i0+1,J1,i2+1,i3)); FTable_2D(i1,i3) = __max_float(FTable_2D(i1,i3),__temp__); }
	#define S3(i0,i1,i2,i3) {float __temp__ = (S1(I1,i0))+(FTable_4D(i0+1,J1,i1,i3)); FTable_2D(i1,i3) = __max_float(FTable_2D(i1,i3),__temp__); }
	#define S4(i0,i1,i2,i3) {float __temp__ = (FTable_4D(I1,i0,i1,i3))+(S1(i0+1,J1)); FTable_2D(i1,i3) = __max_float(FTable_2D(i1,i3),__temp__); }
	{
		//Domain
		//{i,j,i2,i3|i3==0 && i==M && J1>=I1+1 && i2>=j+1 && M>=3 && N>=3 && M>=J1+1 && I1>=0 && j>=0 && N>=i2+1}
		//{i,j,i2,i3|i3==0 && i2==j && i==M && J1>=I1+1 && I1>=0 && M>=3 && N>=3 && M>=J1+1 && j>=0 && ts2_l1>=1 && N>=j+1 && ts4_l1>=1 && ts3_l1>=1}
		//{i,j,i2,i3|i2==0 && i==-1 && M>=3 && N>=3 && M>=J1+1 && I1>=0 && J1>=I1+1 && ts2_l1>=1 && ts3_l1>=1 && ts4_l1>=1 && j>=0 && i3>=j+1 && N>=i3+1}
		//{i,j,i2,i3|i2==0 && i==-1 && M>=3 && N>=3 && M>=J1+1 && I1>=0 && J1>=I1+1 && ts2_l1>=1 && ts3_l1>=1 && ts4_l1>=1 && N>=i3+1 && i3>=j && j>=0}
		//{i,j,i2,i3|i2==0 && i==-1 && M>=3 && N>=3 && M>=J1+1 && I1>=0 && J1>=I1+1 && ts2_l1>=1 && ts3_l1>=1 && ts4_l1>=1 && j>=0 && N>=i3+1 && i3>=j}
		//{i0,i1,i2,i3|i0>=I1 && J1>=i0+1 && i2>=i1 && i3>=i2+1 && M>=3 && N>=3 && M>=J1+1 && I1>=0 && J1>=I1+1 && M>=i0+1 && i1>=0 && N>=i2+1 && i0>=-1 && N>=i3+1 && i2>=-1 && i3>=i1+1}
		//{i0,i1,i2,i3|i2==i1 && i0>=I1 && J1>=i0+1 && M>=3 && N>=3 && M>=J1+1 && I1>=0 && J1>=I1+1 && i0>=-1 && M>=i0+1 && i3>=i1 && N>=i3+1 && i1>=0}
		//{i0,i1,i2,i3|i2==i1 && i0>=I1 && J1>=i0+1 && M>=3 && N>=3 && M>=J1+1 && I1>=0 && J1>=I1+1 && M>=i0+1 && i1>=0 && N>=i3+1 && i3>=i1 && i0>=-1}
		int ti2_l1,ti3_l1,ti4_l1,c1,c2,c3,c4;
		for(c1=-1;c1 <= -1;c1+=1)
		 {
		 	for(ti2_l1=(ceild((-ts2_l1+1),(ts2_l1))) * (ts2_l1);ti2_l1 <= N-1;ti2_l1+=ts2_l1)
		 	 {
		 	 	for(ti3_l1=(ceild((-ts3_l1+1),(ts3_l1))) * (ts3_l1);ti3_l1 <= 0;ti3_l1+=ts3_l1)
		 	 	 {
		 	 	 	for(ti4_l1=(ceild((min(N-1,ti2_l1) + -ts4_l1+1),(ts4_l1))) * (ts4_l1);ti4_l1 <= N-1;ti4_l1+=ts4_l1)
		 	 	 	 {
		 	 	 	 	{
		 	 	 	 		for(c2=max(ti2_l1,0);c2 <= min(ti2_l1+ts2_l1-1,N-2);c2+=1)
		 	 	 	 		 {
		 	 	 	 		 	for(c3=max(ti3_l1,0);c3 <= min(ti3_l1+ts3_l1-1,0);c3+=1)
		 	 	 	 		 	 {
		 	 	 	 		 	 	for(c4=max(ti4_l1,c2);c4 <= min(ti4_l1+ts4_l1-1,c2);c4+=1)
		 	 	 	 		 	 	 {
		 	 	 	 		 	 	 	S6((-1),(c2),(0),(c2));
		 	 	 	 		 	 	 	S7((-1),(c2),(0),(c2));
		 	 	 	 		 	 	 }
		 	 	 	 		 	 	for(c4=max(ti4_l1,c2+1);c4 <= min(ti4_l1+ts4_l1-1,N-1);c4+=1)
		 	 	 	 		 	 	 {
		 	 	 	 		 	 	 	S5((-1),(c2),(0),(c4));
		 	 	 	 		 	 	 	S6((-1),(c2),(0),(c4));
		 	 	 	 		 	 	 	S7((-1),(c2),(0),(c4));
		 	 	 	 		 	 	 }
		 	 	 	 		 	 }
		 	 	 	 		 }
		 	 	 	 		for(c2=max(ti2_l1,N-1);c2 <= min(ti2_l1+ts2_l1-1,N-1);c2+=1)
		 	 	 	 		 {
		 	 	 	 		 	for(c3=max(ti3_l1,0);c3 <= min(ti3_l1+ts3_l1-1,0);c3+=1)
		 	 	 	 		 	 {
		 	 	 	 		 	 	for(c4=max(ti4_l1,N-1);c4 <= min(ti4_l1+ts4_l1-1,N-1);c4+=1)
		 	 	 	 		 	 	 {
		 	 	 	 		 	 	 	S6((-1),(N-1),(0),(N-1));
		 	 	 	 		 	 	 }
		 	 	 	 		 	 }
		 	 	 	 		 	for(c3=max(ti3_l1,0);c3 <= min(ti3_l1+ts3_l1-1,0);c3+=1)
		 	 	 	 		 	 {
		 	 	 	 		 	 	for(c4=max(ti4_l1,N-1);c4 <= min(ti4_l1+ts4_l1-1,N-1);c4+=1)
		 	 	 	 		 	 	 {
		 	 	 	 		 	 	 	S7((-1),(N-1),(0),(N-1));
		 	 	 	 		 	 	 }
		 	 	 	 		 	 }
		 	 	 	 		 }
		 	 	 	 	}
		 	 	 	 }
		 	 	 }
		 	 }
		 }
		for(c1=I1;c1 <= J1-1;c1+=1)
		 {
		 	for(ti2_l1=(ceild((-ts2_l1+1),(ts2_l1))) * (ts2_l1);ti2_l1 <= N-1;ti2_l1+=ts2_l1)
		 	 {
		 	 	for(ti3_l1=(ceild((min(N-2,ti2_l1) + -ts3_l1+1),(ts3_l1))) * (ts3_l1);ti3_l1 <= N-1;ti3_l1+=ts3_l1)
		 	 	 {
		 	 	 	for(ti4_l1=(ceild((min(N-2,min(ti2_l1,ti3_l1+1)) + -ts4_l1+1),(ts4_l1))) * (ts4_l1);ti4_l1 <= N-1;ti4_l1+=ts4_l1)
		 	 	 	 {
		 	 	 	 	{
		 	 	 	 		for(c2=max(ti2_l1,0);c2 <= min(ti2_l1+ts2_l1-1,N-3);c2+=1)
		 	 	 	 		 {
		 	 	 	 		 	for(c3=max(ti3_l1,c2);c3 <= min(ti3_l1+ts3_l1-1,c2);c3+=1)
		 	 	 	 		 	 {
		 	 	 	 		 	 	for(c4=max(ti4_l1,c2);c4 <= min(ti4_l1+ts4_l1-1,c2);c4+=1)
		 	 	 	 		 	 	 {
		 	 	 	 		 	 	 	S3((c1),(c2),(c2),(c2));
		 	 	 	 		 	 	 	S4((c1),(c2),(c2),(c2));
		 	 	 	 		 	 	 }
		 	 	 	 		 	 	for(c4=max(ti4_l1,c2+1);c4 <= min(ti4_l1+ts4_l1-1,N-1);c4+=1)
		 	 	 	 		 	 	 {
		 	 	 	 		 	 	 	S2((c1),(c2),(c2),(c4));
		 	 	 	 		 	 	 	S3((c1),(c2),(c2),(c4));
		 	 	 	 		 	 	 	S4((c1),(c2),(c2),(c4));
		 	 	 	 		 	 	 }
		 	 	 	 		 	 }
		 	 	 	 		 	for(c3=max(ti3_l1,c2+1);c3 <= min(ti3_l1+ts3_l1-1,N-2);c3+=1)
		 	 	 	 		 	 {
		 	 	 	 		 	 	for(c4=max(ti4_l1,c3+1);c4 <= min(ti4_l1+ts4_l1-1,N-1);c4+=1)
		 	 	 	 		 	 	 {
		 	 	 	 		 	 	 	S2((c1),(c2),(c3),(c4));
		 	 	 	 		 	 	 }
		 	 	 	 		 	 }
		 	 	 	 		 }
		 	 	 	 		for(c2=max(ti2_l1,N-2);c2 <= min(ti2_l1+ts2_l1-1,N-2);c2+=1)
		 	 	 	 		 {
		 	 	 	 		 	for(c3=max(ti3_l1,N-2);c3 <= min(ti3_l1+ts3_l1-1,N-2);c3+=1)
		 	 	 	 		 	 {
		 	 	 	 		 	 	for(c4=max(ti4_l1,N-2);c4 <= min(ti4_l1+ts4_l1-1,N-2);c4+=1)
		 	 	 	 		 	 	 {
		 	 	 	 		 	 	 	S3((c1),(N-2),(N-2),(N-2));
		 	 	 	 		 	 	 	S4((c1),(N-2),(N-2),(N-2));
		 	 	 	 		 	 	 }
		 	 	 	 		 	 	for(c4=max(ti4_l1,N-1);c4 <= min(ti4_l1+ts4_l1-1,N-1);c4+=1)
		 	 	 	 		 	 	 {
		 	 	 	 		 	 	 	S2((c1),(N-2),(N-2),(N-1));
		 	 	 	 		 	 	 	S3((c1),(N-2),(N-2),(N-1));
		 	 	 	 		 	 	 	S4((c1),(N-2),(N-2),(N-1));
		 	 	 	 		 	 	 }
		 	 	 	 		 	 }
		 	 	 	 		 }
		 	 	 	 		for(c2=max(ti2_l1,N-1);c2 <= min(ti2_l1+ts2_l1-1,N-1);c2+=1)
		 	 	 	 		 {
		 	 	 	 		 	for(c3=max(ti3_l1,N-1);c3 <= min(ti3_l1+ts3_l1-1,N-1);c3+=1)
		 	 	 	 		 	 {
		 	 	 	 		 	 	for(c4=max(ti4_l1,N-1);c4 <= min(ti4_l1+ts4_l1-1,N-1);c4+=1)
		 	 	 	 		 	 	 {
		 	 	 	 		 	 	 	S3((c1),(N-1),(N-1),(N-1));
		 	 	 	 		 	 	 }
		 	 	 	 		 	 }
		 	 	 	 		 	for(c3=max(ti3_l1,N-1);c3 <= min(ti3_l1+ts3_l1-1,N-1);c3+=1)
		 	 	 	 		 	 {
		 	 	 	 		 	 	for(c4=max(ti4_l1,N-1);c4 <= min(ti4_l1+ts4_l1-1,N-1);c4+=1)
		 	 	 	 		 	 	 {
		 	 	 	 		 	 	 	S4((c1),(N-1),(N-1),(N-1));
		 	 	 	 		 	 	 }
		 	 	 	 		 	 }
		 	 	 	 		 }
		 	 	 	 	}
		 	 	 	 }
		 	 	 }
		 	 }
		 }
		for(c1=M;c1 <= M;c1+=1)
		 {
		 	for(ti2_l1=(ceild((-ts2_l1+1),(ts2_l1))) * (ts2_l1);ti2_l1 <= N-1;ti2_l1+=ts2_l1)
		 	 {
		 	 	for(ti3_l1=(ceild((min(ti2_l1,N-1) + -ts3_l1+1),(ts3_l1))) * (ts3_l1);ti3_l1 <= N-1;ti3_l1+=ts3_l1)
		 	 	 {
		 	 	 	for(ti4_l1=(ceild((-ts4_l1+1),(ts4_l1))) * (ts4_l1);ti4_l1 <= 0;ti4_l1+=ts4_l1)
		 	 	 	 {
		 	 	 	 	{
		 	 	 	 		for(c2=max(ti2_l1,0);c2 <= min(ti2_l1+ts2_l1-1,N-2);c2+=1)
		 	 	 	 		 {
		 	 	 	 		 	for(c3=max(ti3_l1,c2);c3 <= min(ti3_l1+ts3_l1-1,c2);c3+=1)
		 	 	 	 		 	 {
		 	 	 	 		 	 	for(c4=max(ti4_l1,0);c4 <= min(ti4_l1+ts4_l1-1,0);c4+=1)
		 	 	 	 		 	 	 {
		 	 	 	 		 	 	 	S_1((M),(c2),(c2),(0));
		 	 	 	 		 	 	 }
		 	 	 	 		 	 }
		 	 	 	 		 	for(c3=max(ti3_l1,c2+1);c3 <= min(ti3_l1+ts3_l1-1,N-1);c3+=1)
		 	 	 	 		 	 {
		 	 	 	 		 	 	for(c4=max(ti4_l1,0);c4 <= min(ti4_l1+ts4_l1-1,0);c4+=1)
		 	 	 	 		 	 	 {
		 	 	 	 		 	 	 	S0((M),(c2),(c3),(0));
		 	 	 	 		 	 	 }
		 	 	 	 		 	 }
		 	 	 	 		 }
		 	 	 	 		for(c2=max(ti2_l1,N-1);c2 <= min(ti2_l1+ts2_l1-1,N-1);c2+=1)
		 	 	 	 		 {
		 	 	 	 		 	for(c3=max(ti3_l1,N-1);c3 <= min(ti3_l1+ts3_l1-1,N-1);c3+=1)
		 	 	 	 		 	 {
		 	 	 	 		 	 	for(c4=max(ti4_l1,0);c4 <= min(ti4_l1+ts4_l1-1,0);c4+=1)
		 	 	 	 		 	 	 {
		 	 	 	 		 	 	 	S_1((M),(N-1),(N-1),(0));
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
	#undef S_1
	#undef S5
	#undef S6
	#undef S7
	#undef S2
	#undef S3
	#undef S4
	
	//Memory Free
}

//Memory Macros
#undef FTable_4D
#undef S1
#undef FTable_2D


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
