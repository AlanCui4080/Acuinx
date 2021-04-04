/*copyright (c) 2021 AlanCui*/
#ifndef _MULTIBOOT_H_
//multiboot引导信息标签组标头
struct mbheader_t
{
    unsigned int total_size,rev;
}__attribute__((packed));
//multiboot引导信息标签头
struct mbinfo_t
{
    unsigned int type,size;
}__attribute__((packed));
//帧缓冲区标签
struct mb_fb_t //type=8
{
    struct mbinfo_t header;
    unsigned long long fbuf_addr;
}__attribute__((packed));
//内存映射表表项
struct mb_mment_t 
{
   unsigned long long base_addr,lenth;
   unsigned long type,rev; 
}__attribute__((packed));
//内存映射表标签
struct mb_mmap_t //type=6
{
   struct mbinfo_t header;
   unsigned long ent_size,ent_ver; 
   struct mb_mment_t ent_header;
}__attribute__((packed));

#define _MULTIBOOT_H_
#endif