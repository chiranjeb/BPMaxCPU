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
float reduce_matrix_max_plus_section_C_section_1(long, long, long, long, long, long, long, long, long, int, int, float**, float**);

//Memory Macros
#define A(i3,j3) A[i3][j3]
#define B(i3,j3) B[i3][j3]
#define C_section(i3,j3) C_section[i3][j3]

void matrix_max_plus_section(long M, long N, long N_sec, long N_tile, long MR, long NR, long I2, long J2, long K2, float** A, float** B, float** C_section){
	///Parameter checking
	if (!((M >= 3 && N >= 8 && N_sec >= 2 && N_tile >= 4 && MR >= 1 && NR >= 1 && I2 >= 0 && J2 >= I2 && N_sec >= J2+1 && K2 >= I2 && J2 >= K2+1))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
        //printf("\nmatrix_max_plus_section:I2:%ld, J2:%ld, K2:%ld\n", I2, J2, K2); 
	
	#define S0(i3,j3) C_section(i3,j3) = max( C_section(i3,j3), reduce_matrix_max_plus_section_C_section_1(M,N,N_sec,N_tile,MR,NR,I2,J2,K2,i3,j3,A,B))
	{
		//Domain
		//{i3,j3|N_tile>=j3+1 && N_tile>=4 && M>=3 && N>=8 && i3>=0 && j3>=0 && MR>=1 && NR>=1 && I2>=0 && N_tile>=i3+1 && N_sec>=J2+1 && K2>=I2 && J2>=K2+1 && J2>=I2 && N_sec>=2}
		int c1,c2;
		for(c1=0;c1 <= N_tile-1;c1+=1)
		 {
		 	for(c2=0;c2 <= N_tile-1;c2+=1)
		 	 {
		 	 	S0((c1),(c2));
		 	 }
		 }
	}
	#undef S0
	
        Dump2D (N_tile, A, "A");        
        Dump2D (N_tile, B, "B");     	
        //printf("\n================Done==================\n"); 
	//Memory Free
}
float reduce_matrix_max_plus_section_C_section_1(long M, long N, long N_sec, long N_tile, long MR, long NR, long I2, long J2, long K2, int i3p, int j3p, float** A, float** B){
	float reduceVar = -FLT_MAX;
	#define S1(i3,j3,k) {float __temp__ = (A(i3,k))+(B(k,j3)); reduceVar = __max_float(reduceVar,__temp__); }
	{
		//Domain
		//{i3,j3,k|N_tile>=j3p+1 && N_tile>=4 && M>=3 && N>=8 && i3p>=0 && j3p>=0 && MR>=1 && NR>=1 && I2>=0 && N_tile>=i3p+1 && N_sec>=J2+1 && K2>=I2 && J2>=K2+1 && J2>=I2 && N_sec>=2 && k>=0 && N_tile>=k+2 && N_tile>=j3+1 && j3>=0 && N_tile>=i3+1 && i3>=0 && i3p==i3 && j3p==j3}
		int c3;
		for(c3=0;c3 <= N_tile-1;c3+=1)
		 {
		 	S1((i3p),(j3p),(c3));
		 }
	}
	#undef S1
	return reduceVar;
}

//Memory Macros
#undef A
#undef B
#undef C_section


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
