#include<stdio.h>
#include"../../src/hotload.c"
#include"hot.h"

int main(){
	load_lib(&hell);
	hello();
	getc(stdin);
	load_lib(&hell);
	hello();
	return 0;
}
