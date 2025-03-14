#ifndef HHOT
#define HHOT
#include"../../src/hotload.c"

typedef void (*hello_t)();
hello_t hello();

#ifndef MST_RELEASE

dylib hell = {
	.path = "./fuc.so",
	.lib = NULL,
	.fucs = (dyfuc []){
		{.name = "hello",.fuc = NULL},
		{.name = "nonono",.fuc = NULL},
		{0}
	}
};

#define hello() \
	do{ \
		hello_t fun = hell.fucs[0].fuc; \
		fun(); \
	}while(0) \

#endif//MST_RELEASE
#endif//HHOT
