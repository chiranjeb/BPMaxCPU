CFLAGS=-fopenmp  -O3  -std=c99  -I/usr/include/malloc/
CFLAGS= -O3  -qopenmp -I/usr/include/malloc/ -xCORE-AVX2 -std=c++11 -xhost -fma -ipo -qopt-report-phase=vec  -qopt-report=5
LIBRARIES=-lm
CC=icpc
OBJS = bpmax.o bpmax_single_strand_s1.o bpmax_single_strand_s2.o bpmax_elementwise_ops.o bpmax_outer_reductions.o bpmax_inner_reductions.o 
all: plain check

debug: CFLAGS =-DDEBUG -g -Wall -Wextra -std=c99 -I/usr/include/malloc/
debug: all
		
plain: $(OBJS)
	$(CC) bpmax-wrapper.c external_functions.c -o bpmax $(OBJS) $(CFLAGS) $(LIBRARIES)

check: $(OBJS)
	$(CC) bpmax-wrapper.c external_functions.c -o bpmax.check $(OBJS) $(CFLAGS) $(LIBRARIES) -DCHECKING

verify: $(OBJS) bpmax_verify.o
	$(CC) bpmax-wrapper.c external_functions.c -o bpmax.verify $(OBJS) bpmax_verify.o $(CFLAGS) $(LIBRARIES) -DVERIFY

verify-rand: $(OBJS) bpmax_verify.o
	$(CC) bpmax-wrapper.c external_functions.c -o bpmax.verify-rand $(OBJS) bpmax_verify.o $(CFLAGS) $(LIBRARIES) -DVERIFY -DRANDOM

bpmax.o : bpmax.c
	$(CC) bpmax.c -o bpmax.o $(CFLAGS) $(LIBRARIES) -c

bpmax_single_strand_s1.o : bpmax_single_strand_s1.c
	$(CC) bpmax_single_strand_s1.c -o bpmax_single_strand_s1.o $(CFLAGS) $(LIBRARIES) -c

bpmax_single_strand_s2.o : bpmax_single_strand_s2.c
	$(CC) bpmax_single_strand_s2.c -o bpmax_single_strand_s2.o $(CFLAGS) $(LIBRARIES) -c

bpmax_elementwise_ops.o : bpmax_elementwise_ops.c
	$(CC) bpmax_elementwise_ops.c -o bpmax_elementwise_ops.o $(CFLAGS) $(LIBRARIES) -c

bpmax_outer_reductions.o : bpmax_outer_reductions.c
	$(CC) bpmax_outer_reductions.c -o bpmax_outer_reductions.o $(CFLAGS) $(LIBRARIES) -c

bpmax_inner_reductions.o : bpmax_inner_reductions.c
	$(CC) bpmax_inner_reductions.c -o bpmax_inner_reductions.o $(CFLAGS) $(LIBRARIES) -c

bpmax_verify.o : bpmax_verify.c
	$(CC) bpmax_verify.c -o bpmax_verify.o $(CFLAGS) $(LIBRARIES) -c

clean:
	rm -f *.o bpmax bpmax.check bpmax.verify bpmax.verify-rand
