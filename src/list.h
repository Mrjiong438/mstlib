#ifndef MST_LIST
#define MST_LIST

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

#define List_tail(_list) _list.item[_list.length - 1]

#define List(type)\
	struct{\
		size_t length;\
		size_t size;\
		type *item;\
	}

#define NEWITEM(_list,_pos,_item) \
	/* TODO custom function to add element */ \
	_list.item[_pos] = _item; \
	_list.length++; \

#define List_free(_list) \
	do{ \
		if(_list.length != 0){ \
			free(_list.item); \
			_list.item = NULL; \
			_list.length = 0; \
			_list.size = 0; \
		} \
	}while(0)

#define List_alloc(_list,_size)

#define List_append(_list,_item) \
	do{ \
		if(_list.size == 0){ \
			_list.item = malloc(sizeof(*_list.item)); \
			if(_list.item == NULL){ \
				fprintf(stderr,"%s:%d: List_append: " #_list " malloc failed %s\n", \
						__FILE__,__LINE__,strerror(errno)); \
				break; \
			} \
			_list.size++; \
		} \
		if(_list.size == _list.length){ \
			void *temp_p = realloc(_list.item,(_list.length + 1) * sizeof(*_list.item)); \
			if (temp_p == NULL){ \
				fprintf(stderr,"%s:%d: List_append: " #_list " realloc failed %s\n", \
						__FILE__,__LINE__,strerror(errno)); \
				break; \
			} \
			_list.item = temp_p; \
			_list.size++; \
		} \
		NEWITEM(_list,_list.length,_item) \
	}while(0) \
	

#define List_pop(_list) \
	do{ \
		if(_list.length == 0){ \
			fprintf(stderr,"%s:%d: List_pop: " #_list " is already empty\n", \
					__FILE__,__LINE__); \
			break; \
		} \
		if(_list.length == 1){ \
			_list.length = 0; \
			break; \
		} \
		_list.length--; \
	}while(0)

#define List_take(_list) \
	do{ \
		if(_list.length == 0){ \
			fprintf(stderr,"%s:%d: List_take: " #_list " is already empty\n", \
					__FILE__,__LINE__); \
			break; \
		} \
		if(_list.length == 1){ \
			_list.length = 0; \
			break; \
		} \
		memmove(_list.item,_list.item + 1,(_list.length - 1) * sizeof(*_list.item)); \
		_list.length--; \
	}while(0)

#define List_insert(_list,_index,_item) \
	do{ \
		if(_index == 0 && _list.length == 0){ \
			_list.item = malloc(sizeof(*_list.item)); \
			if(_list.item == NULL){ \
				fprintf(stderr,"%s:%d: List_insert: " #_list " malloc failed %s\n", \
						__FILE__,__LINE__,strerror(errno)); \
				break; \
			} \
			NEWITEM(_list,_index,_item) \
			break; \
		} \
		if (_index < 0 || _index >= _list.length){ \
			fprintf(stderr,"%s:%d: List_insert: " #_list " index is not in range\n", \
					__FILE__,__LINE__); \
			break; \
		} \
		if(_list.size == _list.length){ \
			void *temp_p = realloc(_list.item,(_list.length + 1) * sizeof(*_list.item)); \
			if (temp_p == NULL){ \
				fprintf(stderr,"%s:%d: List_append: " #_list " realloc failed %s\n", \
						__FILE__,__LINE__,strerror(errno)); \
				break; \
			} \
			_list.item = temp_p; \
			_list.size++; \
		} \
		memmove(_list.item + _index + 1, \
				_list.item + _index, \
				(_list.length - _index) * sizeof(*_list.item)); \
		NEWITEM(_list,_index,_item) \
	}while(0)

#endif
