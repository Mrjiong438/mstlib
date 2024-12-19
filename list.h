#ifndef MST_LIST
#define MST_LIST

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

#define List_head(_list) _list.item[0]
#define List_tail(_list) _list.item[_list.length - 1]

#define List(type)		\
	struct{				\
		type *item;		\
		size_t length;	\
		char opration_result; \
	}

#define List_append(_list,_item) \
	do{ \
		if(_list.length == 0){ \
			_list.item = malloc(sizeof(*_list.item)); \
			if(_list.item == NULL){ \
				fprintf(stderr,"List_append: " #_list " malloc failed %s\n",strerror(errno)); \
				_list.opration_result = 1; \
				break; \
			} \
			/* TODO custom function to add element */ \
			_list.item[0] = _item; \
			_list.length = 1; \
			_list.opration_result = 0; \
			break; \
		} \
		void *temp_p = realloc(_list.item,(_list.length + 1) * sizeof(*_list.item)); \
		if (temp_p == NULL){ \
			fprintf(stderr,"List_append: " #_list " realloc failed %s\n",strerror(errno)); \
			_list.opration_result = 1; \
			break; \
		} \
		_list.item = temp_p; \
		/* TODO custom function to add element */ \
		_list.item[_list.length - 1] = _item; \
		_list.length++; \
		_list.opration_result = 0; \
	}while(0) \
	

#define List_pop(_list) \
	do{ \
		if(_list.length == 0){ \
			fprintf(stderr,"List_take: " #_list " is already empty\n"); \
			_list.opration_result = 1; \
			break; \
		} \
		if(_list.length == 1){ \
			free(_list.item); \
			_list.item = NULL; \
			_list.length = 0; \
			_list.opration_result = 0; \
			break; \
		} \
		void *temp_p = realloc(_list.item,(_list.length - 1) * sizeof(*_list.item)); \
		if (temp_p == NULL){ \
			fprintf(stderr,"List_pop: " #_list " realloc failed %s\n",strerror(errno)); \
			_list.opration_result = 1; \
			break; \
		} \
		_list.item = temp_p; \
		_list.length--; \
		_list.opration_result = 0; \
	}while(0)

#define List_take(_list) \
	do{ \
		if(_list.length == 0){ \
			fprintf(stderr,"List_take: " #_list " is already empty\n"); \
			_list.opration_result = 1; \
			break; \
		} \
		if(_list.length == 1){ \
			free(_list.item); \
			_list.item = NULL; \
			_list.length = 0; \
			_list.opration_result = 0; \
			break; \
		} \
		memmove(_list.item,_list.item + 1,(_list.length - 1) * sizeof(*_list.item)); \
		void *temp_p = realloc(_list.item,(_list.length - 1) * sizeof(*_list.item)); \
		if (temp_p == NULL){ \
			fprintf(stderr,"List_take: " #_list " realloc failed %s\n",strerror(errno)); \
			_list.opration_result = 1; \
			break; \
		} \
		_list.item = temp_p; \
		_list.length--; \
		_list.opration_result = 0; \
	}while(0)

#define List_insert(_list,_index,_item) \
	do{ \
		if(_index == 0 && _list.length == 0){ \
			_list.item = malloc(sizeof(*_list.item)); \
			if(_list.item == NULL){ \
				fprintf(stderr,"List_insert: " #_list " malloc failed %s\n",strerror(errno)); \
				_list.opration_result = 1; \
				break; \
			} \
			/* TODO custom function to add element */ \
			_list.item[_index] = _item; \
			_list.length++; \
			_list.opration_result = 0; \
			break; \
		} \
		if (_index < 0 || _index >= _list.length){ \
			fprintf(stderr,"List_insert: " #_list " index is not in range\n"); \
			_list.opration_result = 1; \
			break; \
		} \
		void *temp_p = realloc(_list.item,(_list.length + 1) * sizeof(*_list.item)); \
		if (temp_p == NULL){ \
			fprintf(stderr,"List_insert: " #_list " realloc failed %s\n",strerror(errno)); \
			_list.opration_result = 1; \
			break; \
		} \
		_list.item = temp_p; \
		memmove(_list.item + _index + 1, \
				_list.item + _index, \
				(_list.length - _index) * sizeof(*_list.item)); \
		/* TODO custom function to add element */ \
		_list.item[_index] = _item; \
		_list.length++; \
		_list.opration_result = 0; \
	}while(0)

#endif
