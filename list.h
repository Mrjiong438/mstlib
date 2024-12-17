#ifndef MST_LIST
#define MST_LIST

#include<stddef.h>
#include<stdio.h>
#include<stdlib.h>

#define List(type)		\
	struct{				\
		type *item;		\
		size_t length;	\
	}

#define list_append(l,i)                                                     \
	{                                                                        \
		if(sizeof(*l.item) != sizeof(i)){                                    \
			fprintf(stderr,"list_append:wrong type\n");                      \
		}                                                                    \
		if(l.length == 0){                                                   \
			l.item = malloc(sizeof(*l.item));                                \
			if(l.item != NULL)                                               \
				l.length++;                                                  \
			else                                                             \
				perror("l.item malloc failed");                              \
		}                                                                    \
		else{                                                                \
			void *temp_p = realloc(l.item,(l.length+1)*sizeof(*l.item));     \
			if (temp_p != NULL){                                             \
				l.item = temp_p;                                             \
				l.length++;                                                  \
			}                                                                \
			else                                                             \
				perror("l.item append realloc failed");                      \
		}                                                                    \
                                                                             \
	}while(0)

#endif
