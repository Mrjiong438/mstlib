#include<stdio.h>
#include<stdlib.h>
#include"../src/list.h"

int main(){
	List(long) a = {0};

	List_append(a,1);
	List_append(a,2);
	List_append(a,3);
	List_append(a,4);
	List_append(a,5);

	/* List_insert(a,1,6); */
	/* List_insert(a,1,7); */
	/* List_insert(a,1,8); */
	/* List_insert(a,1,9); */
	/* List_insert(a,1,10); */

	List_pop(a);

	for(int i = 0;i < a.length;i++){
		printf("%ld\n",a.item[i]);
	}
	printf("length:%zu\n",a.length);
	printf("size:%zu\n",sizeof(a.item));

	if(a.item == NULL){
		printf("NULL\n");
	}
	return 0;
}
