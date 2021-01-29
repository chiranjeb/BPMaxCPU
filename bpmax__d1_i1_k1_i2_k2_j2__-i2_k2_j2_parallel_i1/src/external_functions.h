//External Functions
#include <stdlib.h>
#include <stdio.h>

float e_intra_score(int,int);
float e_inter_score(int,int);
unsigned char toNum(char c);
void ReadSequencesFromFiles(char *file_name, int *outSequence, long length, bool verbose);


/**
The following function implementations are taken from the piRNA application written by

Authors: Hamidreza Chitsaz and Ali Ebrahimpour Boroojeny
  Colorado State University
  Algorithmic Biology Lab
**/

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
