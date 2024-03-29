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
void transform_section_like_B_for_register_tile(long, long, long, long, long, long, long, long, float**, float**);
void transform_section_like_A_for_register_tile(long, long, long, long, long, long, long, long, float**, float**);
void matrix_max_plus_section(long, long, long, long, long, long, long, long, long, float**, float**, float**);
void bpmax_r3_section(long, long, long, long, long, long, long, long, long, long, long, long, long, float**, float**, float**);
void bpmax_r4_section(long, long, long, long, long, long, long, long, long, long, long, long, long, float**, float**, float**);


//Memory Macros
#define seq1(i) seq1[i]
#define S1(i,j) S1[i][j]
#define FTable_A(i2,j2,i3,j3) FTable_A[i2][j2][i3][j3]
#define FTable_B(i2,j2,i3,j3) FTable_B[i2][j2][i3][j3]
#define FTable_C(i1,j1,i2,j2,i3,j3) FTable_C[i1][j1][i2][j2][i3][j3]
#define FTable_C_I1_J1(i2,j2,i3,j3) FTable_C_I1_J1[i2][j2][i3][j3]

void bpmax_outer_reductions(long M, long N, long N_sec, long N_tile, long R, long MR, long NR, long P, long I1, long J1, long K1, int* seq1, float** S1, float**** FTable_A, float**** FTable_B, float****** FTable_C, float*** FTable_Pack_A, float*** FTable_Pack_B, float**** FTable_C_I1_J1){
	///Parameter checking
	if (!((M >= 1 && N >= 8 && N_sec >= 2 && N_tile >= 4 && R >= 0 && N_tile >= R+1 && MR >= 1 && NR >= 1 && P >= 1 && 0 >= P-128 && I1 >= 0 && J1 >= I1 && M >= J1+1 && K1 >= I1 && J1 >= K1+1))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
    }
#if OUTER_REDUCTIONS_TIMING
    struct timeval time;
    double elapsed_time;
    gettimeofday(&time, NULL);
    elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000) - elapsed_time;
