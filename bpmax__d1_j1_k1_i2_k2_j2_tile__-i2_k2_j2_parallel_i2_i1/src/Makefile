#CFLAGS=-fopenmp  -O3  -std=c99  -I/usr/include/malloc/
#LIBRARIES=-lm
#CC?=gcc
OBJS = bpmax.o
CFLAGS= -DRANDOM -std=c++11 -xhost -fma -ipo -qopenmp -qopt-report-phase=vec -qopenmp -qopt-report=5  -I/usr/include/malloc/
LIBRARIES=-lm
CC=icpc

all: plain check

debug: CFLAGS =-DDEBUG -g -Wall -Wextra -std=c99 -I/usr/include/malloc/
debug: all

plain: $(OBJS)
	$(CC) bpmax-wrapper.c external_functions.c bpmax_k1_k2_reductions.c bpmax_k1_reductions.c -o bpmax $(OBJS) $(CFLAGS) $(LIBRARIES)

check: $(OBJS)

	$(CC) bpmax-wrapper.c external_functions.c bpmax_k1_k2_reductions.c bpmax_k1_reductions.c -o bpmax.check $(OBJS) $(CFLAGS) $(LIBRARIES) -DCHECKING

verify: $(OBJS) bpmax_verify.o
	$(CC) bpmax-wrapper.c external_functions.c bpmax_k1_k2_reductions.c bpmax_k1_reductions.c -o bpmax.verify $(OBJS) bpmax_verify.o $(CFLAGS) $(LIBRARIES) -DVERIFY

verify-rand: $(OBJS) bpmax_verify.o
	$(CC) bpmax-wrapper.c external_functions.c bpmax_k1_k2_reductions.c bpmax_k1_reductions.c -o bpmax.verify-rand $(OBJS) bpmax_verify.o $(CFLAGS) $(LIBRARIES) -DVERIFY -DRANDOM

bpmax.o : bpmax.c
	$(CC) bpmax.c -o bpmax.o $(CFLAGS) $(LIBRARIES) -c

bpmax_verify.o : bpmax_verify.c
	$(CC) bpmax_verify.c -o bpmax_verify.o $(CFLAGS) $(LIBRARIES) -c

clean:
	rm -f *.o bpmax bpmax.check bpmax.verify bpmax.verify-rand *.optrpt
