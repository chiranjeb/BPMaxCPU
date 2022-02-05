CFLAGS=-fopenmp  -O3  -std=c99  -I/usr/include/malloc/
LIBRARIES=-lm
CC=icpc
CFLAGS= -O3  -qopenmp -I/usr/include/malloc/ -xCORE-AVX2 -std=c++11 -xhost -fma -ipo -qopt-report-phase=vec  -qopt-report=5
OBJS = bpmax.o transform_reverse_1D_to_2D.o bpmax_single_strand_s2_tile.o 
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

bpmax_single_strand_s2.o : bpmax_single_strand_s2.c
	$(CC) bpmax_single_strand_s2.c -o bpmax_single_strand_s2.o $(CFLAGS) $(LIBRARIES) -c
bpmax_single_strand_s2_tile.o : bpmax_single_strand_s2_tile.c
	$(CC) bpmax_single_strand_s2_tile.c -o bpmax_single_strand_s2_tile.o $(CFLAGS) $(LIBRARIES) -c
bpmax_single_strand_diagonal_tile.o : bpmax_single_strand_diagonal_tile.c
	$(CC) bpmax_single_strand_diagonal_tile.c -o bpmax_single_strand_diagonal_tile.o $(CFLAGS) $(LIBRARIES) -c
bpmax_single_strand_finalize.o : bpmax_single_strand_finalize.c
	$(CC) bpmax_single_strand_finalize.c -o bpmax_single_strand_finalize.o $(CFLAGS) $(LIBRARIES) -c
bpmax_ftable_init.o : bpmax_ftable_init.c
	$(CC) bpmax_ftable_init.c -o bpmax_ftable_init.o $(CFLAGS) $(LIBRARIES) -c
transform_reverse_1D_to_2D.o : transform_reverse_1D_to_2D.c
	$(CC) transform_reverse_1D_to_2D.c -o transform_reverse_1D_to_2D.o $(CFLAGS) $(LIBRARIES) -c

bpmax_single_strand_s2_tile.o : bpmax_single_strand_s2_tile.c
	$(CC) bpmax_single_strand_s2_tile.c -o bpmax_single_strand_s2_tile.o $(CFLAGS) $(LIBRARIES) -c

bpmax_verify.o : bpmax_verify.c
	$(CC) bpmax_verify.c -o bpmax_verify.o $(CFLAGS) $(LIBRARIES) -c

clean:
	rm -f *.o bpmax bpmax.check bpmax.verify bpmax.verify-rand
