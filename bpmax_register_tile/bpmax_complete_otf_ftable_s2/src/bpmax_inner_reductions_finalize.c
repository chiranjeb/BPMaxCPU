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
#define S2_C(i2,j2,i3,j3) S2_C[i2][j2][i3][j3]
#define C(i2,j2,i3,j3) C[i2][j2][i3][j3]
#define NR_C_I2_J2(i2) NR_C_I2_J2[i2]
#define NR_C_I2_J2_3(i2) NR_C_I2_J2_3[i2]
#define C_I2_J2(i3,j3) C_I2_J2[i3][j3]

void bpmax_inner_reductions_finalize(long N, long N_sec, long N_tile, long R, long MR, long NR, long I2, long J2, int** seq2_t, float**** S2_C, float**** C, float** C_I2_J2){
	///Parameter checking
	if (!((N >= 8 && N_sec >= 2 && N_tile >= 4 && R >= 0 && N_tile >= R+1 && MR >= 1 && NR >= 1 && I2 >= 0 && J2 >= I2+1 && N_sec >= J2+1))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
    
    R = CALCULATE_R_i(I2, R);

	//Memory Allocation
	int mz1;
	
	float* NR_C_I2_J2 = (float*)malloc(sizeof(float)*(N_tile));
	mallocCheck(NR_C_I2_J2, (N_tile), float);
	
	float* NR_C_I2_J2_3 = (float*)malloc(sizeof(float)*(N_tile));
	mallocCheck(NR_C_I2_J2_3, (N_tile), float);
	#define S0(i,j,i2,i3) C_I2_J2(-i,i2) = C(I2+1,J2,0,i2)
	#define S1(i,j,i2,i3) C_I2_J2(-i,i2) = __max_float(0,C_I2_J2(-i,i2))
	#define S2(i,j,i2,i3) C_I2_J2(-i,i2) = __max_float((C(I2,J2-1,-i+1,N_tile-1))+(e_intra_score(seq2_t(I2,-i),seq2_t(J2,i2))),C_I2_J2(-i,i2))
	#define S3(i,j,i2,i3) C_I2_J2(-i,i2) = __max_float((C(I2,J2,-i+1,i2-1))+(e_intra_score(seq2_t(I2,-i),seq2_t(J2,i2))),C_I2_J2(-i,i2))
	#define S4(i,j,i2,i3) C_I2_J2(-i,i2) = C_I2_J2(-i,i2)
	#define S5(i,j,i2,i3) C_I2_J2(-i,i2) = __max_float(C_I2_J2(-i,i2),__max_float(NR_C_I2_J2(i2),__max_float(C_I2_J2(-i,i2),__max_float(C_I2_J2(-i,i2),NR_C_I2_J2_3(i2)))))
	#define S6(i,j,i2,i3) C_I2_J2(-i,i2) = __max_float(C_I2_J2(-i,i2),__max_float(NR_C_I2_J2(i2),__max_float(C_I2_J2(-i,i2),0)))
	#define S11(i,j,i2,i3) //C_I2_J2(j,i3) = 1.401298464324817E-45
	#define S12(i,j,i2,i3) //C_I2_J2(j,i3) = 1.401298464324817E-45
	#define S13(i,j,i2,i3) NR_C_I2_J2(i3) = 1.401298464324817E-45
	#define S14(i,j,i2,i3) NR_C_I2_J2_3(i3) = 1.401298464324817E-45
	#define S8(i0,i1,i2,i3) {float __temp__ = (C(I2,I2,i1,i2))+(S2_C(I2,J2,i2+1,i3)); C_I2_J2(i1,i3) = __max_float(C_I2_J2(i1,i3),__temp__); }
	#define S9(i0,i1,i2,i3) {float __temp__ = (S2_C(I2,J2,i1,i2))+(C(J2,J2,i2+1,i3)); C_I2_J2(i1,i3) = __max_float(C_I2_J2(i1,i3),__temp__); }
	#define S7(i0,i1,i2,i3) {float __temp__ = (S2_C(I2,I2,-i0,i2))+(C(I2,J2,i2+1,i3)); NR_C_I2_J2(i3) = __max_float(NR_C_I2_J2(i3),__temp__); }
	#define S10(i0,i1,i2,i3) {float __temp__ = (C(I2,J2,-i0,i2))+(S2_C(J2,J2,i2+1,i3)); NR_C_I2_J2_3(i3) = __max_float(NR_C_I2_J2_3(i3),__temp__); }
	{
		//Domain
		//{i,j,i2,i3|i3==i2 && j==0 && N_tile+i==0 && N>=8 && N_sec>=2 && N_tile>=4 && R>=0 && N_tile>=R+1 && MR>=1 && NR>=1 && I2>=0 && J2>=I2+1 && N_sec>=J2+1 && N_tile>=i2+1 && i2>=0}
		//{i,j,i2,i3|i3==i2 && j==0 && J2==I2+1 && 0>=N_tile+i+i2-3 && N>=8 && N_sec>=2 && N_tile>=4 && R>=0 && N_tile>=R+1 && MR>=1 && NR>=1 && I2>=0 && N_sec>=I2+2 && N_tile+i>=1 && N_tile>=i2+1 && i2>=0 && 0>=R+i}
		//{i,j,i2,i3|i3==0 && i2==0 && j==0 && J2==I2+1 && N>=8 && R>=0 && MR>=1 && NR>=1 && I2>=0 && N_sec>=I2+2 && 0>=R+i && N_tile+i>=4} || {i,j,i2,i3|i3==0 && i2==0 && j==0 && N>=8 && N_tile>=4 && R>=0 && MR>=1 && NR>=1 && I2>=0 && J2>=I2+2 && N_sec>=J2+1 && 0>=R+i && N_tile+i>=1}
		//{i,j,i2,i3|i3==i2 && j==0 && J2==I2+1 && N>=8 && N_tile>=4 && R>=0 && MR>=1 && NR>=1 && I2>=0 && N_sec>=I2+2 && 0>=R+i && N_tile+i>=1 && i2>=1 && N_tile>=i2+1 && N_tile+i+i2>=4} || {i,j,i2,i3|i3==i2 && j==0 && N>=8 && N_tile>=4 && R>=0 && MR>=1 && NR>=1 && I2>=0 && J2>=I2+2 && N_sec>=J2+1 && 0>=R+i && N_tile+i>=1 && i2>=1 && N_tile>=i2+1}
		//{i,j,i2,i3|i3==i2+1 && j==3 && N_tile+i==0 && N>=8 && N_sec>=2 && N_tile>=4 && R>=0 && N_tile>=R+1 && MR>=1 && NR>=1 && I2>=0 && J2>=I2+1 && N_sec>=J2+1 && N_tile>=i2+1 && i2>=0}
		//{i,j,i2,i3|i3==i2+1 && j==3 && N>=8 && N_sec>=2 && N_tile>=4 && R>=0 && N_tile>=R+1 && MR>=1 && NR>=1 && I2>=0 && J2>=I2+1 && N_sec>=J2+1 && i2>=1 && N_tile+i>=1 && 0>=R+i && 0>=i && N_tile>=i2+1}
		//{i,j,i2,i3|i3==1 && i2==0 && j==3 && N>=8 && N_sec>=2 && N_tile>=4 && R>=0 && N_tile>=R+1 && MR>=1 && NR>=1 && I2>=0 && J2>=I2+1 && N_sec>=J2+1 && N_tile+i>=1 && 0>=R+i && 0>=i}
		//{i,j,i2,i3|i2==-1 && 2N_tile+i==0 && N>=8 && N_sec>=2 && N_tile>=4 && R>=0 && N_tile>=R+1 && MR>=1 && NR>=1 && I2>=0 && J2>=I2+1 && N_sec>=J2+1 && j>=R && N_tile>=j+1 && i3>=0 && N_tile>=i3+1 && j>=0}
		//{i,j,i2,i3|i2==-1 && 2N_tile+i==1 && N>=8 && N_sec>=2 && N_tile>=4 && R>=0 && N_tile>=R+1 && MR>=1 && NR>=1 && I2>=0 && J2>=I2+1 && N_sec>=J2+1 && j>=R && i3>=1 && j>=0 && N_tile>=i3+1 && N_tile>=j+1}
		//{i,j,i2,i3|i2==-1 && j==1 && N>=8 && N_sec>=2 && N_tile>=4 && R>=0 && N_tile>=R+1 && MR>=1 && NR>=1 && I2>=0 && J2>=I2+1 && N_sec>=J2+1 && 0>=R+i && N_tile+i>=1 && i3>=0 && N_tile>=i3+1 && 0>=i}
		//{i,j,i2,i3|i2==-1 && j==2 && N>=8 && N_sec>=2 && N_tile>=4 && R>=0 && N_tile>=R+1 && MR>=1 && NR>=1 && I2>=0 && J2>=I2+1 && N_sec>=J2+1 && 0>=R+i && i3>=1 && 0>=i && N_tile>=i3+1 && N_tile+i>=1}
		//{i0,i1,i2,i3|2N_tile+i0==0 && i2>=i1 && N_tile>=i2+1 && N>=8 && N_sec>=2 && N_tile>=4 && R>=0 && N_tile>=R+1 && MR>=1 && NR>=1 && I2>=0 && J2>=I2+1 && N_sec>=J2+1 && i3>=0 && N_tile>=i3+1 && N_sec>=I2+1 && i1>=0 && N_tile>=i1+1 && i2>=0 && i1>=R}
		//{i0,i1,i2,i3|2N_tile+i0==1 && i2>=0 && i3>=i2+1 && N>=8 && N_sec>=2 && N_tile>=4 && R>=0 && N_tile>=R+1 && MR>=1 && NR>=1 && I2>=0 && J2>=I2+1 && N_sec>=J2+1 && i3>=1 && N_tile>=i3+1 && J2>=0 && i1>=0 && N_tile>=i1+1 && N_tile>=i2+1 && i1>=R}
		//{i0,i1,i2,i3|i1==1 && i0+i2>=0 && N_tile>=i2+1 && N>=8 && N_sec>=2 && N_tile>=4 && R>=0 && N_tile>=R+1 && MR>=1 && NR>=1 && I2>=0 && J2>=I2+1 && N_sec>=J2+1 && i3>=0 && N_tile>=i3+1 && N_sec>=I2+1 && 0>=i0 && N_tile+i0>=1 && i2>=0 && 0>=R+i0}
		//{i0,i1,i2,i3|i1==2 && i2>=0 && i3>=i2+1 && N>=8 && N_sec>=2 && N_tile>=4 && R>=0 && N_tile>=R+1 && MR>=1 && NR>=1 && I2>=0 && J2>=I2+1 && N_sec>=J2+1 && i3>=1 && N_tile>=i3+1 && J2>=0 && 0>=i0 && N_tile+i0>=1 && N_tile>=i2+1 && 0>=R+i0}
		int c1,c2,c3,c4;
		for(c2=R;c2 <= N_tile-1;c2+=1)
		 {
		 	for(c4=0;c4 <= N_tile-1;c4+=1)
		 	 {
		 	 	S11((-2*N_tile),(c2),(-1),(c4));
		 	 }
		 	for(c3=c2;c3 <= N_tile-1;c3+=1)
		 	 {
		 	 	for(c4=0;c4 <= N_tile-1;c4+=1)
		 	 	 {
		 	 	 	S8((-2*N_tile),(c2),(c3),(c4));
		 	 	 }
		 	 }
		 }
		for(c2=R;c2 <= N_tile-1;c2+=1)
		 {
		 	for(c4=1;c4 <= N_tile-1;c4+=1)
		 	 {
		 	 	S12((-2*N_tile+1),(c2),(-1),(c4));
		 	 }
		 	for(c3=0;c3 <= N_tile-2;c3+=1)
		 	 {
		 	 	for(c4=c3+1;c4 <= N_tile-1;c4+=1)
		 	 	 {
		 	 	 	S9((-2*N_tile+1),(c2),(c3),(c4));
		 	 	 }
		 	 }
		 }
		for(c3=0;c3 <= N_tile-1;c3+=1)
		 {
		 	S0((-N_tile),(0),(c3),(c3));
		 }
		for(c3=0;c3 <= N_tile-1;c3+=1)
		 {
		 	S4((-N_tile),(3),(c3),(c3+1));
		 }
		if ((I2 <= J2-2)) {
			{
				for(c1=-N_tile+1;c1 <= -R;c1+=1)
				 {
				 	S2((c1),(0),(0),(0));
				 	for(c3=1;c3 <= N_tile-1;c3+=1)
				 	 {
				 	 	S3((c1),(0),(c3),(c3));
				 	 }
				 	for(c4=0;c4 <= N_tile-1;c4+=1)
				 	 {
				 	 	S13((c1),(1),(-1),(c4));
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
				 	 	S14((c1),(2),(-1),(c4));
				 	 }
				 	for(c3=0;c3 <= N_tile-2;c3+=1)
				 	 {
				 	 	for(c4=c3+1;c4 <= N_tile-1;c4+=1)
				 	 	 {
				 	 	 	S10((c1),(2),(c3),(c4));
				 	 	 }
				 	 }
				 	S6((c1),(3),(0),(1));
				 	for(c3=1;c3 <= N_tile-1;c3+=1)
				 	 {
				 	 	S5((c1),(3),(c3),(c3+1));
				 	 }
				 }
			}
		}
		if ((I2 == J2-1)) {
			{
				for(c1=-N_tile+1;c1 <= min(-R,-N_tile+3);c1+=1)
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
				 	 	S13((c1),(1),(-1),(c4));
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
				 	 	S14((c1),(2),(-1),(c4));
				 	 }
				 	for(c3=0;c3 <= N_tile-2;c3+=1)
				 	 {
				 	 	for(c4=c3+1;c4 <= N_tile-1;c4+=1)
				 	 	 {
				 	 	 	S10((c1),(2),(c3),(c4));
				 	 	 }
				 	 }
				 	S6((c1),(3),(0),(1));
				 	for(c3=1;c3 <= N_tile-1;c3+=1)
				 	 {
				 	 	S5((c1),(3),(c3),(c3+1));
				 	 }
				 }
			}
		}
		if ((I2 == J2-1)) {
			{
				for(c1=-N_tile+4;c1 <= -R;c1+=1)
				 {
				 	S2((c1),(0),(0),(0));
				 	for(c3=1;c3 <= N_tile-1;c3+=1)
				 	 {
				 	 	S3((c1),(0),(c3),(c3));
				 	 }
				 	for(c4=0;c4 <= N_tile-1;c4+=1)
				 	 {
				 	 	S13((c1),(1),(-1),(c4));
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
				 	 	S14((c1),(2),(-1),(c4));
				 	 }
				 	for(c3=0;c3 <= N_tile-2;c3+=1)
				 	 {
				 	 	for(c4=c3+1;c4 <= N_tile-1;c4+=1)
				 	 	 {
				 	 	 	S10((c1),(2),(c3),(c4));
				 	 	 }
				 	 }
				 	S6((c1),(3),(0),(1));
				 	for(c3=1;c3 <= N_tile-1;c3+=1)
				 	 {
				 	 	S5((c1),(3),(c3),(c3+1));
				 	 }
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
	#undef S11
	#undef S12
	#undef S13
	#undef S14
	#undef S8
	#undef S9
	#undef S7
	#undef S10
	
	//Memory Free
	free(NR_C_I2_J2);
	free(NR_C_I2_J2_3);
}

//Memory Macros
#undef seq2_t
#undef S2_C
#undef C
#undef NR_C_I2_J2
#undef NR_C_I2_J2_3
#undef C_I2_J2


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
