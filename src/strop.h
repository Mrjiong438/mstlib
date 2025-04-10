#ifndef MST_STROP
#define MST_STROP
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

void mst_file_getpath(char dest[],const char *str);
char* mst_file_getname(const char *str);
int mst_file_makedir(const char *path);
size_t mst_string_split(size_t destptr[],size_t n,char deststr[],const char *str,const char *split_char);

#ifdef MST_STROP_IMPLEMENTATION
void mst_file_getpath(char dest[],const char *str){
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

char* mst_file_getname(const char *str){
	int i = (int)strlen(str) - 1;
	for(;i > 0;i--)
		if(str[i] == '\\' || str[i] == '/') break;
	return (char *)(str + i + 1);
}

int mst_file_makedir(const char *path){
#ifdef _WIN32
	return _mkdir(path);
#endif//WIN32
#ifdef __linux__
	return mkdir(path, 0777);
#endif//__linux__
}

size_t mst_string_split(size_t destptr[],size_t n,char deststr[],const char *str,const char *split_char){
	if(destptr == NULL) return 0;
	if(n <= 0) return 0;

	const char *spclist;
	size_t count = 0;
	if(split_char == NULL)
		spclist = " \n";
	else
		spclist = split_char;

	while(deststr == NULL)
		deststr = malloc(strlen(str) * sizeof(char));
	strcpy(deststr,str);

	if(deststr[0] != '\0'){
		destptr[count++] = 0;
	}
	for(size_t i = 1;i < strlen(str);i++){
		if (count >= n) return count;
		if(strchr(spclist,deststr[i]) != NULL){
			deststr[i] = '\0';
		}else if(deststr[i - 1] == '\0'){
			destptr[count++] = i;
		}
	}
	return count;

}
/* size_t mst_string_split(size_t destptr[],size_t n,char deststr[],const char *str,const char *split_char){ */
size_t mst_string_list_ull(unsigned long long dest[],size_t n,const char *str){
	if(n <= 0) return 0;
	size_t count = 0;
	memset(dest,0,n * sizeof(dest[0]));
	if(str[0] <= '9' && str[0] >= '0'){
		dest[count] = dest[count] * 10 + str[0] - '0';
		/* printf("i:0,c:%c,count:%zu\n",str[0],count); */
	}
	for(size_t i = 1;i <= strlen(str);i++){
		if (count >= n) return count;
		/* printf("i:%zu,c:%c,count:%zu\n",i,str[i],count); */
		if(str[i] <= '9' && str[i] >= '0'){
			dest[count] = dest[count] * 10 + str[i] - '0';
		}else if(str[i - 1] >= '0' && str[i - 1] <= '9'){
			count++;
		}
	}
	return count;
}
#endif//MST_STROP_IMPLEMENTATION
#endif//MST_STROP
