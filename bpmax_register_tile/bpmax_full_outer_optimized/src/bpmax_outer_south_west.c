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
       printf("-----------------------------------------------------------------------\n");
       printf("%s\n", message);
       printf("-----------------------------------------------------------------------\n");
       for ( int i = 0; i < M; i++)
       {
            for (int j = 0; j < M; j++ )
            {
               if ( i <= j) printf("%7.3f", Tab[i][j]); //printf("%4e ", Tab[i][j]);
               else        printf("%7.3f", 0.0); //printf( "%4e ", 0.0);
            }
            printf("\n");
     }
}

//Memory Macros
#define seq1(i) seq1[i]
#define S1(i,j) S1[i][j]
#define FTable_section(i3,j3) FTable_section[i3][j3]
#define FTable_C_section(i3,j3) FTable_C_section[i3][j3]

void bpmax_outer_south_west(long M, long N, long N_sec, long N_tile, long MR, long NR, long I1, long J1, long K1, long I2, long J2, int* seq1, float** S1, float** FTable_section, float** FTable_C_section){
	///Parameter checking
	if (!((M >= 1 && N >= 8 && N_sec >= 2 && N_tile >= 4 && MR >= 1 && NR >= 1 && I1 >= 0 && J1 >= I1 && M >= J1+1 && K1 >= I1 && J1 >= K1+1 && I2 >= 0 && J2 >= I2 && N_sec >= J2+1))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	//Memory Allocation

        //Dump2D_l ( N_tile, FTable_C_section, "Before");	
	//fflush(stdout);
	#define S0(i3,j3) FTable_C_section(i3,j3) = FTable_C_section(i3,j3)
	#define S_1(i3,j3) FTable_C_section(i3,j3) = __max_float(FTable_C_section(i3,j3),(FTable_section(i3,j3))+(e_intra_score(seq1(I1),seq1(J1))))
	{
		//Domain
		//{i3,j3|M>=1 && N>=8 && N_sec>=2 && N_tile>=4 && MR>=1 && NR>=1 && I1>=0 && J1>=I1 && M>=J1+1 && K1>=I1 && J1>=K1+1 && I2>=0 && J2>=I2 && N_sec>=J2+1 && I1>=J1-3 && i3>=0 && N_tile>=i3+1 && j3>=0 && N_tile>=j3+1}
		//{i3,j3|M>=1 && N>=8 && N_sec>=2 && N_tile>=4 && MR>=1 && NR>=1 && I1>=0 && J1>=I1+4 && M>=J1+1 && K1>=I1 && J1>=K1+1 && I2>=0 && J2>=I2 && N_sec>=J2+1 && i3>=0 && N_tile>=i3+1 && j3>=0 && N_tile>=j3+1 && M>=I1+1 && J1>=0}
		int c1,c2;
		if ((I1 <= J1-4)) {
			{
				for(c1=0;c1 <= N_tile-1;c1+=1)
				 {
				 	for(c2=0;c2 <= N_tile-1;c2+=1)
				 	 {
				 	 	S_1((c1),(c2));
				 	 }
				 }
			}
		}
		if ((I1 >= J1-3)) {
			{
				for(c1=0;c1 <= N_tile-1;c1+=1)
				 {
				 	for(c2=0;c2 <= N_tile-1;c2+=1)
				 	 {
				 	 	S0((c1),(c2));
				 	 }
				 }
			}
		}
	}
	#undef S0
	#undef S_1
        //Dump2D_l ( N_tile, FTable_C_section, "after");	
	
	//Memory Free
}

//Memory Macros
#undef seq1
#undef S1
#undef FTable_section
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
