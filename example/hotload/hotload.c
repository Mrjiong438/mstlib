#include<stdio.h>
#include"../../src/hotload.c"

int main(){
	dylib hello = {
		.path = "./fuc.so",
		.lib = NULL,
		.fucs = (dyfuc []){
			{.name = "hello",.fuc = NULL},
			{.name = "nonono",.fuc = NULL},
			{0}
		}
	};
	printf("%d\n",hello.fucs[2].name == NULL);
	return 0;
}
