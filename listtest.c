#include<stdio.h>
#include<stdlib.h>
#include"list.h"

int main(){
	List(int) a = {0};

	List_append(a,1);
	List_append(a,2);
	List_append(a,3);
	List_append(a,4);
	List_append(a,5);

	for(int i = 0;i < a.length;i++){
		printf("%d\n",a.item[i]);
	}
	printf("\n");

	List_take(a);
	List_take(a);
	List_take(a);

	for(int i = 0;i < a.length;i++){
		printf("%d\n",a.item[i]);
	}

	if(a.item == NULL){
		printf("NULL\n");
	}
	return 0;
}
