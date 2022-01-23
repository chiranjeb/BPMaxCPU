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
#include <time.h>
#include <sys/time.h>
#include <sys/errno.h>
#include <omp.h>


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
#define EPSILON 1.0E-9







//Memory Macros
#define FTable_6D_1(i2,j2,i3,j3,i4,j4) FTable_6D_1[i2][j2][i3][j3][i4][j4]
#define FTable_6D_2(i2,j2,i3,j3,i4,j4) FTable_6D_2[i2][j2][i3][j3][i4][j4]
#define FTable_6D(i2,j2,i3,j3,i4,j4) FTable_6D[i2][j2][i3][j3][i4][j4]
#define FTable_6D_3(i2,j2,i3,j3,i4,j4) FTable_6D_3[i2][j2][i3][j3][i4][j4]

#define FTable_6D_verify(i2,j2,i3,j3,i4,j4) FTable_6D_verify[i2][j2][i3][j3][i4][j4]
#define FTable_6D_3_verify(i2,j2,i3,j3,i4,j4) FTable_6D_3_verify[i2][j2][i3][j3][i4][j4]
#define var_FTable_6D(i2,j2,i3,j3,i4,j4) FTable_6D(i2,j2,i3,j3,i4,j4)
#define var_FTable_6D_verify(i2,j2,i3,j3,i4,j4) FTable_6D_verify(i2,j2,i3,j3,i4,j4)
#define var_FTable_6D_3(i2,j2,i3,j3,i4,j4) FTable_6D_3(i2,j2,i3,j3,i4,j4)
#define var_FTable_6D_3_verify(i2,j2,i3,j3,i4,j4) FTable_6D_3_verify(i2,j2,i3,j3,i4,j4)

//function prototypes
void bpmax_max_r0_single(long, long, long, long, long, long, long, long, float******, float******, float******, float******);
void bpmax_max_r0_single_verify(long, long, long, long, long, long, long, long, float******, float******, float******, float******);

