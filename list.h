#ifndef MST_LIST
#define MST_LIST

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define List_head(_list) _list.item[0]
#define List_tail(_list) _list.item[_list.length]

#define List(type)		\
	struct{				\
		type *item;		\
		size_t length;	\
	}

#define List_append(_list,_item) \
	do{ \
		if(_list.length == 0){ \
			_list.item = malloc(sizeof(*_list.item)); \
			if(_list.item != NULL){ \
				_list.length++; \
				_list.item[0] = _item; \
			} \
			else \
				perror("List_append: " #_list " malloc failed"); \
		} \
		else{ \
			void *temp_p = realloc(_list.item,(_list.length + 1) * sizeof(*_list.item)); \
			if (temp_p != NULL){ \
				_list.item = temp_p; \
				_list.length++; \
				_list.item[_list.length - 1] = _item; \
			} \
			else \
				perror("List_append: " #_list " realloc failed"); \
		} \
	}while(0) \
	

#define List_pop(_list) \
	do{ \
		if(_list.length > 1){ \
			void *temp_p = realloc(_list.item,(_list.length - 1) * sizeof(*_list.item)); \
			if (temp_p != NULL){ \
				_list.item = temp_p; \
				_list.length--; \
			} \
			else \
				perror("List_pop: " #_list " realloc failed"); \
		} \
		else if(_list.length == 1){ \
			free(_list.item); \
			_list.item = NULL; \
			_list.length = 0; \
		} \
		else{ \
			perror("List_pop: " #_list " is already empty"); \
		} \
	}while(0)

#define List_take(_list) \
	do{ \
		if(_list.length > 1){ \
			memmove(_list.item,_list.item + 1,(_list.length - 1) * sizeof(*_list.item)); \
			void *temp_p = realloc(_list.item,(_list.length - 1) * sizeof(*_list.item)); \
			if (temp_p != NULL){ \
				_list.item = temp_p; \
				_list.length--; \
			} \
			else \
				perror("List_take: " #_list " realloc failed"); \
		} \
		else if(_list.length == 1){ \
			free(_list.item); \
			_list.item = NULL; \
			_list.length = 0; \
		} \
		else{ \
			perror("List_take: " #_list " is already empty"); \
		} \
	}while(0)

#endif
