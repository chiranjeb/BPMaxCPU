CFLAGS= -O3  -std=c99  -I/usr/include/malloc/
LIBRARIES=-lm
CC?=gcc
OBJS = bpmax_single_strand_finalize.o 
all: plain check

debug: CFLAGS =-DDEBUG -g -Wall -Wextra -std=c99 -I/usr/include/malloc/
debug: all
		
plain: $(OBJS)
	$(CC) bpmax_single_strand_finalize-wrapper.c -o bpmax_single_strand_finalize $(OBJS) $(CFLAGS) $(LIBRARIES)

check: $(OBJS)
	$(CC) bpmax_single_strand_finalize-wrapper.c -o bpmax_single_strand_finalize.check $(OBJS) $(CFLAGS) $(LIBRARIES) -DCHECKING

verify: $(OBJS) bpmax_single_strand_finalize_verify.o
	$(CC) bpmax_single_strand_finalize-wrapper.c -o bpmax_single_strand_finalize.verify $(OBJS) bpmax_single_strand_finalize_verify.o $(CFLAGS) $(LIBRARIES) -DVERIFY

verify-rand: $(OBJS) bpmax_single_strand_finalize_verify.o
	$(CC) bpmax_single_strand_finalize-wrapper.c -o bpmax_single_strand_finalize.verify-rand $(OBJS) bpmax_single_strand_finalize_verify.o $(CFLAGS) $(LIBRARIES) -DVERIFY -DRANDOM

bpmax_single_strand_finalize.o : bpmax_single_strand_finalize.c
	$(CC) bpmax_single_strand_finalize.c -o bpmax_single_strand_finalize.o $(CFLAGS) $(LIBRARIES) -c

bpmax_single_strand_finalize_verify.o : bpmax_single_strand_finalize_verify.c
	$(CC) bpmax_single_strand_finalize_verify.c -o bpmax_single_strand_finalize_verify.o $(CFLAGS) $(LIBRARIES) -c

clean:
	rm -f *.o bpmax_single_strand_finalize bpmax_single_strand_finalize.check bpmax_single_strand_finalize.verify bpmax_single_strand_finalize.verify-rand
