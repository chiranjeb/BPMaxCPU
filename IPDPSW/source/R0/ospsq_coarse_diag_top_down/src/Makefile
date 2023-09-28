CFLAGS= -DRANDOM -std=c++11 -xhost -fma -ipo -qopenmp -qopt-report-phase=vec -qopenmp -qopt-report=1  -I/usr/include/malloc/ -xCORE-AVX2
LIBRARIES=-lm
CC=/s/parsons/l/sys/intel/bin/icpc
#CFLAGS=-fopenmp  -O3  -std=c99  -I/usr/include/malloc/
#LIBRARIES=-lm
#CC?=gcc
OBJS = ospsqmax_float.o 
all: plain check

debug: CFLAGS =-DDEBUG -g -Wall -Wextra -std=c99 -I/usr/include/malloc/
debug: all
		
plain: $(OBJS)
	$(CC) ospsqmax_float-wrapper.c -o ospsqmax_float $(OBJS) $(CFLAGS) $(LIBRARIES)

check: $(OBJS)
	$(CC) ospsqmax_float-wrapper.c -o ospsqmax_float.check $(OBJS) $(CFLAGS) $(LIBRARIES) -DCHECKING

verify: $(OBJS) ospsqmax_float_verify.o
	$(CC) ospsqmax_float-wrapper.c -o ospsqmax_float.verify $(OBJS) ospsqmax_float_verify.o $(CFLAGS) $(LIBRARIES) -DVERIFY

verify-rand: $(OBJS) ospsqmax_float_verify.o
	$(CC) ospsqmax_float-wrapper.c -o ospsqmax_float.verify-rand $(OBJS) ospsqmax_float_verify.o $(CFLAGS) $(LIBRARIES) -DVERIFY -DRANDOM

ospsqmax_float.o : ospsqmax_float.c
	$(CC) ospsqmax_float.c -o ospsqmax_float.o $(CFLAGS) $(LIBRARIES) -c

ospsqmax_float_verify.o : ospsqmax_float_verify.c
	$(CC) ospsqmax_float_verify.c -o ospsqmax_float_verify.o $(CFLAGS) $(LIBRARIES) -c

clean:
	rm -f *.o ospsqmax_float ospsqmax_float.check ospsqmax_float.verify ospsqmax_float.verify-rand
