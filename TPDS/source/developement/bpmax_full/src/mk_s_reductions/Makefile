CFLAGS= -O3  -std=c99  -I/usr/include/malloc/
LIBRARIES=-lm
CC?=gcc
OBJS = bpmax_single_strand_s2_tile.o bpmax_single_strand_diagonal_tile.o matrix_max_plus_section.o bpmax_single_strand_finalize.o transform_section_like_B_for_register_tile.o transform_section_like_A_for_register_tile.o 
all: plain check

debug: CFLAGS =-DDEBUG -g -Wall -Wextra -std=c99 -I/usr/include/malloc/
debug: all
		
plain: $(OBJS)
	$(CC) bpmax_single_strand_s2_tile-wrapper.c -o bpmax_single_strand_s2_tile $(OBJS) $(CFLAGS) $(LIBRARIES)

check: $(OBJS)
	$(CC) bpmax_single_strand_s2_tile-wrapper.c -o bpmax_single_strand_s2_tile.check $(OBJS) $(CFLAGS) $(LIBRARIES) -DCHECKING

verify: $(OBJS) bpmax_single_strand_s2_tile_verify.o
	$(CC) bpmax_single_strand_s2_tile-wrapper.c -o bpmax_single_strand_s2_tile.verify $(OBJS) bpmax_single_strand_s2_tile_verify.o $(CFLAGS) $(LIBRARIES) -DVERIFY

verify-rand: $(OBJS) bpmax_single_strand_s2_tile_verify.o
	$(CC) bpmax_single_strand_s2_tile-wrapper.c -o bpmax_single_strand_s2_tile.verify-rand $(OBJS) bpmax_single_strand_s2_tile_verify.o $(CFLAGS) $(LIBRARIES) -DVERIFY -DRANDOM

bpmax_single_strand_s2_tile.o : bpmax_single_strand_s2_tile.c
	$(CC) bpmax_single_strand_s2_tile.c -o bpmax_single_strand_s2_tile.o $(CFLAGS) $(LIBRARIES) -c

bpmax_single_strand_diagonal_tile.o : bpmax_single_strand_diagonal_tile.c
	$(CC) bpmax_single_strand_diagonal_tile.c -o bpmax_single_strand_diagonal_tile.o $(CFLAGS) $(LIBRARIES) -c

matrix_max_plus_section.o : matrix_max_plus_section.c
	$(CC) matrix_max_plus_section.c -o matrix_max_plus_section.o $(CFLAGS) $(LIBRARIES) -c

bpmax_single_strand_finalize.o : bpmax_single_strand_finalize.c
	$(CC) bpmax_single_strand_finalize.c -o bpmax_single_strand_finalize.o $(CFLAGS) $(LIBRARIES) -c

transform_section_like_B_for_register_tile.o : transform_section_like_B_for_register_tile.c
	$(CC) transform_section_like_B_for_register_tile.c -o transform_section_like_B_for_register_tile.o $(CFLAGS) $(LIBRARIES) -c

transform_section_like_A_for_register_tile.o : transform_section_like_A_for_register_tile.c
	$(CC) transform_section_like_A_for_register_tile.c -o transform_section_like_A_for_register_tile.o $(CFLAGS) $(LIBRARIES) -c

bpmax_single_strand_s2_tile_verify.o : bpmax_single_strand_s2_tile_verify.c
	$(CC) bpmax_single_strand_s2_tile_verify.c -o bpmax_single_strand_s2_tile_verify.o $(CFLAGS) $(LIBRARIES) -c

clean:
	rm -f *.o bpmax_single_strand_s2_tile bpmax_single_strand_s2_tile.check bpmax_single_strand_s2_tile.verify bpmax_single_strand_s2_tile.verify-rand
