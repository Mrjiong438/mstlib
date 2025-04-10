#include<stdio.h>
#define MST_STROP_IMPLEMENTATION
#include"../../src/strop.h"


int main(int argc,const char *argv[]){
	if (argc < 2) return 1;
	char str[64];
	strcpy(str,argv[1]);
	unsigned long long dest[64];

	printf("%s\n",str);
	size_t num = mst_string_list_ull(dest,50,str);
	printf("num:%zu\n",num);

	for(size_t i = 0;i < num;i++){
		printf("%lld,",dest[i]);
	}

	return 0;
}
