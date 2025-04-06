#ifndef HHOT
#define HHOT
#include"../../src/hotload.h"

typedef void (*hello_t)();
typedef int (*add_t)(int a,int b);

#ifndef MST_RELEASE

dylib hell = {
	.path = "./fuc.so",
	.lib = NULL,
	.fucs = (dyfuc []){
		{.name = "hello",.fuc = NULL},
		{.name = "nonono",.fuc = NULL},
		{.name = "add",.fuc = NULL},
		{0}
	}
};

void hello(){
	void (*fun)() = hell.fucs[0].fuc;
	return fun();
}

int add(int a,int b){
	int (*fun)() = hell.fucs[2].fuc;
	return fun(a,b);
}

#endif//MST_RELEASE
#endif//HHOT
