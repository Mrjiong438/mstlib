.PHONY : hot all

all : ./a.out ./fuc.so

#include"../../src/hotload.c"
#include"hot.h"

./a.out : ./hotload.c ../../src/hotload.c hot.h
	gcc hotload.c -ldl
./fuc.so : ./fuc.c
	gcc -fPIC -shared fuc.c -o fuc.so
