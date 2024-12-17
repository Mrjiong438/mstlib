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

#define List_append(_list,_item)                                                     \
	{                                                                        \
		if(_list.length == 0){                                                   \
			_list.item = malloc(sizeof(*_list.item));                                \
			if(_list.item != NULL){                                              \
				_list.length++;                                                  \
				_list.item[0] = _item;                                               \
			}                                                                \
			else                                                             \
				perror("_list.item malloc failed");                              \
		}                                                                    \
		else{                                                                \
			void *temp_p = realloc(l.item,(_list.length+1)*sizeof(*_list.item));     \
			if (temp_p != NULL){                                             \
				_list.item = temp_p;                                             \
				_list.length++;                                                  \
				_list.item[l.length-1] = _item;                                        \
			}                                                                \
			else                                                             \
				perror("_list.item append realloc failed");                      \
		}                                                                    \
	}while(0)

#endif
