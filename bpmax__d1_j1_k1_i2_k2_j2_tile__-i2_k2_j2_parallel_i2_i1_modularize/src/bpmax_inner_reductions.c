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
#define FTable_4D(i,j,i2,j2) FTable_4D[i][j][i2][j2]
#define S2(i,j) S2[i][j]
#define NR_FTable_2D(i2,j2) NR_FTable_2D[i2][j2]
#define NR_FTable_2D_1(i2,j2) NR_FTable_2D_1[i2][j2]
#define FTable_2D(i,j) FTable_2D[i][j]

void bpmax_inner_reductions(long M, long N, long I1, long J1, long T1, long T2, long T3, float**** FTable_4D, float** S2, float** FTable_2D){
	///Parameter checking
	if (!((M >= 3 && N >= 3 && T1 >= 1 && T2 >= 1 && T3 >= 1 && I1 >= 0 && J1 >= I1 && M >= J1+1))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	//Memory Allocation
	int mz1, mz2;
	
	float* _lin_NR_FTable_2D = (float*)malloc(sizeof(float)*((N-1) * (N)));
	mallocCheck(_lin_NR_FTable_2D, ((N-1) * (N)), float);
	float** NR_FTable_2D = (float**)malloc(sizeof(float*)*(N-1));
	mallocCheck(NR_FTable_2D, (N-1), float*);
	for (mz1=0;mz1 < N-1; mz1++) {
		NR_FTable_2D[mz1] = &_lin_NR_FTable_2D[(mz1*(N))];
	}
	
	float* _lin_NR_FTable_2D_1 = (float*)malloc(sizeof(float)*((N-1) * (N)));
	mallocCheck(_lin_NR_FTable_2D_1, ((N-1) * (N)), float);
	float** NR_FTable_2D_1 = (float**)malloc(sizeof(float*)*(N-1));
	mallocCheck(NR_FTable_2D_1, (N-1), float*);
	for (mz1=0;mz1 < N-1; mz1++) {
		NR_FTable_2D_1[mz1] = &_lin_NR_FTable_2D_1[(mz1*(N))];
	}
	#define S0(i,j,i2) FTable_2D(-i,j) = FTable_4D(I1,J1,-i,j)
	#define S1(i,j,i2) FTable_2D(-i,j) = __max_float(FTable_4D(I1,J1,-i,j),__max_float(NR_FTable_2D(-i,j),NR_FTable_2D_1(-i,j)))
	#define S4(i,j,i2) NR_FTable_2D(-i,i2) = 1.401298464324817E-45
	#define S5(i,j,i2) NR_FTable_2D_1(-i,i2) = 1.401298464324817E-45
	#define S_2(i0,i1,i2) {float __temp__ = (FTable_4D(I1,J1,-i0,i1))+(S2(i1+1,i2)); NR_FTable_2D(-i0,i2) = __max_float(NR_FTable_2D(-i0,i2),__temp__); }
	#define S3(i0,i1,i2) {float __temp__ = (S2(-i0,i1))+(FTable_4D(I1,J1,i1+1,i2)); NR_FTable_2D_1(-i0,i2) = __max_float(NR_FTable_2D_1(-i0,i2),__temp__); }
	{
		//Domain
		//{i,j,i2|i+i2==0 && i+j==0 && M>=3 && N>=3 && T1>=1 && T2>=1 && T3>=1 && I1>=0 && J1>=I1 && M>=J1+1 && 0>=i && N+i>=1}
		//{i,j,i2|i2==j && M>=3 && N>=3 && T1>=1 && T2>=1 && T3>=1 && I1>=0 && J1>=I1 && M>=J1+1 && i+j>=1 && N>=j+1 && 0>=i}
		//{i,j,i2|i+j==-1 && M>=3 && N>=3 && T1>=1 && T2>=1 && T3>=1 && I1>=0 && J1>=I1 && M>=J1+1 && 0>=i && i+i2>=1 && N>=i2+1}
		//{i,j,i2|i+j==-1 && M>=3 && N>=3 && T1>=1 && T2>=1 && T3>=1 && I1>=0 && J1>=I1 && M>=J1+1 && N>=i2+1 && i+i2>=1 && 0>=i}
		//{i0,i1,i2|i0+i1>=0 && i2>=i1+1 && M>=3 && N>=3 && T1>=1 && T2>=1 && T3>=1 && I1>=0 && J1>=I1 && M>=J1+1 && N>=i2+1 && i1>=-1 && N>=i1+1 && 0>=i0 && i0+i2>=1}
		//{i0,i1,i2|i0+i1>=0 && i2>=i1+1 && M>=3 && N>=3 && T1>=1 && T2>=1 && T3>=1 && I1>=0 && J1>=I1 && M>=J1+1 && 0>=i0 && i1>=-1 && N>=i1+1 && N>=i2+1 && i0+i2>=1}
		int c1,c2,c3;
		S0((-N+1),(N-1),(N-1));
		S4((-N+2),(N-3),(N-1));
		S5((-N+2),(N-3),(N-1));
		S0((-N+2),(N-2),(N-2));
		S_2((-N+2),(N-2),(N-1));
		S3((-N+2),(N-2),(N-1));
		S1((-N+2),(N-1),(N-1));
		for(c1=-N+3;c1 <= 0;c1+=1)
		 {
		 	for(c3=-c1+1;c3 <= N-1;c3+=1)
		 	 {
		 	 	S4((c1),(-c1-1),(c3));
		 	 	S5((c1),(-c1-1),(c3));
		 	 }
		 	S0((c1),(-c1),(-c1));
		 	for(c3=-c1+1;c3 <= N-1;c3+=1)
		 	 {
		 	 	S_2((c1),(-c1),(c3));
		 	 	S3((c1),(-c1),(c3));
		 	 }
		 	for(c2=-c1+1;c2 <= N-2;c2+=1)
		 	 {
		 	 	S1((c1),(c2),(c2));
		 	 	for(c3=c2+1;c3 <= N-1;c3+=1)
		 	 	 {
		 	 	 	S_2((c1),(c2),(c3));
		 	 	 	S3((c1),(c2),(c3));
		 	 	 }
		 	 }
		 	S1((c1),(N-1),(N-1));
		 }
	}
	#undef S0
	#undef S1
	#undef S4
	#undef S5
	#undef S_2
	#undef S3
	
	//Memory Free
	free(_lin_NR_FTable_2D);
	free(NR_FTable_2D);
	
	free(_lin_NR_FTable_2D_1);
	free(NR_FTable_2D_1);
}

//Memory Macros
#undef FTable_4D
#undef S2
#undef NR_FTable_2D
#undef NR_FTable_2D_1
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
