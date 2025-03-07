#include<stdio.h>
#include"../../src/filepath.h"


int main(int argc,const char *argv[]){
	char path[64];
	file_getpath(path,argv[0]);
	printf("%s\n",path);
	printf("%s\n",file_getname(argv[0]));
	return 0;
}
