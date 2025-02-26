.PHONY : all list filepath

all : listtest.out filepath.out

list : listtest.out
	./$<
listtest.out : listtest.c ../src/list.h
	cc -g $< -o $@

filepath : filepath.out
	./$<
filepath.out : filepath.c ../src/filepath.h
	cc -g $< -o $@
