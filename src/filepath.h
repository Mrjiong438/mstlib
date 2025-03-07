#include<stdlib.h>
#include<string.h>

void file_getpath(char dest[],const char *str){
	int i = (int)strlen(str)-1;
	while(str[i] != '/'){
		if(i==0)
			break;
		i--;
	}
	if (dest == NULL){
		return;
	}
	strncpy(dest,str,i+1);
	dest[i] = '\0';
}

char* file_getname(const char *str){
	int i = (int)strlen(str)-1;
	while(str[i] != '/'){
		if(i==0)
			break;
		i--;
	}
	return (char *)(str + i + 1);
}
