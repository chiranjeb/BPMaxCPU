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




//SubSystem Function Declarations
void bpmax_matrix_max_plus_collections(long, long, long, long, long, long, long, long, long, long, float******, float******, float****);


//Memory Macros
#define FTable_6D_1(i2,j2,i3,j3,i4,j4) FTable_6D_1[i2][j2][i3][j3][i4][j4]
#define FTable_6D_2(i2,j2,i3,j3,i4,j4) FTable_6D_2[i2][j2][i3][j3][i4][j4]
#define FTable_6D(i2,j2,i3,j3,i4,j4) FTable_6D[i2][j2][i3][j3][i4][j4]

void bpmax_max_r0_r3_r4_instance(long M, long N, long N_sec, long N_tile, long N_tile_div_MR, long N_tile_div_NR, long MR, long NR, float****** FTable_6D_1, float****** FTable_6D_2, float****** FTable_6D){
	///Parameter checking
	if (!((M >= 16 && N >= 96 && N_sec >= 1 && N_tile >= 96 && N_tile_div_MR >= 1 && N_tile_div_NR >= 1 && MR >= 1 && NR >= 1))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	//Memory Allocation
	
	#define S0(i,j,i2,i3,i4,i5) bpmax_matrix_max_plus_collections(M,N,N_sec,N_tile,N_tile_div_MR,N_tile_div_NR,MR,NR,i,j,FTable_6D_1,FTable_6D_2,FTable_6D[i][j])
	{
		//Domain
		//{i,j,i2,i3,i4,i5|i5==0 && i4==0 && i3==0 && i2==0 && i>=0 && j>=i && N_sec>=j+1 && M>=16 && N>=96 && N_sec>=1 && N_tile>=96 && N_tile_div_MR>=1 && N_tile_div_NR>=1 && MR>=1 && NR>=1}
		int c1,c2;
		for(c1=0;c1 <= N_sec-1;c1+=1)
		 {
		 	for(c2=c1;c2 <= N_sec-1;c2+=1)
		 	 {
		 	 	S0((c1),(c2),(0),(0),(0),(0));
		 	 }
		 }
	}
	#undef S0
	
	//Memory Free
}

//Memory Macros
#undef FTable_6D_1
#undef FTable_6D_2
#undef FTable_6D


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
