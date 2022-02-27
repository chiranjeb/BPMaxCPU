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




//SubSystem Function Declarations
void matrix_max_plus_section(long, long, long, long, long, long, long, long, long, float**, float**, float**);
void bpmax_inner_reductions_finalize(long, long, long, long, long, long, long, long, int**, float****, float****, float**);
void transform_section_like_B_for_register_tile(long, long, long, long, long, long, long, long, float**, float**);
void transform_section_like_A_for_register_tile(long, long, long, long, long, long, long, long, float**, float**);
void bpmax_inner_reductions_diagonal_tile(long, long, long, long, long, long, long, long, int**, float**, float**);


//Memory Macros
#define seq2_t(i,j) seq2_t[i][j]
#define S2_A(i2,j2,i3,j3) S2_A[i2][j2][i3][j3]
#define S2_B(i2,j2,i3,j3) S2_B[i2][j2][i3][j3]
#define S2_C(i2,j2,i3,j3) S2_C[i2][j2][i3][j3]
#define FTable_A(i,i3,j3) FTable_A[i][i3][j3]
#define FTable_B(i,i3,j3) FTable_B[i][i3][j3]

#define FTable_C(i2,j2,i3,j3) FTable_C[i2][j2][i3][j3]

void bpmax_inner_reductions(long M, long N, long N_sec, long N_tile, long R, long MR, long NR, long P, long I1, long J1, int** seq2_t, float**** S2_A, float**** S2_B, float**** S2_C, float*** FTable_A, float*** FTable_B, float**** FTable_C){
	///Parameter checking
	if (!((M >= 1 && N >= 8 && N_sec >= 2 && N_tile >= 4 && R >= 0 && N_tile >= R+1 && MR >= 1 && NR >= 1 && P >= 1 && 0 >= P-128 && I1 >= 0 && J1 >= I1 && M >= J1+1))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	//Memory Allocation
#if OUTER_REDUCTIONS_TIMING
    struct timeval time;
    double elapsed_time;
    gettimeofday(&time, NULL);
    elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000) - elapsed_time;
#endif

	#define S0(i,j,k,i3,i4) matrix_max_plus_section(N,N_sec,N_tile,(-i==0)?R:0,MR,NR,-i,i3,j,S2_A[-i][j],FTable_B[0],FTable_C[-i][i3])
	#define S1(i,j,k,i3,i4) matrix_max_plus_section(N,N_sec,N_tile,(-i==0)?R:0,MR,NR,-i,i3,j,FTable_A[0],S2_B[j][i3],FTable_C[-i][i3])
	#define S2(i,j,i2,i3,i4) bpmax_inner_reductions_finalize(N,N_sec,N_tile,(-i==0)?R:0,MR,NR,-i,j,seq2_t,S2_C,FTable_C,FTable_C[-i][j])
	#define S3(i,j,k,i3,i4) transform_section_like_B_for_register_tile(N,N_sec,N_tile,R,MR,NR,-i,i3,FTable_C[j][i3],FTable_B[0])
	#define S4(i,j,i2,i3,i4) transform_section_like_A_for_register_tile(N,N_sec,N_tile,R,MR,NR,-i,j,FTable_C[-i][j],FTable_A[0])
	#define S5(i,j,i2,i3,i4) bpmax_inner_reductions_diagonal_tile(N,N_sec,N_tile,(-i == 0)?R:0,MR,NR,-i,j,seq2_t,S2_C[-i][j],FTable_C[-i][j])
	{
		//Domain
		//{i,j,k,i3,i4|i4==1 && k==3 && 0>=i && i+i3>=1 && N_sec>=i3+1 && i+j>=1 && i3>=j+1 && M>=1 && N>=8 && N_sec>=2 && N_tile>=4 && R>=0 && N_tile>=R+1 && MR>=1 && NR>=1 && P>=1 && 0>=P-128 && I1>=0 && J1>=I1 && M>=J1+1}
		//{i,j,k,i3,i4|i4==0 && k==5 && 0>=i && i+i3>=1 && N_sec>=i3+1 && i+j>=1 && i3>=j+1 && M>=1 && N>=8 && N_sec>=2 && N_tile>=4 && R>=0 && N_tile>=R+1 && MR>=1 && NR>=1 && P>=1 && 0>=P-128 && I1>=0 && J1>=I1 && M>=J1+1}
		//{i,j,i2,i3,i4|i4==0 && i3==j && i2==0 && 0>=i && i+j>=1 && N_sec>=j+1 && M>=1 && N>=8 && N_sec>=2 && N_tile>=4 && R>=0 && N_tile>=R+1 && MR>=1 && NR>=1 && P>=1 && 0>=P-128 && I1>=0 && J1>=I1 && M>=J1+1}
		//{i,j,k,i3,i4|i4==0 && k==3 && 0>=i && i+i3>=1 && N_sec>=i3+1 && i+j>=1 && i3>=j+1 && M>=1 && N>=8 && N_sec>=2 && N_tile>=4 && R>=0 && N_tile>=R+1 && MR>=1 && NR>=1 && P>=1 && 0>=P-128 && I1>=0 && J1>=I1 && M>=J1+1}
		//{i,j,i2,i3,i4|i4==0 && i3==j && i2==4 && 0>=i && i+j>=1 && N_sec>=j+1 && M>=1 && N>=8 && N_sec>=2 && N_tile>=4 && R>=0 && N_tile>=R+1 && MR>=1 && NR>=1 && P>=1 && 0>=P-128 && I1>=0 && J1>=I1 && M>=J1+1}
		//{i,j,i2,i3,i4|i4==0 && i+i3==0 && i2==0 && i+j==0 && 0>=i && N_sec+i>=1 && M>=1 && N>=8 && N_sec>=2 && N_tile>=4 && R>=0 && N_tile>=R+1 && MR>=1 && NR>=1 && P>=1 && 0>=P-128 && I1>=0 && J1>=I1 && M>=J1+1}
		int c1,c2,c4;
		S5((-N_sec+1),(N_sec-1),(0),(N_sec-1),(0));
		S5((-N_sec+2),(N_sec-2),(0),(N_sec-2),(0));
		S2((-N_sec+2),(N_sec-1),(0),(N_sec-1),(0));
		S4((-N_sec+2),(N_sec-1),(4),(N_sec-1),(0));
		for(c1=-N_sec+3;c1 <= 0;c1+=1)
		 {
		 	S5((c1),(-c1),(0),(-c1),(0));
		 	for(c2=-c1+1;c2 <= N_sec-2;c2+=1)
		 	 {
		 	 	S2((c1),(c2),(0),(c2),(0));
		 	 	for(c4=c2+1;c4 <= N_sec-1;c4+=1)
		 	 	 {
		 	 	 	S3((c1),(c2),(3),(c4),(0));
		 	 	 	S0((c1),(c2),(3),(c4),(1));
		 	 	 }
		 	 	S4((c1),(c2),(4),(c2),(0));
		 	 	for(c4=c2+1;c4 <= N_sec-1;c4+=1)
		 	 	 {
		 	 	 	S1((c1),(c2),(5),(c4),(0));
		 	 	 }
		 	 }
		 	S2((c1),(N_sec-1),(0),(N_sec-1),(0));
		 	S4((c1),(N_sec-1),(4),(N_sec-1),(0));
		 }
#if OUTER_REDUCTIONS_TIMING
	gettimeofday(&time, NULL);
    elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000) - elapsed_time;
    printf("==>Inner Reductions for FTable(%d, %d): Execution time : %lf sec. GFLOPS: %f\n", I1, J1, elapsed_time, ((double)2*N*N*N*1E-9)/ (6*elapsed_time));
#endif
	}
	#undef S0
	#undef S1
	#undef S2
	#undef S3
	#undef S4
	#undef S5
	
	//Memory Free
	
	
	
	

	

}

//Memory Macros
#undef seq2_t
#undef S2_A
#undef S2_B
#undef S2_C
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
