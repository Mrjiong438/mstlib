#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MST_COMPRESS_IMPLEMENTATION
#include"../../compress.h"

const char* s = "I am Sam\n\nSam I am\n\nThat Sam-I-am!\nThat Sam-I-am!\nI do not like\nthat Sam-I-am!\n\nDo you like green eggs and ham?\n\nI do not like them, Sam-I-am.\nI do not like green eggs and ham.\n";

#define a1 argv[1]
#define a2 argv[2]
/* #define a1 s */
/* #define a2 (s + 29) */

int main(int argc,char **argv){
    if(argc < 2)
        return -1;
    size_t *buff = NULL;
    buff = malloc(sizeof(buff[0]) * strlen(a1));
    size_t index;
    size_t length;
    length = longest_match(&index,a1,strlen(a1),a2,strlen(a2), buff);
    /* length = longest_match(&index,a1,177,a2,148, buff); */
    printf("index:%zu,length:%zu\n",index,length);
    printf( "%s\n%*s\n%*s\n",
            a1,
            index + strlen(a2), a2,
            index + length, "^");
    return 0;
}
