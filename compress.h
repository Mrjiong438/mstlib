#ifndef MST_COMPRESS
#define MST_COMPRESS
#include<stdio.h>
#include<string.h>
//e_m2f means encode file to file
//d_f2m means decode memery to memery
//and so on
//
//get data and write least 9 byte most 17 byte to write_buf,return how many byte writed

const size_t la_buff_size = 258;

#ifdef MST_COMPRESS_IMPLEMENTATION
//is a weird implementation but basicly a changed dynamic programming way of longest common substring
//return the length of match
size_t longest_match(
        size_t *r_index,
        const unsigned char *targit,const size_t tlen,
        const unsigned char *parent,const size_t plen,
        size_t *buf
    ){
    size_t max_index = 0;
    size_t max_length = 0;
    for(size_t i = 0;i < tlen;i++){
        if(targit[i] == parent[0]){
            buf[i % plen] = 1;
            if(buf[i % plen] > max_length){
                max_length = buf[i % plen];
                max_index = i;
            }
        }
        for(size_t j = 1;j < plen && i >= j;j++){
            if(targit[i] != parent[j]){
                buf[(i-j) % plen] = 0;
            }else
            if(buf[(i-j) % plen] != 0){
                buf[(i-j) % plen]++;
            }

            if(buf[(i-j) % plen] > max_length){
                max_length = buf[(i-j) % plen];
                max_index = i-j;
            }
        }
    }
    *r_index = max_index;
    return max_length;
}
//return the size of compressed data
size_t lzss_encode_f2f(
        const char *in_file_name,const char *out_file_name,
        size_t window_size
    ){
    unsigned char buf_write[17];
    size_t writed_byte_count = 0;
    buf_write[0] = 0x00;
    unsigned char flag_mask = 0x01;
    FILE *input = NULL;
    input = fopen(in_file_name,"rb");
    FILE *output = NULL;
    output = fopen(out_file_name,"wb");
    unsigned char buf_read[32 * 1024];
    size_t endindex = 1;
    size_t encohead = 0;
    endindex += fread(buf_read,16*1024,1,input);
    do{
        while(encohead != endindex){
        }
    }while();
}
/* size_t lzss_c_m2f_pro( */
/*         const void *data,size_t len,const char *out_file, */
/*         unsigned char *sliding_buff,size_t window_size */
/*     ){ */
/*     unsigned char write_buf[17]; */
/*     size_t writed_byte_count = 0; */
/*     write_buf[0] = 0x00; */
/*     unsigned char flag_mask = 0x01; */
/*     for(size_t i = 1;i < len;){ */
/*     } */
/* } */
/* size_t lzss_c_m2m_origen( */
/*         unsigned char *data,size_t len,unsigned char *out_buff, */
/*         unsigned char *sliding_buff,size_t window_size */
/*     ){ */
/*     unsigned char write_buf[17]; */
/*     size_t writed_byte_count = 0; */
/*     write_buf[0] = 0x00; */
/*     unsigned char flag_mask = 0x01; */
/*     for(size_t i = 1;i < len;){ */
/*     } */
/* } */
#endif//MST_COMPRESS_IMPLEMENTATION
#endif//MST_COMPRESS
