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

//Memory Macros
#define A(i3,j3) A[i3][j3]
#define B(i3,j3) B[i3][j3]
#define C(i3,j3) C[i3][j3]

void matrix_max_plus(long N, long N_sec, long N_tile, long START_I, long START_K, long START_J, long MR, long NR, long I2, long J2, long K2, float** A, float** B, float** C){
	///Parameter checking
	if (!((N >= 8 && N_sec >= 2 && N_tile >= 4 && START_I >= 0 && N_tile >= START_I+1 && START_J >= 0 && N_tile >= START_J+1 && START_K >= 0 && N_tile >= START_K+1 && MR >= 1 && NR >= 1 && I2 >= 0 && J2 >= I2 && N_sec >= J2+1 && K2 >= I2 && J2 >= K2))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}

	
#if REGISTER_TILED_KERNEL
    float *m_PackA = &A[0][0];
    float *m_PackB = &B[0][0];
    float *C_1D = &C[0][0];
    for ( int jj=0; jj<N_tile; jj+=NR )
	{
        for ( int ii=0; ii<N_tile; ii+=MR )
        {
            if ( MR == 3 && NR == 24)
            {
                register_tile_3_24( N_tile, &m_PackA[ii*N_tile], &m_PackB[jj*N_tile], &C_1D[ii * N_tile + jj], 0, 0, N_tile );
            }
            else if ( MR == 2 && NR == 24)
            {
                register_tile_2_24( N_tile, &m_PackA[ii*N_tile], &m_PackB[jj*N_tile], &C_1D[ii * N_tile + jj], 0, 0, N_tile );
            }
            else if ( MR == 3 && NR == 16)
            {
                register_tile_3_16( N_tile, &m_PackA[ii*N_tile], &m_PackB[jj*N_tile], &C_1D[ii * N_tile + jj], 0, 0, N_tile );
            }
            else if ( MR == 4 && NR == 16)
            {
                register_tile_4_16( N_tile, &m_PackA[ii*N_tile], &m_PackB[jj*N_tile], &C_1D[ii * N_tile + jj], 0, 0, N_tile );
            }
            else
            {
                printf("\n************ Unknown Register Tile ********************");
		        exit(-1);
            }
        }
    }
#else
	#define S1(i,j,i2) //C(j,i2) = 1.401298464324817E-45
	#define S0(i0,i1,i2) {float __temp__ = (A(i0,i1))+(B(i1,i2)); C(i0,i2) = __max_float(C(i0,i2),__temp__); }
	{
		//Domain
		//{i,j,i2|i==-1 && N>=8 && N_sec>=2 && N_tile>=4 && START_I>=0 && N_tile>=START_I+1 && START_J>=0 && N_tile>=START_J+1 && START_K>=0 && N_tile>=START_K+1 && MR>=1 && NR>=1 && I2>=0 && J2>=I2 && N_sec>=J2+1 && K2>=I2 && J2>=K2 && j>=START_I && N_tile>=j+1 && i2>=START_J && N_tile>=i2+1}
		//{i0,i1,i2|i1>=0 && N_tile>=i1+1 && N>=8 && N_sec>=2 && N_tile>=4 && START_I>=0 && N_tile>=START_I+1 && START_J>=0 && N_tile>=START_J+1 && START_K>=0 && N_tile>=START_K+1 && MR>=1 && NR>=1 && I2>=0 && J2>=I2 && N_sec>=J2+1 && K2>=I2 && J2>=K2 && i0>=START_I && N_tile>=i0+1 && i1>=START_K && i2>=START_J && N_tile>=i2+1}
		int c1,c2,c3;
		for(c2=START_I;c2 <= N_tile-1;c2+=1)
		 {
		 	for(c3=START_J;c3 <= N_tile-1;c3+=1)
		 	 {
		 	 	S1((-1),(c2),(c3));
		 	 }
		 }
		for(c1=START_I;c1 <= N_tile-1;c1+=1)
		 {
		 	for(c2=START_K;c2 <= N_tile-1;c2+=1)
		 	 {
		 	 	for(c3=START_J;c3 <= N_tile-1;c3+=1)
		 	 	 {
		 	 	 	S0((c1),(c2),(c3));
		 	 	 }
		 	 }
		 }
	}
    #undef S1
    #undef S0
#endif
}

void matrix_max_plus_section(long N, long N_sec, long N_tile, long R, long MR, long NR, long I2, long J2, long K2, float** A, float** B, float** C_section){
	///Parameter checking
	if (!((N >= 8 && N_sec >= 2 && N_tile >= 4 && R >= 0 && N_tile >= R+1 && MR >= 1 && NR >= 1 && I2 >= 0 && J2 >= I2 && N_sec >= J2+1 && K2 >= I2 && J2 >= K2))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}

    long START_I, START_K, START_J;
    START_I = START_K = START_J = 0;
    if ( I2 == 0)
    {
        START_I = R;
        if ( K2 == 0) START_K = R;
        if ( J2 == 0) START_J = R;
    }
    matrix_max_plus(N, N_sec, N_tile, START_I, START_K, START_J, MR, NR, I2, J2, K2, A, B, C_section);
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
