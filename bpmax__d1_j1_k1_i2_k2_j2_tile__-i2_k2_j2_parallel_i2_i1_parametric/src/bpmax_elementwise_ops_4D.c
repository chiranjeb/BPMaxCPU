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






//Memory Macros
#define seq1(i) seq1[i]
#define seq2(i) seq2[i]
#define S1(i,j) S1[i][j]
#define S2(i2,j2,i3,j3) S2[i2][j2][i3][j3]
#define FTable_6D(i1,j1,i2,j2,i3,j3) FTable_6D[i1][j1][i2][j2][i3][j3]
#define FTable_s(i,j) FTable_s[i][j]

void bpmax_elementwise_ops_4D(long M, long N, long N_sec, long N_tile, long I1, long J1, long I2, long J2, long i3_offset, long j3_offset, int* seq1, int* seq2, float** S1, float**** S2, float****** FTable_6D, float** FTable_s){
	///Parameter checking
	if (!((M >= 16 && N >= 96 && N_sec >= 1 && N_tile >= 96 && I1 >= 0 && J1 >= I1 && M >= J1+1 && I2 >= 0 && J2 >= I2 && N_sec >= J2+1 && i3_offset >= 0 && N_tile >= i3_offset+1 && j3_offset >= 0 && N_tile >= j3_offset+1))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	//Memory Allocation
	
	#define S0(i,j) FTable_s(i,j) = 0
	#define S_1(i,j) FTable_s(i,j) = e_inter_score(seq1(I1),seq2(0))
	#define S_2(i,j) FTable_s(i,j) = (S1(I1,J1))+(S2(I2,J2,i,j))
	#define S3(i,j) FTable_s(i,j) = 0
	#define S4(i,j) FTable_s(i,j) = __max_float((FTable_6D(I1+1,J1-1,I2,J2,i,j))+(e_intra_score(seq1(I1),seq1(J1))),(S1(I1,J1))+(S2(I2,J2,i,j)))
	#define S5(i,j) FTable_s(i,j) = __max_float(0,(S1(I1,J1))+(S2(I2,J2,i,j)))
	{
		//Domain
		//{i,j|i==N_tile && M>=16 && N>=96 && N_sec>=1 && N_tile>=96 && I1>=0 && J1>=I1 && M>=J1+1 && I2>=0 && J2>=I2 && N_sec>=J2+1 && i3_offset>=0 && N_tile>=i3_offset+1 && j3_offset>=0 && N_tile>=j3_offset+1 && j>=j3_offset && N_tile>=j+1}
		//{i,j|j==i && J2==I2 && J1==I1 && M>=16 && N>=96 && N_sec>=1 && N_tile>=96 && I1>=0 && j3_offset>=0 && M>=I1+1 && I2>=0 && N_tile>=i3_offset+1 && N_sec>=I2+1 && i3_offset>=0 && N_tile>=j3_offset+1 && N_tile>=i+1 && i>=i3_offset && i>=j3_offset}
		//{i,j|J2==I2 && J1==I1 && M>=16 && N>=96 && N_sec>=1 && N_tile>=96 && I1>=0 && j>=i+1 && M>=I1+1 && I2>=0 && N_tile>=i3_offset+1 && N_sec>=I2+1 && i3_offset>=0 && N_tile>=j3_offset+1 && j3_offset>=0 && N_tile>=i+1 && i>=0 && N_tile>=j+1 && j>=0 && j>=j3_offset && i>=i3_offset}
		//{i,j|J2==I2 && J1==I1 && M>=16 && N>=96 && N_sec>=1 && N_tile>=96 && I1>=0 && i>=j+1 && M>=I1+1 && I2>=0 && N_tile>=i3_offset+1 && N_sec>=I2+1 && i3_offset>=0 && N_tile>=j3_offset+1 && j3_offset>=0 && N_tile>=i+1 && j>=j3_offset && i>=i3_offset}
		//{i,j|M>=16 && N>=96 && N_tile>=96 && I1>=0 && J1>=I1+4 && M>=J1+1 && I2>=0 && J2>=I2 && N_sec>=J2+1 && i3_offset>=0 && j3_offset>=0 && i>=i3_offset && N_tile>=i+1 && j>=j3_offset && N_tile>=j+1}
		//{i,j|M>=16 && N>=96 && N_tile>=96 && J1+J2>=I1+I2+1 && J1>=I1 && i3_offset>=0 && I1>=0 && I1>=J1-3 && N_sec>=J2+1 && M>=J1+1 && j3_offset>=0 && i>=i3_offset && N_tile>=i+1 && j>=j3_offset && N_tile>=j+1 && J2>=I2 && I2>=0}
		int c1,c2;
		if ((I1 == J1 && I2 == J2)) {
			{
				for(c1=i3_offset;c1 <= j3_offset-1;c1+=1)
				 {
				 	for(c2=j3_offset;c2 <= N_tile-1;c2+=1)
				 	 {
				 	 	S_2((c1),(c2));
				 	 }
				 }
			}
		}
		if ((I1 == J1 && I2 == J2 && N_tile >= j3_offset+2 && i3_offset <= j3_offset)) {
			{
				S_1((j3_offset),(j3_offset));
				for(c2=j3_offset+1;c2 <= N_tile-1;c2+=1)
				 {
				 	S_2((j3_offset),(c2));
				 }
			}
		}
		if ((I1 == J1 && I2 == J2 && N_tile == j3_offset+1)) {
			{
				S_1((N_tile-1),(N_tile-1));
			}
		}
		if ((I1 == J1 && I2 == J2)) {
			{
				for(c1=max(i3_offset,j3_offset+1);c1 <= N_tile-2;c1+=1)
				 {
				 	for(c2=j3_offset;c2 <= c1-1;c2+=1)
				 	 {
				 	 	S3((c1),(c2));
				 	 }
				 	S_1((c1),(c1));
				 	for(c2=c1+1;c2 <= N_tile-1;c2+=1)
				 	 {
				 	 	S_2((c1),(c2));
				 	 }
				 }
			}
		}
		if ((I1 == J1 && I2 == J2 && N_tile >= j3_offset+2)) {
			{
				for(c2=j3_offset;c2 <= N_tile-2;c2+=1)
				 {
				 	S3((N_tile-1),(c2));
				 }
				S_1((N_tile-1),(N_tile-1));
			}
		}
		if ((I1 >= J1-3 && I1+I2 <= J1+J2-1)) {
			{
				for(c1=i3_offset;c1 <= N_tile-1;c1+=1)
				 {
				 	for(c2=j3_offset;c2 <= N_tile-1;c2+=1)
				 	 {
				 	 	S5((c1),(c2));
				 	 }
				 }
			}
		}
		if ((I1 <= J1-4)) {
			{
				for(c1=i3_offset;c1 <= N_tile-1;c1+=1)
				 {
				 	for(c2=j3_offset;c2 <= N_tile-1;c2+=1)
				 	 {
				 	 	S4((c1),(c2));
				 	 }
				 }
			}
		}
		for(c2=j3_offset;c2 <= N_tile-1;c2+=1)
		 {
		 	S0((N_tile),(c2));
		 }
	}
	#undef S0
	#undef S_1
	#undef S_2
	#undef S3
	#undef S4
	#undef S5
	
	//Memory Free
}

//Memory Macros
#undef seq1
#undef seq2
#undef S1
#undef S2
#undef FTable_6D
#undef FTable_s


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