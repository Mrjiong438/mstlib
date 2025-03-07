#include<stdio.h>
#include<stdlib.h>
#include"../../src/split_num.h"

int main(int argc,const char *argv[]){
	if(argc < 3) return 1;
	if(argc > 3) return 1;
	int m,n;
	m = atoi(argv[1]);
	n = atoi(argv[2]);
	for(int i = 0;i < n;i++)
		printf("%d ",split_numofi(m,n,i));
	return 0;
}
