#ifndef HHOT
#define HHOT

typedef void (*hello_t)();
typedef int (*add_t)(int a,int b);


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
	hello_t fun = hell.fucs[0].fuc;
	return fun();
}

int add(int a,int b){
	add_t fun = hell.fucs[2].fuc;
	return fun(a,b);
}

#endif//HHOT
