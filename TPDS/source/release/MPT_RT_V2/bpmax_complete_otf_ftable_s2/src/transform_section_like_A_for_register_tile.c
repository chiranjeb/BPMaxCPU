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
#define MAX(x, y)    ((x)>(y) ? (x) : (y))
#define min(x, y)   ((x)>(y) ? (y) : (x))
#define MIN(x, y)    ((x)>(y) ? (y) : (x))
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
#define C(i3,j3) C[i3][j3]
#define A(i3,j3) A[i3][j3]

void transform_section_like_A_for_register_tile(long N, long N_sec, long N_tile, long R, long MR, long NR, long I2, long J2, float** C, float** A){
    ///Parameter checking
    if (!((N >= 8 && N_sec >= 2 && N_tile >= 4 && R >= 0 && N_tile >= R+1 && MR >= 1 && NR >= 1 && I2 >= 0 && J2 >= I2 && N_sec >= J2+1))) {
        printf("The value of parameters are not valid.\n");
        exit(-1);
    }

    if ( I2 != 0 )
       R = 0;
    long START_J=0, START_I=0;
    if ( I2 == 0 )
    {
        START_I = R;   
        if (J2 == 0) START_J = R;
    }


    
#if REGISTER_TILED_KERNEL
   //printf(" transfor A Start\n");fflush(stdout);
    if ( START_J == 0)
    {
        float *Pack = &A[START_I][0];
        for( int ii = R; ii <= N_tile-1; ii+= MR)
        {  
            int mr = min(MR, N_tile-ii);
            for( int k = 0; k <= N_tile-1; k++)
            { 
                for(int iii = 0; iii < mr; iii++ )
                {  
                    *Pack++ = C[ii+iii][k]; 
                }
            }
        }
    }
    else
    {

        /*float *Pack = &A[0][0];
            {
                    int c1,c2;
                    for(c1=0;c1 <= N_tile-1;c1+=1)
                     {
                            for(c2=0;c2 <= N_tile-1;c2+=1)
                            {
                                    *Pack++ = 0.0;
                            }
                    }
        }
       Dump2D (N_tile, A, "Transform In A: after memset A");
       */
         #define S0(i3,j3) A(i3,j3) = C(i3,j3)
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
   //printf(" transfor A Done\n");fflush(stdout);
#else
    #define S0(i3,j3) A(i3,j3) = C(i3,j3)
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
    
    Dump2D (N_tile, C, "Transform In A: C");    
    Dump2D (N_tile, A, "Transform In A: A");    
    //Memory Free
}

//Memory Macros
#undef C
#undef A


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
