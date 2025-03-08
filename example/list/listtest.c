#include<stdio.h>
#include<stdlib.h>
#include"../../src/list.h"

typedef List(long)longlist;

int main(){
	longlist *a = NULL;
	a = malloc(sizeof(longlist));
	memset(a,0,sizeof(longlist));

	List_append((*a),1);
	List_append((*a),2);
	List_append((*a),3);
	List_append((*a),4);
	List_append((*a),5);

	List_pop((*a));

	List_insert((*a),1,6);
	List_insert((*a),1,7);
	List_insert((*a),1,8);
	List_insert((*a),1,9);
	List_insert((*a),1,10);

	for(size_t i = 0;i < a->length;i++){
		printf("%ld\n",a->item[i]);
	}
	printf("length:%zu\n",a->length);
	printf("size:%zu\n",a->size);

	if(a->item == NULL){
		printf("NULL\n");
	}
	return 0;
}
