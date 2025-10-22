#ifndef MST_COMPRESS
#define MST_COMPRESS
#include<stdio.h>
#include<string.h>

#ifdef MST_COMPRESS_IMPLEMENTATION
void lzss(char *data,size_t len,FILE fp){
    unsigned char write_buf[9];
    write_buf[0] = 0x00;
}
#endif//MST_COMPRESS_IMPLEMENTATION
#endif//MST_COMPRESS
