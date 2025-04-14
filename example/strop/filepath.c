#include<stdio.h>
#define MST_STROP_IMPLEMENTATION
#include"../../src/strop.h"


int main(int argc,const char *argv[]){
	if (argc < 2) return 1;
	size_t ptrlist[50];
	/* char *str = "114,514,1919,810,asdasd \n"; */
	char str[64];
	strcpy(str,argv[1]);
	char dest[64];
	for(size_t i = 0;i < strlen(str);i++)
		printf("%02lX ",i);
	printf("\n");
	for(size_t i = 0;i < strlen(str);i++)
		printf("%02X ",str[i]);
	printf("\n");

	size_t num = mst_string_split(ptrlist,50,dest,argv[1],",");
	printf("num:%zu\n",num);

	/* str[0] = '\0'; */
	for(size_t i = 0;i < strlen(str);i++)
		printf("%02X ",dest[i]);
	printf("\n");

	printf("%02lX ",ptrlist[0]);
	for(size_t i = 1;i < num;i++)
		printf("%*s%02lX ",(int)(3*(ptrlist[i] - ptrlist[i-1] - 1)),"",ptrlist[i]);
	printf("\n");

	printf("%s\n",dest + ptrlist[0]);
	return 0;
}
