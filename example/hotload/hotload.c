#include<stdio.h>
#define MST_HOT_LOAD_IMPLEMENTATION
#include"../../src/hotload.c"
#include"hot.h"

int main(){
	mst_load_lib(&hell);
	hello();
	getc(stdin);
	mst_load_lib(&hell);
	hello();
	return 0;
}
