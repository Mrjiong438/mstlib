.PHONY : hot all

all : ./a.out ./fuc.so


./a.out : ./hotload.c
	gcc hotload.c -ldl
./fuc.so : ./fuc.c
	gcc -fPIC -shared fuc.c -o fuc.so
