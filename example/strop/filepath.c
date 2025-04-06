#include<stdio.h>
#define MST_STROP_IMPLEMENTATION
#include"../../src/strop.h"


int main(int argc,const char *argv[]){
	size_t ptrlist[50];
	char *str = "114 514 1919 810 asdasd \n";
	char dest[64];
	for(size_t i = 0;i < strlen(str);i++)
		printf("%02lX ",i);
	printf("\n");
	for(size_t i = 0;i < strlen(str);i++)
		printf("%02X ",str[i]);
	printf("\n");
	size_t num = mst_string_split(ptrlist,50,dest,str,NULL);
	/* str[0] = '\0'; */
	for(size_t i = 0;i < strlen(str);i++)
		printf("%02X ",dest[i]);
	printf("\n");

	printf("%02lX ",ptrlist[0]);
	for(size_t i = 1;i < num;i++)
		printf("%*s%02lX ",(int)(3*(ptrlist[i] - ptrlist[i-1] - 1)),"",ptrlist[i]);
	printf("\n");
	return 0;
}
