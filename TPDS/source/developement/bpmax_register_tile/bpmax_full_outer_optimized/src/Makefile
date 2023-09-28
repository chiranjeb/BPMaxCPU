CFLAGS=-fopenmp  -O3  -std=c99  -I/usr/include/malloc/
LIBRARIES=-lm
CC=icpc
CFLAGS= -O3  -qopenmp -I/usr/include/malloc/ -xCORE-AVX2 -std=c++11 -xhost -fma -ipo -qopt-report-phase=vec  -qopt-report=5
OBJS = bpmax.o bpmax_single_strand_s1.o bpmax_ftable_init.o transform_reverse_1D_to_2D.o matrix_max_plus_section.o transform_section_like_A_for_register_tile.o transform_section_like_B_for_register_tile.o bpmax_single_strand_s2_tile.o bpmax_single_strand_diagonal_tile.o bpmax_single_strand_finalize.o bpmax_inner_triangle_transform_4D_2_2D.o bpmax_inner_reductions.o bpmax_inner_reductions_diagonal_tile.o bpmax_inner_reductions_finalize.o bpmax_outer_south_west.o bpmax_r3_section.o bpmax_r4_section.o bpmax_outer_reductions.o bpmax_outer_reductions_diagonal_tile.o reg_3_24.o reg_2_24.o reg_2_32.o reg_3_16.o reg_4_16.o
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

reg_3_24.o : reg_3_24.c
	$(CC) reg_3_24.c -o reg_3_24.o $(CFLAGS) $(LIBRARIES) -c

reg_2_24.o : reg_2_24.c
	$(CC) reg_2_24.c -o reg_2_24.o $(CFLAGS) $(LIBRARIES) -c

reg_2_32.o : reg_2_32.c
	$(CC) reg_2_32.c -o reg_2_32.o $(CFLAGS) $(LIBRARIES) -c

reg_3_16.o : reg_3_16.c
	$(CC) reg_3_16.c -o reg_3_16.o $(CFLAGS) $(LIBRARIES) -c

reg_4_16.o : reg_4_16.c
	$(CC) reg_4_16.c -o reg_4_16.o $(CFLAGS) $(LIBRARIES) -c

bpmax_single_strand_s1.o : bpmax_single_strand_s1.c
	$(CC) bpmax_single_strand_s1.c -o bpmax_single_strand_s1.o $(CFLAGS) $(LIBRARIES) -c

bpmax_single_strand_s2.o : bpmax_single_strand_s2.c
	$(CC) bpmax_single_strand_s2.c -o bpmax_single_strand_s2.o $(CFLAGS) $(LIBRARIES) -c

bpmax_single_strand_diagonal_tile.o : bpmax_single_strand_diagonal_tile.c
	$(CC) bpmax_single_strand_diagonal_tile.c -o bpmax_single_strand_diagonal_tile.o $(CFLAGS) $(LIBRARIES) -c

bpmax_single_strand_finalize.o : bpmax_single_strand_finalize.c
	$(CC) bpmax_single_strand_finalize.c -o bpmax_single_strand_finalize.o $(CFLAGS) $(LIBRARIES) -c

bpmax_ftable_init.o : bpmax_ftable_init.c
	$(CC) bpmax_ftable_init.c -o bpmax_ftable_init.o $(CFLAGS) $(LIBRARIES) -c

transform_reverse_1D_to_2D.o : transform_reverse_1D_to_2D.c
	$(CC) transform_reverse_1D_to_2D.c -o transform_reverse_1D_to_2D.o $(CFLAGS) $(LIBRARIES) -c

bpmax_inner_triangle_transform_4D_2_2D.o : bpmax_inner_triangle_transform_4D_2_2D.c
	$(CC) bpmax_inner_triangle_transform_4D_2_2D.c -o bpmax_inner_triangle_transform_4D_2_2D.o $(CFLAGS) $(LIBRARIES) -c

bpmax_single_strand_s2_tile.o : bpmax_single_strand_s2_tile.c
	$(CC) bpmax_single_strand_s2_tile.c -o bpmax_single_strand_s2_tile.o $(CFLAGS) $(LIBRARIES) -c

bpmax_outer_south_west.o : bpmax_outer_south_west.c
	$(CC) bpmax_outer_south_west.c -o bpmax_outer_south_west.o $(CFLAGS) $(LIBRARIES) -c

bpmax_r3_section.o : bpmax_r3_section.c
		$(CC) bpmax_r3_section.c -o bpmax_r3_section.o $(CFLAGS) $(LIBRARIES) -c

bpmax_r4_section.o : bpmax_r4_section.c
		$(CC) bpmax_r4_section.c -o bpmax_r4_section.o $(CFLAGS) $(LIBRARIES) -c

bpmax_outer_reductions.o : bpmax_outer_reductions.c
		$(CC) bpmax_outer_reductions.c -o bpmax_outer_reductions.o $(CFLAGS) $(LIBRARIES) -c

bpmax_inner_reductions.o : bpmax_inner_reductions.c
	$(CC) bpmax_inner_reductions.c -o bpmax_inner_reductions.o $(CFLAGS) $(LIBRARIES) -c

bpmax_inner_reductions_diagonal_tile.o : bpmax_inner_reductions_diagonal_tile.c
	$(CC) bpmax_inner_reductions_diagonal_tile.c -o bpmax_inner_reductions_diagonal_tile.o $(CFLAGS) $(LIBRARIES) -c

matrix_max_plus_section.o : matrix_max_plus_section.c
	$(CC) matrix_max_plus_section.c -o matrix_max_plus_section.o $(CFLAGS) $(LIBRARIES) -c

bpmax_inner_reductions_finalize.o : bpmax_inner_reductions_finalize.c
	$(CC) bpmax_inner_reductions_finalize.c -o bpmax_inner_reductions_finalize.o $(CFLAGS) $(LIBRARIES) -c
transform_section_like_A_for_register_tile.o : transform_section_like_A_for_register_tile.c
	$(CC) transform_section_like_A_for_register_tile.c -o transform_section_like_A_for_register_tile.o $(CFLAGS) $(LIBRARIES) -c

transform_section_like_B_for_register_tile.o : transform_section_like_B_for_register_tile.c
	$(CC) transform_section_like_B_for_register_tile.c -o transform_section_like_B_for_register_tile.o $(CFLAGS) $(LIBRARIES) -c


bpmax_outer_reductions_diagonal_tile.o : bpmax_outer_reductions_diagonal_tile.c
	$(CC) bpmax_outer_reductions_diagonal_tile.c -o bpmax_outer_reductions_diagonal_tile.o $(CFLAGS) $(LIBRARIES) -c

bpmax_verify.o : bpmax_verify.c
	$(CC) bpmax_verify.c -o bpmax_verify.o $(CFLAGS) $(LIBRARIES) -c

clean:
	rm -f *.o *.optrpt bpmax bpmax.check bpmax.verify bpmax.verify-rand
