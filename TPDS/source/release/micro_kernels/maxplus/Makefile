#CFLAGS=-fopenmp  -O3  -std=c99  -I/usr/include/malloc/
#LIBRARIES=-lm
#CC?=gcc
#CFLAGS= -DRANDOM -std=c++11 -xhost -fma -ipo -qopenmp -qopt-report-phase=vec -qopenmp -qopt-report=5  -I/usr/include/malloc/

CFLAGS=-std=c++11 -Ofast -xhost -xCORE-AVX2 -ipo -qopt-report=5 
RFLAGS=-std=c++11 -Ofast -xhost -xCORE-AVX2  -qopt-report=5 
#CFLAGS=-std=c++11  -xhost -xCORE-AVX2 -qopt-report=5 
LIBRARIES=-lm
CC=icc

OBJS=max_plus.o reg_2_32.o reg_2_24.o reg_3_16.o reg_4_16.o reg_3_24.o
OBJS_S=reg_2_32.s reg_2_24.s reg_3_16.s reg_4_16.s reg_3_24.s
all: max_plus register_only_2_16.s register_only_2_24.s register_only_3_24.s register_only_main.s

debug: CFLAGS =-DDEBUG -g -Wall -Wextra -std=c99 -I/usr/include/malloc/
debug: all

max_plus.o: max_plus.cpp
	$(CC) $(CFLAGS) -c $< -o max_plus.o

reg_2_32.o: reg_2_32.cpp
	$(CC) $(CFLAGS) -c $< -o reg_2_32.o 
reg_2_32.s: reg_2_32.cpp
	$(CC) $(CFLAGS) -S $< -o reg_2_32.s 

reg_2_24.o: reg_2_24.cpp
	$(CC) $(CFLAGS) -c $< -o reg_2_24.o 
reg_2_24.s: reg_2_24.cpp
	$(CC) $(CFLAGS) -S $< -o reg_2_24.s 

reg_3_16.o: reg_3_16.cpp
	$(CC) $(CFLAGS) -c $< -o reg_3_16.o 
reg_3_16.s: reg_3_16.cpp
	$(CC) $(CFLAGS) -S $< -o reg_3_16.s 

reg_3_24.o: reg_3_24.cpp
	$(CC) $(CFLAGS) -c $< -o reg_3_24.o 
reg_3_24.s: reg_3_24.cpp
	$(CC) $(CFLAGS) -S $< -o reg_3_24.s 

reg_4_16.o: reg_4_16.cpp
	$(CC) $(CFLAGS) -c $< -o reg_4_16.o 
reg_4_16.s: reg_4_16.cpp
	$(CC) $(CFLAGS) -S $< -o reg_4_16.s 

max_plus:$(OBJS) $(OBJS_S)
	$(CC) $(CFLAGS) -o max_plus $(OBJS)
	rm -rf *.o

#register_only: register_only_asm register_only_intrinsic
register_only_2_24.s: register_only_2_24.cpp
	$(CC) $(CFLAGS) -S $< -o register_only_2_24.s

register_only_3_24.s: register_only_3_24.cpp
	$(CC) $(CFLAGS) -S $< -o register_only_3_24.s

register_only_2_16.s: register_only_2_16.cpp
	$(CC) $(CFLAGS) -S $< -o register_only_2_16.s

register_only_main.s: register_only_main.cpp
	$(CC) $(CFLAGS)  -S -fsource-asm $< -o register_only_main.s	

#register_only: register_only.s register_only_main.s
#	$(CC) $(CFLAGS)  register_only.s register_only_main.s -o register_only
	
register_only: register_only_2_16.s register_only_2_24.s  register_only_3_24.s register_only_main.cpp
	$(CC) $(CFLAGS)  register_only_2_16.s register_only_2_24.s register_only_3_24.s  register_only_main.cpp -o register_only

register_only_asm: register_only.cpp
	$(CC) $(CFLAGS) -fasm-blocks  $< -o register_only_asm
	$(CC) $(CFLAGS) -fasm-blocks  -S $< -o register_only_asm.s

register_only_intrinsic: register_only.cpp
	$(CC) $(CFLAGS) -D__USE_INTRINSIC__   $< -o register_only_intrinsic
	$(CC) $(CFLAGS) -D__USE_INTRINSIC__  -S $< -o register_only_intrinsic.s


clean:
	rm -f *.o *.optrpt max_plus register_only $(OBJS) *.s
