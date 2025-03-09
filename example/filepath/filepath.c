#include<stdio.h>
#define MST_FILE_IMPLEMENTATION
#include"../../src/file.h"


int main(int argc,const char *argv[]){
	char path[64];
	mst_file_getpath(path,argv[0]);
	printf("%s\n",path);
	printf("%s\n",mst_file_getname(argv[0]));
	return 0;
}
