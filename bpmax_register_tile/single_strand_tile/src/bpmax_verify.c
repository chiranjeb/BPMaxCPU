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



///Global Variables
static int* seq2;
static float** S2;
static char** _flag_S2;


//Local Function Declarations
float reduce_bpmax_verify_S2_1(long, long, long, long, long, long, int, int);
float eval_S2(long, long, long, long, long, long, int, int);

//Memory Macros
#define seq2(i) seq2[i]
#define S2(i,j) S2[i][j]
#define _flag_S2(i,j) _flag_S2[i][j]

void bpmax_verify(long M, long N, long N_sec, long N_tile, long MR, long NR, int* _local_seq2, float** _local_S2){
	///Parameter checking
	if (!((M >= 3 && N >= 16 && N_sec >= 4 && N_tile >= 4 && MR >= 1 && NR >= 1))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	//Copy to global
	seq2 = _local_seq2;
	S2 = _local_S2;
	
	//Memory Allocation
	int mz1, mz2;
	
	char* _lin__flag_S2 = (char*)malloc(sizeof(char)*((N) * (N)));
	mallocCheck(_lin__flag_S2, ((N) * (N)), char);
	_flag_S2 = (char**)malloc(sizeof(char*)*(N));
	mallocCheck(_flag_S2, (N), char*);
	for (mz1=0;mz1 < N; mz1++) {
		_flag_S2[mz1] = &_lin__flag_S2[(mz1*(N))];
	}
	memset(_lin__flag_S2, 'N', ((N) * (N)));
	#define S0(i,j) eval_S2(M,N,N_sec,N_tile,MR,NR,i,j)
	{
		//Domain
		//{i,j|i>=0 && j>=i && N>=j+1 && M>=3 && N>=16 && N_sec>=4 && N_tile>=4 && MR>=1 && NR>=1}
		int c1,c2;
		for(c1=0;c1 <= N-1;c1+=1)
		 {
		 	for(c2=c1;c2 <= N-1;c2+=1)
		 	 {
		 	 	S0((c1),(c2));
		 	 }
		 }
	}
	#undef S0
	
	//Memory Free
	free(_lin__flag_S2);
	free(_flag_S2);
}
float reduce_bpmax_verify_S2_1(long M, long N, long N_sec, long N_tile, long MR, long NR, int ip, int jp){
	float reduceVar = -FLT_MAX;
	#define S0(i,j,k) {float __temp__ = (eval_S2(M,N,N_sec,N_tile,MR,NR,i,k))+(eval_S2(M,N,N_sec,N_tile,MR,NR,k+1,j)); reduceVar = __max_float(reduceVar,__temp__); }
	{
		//Domain
		//{i,j,k|M>=3 && N>=16 && N_sec>=4 && N_tile>=4 && MR>=1 && NR>=1 && N>=jp+1 && ip>=0 && jp>=ip+4 && jp>=0 && N>=ip+1 && j>=i+4 && j>=0 && N>=i+1 && k>=-1 && N>=j+1 && N>=k+1 && j>=k+1 && i>=0 && k>=i && ip==i && jp==j}
		int c3;
		for(c3=ip;c3 <= jp-1;c3+=1)
		 {
		 	S0((ip),(jp),(c3));
		 }
	}
	#undef S0
	return reduceVar;
}
float eval_S2(long M, long N, long N_sec, long N_tile, long MR, long NR, int i, int j){
	if ( _flag_S2(i,j) == 'N' ) {
		_flag_S2(i,j) = 'I';
	//Body for S2
		S2(i,j) = (((i >= j-3))?0:(__max_float((eval_S2(M,N,N_sec,N_tile,MR,NR,i+1,j-1))+(e_intra_score(seq2(-i+N-1),seq2(-j+N-1))),reduce_bpmax_verify_S2_1(M,N,N_sec,N_tile,MR,NR,i,j))));
		_flag_S2(i,j) = 'F';
	} else if ( _flag_S2(i,j) == 'I' ) {
		printf("There is a self dependence on S2 at (%d,%d) \n",i,j);
		exit(-1);
	}
	return S2(i,j);
}

//Memory Macros
#undef seq2
#undef S2
#undef _flag_S2


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
