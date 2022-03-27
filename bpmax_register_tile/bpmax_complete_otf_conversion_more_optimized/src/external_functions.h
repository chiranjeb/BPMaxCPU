//External Functions
#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <time.h>
#include <sys/time.h>
#include<immintrin.h>

#define CALCULATE_R_i(i, R) ((i==0) ? (R) : 0)
#define CALCULATE_R_j(i, j, R) ((i==0 && (j==0)) ? (R) : 0)
///////////////////////////////////////////////////////////////////////////////////////////////////
//                           FEATURES and OPTIONS
///////////////////////////////////////////////////////////////////////////////////////////////////
#define DEBUG 0
#define REGISTER_TILED_KERNEL 1
#define OUTER_REDUCTIONS_TIMING 0

/////////////////////////////////////////////////////////////////////////////////////////////////
#define C_p(i, j) C_p[ (i * ldC) + j]
void register_tile_3_24(int ldK, float *A, float *B, float *C, int ldA, int ldB, int ldC);
void register_tile_2_24(int ldK, float *A, float *B, float *C, int ldA, int ldB, int ldC);
void register_tile_1_24(int ldK, float *A, float *B, float *C, int ldA, int ldB, int ldC);
void register_tile_4_16(int ldK, float *A, float *B, float *C, int ldA, int ldB, int ldC);
void register_tile_3_16(int ldK, float *A, float *B, float *C, int ldA, int ldB, int ldC);
void register_tile_2_32(int ldK, float *A, float *B, float *C, int ldA, int ldB, int ldC);
void register_tile_1_8(int ldK, float *A, float *B, float *C, int ldA, int ldB, int ldC);
void register_tile_2_8(int ldK, float *A, float *B, float *C, int ldA, int ldB, int ldC);
void register_tile_3_8(int ldK, float *A, float *B, float *C, int ldA, int ldB, int ldC);



void print256_num(__m256 var);
float e_intra_score(int,int);
float e_inter_score(int,int);
float e_get_minimum (int,int);
unsigned char toNum(char c);
void ReadSequencesFromFiles(char *file_name, int *outSequence, long length, bool verbose);

void Dump2D(int M, float **Tab, const char *message, int dump=false);
void Dump4D(int N_sec, int N_i_tile, int N_j_tile, float ****Tab, const char *message);

class Alloc {
public:
	void* xcalloc(unsigned long, unsigned long);
	void* xmalloc(unsigned long);
	void* xrealloc(void*, unsigned long);
};

class Sequence {
private:
	Alloc alloc; 
	char *file_name;
	char *name;
	char *string;
	char short_filename[100];
	unsigned char *seq; /* [0-4] for [A,C,G,TU,N] */
	unsigned char *reverse_seq; /* [0-4] for [A,C,G,TU,N] */
	unsigned int len;
	bool loaded;
	unsigned char toNum(char c);
	int readSequence(FILE *);
	void checkArray(char** array, unsigned int* available, unsigned int used, unsigned int increment);
	void computeReverse();

public:
	Sequence(char *fn);
	Sequence(FILE*, char *fn);
	Sequence(char *, char *n, char *st, unsigned char *sq, unsigned int l);
	~Sequence();
	int load(FILE *f);
	int input(FILE* file);
	bool isLoaded() {return loaded;};
	char *getName();
	char *getFileName();
	char *getString();
	unsigned char *getSeq();
	unsigned char *getReverse();
	unsigned int getLen();
	Sequence *split();
	int copySequence(int *outsequence, bool verbose);
};
