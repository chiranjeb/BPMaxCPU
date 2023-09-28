CFLAGS= -O3  -std=c99  -I/usr/include/malloc/
LIBRARIES=-lm
CC?=gcc
OBJS = bpmax_inner_reductions_finalize.o 
all: plain check

debug: CFLAGS =-DDEBUG -g -Wall -Wextra -std=c99 -I/usr/include/malloc/
debug: all
		
plain: $(OBJS)
	$(CC) bpmax_inner_reductions_finalize-wrapper.c -o bpmax_inner_reductions_finalize $(OBJS) $(CFLAGS) $(LIBRARIES)

check: $(OBJS)
	$(CC) bpmax_inner_reductions_finalize-wrapper.c -o bpmax_inner_reductions_finalize.check $(OBJS) $(CFLAGS) $(LIBRARIES) -DCHECKING

verify: $(OBJS) bpmax_inner_reductions_finalize_verify.o
	$(CC) bpmax_inner_reductions_finalize-wrapper.c -o bpmax_inner_reductions_finalize.verify $(OBJS) bpmax_inner_reductions_finalize_verify.o $(CFLAGS) $(LIBRARIES) -DVERIFY

verify-rand: $(OBJS) bpmax_inner_reductions_finalize_verify.o
	$(CC) bpmax_inner_reductions_finalize-wrapper.c -o bpmax_inner_reductions_finalize.verify-rand $(OBJS) bpmax_inner_reductions_finalize_verify.o $(CFLAGS) $(LIBRARIES) -DVERIFY -DRANDOM

bpmax_inner_reductions_finalize.o : bpmax_inner_reductions_finalize.c
	$(CC) bpmax_inner_reductions_finalize.c -o bpmax_inner_reductions_finalize.o $(CFLAGS) $(LIBRARIES) -c

bpmax_inner_reductions_finalize_verify.o : bpmax_inner_reductions_finalize_verify.c
	$(CC) bpmax_inner_reductions_finalize_verify.c -o bpmax_inner_reductions_finalize_verify.o $(CFLAGS) $(LIBRARIES) -c

clean:
	rm -f *.o bpmax_inner_reductions_finalize bpmax_inner_reductions_finalize.check bpmax_inner_reductions_finalize.verify bpmax_inner_reductions_finalize.verify-rand
