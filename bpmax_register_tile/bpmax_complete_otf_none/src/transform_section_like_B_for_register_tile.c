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



void Dump2D_l(int M, float **Tab, const char *message)
{
#if DEBUG
       printf("-----------------------------------------------------------------------\n");
       printf("%s\n", message);
       printf("-----------------------------------------------------------------------\n");
       for ( int i = 0; i < M+1; i++)
       {
            for (int j = 0; j < M; j++ )
            {
               printf(" %9.3e", Tab[i][j]); //printf("%4e ", Tab[i][j]);
            }
            printf("\n");
     }
#endif
}



//Memory Macros
#define C(i3,j3) C[i3][j3]
#define B(i3,j3) B[i3][j3]

void transform_section_like_B_for_register_tile(long N, long N_sec, long N_tile, long R, long MR, long NR, long I2, long J2, float** C, float** B){
	///Parameter checking
	if (!((N >= 8 && N_sec >= 2 && N_tile >= 4 && R >= 0 && N_tile >= R+1 && MR >= 1 && NR >= 1 && I2 >= 0 && J2 >= I2 && N_sec >= J2+1))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	//Memory Allocation
#if REGISTER_TILED_KERNEL
    //printf(" transfor B Start\n");fflush(stdout);
    float *Pack = &B[0][0];
    if ( I2 !=0 && J2 !=0)
       R = 0;   
    
    long START_I=0;
    if ( I2 == 0 )
    {
        START_I = R;
    }

    if ( START_I == 0)
    {
        for( int jj = 0; jj <= N_tile-1; jj+= NR)
        {
		    for ( int ii = 1 ; ii <= N_tile ; ii++ )
		    {
			    const float *Cptr = &C[ii][jj];
			    for (int jjj = 0; jjj < NR; jjj++)
			    {
                    //printf("B: jj(%d), ii(%d), jjj(%d)\n", jj, ii, jjj);fflush(stdout);
				    *Pack++ = *Cptr++;
			    }
		    }
        }
    }
    else
    {
	    #define S0(i3,j3) B(i3,j3) = C(i3+1,j3)
	    {
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
    }

   //printf(" transfor B End\n");fflush(stdout);
#else
	#define S0(i3,j3) B(i3,j3) = C(i3+1,j3)
	{
		//Domain
		//{i3,j3|i3>=0 && N_tile>=i3+1 && j3>=0 && N_tile>=j3+1 && N>=8 && N_sec>=2 && N_tile>=4 && R>=0 && N_tile>=R+1 && MR>=1 && NR>=1 && I2>=0 && J2>=I2 && N_sec>=J2+1}
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
#endif
    Dump2D_l (N_tile, C, "Transform In B: C");
    Dump2D (N_tile, B, "Transform In B: B");
	
	//Memory Free
}

//Memory Macros
#undef C
#undef B


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
