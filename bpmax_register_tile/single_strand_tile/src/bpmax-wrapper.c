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
#define EPSILON 1.0E-9







//Memory Macros
#define seq2(i) seq2[i]
#define S2_A(k,i2,j2,i3,j3) S2_A[k][i2][j2][i3][j3]
#define S2_B(k,i2,j2,i3,j3) S2_B[k][i2][j2][i3][j3]
#define S2_C(k,i2,j2,i3,j3) S2_C[k][i2][j2][i3][j3]
#define seq2_t(i,j) seq2_t[i][j]
#define S2(k,i,j) S2[k][i][j]

#define S2_verify(k,i,j) S2_verify[k][i][j]
#define var_S2(k,i,j) S2(k,i,j)
#define var_S2_verify(k,i,j) S2_verify(k,i,j)

//function prototypes
void bpmax(long, long, long, long, long, long, int*, float***);
void bpmax_verify(long, long, long, long, long, long, int*, float**);

//main
int main(int argc, char** argv) {
	//Check number of args
	if (argc <= 5) {
		printf("Number of argument is smaller than expected.\n");
		printf("Expecting M,N,N_sec,N_tile,MR,NR\n");
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
	
	//Initialisation of MR
	errno = 0;
	end = 0;
	val = argv[5];
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
	val = argv[6];
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
	if (!((M >= 3 && N >= 16 && N_sec >= 2 && N_tile >= 4 && MR >= 1 && NR >= 1))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	
	
	//Memory Allocation
	int mz1, mz2, mz3, mz4, mz5;
	int* seq2 = (int*)malloc(sizeof(int)*(N));
	mallocCheck(seq2, (N), int);
	float* _lin_S2 = (float*)malloc(sizeof(float)*((N) * (N)));
	mallocCheck(_lin_S2, ((N) * (N)), float);
	float*** S2 = (float***)malloc(sizeof(float**)*(1));
	mallocCheck(S2, (1), float**);
	for (mz1=0;mz1 < 1; mz1++) {
		S2[mz1] = (float**)malloc(sizeof(float*)*(N));
		mallocCheck(S2[mz1], (N), float*);
		for (mz2=0;mz2 < N; mz2++) {
			S2[mz1][mz2] = &_lin_S2[(mz1*((N) * (N))) + (mz2*(N))];
		}
	}
	#ifdef VERIFY
		float* _lin_S2_verify = (float*)malloc(sizeof(float)*((N) * (N)));
		mallocCheck(_lin_S2_verify, ((N) * (N)), float);
		float*** S2_verify = (float***)malloc(sizeof(float**)*(1));
		mallocCheck(S2_verify, (1), float**);
		for (mz1=0;mz1 < 1; mz1++) {
			S2_verify[mz1] = (float**)malloc(sizeof(float*)*(N));
			mallocCheck(S2_verify[mz1], (N), float*);
			for (mz2=0;mz2 < N; mz2++) {
				S2_verify[mz1][mz2] = &_lin_S2_verify[(mz1*((N) * (N))) + (mz2*(N))];
			}
		}
	#endif

	//Initialization of rand
	srand((unsigned)time(NULL));
	 
	//Input Initialization
	{
		#if defined (RANDOM)
			#define S0(i) (seq2(i) = rand()%4); 
		#elif defined (CHECKING) || defined (VERIFY)
			#ifdef NO_PROMPT
				#define S0(i) scanf("%c", &seq2(i)); seq2(i) = toNum(seq2(i));
			#else
				#define S0(i) printf("seq2(%ld)=",(long) i); scanf("%d", &seq2(i))
			#endif
		#else
                        #define S0(i) 
                        ReadSequencesFromFiles(argc==9? argv[8] : NULL, seq2, N, true);
		#endif
		
		
		int c1;
		for(c1=0;c1 <= N-1;c1+=1)
		 {
		 	S0((c1));
		 }
		#undef S0
	}
	
	//Timing
	struct timeval time;
	double elapsed_time;
	
	//Call the main computation
	gettimeofday(&time, NULL);
	elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000);
	
	bpmax(M, N, N_sec, N_tile, MR, NR, seq2, S2);

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
		fprintf(fp, "%ld\t%ld\t%ld\t%ld\t%ld\t%ld\t%lf\n",M,N,N_sec,N_tile,MR,NR,elapsed_time);
		fclose(fp);
	#endif
	
	//Verification Run
	#ifdef VERIFY
		#ifdef TIMING
			gettimeofday(&time, NULL);
			elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000);
		#endif
    	bpmax_verify(M, N, N_sec, N_tile, MR, NR, seq2, S2_verify[0]);
    	#ifdef TIMING
    		gettimeofday(&time, NULL);
			elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000) - elapsed_time;
			
			FILE * fp_verify = fopen( "trace_verify.dat","a+");
			if (fp == NULL) {
					printf("I couldn't open trace_verify.dat for writing.\n");
					exit(EXIT_FAILURE);
			}
			fprintf(fp, "%ld\t%ld\t%ld\t%ld\t%ld\t%ld\t%lf\n",M,N,N_sec,N_tile,MR,NR,elapsed_time);
			fclose(fp_verify);
		#endif
	#endif
    	
	#ifdef CHECKING
    	//Print Outputs
		
		{
			#ifdef NO_PROMPT
				#define S0(k,i,j) printf("%0.2f\n",var_S2(k,i,j))
			#else
				#define S0(k,i,j) printf("S2(%ld,%ld,%ld)=",(long) k,(long) i,(long) j);printf("%0.2f\n",var_S2(k,i,j))
			#endif
			int c2,c3;
			for(c2=0;c2 <= N-1;c2+=1)
			 {
			 	for(c3=c2;c3 <= N-1;c3+=1)
			 	 {
			 	 	S0((0),(c2),(c3));
			 	 }
			 }
			#undef S0
		}
	#elif VERIFY
		//Compare outputs for verification
		{
			//Error Counter
			int _errors_ = 0;
			#define S0(k,i,j) if (fabsf(1.0f - var_S2_verify(k,i,j)/var_S2(k,i,j)) > EPSILON) _errors_++;
			int c2,c3;
			for(c2=0;c2 <= N-1;c2+=1)
			 {
			 	for(c3=c2;c3 <= N-1;c3+=1)
			 	 {
			 	 	S0((0),(c2),(c3));
			 	 }
			 }
			#undef S0
			if(_errors_ == 0){
				printf("TEST for S2 PASSED\n");
			}else{
				printf("TEST for S2 FAILED. #Errors: %d\n", _errors_);
			}
		}
    #endif
    
	//Memory Free
	free(seq2);
	free(_lin_S2);
	for (mz1=0;mz1 < 1; mz1++) {
		free(S2[mz1]);
	}
	free(S2);
	#ifdef VERIFY
		free(_lin_S2_verify);
		for (mz1=0;mz1 < 1; mz1++) {
			free(S2_verify[mz1]);
		}
		free(S2_verify);
	#endif
	
	return EXIT_SUCCESS;
}

//Memory Macros
#undef seq2
#undef S2_A
#undef S2_B
#undef S2_C
#undef seq2_t
#undef S2


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
