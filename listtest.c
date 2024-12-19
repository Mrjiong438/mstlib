#include<stdio.h>
#include<stdlib.h>
#include"list.h"

int main(){
	List(int) a = {0};

	List_insert(a,0,1);
	List_insert(a,0,2);
	List_insert(a,0,3);
	List_insert(a,0,4);
	List_insert(a,0,5);

	for(int i = 0;i < a.length;i++){
		printf("%d\n",a.item[i]);
	}
	printf("length:%zu\n",a.length);

	if(a.item == NULL){
		printf("NULL\n");
	}
	return 0;
}