//main
int main(int argc, char** argv) {
	//Check number of args
	if (argc <= 8) {
		printf("Number of argument is smaller than expected.\n");
		printf("Expecting M,N,N_sec,N_tile,N_tile_div_MR,N_tile_div_NR,MR,NR\n");
		exit(0);
	}
	
	char *end = 0;
	char *val = 0;
	//Read Parameters
	//Initialisation of M
	errno = 0;
	end = 0;
	val = argv[1];
	long M = strtol(val,&end,10);
	if ((errno == ERANGE && (M == LONG_MAX || M == LONG_MIN)) || (errno != 0 && M == 0)) {
		perror("strtol");
		exit(EXIT_FAILURE);
	}
	if (end == val) {
		fprintf(stderr, "No digits were found for M\n");
		exit(EXIT_FAILURE);
	}
	if (*end != '\0'){
		printf("For parameter M: Converted part: %ld, non-convertible part: %s\n", M, end);
		exit(EXIT_FAILURE);
	}
	
	//Initialisation of N
	errno = 0;
	end = 0;
	val = argv[2];
	long N = strtol(val,&end,10);
	if ((errno == ERANGE && (N == LONG_MAX || N == LONG_MIN)) || (errno != 0 && N == 0)) {
		perror("strtol");
		exit(EXIT_FAILURE);
	}
	if (end == val) {
		fprintf(stderr, "No digits were found for N\n");
		exit(EXIT_FAILURE);
	}
	if (*end != '\0'){
		printf("For parameter N: Converted part: %ld, non-convertible part: %s\n", N, end);
		exit(EXIT_FAILURE);
	}
	
	//Initialisation of N_sec
	errno = 0;
	end = 0;
	val = argv[3];
	long N_sec = strtol(val,&end,10);
	if ((errno == ERANGE && (N_sec == LONG_MAX || N_sec == LONG_MIN)) || (errno != 0 && N_sec == 0)) {
		perror("strtol");
		exit(EXIT_FAILURE);
	}
	if (end == val) {
		fprintf(stderr, "No digits were found for N_sec\n");
		exit(EXIT_FAILURE);
	}
	if (*end != '\0'){
		printf("For parameter N_sec: Converted part: %ld, non-convertible part: %s\n", N_sec, end);
		exit(EXIT_FAILURE);
	}
	
	//Initialisation of N_tile
	errno = 0;
	end = 0;
	val = argv[4];
	long N_tile = strtol(val,&end,10);
	if ((errno == ERANGE && (N_tile == LONG_MAX || N_tile == LONG_MIN)) || (errno != 0 && N_tile == 0)) {
		perror("strtol");
		exit(EXIT_FAILURE);
	}
	if (end == val) {
		fprintf(stderr, "No digits were found for N_tile\n");
		exit(EXIT_FAILURE);
	}
	if (*end != '\0'){
		printf("For parameter N_tile: Converted part: %ld, non-convertible part: %s\n", N_tile, end);
		exit(EXIT_FAILURE);
	}
	
	//Initialisation of N_tile_div_MR
	errno = 0;
	end = 0;
	val = argv[5];
	long N_tile_div_MR = strtol(val,&end,10);
	if ((errno == ERANGE && (N_tile_div_MR == LONG_MAX || N_tile_div_MR == LONG_MIN)) || (errno != 0 && N_tile_div_MR == 0)) {
		perror("strtol");
		exit(EXIT_FAILURE);
	}
	if (end == val) {
		fprintf(stderr, "No digits were found for N_tile_div_MR\n");
		exit(EXIT_FAILURE);
	}
	if (*end != '\0'){
		printf("For parameter N_tile_div_MR: Converted part: %ld, non-convertible part: %s\n", N_tile_div_MR, end);
		exit(EXIT_FAILURE);
	}
	
	//Initialisation of N_tile_div_NR
	errno = 0;
	end = 0;
	val = argv[6];
	long N_tile_div_NR = strtol(val,&end,10);
	if ((errno == ERANGE && (N_tile_div_NR == LONG_MAX || N_tile_div_NR == LONG_MIN)) || (errno != 0 && N_tile_div_NR == 0)) {
		perror("strtol");
		exit(EXIT_FAILURE);
	}
	if (end == val) {
		fprintf(stderr, "No digits were found for N_tile_div_NR\n");
		exit(EXIT_FAILURE);
	}
	if (*end != '\0'){
		printf("For parameter N_tile_div_NR: Converted part: %ld, non-convertible part: %s\n", N_tile_div_NR, end);
		exit(EXIT_FAILURE);
	}
	
	//Initialisation of MR
	errno = 0;
	end = 0;
	val = argv[7];
	long MR = strtol(val,&end,10);
	if ((errno == ERANGE && (MR == LONG_MAX || MR == LONG_MIN)) || (errno != 0 && MR == 0)) {
		perror("strtol");
		exit(EXIT_FAILURE);
	}
	if (end == val) {
		fprintf(stderr, "No digits were found for MR\n");
		exit(EXIT_FAILURE);
	}
	if (*end != '\0'){
		printf("For parameter MR: Converted part: %ld, non-convertible part: %s\n", MR, end);
		exit(EXIT_FAILURE);
	}
	
	//Initialisation of NR
	errno = 0;
	end = 0;
	val = argv[8];
	long NR = strtol(val,&end,10);
	if ((errno == ERANGE && (NR == LONG_MAX || NR == LONG_MIN)) || (errno != 0 && NR == 0)) {
		perror("strtol");
		exit(EXIT_FAILURE);
	}
	if (end == val) {
		fprintf(stderr, "No digits were found for NR\n");
		exit(EXIT_FAILURE);
	}
	if (*end != '\0'){
		printf("For parameter NR: Converted part: %ld, non-convertible part: %s\n", NR, end);
		exit(EXIT_FAILURE);
	}
	
	
	///Parameter checking
	if (!((M >= 16 && N >= 96 && N_sec >= 1 && N_tile >= 96 && N_tile_div_MR >= 1 && N_tile_div_NR >= 1 && MR >= 1 && NR >= 1))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	
	
	//Memory Allocation
	int mz1, mz2, mz3, mz4, mz5, mz6;
	float* _lin_FTable_6D_1 = (float*)malloc(sizeof(float)*((N_sec) * (N_sec) * (N_tile+1) * (N_tile) * (MR) * (NR)));
	mallocCheck(_lin_FTable_6D_1, ((N_sec) * (N_sec) * (N_tile+1) * (N_tile) * (MR) * (NR)), float);
	float****** FTable_6D_1 = (float******)malloc(sizeof(float*****)*(N_sec));
	mallocCheck(FTable_6D_1, (N_sec), float*****);
	for (mz1=0;mz1 < N_sec; mz1++) {
		FTable_6D_1[mz1] = (float*****)malloc(sizeof(float****)*(N_sec));
		mallocCheck(FTable_6D_1[mz1], (N_sec), float****);
		for (mz2=0;mz2 < N_sec; mz2++) {
			FTable_6D_1[mz1][mz2] = (float****)malloc(sizeof(float***)*(N_tile+1));
			mallocCheck(FTable_6D_1[mz1][mz2], (N_tile+1), float***);
			for (mz3=0;mz3 < N_tile+1; mz3++) {
				FTable_6D_1[mz1][mz2][mz3] = (float***)malloc(sizeof(float**)*(N_tile));
				mallocCheck(FTable_6D_1[mz1][mz2][mz3], (N_tile), float**);
				for (mz4=0;mz4 < N_tile; mz4++) {
					FTable_6D_1[mz1][mz2][mz3][mz4] = (float**)malloc(sizeof(float*)*(MR));
					mallocCheck(FTable_6D_1[mz1][mz2][mz3][mz4], (MR), float*);
					for (mz5=0;mz5 < MR; mz5++) {
						FTable_6D_1[mz1][mz2][mz3][mz4][mz5] = &_lin_FTable_6D_1[(mz1*((N_sec) * (N_tile+1) * (N_tile) * (MR) * (NR))) + (mz2*((N_tile+1) * (N_tile) * (MR) * (NR))) + (mz3*((N_tile) * (MR) * (NR))) + (mz4*((MR) * (NR))) + (mz5*(NR))];
					}
				}
			}
		}
	}
	float* _lin_FTable_6D_2 = (float*)malloc(sizeof(float)*((N_sec) * (N_sec) * (N_tile+1) * (N_tile) * (MR) * (NR)));
	mallocCheck(_lin_FTable_6D_2, ((N_sec) * (N_sec) * (N_tile+1) * (N_tile) * (MR) * (NR)), float);
	float****** FTable_6D_2 = (float******)malloc(sizeof(float*****)*(N_sec));
	mallocCheck(FTable_6D_2, (N_sec), float*****);
	for (mz1=0;mz1 < N_sec; mz1++) {
		FTable_6D_2[mz1] = (float*****)malloc(sizeof(float****)*(N_sec));
		mallocCheck(FTable_6D_2[mz1], (N_sec), float****);
		for (mz2=0;mz2 < N_sec; mz2++) {
			FTable_6D_2[mz1][mz2] = (float****)malloc(sizeof(float***)*(N_tile+1));
			mallocCheck(FTable_6D_2[mz1][mz2], (N_tile+1), float***);
			for (mz3=0;mz3 < N_tile+1; mz3++) {
				FTable_6D_2[mz1][mz2][mz3] = (float***)malloc(sizeof(float**)*(N_tile));
				mallocCheck(FTable_6D_2[mz1][mz2][mz3], (N_tile), float**);
				for (mz4=0;mz4 < N_tile; mz4++) {
					FTable_6D_2[mz1][mz2][mz3][mz4] = (float**)malloc(sizeof(float*)*(MR));
					mallocCheck(FTable_6D_2[mz1][mz2][mz3][mz4], (MR), float*);
					for (mz5=0;mz5 < MR; mz5++) {
						FTable_6D_2[mz1][mz2][mz3][mz4][mz5] = &_lin_FTable_6D_2[(mz1*((N_sec) * (N_tile+1) * (N_tile) * (MR) * (NR))) + (mz2*((N_tile+1) * (N_tile) * (MR) * (NR))) + (mz3*((N_tile) * (MR) * (NR))) + (mz4*((MR) * (NR))) + (mz5*(NR))];
					}
				}
			}
		}
	}
	float* _lin_FTable_6D = (float*)malloc(sizeof(float)*((N_sec) * (N_sec) * (N_tile+1) * (N_tile) * (NR) * (MR)));
	mallocCheck(_lin_FTable_6D, ((N_sec) * (N_sec) * (N_tile+1) * (N_tile) * (NR) * (MR)), float);
	float****** FTable_6D = (float******)malloc(sizeof(float*****)*(N_sec));
	mallocCheck(FTable_6D, (N_sec), float*****);
	for (mz1=0;mz1 < N_sec; mz1++) {
		FTable_6D[mz1] = (float*****)malloc(sizeof(float****)*(N_sec));
		mallocCheck(FTable_6D[mz1], (N_sec), float****);
		for (mz2=0;mz2 < N_sec; mz2++) {
			FTable_6D[mz1][mz2] = (float****)malloc(sizeof(float***)*(N_tile+1));
			mallocCheck(FTable_6D[mz1][mz2], (N_tile+1), float***);
			for (mz3=0;mz3 < N_tile+1; mz3++) {
				FTable_6D[mz1][mz2][mz3] = (float***)malloc(sizeof(float**)*(N_tile));
				mallocCheck(FTable_6D[mz1][mz2][mz3], (N_tile), float**);
				for (mz4=0;mz4 < N_tile; mz4++) {
					FTable_6D[mz1][mz2][mz3][mz4] = (float**)malloc(sizeof(float*)*(NR));
					mallocCheck(FTable_6D[mz1][mz2][mz3][mz4], (NR), float*);
					for (mz5=0;mz5 < NR; mz5++) {
						FTable_6D[mz1][mz2][mz3][mz4][mz5] = &_lin_FTable_6D[(mz1*((N_sec) * (N_tile+1) * (N_tile) * (NR) * (MR))) + (mz2*((N_tile+1) * (N_tile) * (NR) * (MR))) + (mz3*((N_tile) * (NR) * (MR))) + (mz4*((NR) * (MR))) + (mz5*(MR))];
					}
				}
			}
		}
	}
	float* _lin_FTable_6D_3 = (float*)malloc(sizeof(float)*((N_sec) * (N_sec) * (N_tile) * (N_tile+1) * (MR) * (NR)));
	mallocCheck(_lin_FTable_6D_3, ((N_sec) * (N_sec) * (N_tile) * (N_tile+1) * (MR) * (NR)), float);
	float****** FTable_6D_3 = (float******)malloc(sizeof(float*****)*(N_sec));
	mallocCheck(FTable_6D_3, (N_sec), float*****);
	for (mz1=0;mz1 < N_sec; mz1++) {
		FTable_6D_3[mz1] = (float*****)malloc(sizeof(float****)*(N_sec));
		mallocCheck(FTable_6D_3[mz1], (N_sec), float****);
		for (mz2=0;mz2 < N_sec; mz2++) {
			FTable_6D_3[mz1][mz2] = (float****)malloc(sizeof(float***)*(N_tile));
			mallocCheck(FTable_6D_3[mz1][mz2], (N_tile), float***);
			for (mz3=0;mz3 < N_tile; mz3++) {
				FTable_6D_3[mz1][mz2][mz3] = (float***)malloc(sizeof(float**)*(N_tile+1));
				mallocCheck(FTable_6D_3[mz1][mz2][mz3], (N_tile+1), float**);
				for (mz4=0;mz4 < N_tile+1; mz4++) {
					FTable_6D_3[mz1][mz2][mz3][mz4] = (float**)malloc(sizeof(float*)*(MR));
					mallocCheck(FTable_6D_3[mz1][mz2][mz3][mz4], (MR), float*);
					for (mz5=0;mz5 < MR; mz5++) {
						FTable_6D_3[mz1][mz2][mz3][mz4][mz5] = &_lin_FTable_6D_3[(mz1*((N_sec) * (N_tile) * (N_tile+1) * (MR) * (NR))) + (mz2*((N_tile) * (N_tile+1) * (MR) * (NR))) + (mz3*((N_tile+1) * (MR) * (NR))) + (mz4*((MR) * (NR))) + (mz5*(NR))];
					}
				}
			}
		}
	}
	#ifdef VERIFY
		float* _lin_FTable_6D_verify = (float*)malloc(sizeof(float)*((N_sec) * (N_sec) * (N_tile+1) * (N_tile) * (NR) * (MR)));
		mallocCheck(_lin_FTable_6D_verify, ((N_sec) * (N_sec) * (N_tile+1) * (N_tile) * (NR) * (MR)), float);
		float****** FTable_6D_verify = (float******)malloc(sizeof(float*****)*(N_sec));
		mallocCheck(FTable_6D_verify, (N_sec), float*****);
		for (mz1=0;mz1 < N_sec; mz1++) {
			FTable_6D_verify[mz1] = (float*****)malloc(sizeof(float****)*(N_sec));
			mallocCheck(FTable_6D_verify[mz1], (N_sec), float****);
			for (mz2=0;mz2 < N_sec; mz2++) {
				FTable_6D_verify[mz1][mz2] = (float****)malloc(sizeof(float***)*(N_tile+1));
				mallocCheck(FTable_6D_verify[mz1][mz2], (N_tile+1), float***);
				for (mz3=0;mz3 < N_tile+1; mz3++) {
					FTable_6D_verify[mz1][mz2][mz3] = (float***)malloc(sizeof(float**)*(N_tile));
					mallocCheck(FTable_6D_verify[mz1][mz2][mz3], (N_tile), float**);
					for (mz4=0;mz4 < N_tile; mz4++) {
						FTable_6D_verify[mz1][mz2][mz3][mz4] = (float**)malloc(sizeof(float*)*(NR));
						mallocCheck(FTable_6D_verify[mz1][mz2][mz3][mz4], (NR), float*);
						for (mz5=0;mz5 < NR; mz5++) {
							FTable_6D_verify[mz1][mz2][mz3][mz4][mz5] = &_lin_FTable_6D_verify[(mz1*((N_sec) * (N_tile+1) * (N_tile) * (NR) * (MR))) + (mz2*((N_tile+1) * (N_tile) * (NR) * (MR))) + (mz3*((N_tile) * (NR) * (MR))) + (mz4*((NR) * (MR))) + (mz5*(MR))];
						}
					}
				}
			}
		}
		float* _lin_FTable_6D_3_verify = (float*)malloc(sizeof(float)*((N_sec) * (N_sec) * (N_tile) * (N_tile+1) * (MR) * (NR)));
		mallocCheck(_lin_FTable_6D_3_verify, ((N_sec) * (N_sec) * (N_tile) * (N_tile+1) * (MR) * (NR)), float);
		float****** FTable_6D_3_verify = (float******)malloc(sizeof(float*****)*(N_sec));
		mallocCheck(FTable_6D_3_verify, (N_sec), float*****);
		for (mz1=0;mz1 < N_sec; mz1++) {
			FTable_6D_3_verify[mz1] = (float*****)malloc(sizeof(float****)*(N_sec));
			mallocCheck(FTable_6D_3_verify[mz1], (N_sec), float****);
			for (mz2=0;mz2 < N_sec; mz2++) {
				FTable_6D_3_verify[mz1][mz2] = (float****)malloc(sizeof(float***)*(N_tile));
				mallocCheck(FTable_6D_3_verify[mz1][mz2], (N_tile), float***);
				for (mz3=0;mz3 < N_tile; mz3++) {
					FTable_6D_3_verify[mz1][mz2][mz3] = (float***)malloc(sizeof(float**)*(N_tile+1));
					mallocCheck(FTable_6D_3_verify[mz1][mz2][mz3], (N_tile+1), float**);
					for (mz4=0;mz4 < N_tile+1; mz4++) {
						FTable_6D_3_verify[mz1][mz2][mz3][mz4] = (float**)malloc(sizeof(float*)*(MR));
						mallocCheck(FTable_6D_3_verify[mz1][mz2][mz3][mz4], (MR), float*);
						for (mz5=0;mz5 < MR; mz5++) {
							FTable_6D_3_verify[mz1][mz2][mz3][mz4][mz5] = &_lin_FTable_6D_3_verify[(mz1*((N_sec) * (N_tile) * (N_tile+1) * (MR) * (NR))) + (mz2*((N_tile) * (N_tile+1) * (MR) * (NR))) + (mz3*((N_tile+1) * (MR) * (NR))) + (mz4*((MR) * (NR))) + (mz5*(NR))];
						}
					}
				}
			}
		}
	#endif

	//Initialization of rand
	srand((unsigned)time(NULL));
	 
	//Input Initialization
	{
		#if defined (RANDOM)
			#define S0(i2,j2,i3,j3,i4,j4) (FTable_6D_1(i2,j2,i3,j3,i4,j4) = rand()) 
		#elif defined (CHECKING) || defined (VERIFY)
			#ifdef NO_PROMPT
				#define S0(i2,j2,i3,j3,i4,j4) scanf("%f", &FTable_6D_1(i2,j2,i3,j3,i4,j4))
			#else
				#define S0(i2,j2,i3,j3,i4,j4) printf("FTable_6D_1(%ld,%ld,%ld,%ld,%ld,%ld)=",(long) i2,(long) j2,(long) i3,(long) j3,(long) i4,(long) j4); scanf("%f", &FTable_6D_1(i2,j2,i3,j3,i4,j4))
			#endif
		#else
			#define S0(i2,j2,i3,j3,i4,j4) (FTable_6D_1(i2,j2,i3,j3,i4,j4) = 1)   //Default value
		#endif
		
		
		int c1,c2,c3,c4,c5,c6;
		for(c1=0;c1 <= N_sec-1;c1+=1)
		 {
		 	for(c2=c1;c2 <= N_sec-1;c2+=1)
		 	 {
		 	 	for(c3=0;c3 <= N_tile;c3+=1)
		 	 	 {
		 	 	 	for(c4=0;c4 <= N_tile-1;c4+=1)
		 	 	 	 {
		 	 	 	 	for(c5=0;c5 <= MR-1;c5+=1)
		 	 	 	 	 {
		 	 	 	 	 	for(c6=0;c6 <= NR-1;c6+=1)
		 	 	 	 	 	 {
		 	 	 	 	 	 	S0((c1),(c2),(c3),(c4),(c5),(c6));
		 	 	 	 	 	 }
		 	 	 	 	 }
		 	 	 	 }
		 	 	 }
		 	 }
		 }
		#undef S0
	}
	{
		#if defined (RANDOM)
			#define S0(i2,j2,i3,j3,i4,j4) (FTable_6D_2(i2,j2,i3,j3,i4,j4) = rand()) 
		#elif defined (CHECKING) || defined (VERIFY)
			#ifdef NO_PROMPT
				#define S0(i2,j2,i3,j3,i4,j4) scanf("%f", &FTable_6D_2(i2,j2,i3,j3,i4,j4))
			#else
				#define S0(i2,j2,i3,j3,i4,j4) printf("FTable_6D_2(%ld,%ld,%ld,%ld,%ld,%ld)=",(long) i2,(long) j2,(long) i3,(long) j3,(long) i4,(long) j4); scanf("%f", &FTable_6D_2(i2,j2,i3,j3,i4,j4))
			#endif
		#else
			#define S0(i2,j2,i3,j3,i4,j4) (FTable_6D_2(i2,j2,i3,j3,i4,j4) = 1)   //Default value
		#endif
		
		
		int c1,c2,c3,c4,c5,c6;
		for(c1=0;c1 <= N_sec-1;c1+=1)
		 {
		 	for(c2=c1;c2 <= N_sec-1;c2+=1)
		 	 {
		 	 	for(c3=0;c3 <= N_tile;c3+=1)
		 	 	 {
		 	 	 	for(c4=0;c4 <= N_tile-1;c4+=1)
		 	 	 	 {
		 	 	 	 	for(c5=0;c5 <= MR-1;c5+=1)
		 	 	 	 	 {
		 	 	 	 	 	for(c6=0;c6 <= NR-1;c6+=1)
		 	 	 	 	 	 {
		 	 	 	 	 	 	S0((c1),(c2),(c3),(c4),(c5),(c6));
		 	 	 	 	 	 }
		 	 	 	 	 }
		 	 	 	 }
		 	 	 }
		 	 }
		 }
		#undef S0
	}
	
	//Timing
	struct timeval time;
	double elapsed_time;
	
	//Call the main computation
	gettimeofday(&time, NULL);
	elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000);
	
	bpmax_max_r0_single(M, N, N_sec, N_tile, N_tile_div_MR, N_tile_div_NR, MR, NR, FTable_6D_1, FTable_6D_2, FTable_6D, FTable_6D_3);

	gettimeofday(&time, NULL);
	elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000) - elapsed_time;

	// timing information
	printf("Execution time : %lf sec.\n", elapsed_time);
	
	#ifdef TIMING
		FILE * fp = fopen( "trace.dat","a+");
		if (fp == NULL) {
				printf("I couldn't open trace.dat for writing.\n");
				exit(EXIT_FAILURE);
		}
		fprintf(fp, "%ld\t%ld\t%ld\t%ld\t%ld\t%ld\t%ld\t%ld\t%lf\n",M,N,N_sec,N_tile,N_tile_div_MR,N_tile_div_NR,MR,NR,elapsed_time);
		fclose(fp);
	#endif
	
	//Verification Run
	#ifdef VERIFY
		#ifdef TIMING
			gettimeofday(&time, NULL);
			elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000);
		#endif
    	bpmax_max_r0_single_verify(M, N, N_sec, N_tile, N_tile_div_MR, N_tile_div_NR, MR, NR, FTable_6D_1, FTable_6D_2, FTable_6D_verify, FTable_6D_3_verify);
    	#ifdef TIMING
    		gettimeofday(&time, NULL);
			elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000) - elapsed_time;
			
			FILE * fp_verify = fopen( "trace_verify.dat","a+");
			if (fp == NULL) {
					printf("I couldn't open trace_verify.dat for writing.\n");
					exit(EXIT_FAILURE);
			}
			fprintf(fp, "%ld\t%ld\t%ld\t%ld\t%ld\t%ld\t%ld\t%ld\t%lf\n",M,N,N_sec,N_tile,N_tile_div_MR,N_tile_div_NR,MR,NR,elapsed_time);
			fclose(fp_verify);
		#endif
	#endif
    	
	#ifdef CHECKING
    	//Print Outputs
		
		{
			#ifdef NO_PROMPT
				#define S0(i2,j2,i3,j3,i4,j4) printf("%0.2f\n",var_FTable_6D(i2,j2,i3,j3,j4,i4))
			#else
				#define S0(i2,j2,i3,j3,i4,j4) printf("FTable_6D(%ld,%ld,%ld,%ld,%ld,%ld)=",(long) i2,(long) j2,(long) i3,(long) j3,(long) i4,(long) j4);printf("%0.2f\n",var_FTable_6D(i2,j2,i3,j3,j4,i4))
			#endif
			int c1,c2,c3,c4,c5,c6;
			for(c1=0;c1 <= N_sec-1;c1+=1)
			 {
			 	for(c2=c1;c2 <= N_sec-1;c2+=1)
			 	 {
			 	 	for(c3=0;c3 <= N_tile;c3+=1)
			 	 	 {
			 	 	 	for(c4=0;c4 <= N_tile-1;c4+=1)
			 	 	 	 {
			 	 	 	 	for(c5=0;c5 <= MR-1;c5+=1)
			 	 	 	 	 {
			 	 	 	 	 	for(c6=0;c6 <= NR-1;c6+=1)
			 	 	 	 	 	 {
			 	 	 	 	 	 	S0((c1),(c2),(c3),(c4),(c5),(c6));
			 	 	 	 	 	 }
			 	 	 	 	 }
			 	 	 	 }
			 	 	 }
			 	 }
			 }
			#undef S0
		}
		
		{
			#ifdef NO_PROMPT
				#define S0(i2,j2,i3,j3,i4,j4) printf("%0.2f\n",var_FTable_6D_3(i2,j2,j3,i3,i4,j4))
			#else
				#define S0(i2,j2,i3,j3,i4,j4) printf("FTable_6D_3(%ld,%ld,%ld,%ld,%ld,%ld)=",(long) i2,(long) j2,(long) i3,(long) j3,(long) i4,(long) j4);printf("%0.2f\n",var_FTable_6D_3(i2,j2,j3,i3,i4,j4))
			#endif
			int c1,c2,c3,c4,c5,c6;
			for(c1=0;c1 <= N_sec-1;c1+=1)
			 {
			 	for(c2=c1;c2 <= N_sec-1;c2+=1)
			 	 {
			 	 	for(c3=0;c3 <= N_tile;c3+=1)
			 	 	 {
			 	 	 	for(c4=0;c4 <= N_tile-1;c4+=1)
			 	 	 	 {
			 	 	 	 	for(c5=0;c5 <= MR-1;c5+=1)
			 	 	 	 	 {
			 	 	 	 	 	for(c6=0;c6 <= NR-1;c6+=1)
			 	 	 	 	 	 {
			 	 	 	 	 	 	S0((c1),(c2),(c3),(c4),(c5),(c6));
			 	 	 	 	 	 }
			 	 	 	 	 }
			 	 	 	 }
			 	 	 }
			 	 }
			 }
			#undef S0
		}
	#elif VERIFY
		//Compare outputs for verification
		{
			//Error Counter
			int _errors_ = 0;
			#define S0(i2,j2,i3,j3,i4,j4) if (fabsf(1.0f - var_FTable_6D_verify(i2,j2,i3,j3,j4,i4)/var_FTable_6D(i2,j2,i3,j3,j4,i4)) > EPSILON) _errors_++;
			int c1,c2,c3,c4,c5,c6;
			for(c1=0;c1 <= N_sec-1;c1+=1)
			 {
			 	for(c2=c1;c2 <= N_sec-1;c2+=1)
			 	 {
			 	 	for(c3=0;c3 <= N_tile;c3+=1)
			 	 	 {
			 	 	 	for(c4=0;c4 <= N_tile-1;c4+=1)
			 	 	 	 {
			 	 	 	 	for(c5=0;c5 <= MR-1;c5+=1)
			 	 	 	 	 {
			 	 	 	 	 	for(c6=0;c6 <= NR-1;c6+=1)
			 	 	 	 	 	 {
			 	 	 	 	 	 	S0((c1),(c2),(c3),(c4),(c5),(c6));
			 	 	 	 	 	 }
			 	 	 	 	 }
			 	 	 	 }
			 	 	 }
			 	 }
			 }
			#undef S0
			if(_errors_ == 0){
				printf("TEST for FTable_6D PASSED\n");
			}else{
				printf("TEST for FTable_6D FAILED. #Errors: %d\n", _errors_);
			}
		}
		{
			//Error Counter
			int _errors_ = 0;
			#define S0(i2,j2,i3,j3,i4,j4) if (fabsf(1.0f - var_FTable_6D_3_verify(i2,j2,j3,i3,i4,j4)/var_FTable_6D_3(i2,j2,j3,i3,i4,j4)) > EPSILON) _errors_++;
			int c1,c2,c3,c4,c5,c6;
			for(c1=0;c1 <= N_sec-1;c1+=1)
			 {
			 	for(c2=c1;c2 <= N_sec-1;c2+=1)
			 	 {
			 	 	for(c3=0;c3 <= N_tile;c3+=1)
			 	 	 {
			 	 	 	for(c4=0;c4 <= N_tile-1;c4+=1)
			 	 	 	 {
			 	 	 	 	for(c5=0;c5 <= MR-1;c5+=1)
			 	 	 	 	 {
			 	 	 	 	 	for(c6=0;c6 <= NR-1;c6+=1)
			 	 	 	 	 	 {
			 	 	 	 	 	 	S0((c1),(c2),(c3),(c4),(c5),(c6));
			 	 	 	 	 	 }
			 	 	 	 	 }
			 	 	 	 }
			 	 	 }
			 	 }
			 }
			#undef S0
			if(_errors_ == 0){
				printf("TEST for FTable_6D_3 PASSED\n");
			}else{
				printf("TEST for FTable_6D_3 FAILED. #Errors: %d\n", _errors_);
			}
		}
    #endif
    
	//Memory Free
	free(_lin_FTable_6D_1);
	for (mz1=0;mz1 < N_sec; mz1++) {
		for (mz2=0;mz2 < N_sec; mz2++) {
			for (mz3=0;mz3 < N_tile+1; mz3++) {
				for (mz4=0;mz4 < N_tile; mz4++) {
					free(FTable_6D_1[mz1][mz2][mz3][mz4]);
				}
				free(FTable_6D_1[mz1][mz2][mz3]);
			}
			free(FTable_6D_1[mz1][mz2]);
		}
		free(FTable_6D_1[mz1]);
	}
	free(FTable_6D_1);
	free(_lin_FTable_6D_2);
	for (mz1=0;mz1 < N_sec; mz1++) {
		for (mz2=0;mz2 < N_sec; mz2++) {
			for (mz3=0;mz3 < N_tile+1; mz3++) {
				for (mz4=0;mz4 < N_tile; mz4++) {
					free(FTable_6D_2[mz1][mz2][mz3][mz4]);
				}
				free(FTable_6D_2[mz1][mz2][mz3]);
			}
			free(FTable_6D_2[mz1][mz2]);
		}
		free(FTable_6D_2[mz1]);
	}
	free(FTable_6D_2);
	free(_lin_FTable_6D);
	for (mz1=0;mz1 < N_sec; mz1++) {
		for (mz2=0;mz2 < N_sec; mz2++) {
			for (mz3=0;mz3 < N_tile+1; mz3++) {
				for (mz4=0;mz4 < N_tile; mz4++) {
					free(FTable_6D[mz1][mz2][mz3][mz4]);
				}
				free(FTable_6D[mz1][mz2][mz3]);
			}
			free(FTable_6D[mz1][mz2]);
		}
		free(FTable_6D[mz1]);
	}
	free(FTable_6D);
	free(_lin_FTable_6D_3);
	for (mz1=0;mz1 < N_sec; mz1++) {
		for (mz2=0;mz2 < N_sec; mz2++) {
			for (mz3=0;mz3 < N_tile; mz3++) {
				for (mz4=0;mz4 < N_tile+1; mz4++) {
					free(FTable_6D_3[mz1][mz2][mz3][mz4]);
				}
				free(FTable_6D_3[mz1][mz2][mz3]);
			}
			free(FTable_6D_3[mz1][mz2]);
		}
		free(FTable_6D_3[mz1]);
	}
	free(FTable_6D_3);
	#ifdef VERIFY
		free(_lin_FTable_6D_verify);
		for (mz1=0;mz1 < N_sec; mz1++) {
			for (mz2=0;mz2 < N_sec; mz2++) {
				for (mz3=0;mz3 < N_tile+1; mz3++) {
					for (mz4=0;mz4 < N_tile; mz4++) {
						free(FTable_6D_verify[mz1][mz2][mz3][mz4]);
					}
					free(FTable_6D_verify[mz1][mz2][mz3]);
				}
				free(FTable_6D_verify[mz1][mz2]);
			}
			free(FTable_6D_verify[mz1]);
		}
		free(FTable_6D_verify);
		free(_lin_FTable_6D_3_verify);
		for (mz1=0;mz1 < N_sec; mz1++) {
			for (mz2=0;mz2 < N_sec; mz2++) {
				for (mz3=0;mz3 < N_tile; mz3++) {
					for (mz4=0;mz4 < N_tile+1; mz4++) {
						free(FTable_6D_3_verify[mz1][mz2][mz3][mz4]);
					}
					free(FTable_6D_3_verify[mz1][mz2][mz3]);
				}
				free(FTable_6D_3_verify[mz1][mz2]);
			}
			free(FTable_6D_3_verify[mz1]);
		}
		free(FTable_6D_3_verify);
	#endif
	
	return EXIT_SUCCESS;
}

//Memory Macros
#undef FTable_6D_1
#undef FTable_6D_2
#undef FTable_6D
#undef FTable_6D_3


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
#undef EPSILON
