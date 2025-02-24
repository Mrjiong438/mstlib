#include<stdlib.h>
#include<string.h>

void get_filepath(char **pointer,const char *str){
	int i = (int)strlen(str)-1;
	while(str[i] != '/'){
		if(i==0)
			break;
		i--;
	}
	*pointer = (char*)malloc((i+1) * sizeof(char));
	if (*pointer == NULL){
		return;
	}
	strncpy(*pointer,str,i+1);
	(*pointer)[i] = '\0';
}
