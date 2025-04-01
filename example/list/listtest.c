#include<stdio.h>
#include<stdlib.h>
#include"../../src/list.h"

typedef mst_list(long)longlist;

int main(){
	longlist *a = NULL;
	a = malloc(sizeof(longlist));
	memset(a,0,sizeof(longlist));

	mst_list_append((*a),1);
	mst_list_append((*a),2);
	mst_list_append((*a),3);
	mst_list_append((*a),4);
	mst_list_append((*a),5);

	mst_list_pop((*a));

	mst_list_insert((*a),1,6);
	mst_list_insert((*a),1,7);
	mst_list_insert((*a),1,8);
	mst_list_insert((*a),1,9);
	mst_list_insert((*a),1,10);

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
