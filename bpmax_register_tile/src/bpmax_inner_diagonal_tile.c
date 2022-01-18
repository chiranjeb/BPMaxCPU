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
float reduce_bpmax_inner_diagonal_tile_FTable_C_section_1(long, long, long, long, long, long, long, long, int, int, float**, float**);
float reduce_bpmax_inner_diagonal_tile_FTable_C_section_2(long, long, long, long, long, long, long, long, int, int, float**, float**);

//Memory Macros
#define seq2(i) seq2[i]
#define S2(i2,j2) S2[i2][j2]
#define FTable_C_section(i2,j2) FTable_C_section[i2][j2]

void bpmax_inner_diagonal_tile(long M, long N, long N_sec, long N_tile, long MR, long NR, long I2, long J2, int* seq2, float** S2, float** FTable_C_section){
	///Parameter checking
	if (!((M >= 16 && N >= 96 && N_sec >= 1 && N_tile >= 96 && MR >= 1 && NR >= 1 && I2 >= 0 && J2 >= I2 && N_sec >= J2+1))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	//Memory Allocation
	
	#define S0(i2,j2) FTable_C_section(i2,j2) = FTable_C_section(i2,j2)
	#define S1(i2,j2) FTable_C_section(i2,j2) = __max_float(__max_float(FTable_C_section(i2,j2),(((j2 >= i2+4))?FTable_C_section(i2+1,j2-1):(0))),__max_float(reduce_bpmax_inner_diagonal_tile_FTable_C_section_1(M,N,N_sec,N_tile,MR,NR,I2,J2,i2,j2,FTable_C_section,S2),reduce_bpmax_inner_diagonal_tile_FTable_C_section_2(M,N,N_sec,N_tile,MR,NR,I2,J2,i2,j2,S2,FTable_C_section)))
	{
		//Domain
		//{i2,j2|M>=16 && N>=96 && N_sec>=1 && N_tile>=96 && MR>=1 && NR>=1 && I2>=0 && J2>=I2 && N_sec>=J2+1 && i2>=j2 && i2>=0 && N_tile>=i2+1 && j2>=0 && N_tile>=j2+1}
		//{i2,j2|M>=16 && N>=96 && N_tile>=96 && MR>=1 && NR>=1 && I2>=0 && J2>=I2 && N_sec>=J2+1 && j2>=i2+1 && N_tile>=j2+1 && i2>=0}
		int c1,c2;
		for(c1=0;c1 <= N_tile-2;c1+=1)
		 {
		 	for(c2=0;c2 <= c1;c2+=1)
		 	 {
		 	 	S0((c1),(c2));
		 	 }
		 	for(c2=c1+1;c2 <= N_tile-1;c2+=1)
		 	 {
		 	 	S1((c1),(c2));
		 	 }
		 }
		for(c2=0;c2 <= N_tile-1;c2+=1)
		 {
		 	S0((N_tile-1),(c2));
		 }
	}
	#undef S0
	#undef S1
	
	//Memory Free
}
float reduce_bpmax_inner_diagonal_tile_FTable_C_section_1(long M, long N, long N_sec, long N_tile, long MR, long NR, long I2, long J2, int i2p, int j2p, float** FTable_C_section, float** S2){
	float reduceVar = -FLT_MAX;
	#define S_2(i2,j2,k2) {float __temp__ = (FTable_C_section(i2,k2))+(S2(k2+1,j2)); reduceVar = __max_float(reduceVar,__temp__); }
	{
		//Domain
		//{i2,j2,k2|i2p>=0 && j2p>=i2p+1 && M>=16 && N>=96 && N_tile>=j2p+1 && N_tile>=96 && MR>=1 && NR>=1 && I2>=0 && J2>=I2 && N_sec>=J2+1 && k2>=i2 && j2>=k2+1 && j2>=i2+1 && N_tile>=j2+1 && N_sec>=1 && j2>=0 && N_tile>=k2+2 && k2>=0 && N_tile>=i2+1 && i2>=0 && i2p==i2 && j2p==j2}
		int c3;
		for(c3=i2p;c3 <= j2p-1;c3+=1)
		 {
		 	S_2((i2p),(j2p),(c3));
		 }
	}
	#undef S_2
	return reduceVar;
}
float reduce_bpmax_inner_diagonal_tile_FTable_C_section_2(long M, long N, long N_sec, long N_tile, long MR, long NR, long I2, long J2, int i2p, int j2p, float** S2, float** FTable_C_section){
	float reduceVar = -FLT_MAX;
	#define S_2(i2,j2,k2) {float __temp__ = (S2(i2,k2))+(FTable_C_section(k2+1,j2)); reduceVar = __max_float(reduceVar,__temp__); }
	{
		//Domain
		//{i2,j2,k2|i2p>=0 && j2p>=i2p+1 && M>=16 && N>=96 && N_tile>=j2p+1 && N_tile>=96 && MR>=1 && NR>=1 && I2>=0 && J2>=I2 && N_sec>=J2+1 && k2>=i2 && j2>=k2+1 && j2>=i2+1 && N_tile>=j2+1 && N_sec>=1 && j2>=0 && N_tile>=k2+2 && k2>=0 && N_tile>=i2+1 && i2>=0 && i2p==i2 && j2p==j2}
		int c3;
		for(c3=i2p;c3 <= j2p-1;c3+=1)
		 {
		 	S_2((i2p),(j2p),(c3));
		 }
	}
	#undef S_2
	return reduceVar;
}

//Memory Macros
#undef seq2
#undef S2
#undef FTable_C_section


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
