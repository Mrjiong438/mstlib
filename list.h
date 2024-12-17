#include<stddef.h>
#include<stdio.h>

#define List(type)		\
	struct{				\
		type *item;		\
		size_t length;	\
	}

typedef struct{
	void *item;
	size_t length;
}list;

int list_append(list l,void *i){
	if(sizeof(l.item) != sizeof(i)){
		/* fprintf(stderr,"list_append:wrong type\n"); */
		return 1;
	}
	return 0;
}

/* #define list_append(l,i)									\ */
/* 	{																\ */
/* 		if(sizeof(l.item) != sizeof(i)){							\ */
/* 			/1* fprintf(stderr,"list_append:wrong type\n"); *1/		\ */
/* 			return 1;												\ */
/* 		}															\ */
/* 		return 0;													\ */
/* 	}while(0) */