#endif

	
	
	

	#define S0(i,j,k,i3,i4,i5) transform_section_like_B_for_register_tile(N,N_sec,N_tile,R,MR,NR,k,i4,FTable_B[k][i4],FTable_Pack_B[thread_id])
	#define S_1(i,j,i2,i3,i4,i5) transform_section_like_A_for_register_tile(N,N_sec,N_tile,R,MR,NR,j,i2,FTable_A[j][i2],FTable_Pack_A[thread_id])
	#define S2(i,j,k,i3,i4,i5) matrix_max_plus_section(N,N_sec,N_tile,R,MR,NR,j,i4,k,FTable_Pack_A[thread_id],FTable_Pack_B[thread_id],FTable_C_I1_J1[j][i4])
	#define S3(i,j,i2,i3,i4,i5) bpmax_r3_section(M,N,N_sec,N_tile,R,R,MR,NR,I1,J1,K1,j,i2,S1,FTable_B[j][i2],FTable_C_I1_J1[j][i2])
	#define S4(i,j,i2,i3,i4,i5) bpmax_r4_section(M,N,N_sec,N_tile,R,R,MR,NR,I1,J1,K1,j,i2,FTable_A[j][i2],S1,FTable_C_I1_J1[j][i2])
	{
		//Domain
		//{i,j,k,i3,i4,i5|i5==0 && i3==1 && i==0 && j>=0 && i4>=j && N_sec>=i4+1 && k>=j && i4>=k && M>=1 && N>=8 && N_sec>=2 && N_tile>=4 && R>=0 && N_tile>=R+1 && MR>=1 && NR>=1 && P>=1 && 0>=P-128 && I1>=0 && J1>=I1 && M>=J1+1 && K1>=I1 && J1>=K1+1}
		//{i,j,i2,i3,i4,i5|i5==1 && i4==0 && i3==0 && i==0 && j>=0 && i2>=j && N_sec>=i2+1 && M>=1 && N>=8 && N_sec>=2 && N_tile>=4 && R>=0 && N_tile>=R+1 && MR>=1 && NR>=1 && P>=1 && 0>=P-128 && I1>=0 && J1>=I1 && M>=J1+1 && K1>=I1 && J1>=K1+1}
		//{i,j,k,i3,i4,i5|i5==1 && i3==1 && i==0 && j>=0 && i4>=j && N_sec>=i4+1 && k>=j && i4>=k && M>=1 && N>=8 && N_sec>=2 && N_tile>=4 && R>=0 && N_tile>=R+1 && MR>=1 && NR>=1 && P>=1 && 0>=P-128 && I1>=0 && J1>=I1 && M>=J1+1 && K1>=I1 && J1>=K1+1}
		//{i,j,i2,i3,i4,i5|i5==0 && i4==0 && i3==0 && i==0 && j>=0 && i2>=j && N_sec>=i2+1 && M>=1 && N>=8 && N_sec>=2 && N_tile>=4 && R>=0 && N_tile>=R+1 && MR>=1 && NR>=1 && P>=1 && 0>=P-128 && I1>=0 && J1>=I1 && M>=J1+1 && K1>=I1 && J1>=K1+1}
		//{i,j,i2,i3,i4,i5|i5==0 && i4==0 && i3==0 && i==0 && j>=0 && i2>=j && N_sec>=i2+1 && M>=1 && N>=8 && N_sec>=2 && N_tile>=4 && R>=0 && N_tile>=R+1 && MR>=1 && NR>=1 && P>=1 && 0>=P-128 && I1>=0 && J1>=I1 && M>=J1+1 && K1>=I1 && J1>=K1+1}
        int c2,c3,c5, thread_id;
        #pragma omp parallel for private(c3,c5,thread_id)  schedule(static, 1)
		for(c2=0;c2 <= N_sec-1;c2+=1)
		 {
            thread_id = omp_get_thread_num();
		 	for(c3=c2;c3 <= N_sec-1;c3+=1)
		 	 {
		 	 	S3((0),(c2),(c3),(0),(0),(0));
		 	 	S4((0),(c2),(c3),(0),(0),(0));
		 	 	S_1((0),(c2),(c3),(0),(0),(1));
		 	 	for(c5=c3;c5 <= N_sec-1;c5+=1)
		 	 	 {
		 	 	 	S0((0),(c2),(c3),(1),(c5),(0));
		 	 	 	S2((0),(c2),(c3),(1),(c5),(1));
		 	 	 }
		 	 }
		 }
	}
	#undef S0
	#undef S_1
	#undef S2
	#undef S3
	#undef S4
	
	//Memory Free
	free(_lin_FTable_C_I1_J1_0);
	for (mz1=0;mz1 < N_sec; mz1++) {
		for (mz2=0;mz2 < N_sec; mz2++) {
			for (mz3=0;mz3 < N_sec; mz3++) {
				free(FTable_C_I1_J1_0[mz1][mz2][mz3]);
			}
			free(FTable_C_I1_J1_0[mz1][mz2]);
		}
		free(FTable_C_I1_J1_0[mz1]);
	}
	free(FTable_C_I1_J1_0);
	
	free(_lin_FTable_C_I1_J1_1);
	for (mz1=0;mz1 < N_sec; mz1++) {
		for (mz2=0;mz2 < N_sec; mz2++) {
			free(FTable_C_I1_J1_1[mz1][mz2]);
		}
		free(FTable_C_I1_J1_1[mz1]);
	}
	free(FTable_C_I1_J1_1);
	
	free(_lin_FTable_C_I1_J1_2);
	for (mz1=0;mz1 < N_sec; mz1++) {
		for (mz2=0;mz2 < N_sec; mz2++) {
			free(FTable_C_I1_J1_2[mz1][mz2]);
		}
		free(FTable_C_I1_J1_2[mz1]);
	}
	free(FTable_C_I1_J1_2);
	
	free(_lin_FTable_BB);
	for (mz1=0;mz1 < N_sec; mz1++) {
		for (mz2=0;mz2 < N_sec; mz2++) {
			for (mz3=0;mz3 < N_sec; mz3++) {
				free(FTable_BB[mz1][mz2][mz3]);
			}
			free(FTable_BB[mz1][mz2]);
		}
		free(FTable_BB[mz1]);
	}
	free(FTable_BB);
	
	free(_lin_FTable_AA);
	for (mz1=0;mz1 < N_sec; mz1++) {
		for (mz2=0;mz2 < N_sec; mz2++) {
			free(FTable_AA[mz1][mz2]);
		}
		free(FTable_AA[mz1]);
	}
	free(FTable_AA);
}

//Memory Macros
#undef seq1
#undef S1
#undef FTable_A
#undef FTable_B
#undef FTable_C
#undef FTable_Pack_A
#undef FTable_Pack_B
#undef FTable_C_I1_J1_0
#undef FTable_C_I1_J1_1
#undef FTable_C_I1_J1_2
#undef FTable_BB
#undef FTable_AA
#undef FTable_C_I1_J1


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
