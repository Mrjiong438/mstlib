#ifndef FILE_PATH
#define FILE_PATH
#include<stdlib.h>
#include<string.h>

#ifdef _WIN32
    /* #include<Windows.h> */
    #include<direct.h>
#endif//WIN32
#ifdef __linux__
    #include<sys/stat.h>
    #include<sys/types.h>
#endif

void file_getpath(char dest[],const char *str);
char* file_getname(const char *str);
int makedir(const char *path);

#ifdef FILE_PATH_IMPLEMENTATION
void file_getpath(char dest[],const char *str){
	int i = (int)strlen(str)-1;
	while(str[i] == '\\' || str[i] != '/'){
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
	int i = (int)strlen(str) - 1;
	for(;i > 0;i--)
		if(str[i] == '\\' || str[i] == '/') break;
	return (char *)(str + i + 1);
}

int makedir(const char *path){
#ifdef _WIN32
	return _mkdir(path);
#endif//WIN32
#ifdef __linux__
	return mkdir(path, 0777);
#endif//__linux__
}

#endif//FILE_PATH_IMPLEMENTATION
#endif//FILE_PATH
