#pragma once

typedef unsigned char u8;

void lzss_set_window(u8 *window, int window_size, int init_chr);
int unlzss(unsigned char *src, int srclen, unsigned char *dst, int dstlen);
int lzss_compress(u8 *in, int insz, u8 *out, int outsz); 
