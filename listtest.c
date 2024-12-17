#include<stdio.h>
#include<stdlib.h>
#include"list.h"

int main(){
	List(char) a = {0};

	List_append(a,(char)'i');
	List_append(a,(char)'i');
	List_append(a,(char)'i');
	List_append(a,(char)'i');
	List_append(a,(char)'i');
	List_append(a,(char)'\0');

	printf("%s\n",a.item);
	return 0;
}
