#ifndef MST_COMPRESS
#define MST_COMPRESS
#include<stdio.h>
#include<string.h>
//e_m2f means encode file to file
//d_f2m means decode memery to memery
//and so on
//
//get data and write least 9 byte most 17 byte to write_buf,return how many byte writed

#define la_buff_size 258

#ifdef MST_COMPRESS_IMPLEMENTATION
//is a weird implementation but basicly a changed dynamic programming way of longest common substring
//return the length of match
size_t longest_match(
        size_t *r_index,
        const void *t,const size_t tlen,
        const void *p,const size_t plen,
        size_t *buf
    ){
    unsigned char
        *targit = (unsigned char *)t,
        *parent = (unsigned char *)p;
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
//return the size of decompressed data
/* size_t lzss_decode_f2f( */
/*         const char *in_file_name,const char *out_file_name */
/*     ){ */
/*     FILE *input = NULL; */
/*     input = fopen(in_file_name,"rb"); */
/*     FILE *output = NULL; */
/*     output = fopen(out_file_name,"wb"); */
/*     unsigned char flag; */
/*     unsigned int count_flag = 8; */
/*     unsigned char buf_read[32 * 1024]; */
/*     unsigned char buf_write[32 * 1024]; */
/*     unsigned int count_bufw = 0; */
/*     size_t buf_read_len; */
/*     buf_read_len += fread(buf_read,1,32*1024,input); */

/*     for(unsigned int i = 0;i < buf_read_len;i++){ */
/*         if(count_flag == 8){ */
/*             flag = buf_read[i]; */
/*             count_flag = 0; */
/*             continue; */
/*         } */

/*         if(flag & (0x01 << count_flag) == 0x00){ */
/*             buf_write[count_bufw] = buf_read[i]; */
/*             count_bufw++; */
/*         } */
/*         else{ */
/*             unsigned int index = buf_read[i]; */
/*             unsigned int length = buf_read[i+1]; */
/*             for(unsigned int j = 0;j < length;j++){ */
/*                 buf_write[count_bufw + j] = buf_write[count_bufw - index */
/*             } */
/*         } */
/*         count_flag++; */
/*     } */
/* } */
//return the size of compressed data
size_t lzss_encode_f2f(
        const char *in_file_name,const char *out_file_name
    ){
    unsigned char buf_write[17];
    size_t match_buf[la_buff_size];
    size_t writed_byte_count = 0;
    /* buf_write[0]; */
    unsigned int count_flag = 0;
    unsigned int count_bufw = 0;
    FILE *input = NULL;
    input = fopen(in_file_name,"rb");
    FILE *output = NULL;
    output = fopen(out_file_name,"wb");
    size_t match_index;
    size_t match_length;
    size_t parent_length;
    unsigned char buf_read[32 * 2 * 1024];
    size_t endindex = 0;
    size_t encohead = 0;
    endindex += fread(buf_read,1,32*1024,input);

    buf_write[0] <<= 1;
    count_flag++;
    buf_write[1 + count_bufw] = buf_read[encohead];
    count_bufw++;
    encohead++;
    while(encohead < endindex){
        if(la_buff_size > endindex - encohead)
            parent_length = endindex - encohead;
        else
            parent_length = la_buff_size;
        match_length = longest_match(
                &match_index,
                buf_read,encohead,
                buf_read + encohead,parent_length,
                match_buf
                );
        if(match_length < 3){
            buf_write[0] <<= 1;
            count_flag++;
            buf_write[1+count_bufw] = buf_read[encohead];
            count_bufw++;
            encohead++;
        }
        else{
            buf_write[0] <<= 1;
            buf_write[0] |= 0x01;
            count_flag++;
            buf_write[1+count_bufw] = match_index;
            buf_write[1+count_bufw+1] = match_length;
            count_bufw += 2;
            encohead += match_length;
        }
        if(count_flag == 8){
            fwrite(buf_write,count_bufw+1,1,output);
            writed_byte_count += count_bufw + 1;
            count_flag = 0;
            count_bufw = 0;
        }
    }
    if(count_flag != 0){
        fwrite(buf_write,count_bufw+1,1,output);
        writed_byte_count += count_bufw+1;
    }
    /* do{ */
    /* }while(); */
    fclose(input);
    fclose(output);
    return writed_byte_count;
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
