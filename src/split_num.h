#ifndef SPLIT_NUM
#define SPLIT_NUM

#include<stdio.h>
#include<stdlib.h>

int split_numofi(int m,int n,int i){
	if (m < n) return -1;
	if (i >= n) return -2;
	return (m / n) + (i < (m % n));
}

#endif//SPLIT_NUM
