.PHONY : hot all clear

all : ./a.out ./fuc.so

clear : 
	rm a.out fuc.so

./a.out : ./hotload.c ./hot.h
	gcc hotload.c -ldl
./fuc.so : ./fuc.c
	gcc -fPIC -shared fuc.c -o fuc.so
