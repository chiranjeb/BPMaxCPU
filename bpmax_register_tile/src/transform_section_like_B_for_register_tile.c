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
#include <immintrin.h>



//Memory Macros
#define C(i3,j3) C[i3][j3]
#define B(i3,j3) B[i3][j3]

void transform_section_like_B_for_register_tile(long M, long N, long N_sec, long N_tile, long MR, long NR, long I2, long J2, float** C, float** B){
	///Parameter checking
	if (!((M >= 16 && N >= 96 && N_sec >= 1 && N_tile >= 96 && MR >= 1 && NR >= 1 && I2 >= 0 && J2 >= I2 && N_sec >= J2+1))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}


    float *Pack = &B[0][0];
    for( int jj = 0; jj < N_tile-1; jj+= NR)
    {
      for ( int ii = 1; ii < N_tile ; ii++ )
      {
          const float *Cptr = &C[ii][jj];
          for (int jjj = 0; jjj < NR; jjj++)
          {
             *Pack++ = *Cptr++;
          }
      }
   }
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
