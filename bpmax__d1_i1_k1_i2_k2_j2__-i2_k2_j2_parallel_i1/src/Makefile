CFLAGS= -O3  -fopenmp -I/usr/include/malloc/ -xCORE-AVX2 -std=c++11 -xhost -fma -ipo -qopt-report-phase=vec  -qopt-report=5
LIBRARIES=-lm
CC=/s/parsons/l/sys/intel/bin/icpc
OBJS = bpmax.o
all: plain check

debug: CFLAGS =-DDEBUG -g -Wall -Wextra -std=c99 -I/usr/include/malloc/
debug: all

plain: $(OBJS)
	$(CC) bpmax-wrapper.c external_functions.c -o bpmax $(OBJS) $(CFLAGS) $(LIBRARIES)

check: $(OBJS)
	$(CC) bpmax-wrapper.c external_functions.c -o bpmax.check $(OBJS) $(CFLAGS) $(LIBRARIES) -DCHECKING -DNO_PROMPT 

verify: $(OBJS) bpmax_verify.o
	$(CC) bpmax-wrapper.c external_functions.c -o bpmax.verify $(OBJS) bpmax_verify.o $(CFLAGS) $(LIBRARIES) -DVERIFY -DNO_PROMPT

verify-rand: $(OBJS) bpmax_verify.o
	$(CC) bpmax-wrapper.c external_functions.c -o bpmax.verify-rand $(OBJS) bpmax_verify.o $(CFLAGS) $(LIBRARIES) -DVERIFY -DRANDOM

bpmax.o : bpmax.c
	$(CC) bpmax.c -o bpmax.o $(CFLAGS) $(LIBRARIES) -c

bpmax_verify.o : bpmax_verify.c
	$(CC) bpmax_verify.c -o bpmax_verify.o $(CFLAGS) $(LIBRARIES) -c

clean:
	rm -f *.o bpmax bpmax.check bpmax.verify bpmax.verify-rand
