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
void bpmax_inner_reductions_diagonal_tile(long, long, long, long, long, long, long, int**, float**, float**);
void matrix_max_plus_section(long, long, long, long, long, long, long, long, float**, float**, float**);
void bpmax_inner_reductions_finalize(long, long, long, long, long, long, long, int**, float****, float****, float**);
void transform_section_like_A_for_register_tile(long, long, long, long, long, long, long, float**, float**);
void transform_section_like_B_for_register_tile(long, long, long, long, long, long, long, float**, float**);


//Memory Macros
#define seq2_t(i,j) seq2_t[i][j]
#define S2_A(i2,j2,i3,j3) S2_A[i2][j2][i3][j3]
#define S2_B(i2,j2,i3,j3) S2_B[i2][j2][i3][j3]
#define S2_C(i2,j2,i3,j3) S2_C[i2][j2][i3][j3]
#define FTable_C(i2,j2,i3,j3) FTable_C[i2][j2][i3][j3]
#define FTable_A(i2,j2,i3,j3) FTable_A[i2][j2][i3][j3]
#define FTable_B(i2,j2,i3,j3) FTable_B[i2][j2][i3][j3]

void bpmax_inner_reductions(long M, long N, long N_sec, long N_tile, long MR, long NR, long I1, long J1, int** seq2_t, float**** S2_A, float**** S2_B, float**** S2_C, float**** FTable_C, float**** FTable_A, float**** FTable_B){
	///Parameter checking
	if (!((M >= 1 && N >= 8 && N_sec >= 2 && N_tile >= 4 && MR >= 1 && NR >= 1 && I1 >= 0 && J1 >= I1 && M >= J1+1))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	//Memory Allocation
	int mz1, mz2, mz3, mz4, mz5;
	
	
    Dump4D(N_sec, N_tile+1, N_tile, S2_C, "*************S2 C******************");
    Dump4D(N_sec, N_tile,   N_tile, S2_B, "*************S2 B******************");
    Dump4D(N_sec, N_tile,   N_tile, S2_A, "*************S2 A******************");
	#define S0(i,j,i2,i3) bpmax_inner_reductions_diagonal_tile(N,N_sec,N_tile,MR,NR,-i,j,seq2_t,S2_C[-i][j],FTable_C[-i][j])
	#define S1(i,j,k,i3) { Dump2D(N_tile, S2_A[-i][j], "mm:S2_A");   Dump2D(N_tile, FTable_B[j][i3], "mm:FTable_B");    matrix_max_plus_section(N,N_sec,N_tile,MR,NR,-i,i3,j,S2_A[-i][j],FTable_B[j][i3],FTable_C[-i][i3]);}
	#define S2(i,j,k,i3) { Dump2D(N_tile, FTable_A[-i][j], "mm:FTable_A");   Dump2D(N_tile, S2_B[j][i3], "mm:S2_B");         matrix_max_plus_section(N,N_sec,N_tile,MR,NR,-i,i3,j,FTable_A[-i][j],S2_B[j][i3],FTable_C[-i][i3]);}
	#define S3(i,j,i2,i3) bpmax_inner_reductions_finalize(N,N_sec,N_tile,MR,NR,-i,j,seq2_t,S2_C,FTable_C,FTable_C[-i][j])
	#define S4(i,j,i2,i3) transform_section_like_A_for_register_tile(N,N_sec,N_tile,MR,NR,-i,j,FTable_C[-i][j],FTable_A[-i][j])
	#define S5(i,j,i2,i3) transform_section_like_B_for_register_tile(N,N_sec,N_tile,MR,NR,-i,j,FTable_C[-i][j],FTable_B[-i][j])
	{
		//Domain
		//{i,j,i2,i3|i+i3==0 && i2==0 && i+j==0 && 0>=i && N_sec+i>=1 && M>=1 && N>=8 && N_sec>=2 && N_tile>=4 && MR>=1 && NR>=1 && I1>=0 && J1>=I1 && M>=J1+1}
		//{i,j,k,i3|k==3 && 0>=i && i+i3>=1 && N_sec>=i3+1 && i+j>=1 && i3>=j+1 && M>=1 && N>=8 && N_sec>=2 && N_tile>=4 && MR>=1 && NR>=1 && I1>=0 && J1>=I1 && M>=J1+1}
		//{i,j,k,i3|k==4 && 0>=i && i+i3>=1 && N_sec>=i3+1 && i+j>=1 && i3>=j+1 && M>=1 && N>=8 && N_sec>=2 && N_tile>=4 && MR>=1 && NR>=1 && I1>=0 && J1>=I1 && M>=J1+1}
		//{i,j,i2,i3|i3==j && i2==0 && 0>=i && i+j>=1 && N_sec>=j+1 && M>=1 && N>=8 && N_sec>=2 && N_tile>=4 && MR>=1 && NR>=1 && I1>=0 && J1>=I1 && M>=J1+1}
		//{i,j,i2,i3|i3==j && i2==2 && 0>=i && i+j>=0 && N_sec>=j+1 && M>=1 && N>=8 && N_sec>=2 && N_tile>=4 && MR>=1 && NR>=1 && I1>=0 && J1>=I1 && M>=J1+1}
		//{i,j,i2,i3|i3==j && i2==1 && 0>=i && i+j>=0 && N_sec>=j+1 && M>=1 && N>=8 && N_sec>=2 && N_tile>=4 && MR>=1 && NR>=1 && I1>=0 && J1>=I1 && M>=J1+1}
		int c1,c2,c4;
        Dump2D(N_tile, FTable_C[N_sec-2][N_sec-1], "top corner"); 
        Dump2D(N_tile, FTable_C[N_sec-1][N_sec-1], "Sending"); 
		S0((-N_sec+1),(N_sec-1),(0),(N_sec-1));
		S5((-N_sec+1),(N_sec-1),(1),(N_sec-1));
		S4((-N_sec+1),(N_sec-1),(2),(N_sec-1));
        Dump2D(N_tile, FTable_C[N_sec-1][N_sec-1], "FInalized"); 
        Dump2D(N_tile, FTable_C[N_sec-2][N_sec-1], "top corner"); 
        Dump2D(N_tile, FTable_C[N_sec-2][N_sec-2], "Sending"); 
		S0((-N_sec+2),(N_sec-2),(0),(N_sec-2));
		S5((-N_sec+2),(N_sec-2),(1),(N_sec-2));
		S4((-N_sec+2),(N_sec-2),(2),(N_sec-2));
        Dump2D(N_tile, FTable_C[N_sec-2][N_sec-2], "Finalized"); 
        Dump2D(N_tile, FTable_C[N_sec-2][N_sec-1], "Sending for finalize top corner"); 
		S3((-N_sec+2),(N_sec-1),(0),(N_sec-1));
		S5((-N_sec+2),(N_sec-1),(1),(N_sec-1));
		S4((-N_sec+2),(N_sec-1),(2),(N_sec-1));
        Dump4D(N_sec, N_tile+1, N_tile, FTable_C, "*************FTable C******************"); 
        Dump4D(N_sec, N_tile,   N_tile, FTable_B, "*************FTable B******************"); 
        Dump4D(N_sec, N_tile,   N_tile, FTable_A, "*************FTable A******************"); 
		for(c1=-N_sec+3;c1 <= 0;c1+=1)
		 {
		 	S0((c1),(-c1),(0),(-c1));
		 	S5((c1),(-c1),(1),(-c1));
		 	S4((c1),(-c1),(2),(-c1));
                Dump4D(N_sec, N_tile+1, N_tile, FTable_C, "*************FTable C******************");
                Dump4D(N_sec, N_tile,   N_tile, FTable_B, "*************FTable B******************");
                Dump4D(N_sec, N_tile,   N_tile, FTable_A, "*************FTable A******************");
		 	for(c2=-c1+1;c2 <= N_sec-2;c2+=1)
		 	 {
		 	 	S3((c1),(c2),(0),(c2));
		 	 	S5((c1),(c2),(1),(c2));
		 	 	S4((c1),(c2),(2),(c2));
                Dump4D(N_sec, N_tile+1, N_tile, FTable_C, "*************FTable C******************");
                Dump4D(N_sec, N_tile,   N_tile, FTable_B, "*************FTable B******************");
                Dump4D(N_sec, N_tile,   N_tile, FTable_A, "*************FTable A******************");
		 	 	for(c4=c2+1;c4 <= N_sec-1;c4+=1)
		 	 	 {
		 	 	 	S1((c1),(c2),(3),(c4));
		 	 	 }
		 	 	for(c4=c2+1;c4 <= N_sec-1;c4+=1)
		 	 	 {
		 	 	 	S2((c1),(c2),(4),(c4));
		 	 	 }
		 	 }
		 	S3((c1),(N_sec-1),(0),(N_sec-1));
		 	S5((c1),(N_sec-1),(1),(N_sec-1));
		 	S4((c1),(N_sec-1),(2),(N_sec-1));
            Dump4D(N_sec, N_tile+1, N_tile, FTable_C, "*************FTable C******************");
            Dump4D(N_sec, N_tile,   N_tile, FTable_B, "*************FTable B******************");
            Dump4D(N_sec, N_tile,   N_tile, FTable_A, "*************FTable A******************");
		 }
	}
	#undef S0
	#undef S1
	#undef S2
	#undef S3
	#undef S4
	#undef S5
	
}

//Memory Macros
#undef seq2_t
#undef S2_A
#undef S2_B
#undef S2_C
#undef FTable_C
#undef FTable_A
#undef FTable_B


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
