#ifndef HHOT
#define HHOT

typedef void (*hello_t)();

dylib hell = {
	.path = "./fuc.so",
	.lib = NULL,
	.fucs = (dyfuc []){
		{.name = "hello",.fuc = NULL},
		{.name = "nonono",.fuc = NULL},
		{0}
	}
};

void hello(){
	hello_t fun = hell.fucs[0].fuc;
	fun();
}

#endif//HHOT
