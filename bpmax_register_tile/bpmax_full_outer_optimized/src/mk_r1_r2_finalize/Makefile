CFLAGS= -O3  -std=c99  -I/usr/include/malloc/
LIBRARIES=-lm
CC?=gcc
OBJS = bpmax_inner_reductions_diagonal_tile.o 
all: plain check

debug: CFLAGS =-DDEBUG -g -Wall -Wextra -std=c99 -I/usr/include/malloc/
debug: all
		
plain: $(OBJS)
	$(CC) bpmax_inner_reductions_diagonal_tile-wrapper.c -o bpmax_inner_reductions_diagonal_tile $(OBJS) $(CFLAGS) $(LIBRARIES)

check: $(OBJS)
	$(CC) bpmax_inner_reductions_diagonal_tile-wrapper.c -o bpmax_inner_reductions_diagonal_tile.check $(OBJS) $(CFLAGS) $(LIBRARIES) -DCHECKING

verify: $(OBJS) bpmax_inner_reductions_diagonal_tile_verify.o
	$(CC) bpmax_inner_reductions_diagonal_tile-wrapper.c -o bpmax_inner_reductions_diagonal_tile.verify $(OBJS) bpmax_inner_reductions_diagonal_tile_verify.o $(CFLAGS) $(LIBRARIES) -DVERIFY

verify-rand: $(OBJS) bpmax_inner_reductions_diagonal_tile_verify.o
	$(CC) bpmax_inner_reductions_diagonal_tile-wrapper.c -o bpmax_inner_reductions_diagonal_tile.verify-rand $(OBJS) bpmax_inner_reductions_diagonal_tile_verify.o $(CFLAGS) $(LIBRARIES) -DVERIFY -DRANDOM

bpmax_inner_reductions_diagonal_tile.o : bpmax_inner_reductions_diagonal_tile.c
	$(CC) bpmax_inner_reductions_diagonal_tile.c -o bpmax_inner_reductions_diagonal_tile.o $(CFLAGS) $(LIBRARIES) -c

bpmax_inner_reductions_diagonal_tile_verify.o : bpmax_inner_reductions_diagonal_tile_verify.c
	$(CC) bpmax_inner_reductions_diagonal_tile_verify.c -o bpmax_inner_reductions_diagonal_tile_verify.o $(CFLAGS) $(LIBRARIES) -c

clean:
	rm -f *.o bpmax_inner_reductions_diagonal_tile bpmax_inner_reductions_diagonal_tile.check bpmax_inner_reductions_diagonal_tile.verify bpmax_inner_reductions_diagonal_tile.verify-rand
