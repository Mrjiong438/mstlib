#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MST_COMPRESS_IMPLEMENTATION
#include"../../compress.h"

int main(int argc,char **argv){
    if(argc < 3)
        return -1;
    printf("%zu\n",lzss_encode_f2f(argv[1],argv[2]));
    return 0;
}
