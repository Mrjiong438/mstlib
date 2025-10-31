#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MST_COMPRESS_IMPLEMENTATION
#include"../../compress.h"

int main(int argc,char **argv){
    if(argc < 2)
        return -1;
    size_t *buff = NULL;
    buff = malloc(sizeof(buff[0]) * strlen(argv[2]));
    size_t index;
    size_t length;
    length = longest_match(&index,argv[1],strlen(argv[1]),argv[2],strlen(argv[2]), buff);
    printf( "%s\n%*s\n%*s\n",
            argv[1],
            index + strlen(argv[2]), argv[2],
            index + length, "^");
    return 0;
}
