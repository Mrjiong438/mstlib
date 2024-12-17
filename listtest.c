#include<stdio.h>
#include<stdlib.h>
#include"list.h"

int main(){
	int b;
	list(char) a={0};
	if(a.item==NULL)
		printf("null\n");
	printf("%zu\n",a.length);
	list_append(a,'i');
	return 0;
}
