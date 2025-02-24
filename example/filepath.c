#include<stdio.h>
#include"filepath.h"


int main(int argc,const char **argv){
	char *path = NULL;
	get_filepath(&path,argv[0]);
	if (path == NULL)
		return 1;
	printf("%s\n",path);
	return 0;
}
