#ifndef MST_COMPRESS
#define MST_COMPRESS
#include<stdio.h>
#include<string.h>
//e_m2f means encode file to file
//d_f2m means decode memery to memery
//and so on

#define la_buff_size 258

#ifdef MST_COMPRESS_IMPLEMENTATION
//return the index of match
size_t longest_match(
        size_t *r_length,
        const void *t,const size_t tlen,
        const void *p,const size_t plen,
        size_t *buf
    ){
    unsigned char
        *targit = (unsigned char *)t,
        *parent = (unsigned char *)p;
    size_t max_index = 0;
    size_t max_length = 0;
    memset(buf,0,tlen * sizeof(buf[0]));

    for(size_t j = 0;j < tlen - plen;j++){
        if(parent[0] == targit[j]){
            buf[j] = 1;
            max_index = j;
            max_length = 1;
        }
    }
    for(size_t j = 1;j < tlen;j++){
        if(parent[1] == targit[tlen - j] && buf[tlen - j - 1] != 0){
            buf[tlen - j] = buf[tlen - j - 1] + 1;
            if(buf[tlen - j] >= max_length){
                max_length = buf[tlen- j];
                max_index = tlen - j - max_length + 1;
            }
        }
        else{
            buf[tlen - j] = 0;
        }
    }
    buf[0] = 0;
    for(size_t i = 2;i < plen;i++){
        for(size_t j = 1;j < tlen;j++){
            if(parent[i] == targit[tlen - j] && buf[tlen - j - 1] != 0){
                buf[tlen - j] = buf[tlen - j - 1] + 1;
                if(buf[tlen - j] >= max_length){
                    max_length = buf[tlen- j];
                    max_index = tlen - j - max_length + 1;
                }
            }
            else{
                buf[tlen - j] = 0;
            }
        }
    }
    *r_length = max_length;
    return max_index;
}
//TODO:manuly encode to have a answer
//TODO:decode it!
//return the size of decompressed data
size_t lzss_decode_f2f(
        const char *in_file_name,const char *out_file_name
    ){
    FILE *input = NULL;
    input = fopen(in_file_name,"rb");
    FILE *output = NULL;
    output = fopen(out_file_name,"wb");
    unsigned char flag;
    unsigned int count_flag = 8;
    unsigned char buf_read[32 * 1024];
    unsigned char buf_write[32 * 1024];
    unsigned int count_bufw = 0;
    size_t buf_read_len;
    buf_read_len += fread(buf_read,1,4*1024,input);

}
//return the size of compressed data
size_t lzss_encode_f2f(
        const char *in_file_name,const char *out_file_name
    ){
    unsigned char buf_write[17];
    size_t match_buf[la_buff_size];
    size_t writed_byte_count = 0;
    unsigned int count_flag = 0;
    unsigned int count_bufw = 0;
    FILE *input = NULL;
    input = fopen(in_file_name,"rb");
    FILE *output = NULL;
    output = fopen(out_file_name,"wb");
    size_t match_index;
    size_t match_length;
    size_t parent_length;
    unsigned char buf_read[(256 + 258) * 2];
    size_t endindex = 0;
    size_t encohead = 0;
    endindex += fread(buf_read,1,(256 + 258),input);

    buf_write[0] = 0x00;
    count_flag++;
    buf_write[1 + count_bufw] = buf_read[encohead];
    count_bufw++;
    encohead++;
    while(encohead < endindex){
        if(la_buff_size > endindex - encohead)
            parent_length = endindex - encohead;
        else
            parent_length = la_buff_size;
        match_index =encohead - 1 - longest_match(
                &match_length,
                buf_read,encohead + parent_length,
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
