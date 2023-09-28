#CFLAGS=-fopenmp  -O3  -std=c99  -I/usr/include/malloc/
#LIBRARIES=-lm
#CC?=gcc
CFLAGS= -DRANDOM -std=c++11 -xhost -fma -ipo -qopenmp -qopt-report-phase=vec -qopenmp -qopt-report=5  -I/usr/include/malloc/
LIBRARIES=-lm
CC=/s/parsons/l/sys/intel/bin/icpc
OBJS = ospsq_float.o 
all: plain check

debug: CFLAGS =-DDEBUG -g -Wall -Wextra -std=c99 -I/usr/include/malloc/
debug: all
		
plain: $(OBJS)
	$(CC) ospsq_float-wrapper.c -o ospsq_float $(OBJS) $(CFLAGS) $(LIBRARIES)

check: $(OBJS)
	$(CC) ospsq_float-wrapper.c -o ospsq_float.check $(OBJS) $(CFLAGS) $(LIBRARIES) -DCHECKING

verify: $(OBJS) ospsq_float_verify.o
	$(CC) ospsq_float-wrapper.c -o ospsq_float.verify $(OBJS) ospsq_float_verify.o $(CFLAGS) $(LIBRARIES) -DVERIFY

verify-rand: $(OBJS) ospsq_float_verify.o
	$(CC) ospsq_float-wrapper.c -o ospsq_float.verify-rand $(OBJS) ospsq_float_verify.o $(CFLAGS) $(LIBRARIES) -DVERIFY -DRANDOM

ospsq_float.o : ospsq_float.c
	$(CC) ospsq_float.c -o ospsq_float.o $(CFLAGS) $(LIBRARIES) -c

ospsq_float_verify.o : ospsq_float_verify.c
	$(CC) ospsq_float_verify.c -o ospsq_float_verify.o $(CFLAGS) $(LIBRARIES) -c

clean:
	rm -f *.o ospsq_float ospsq_float.check ospsq_float.verify ospsq_float.verify-rand
