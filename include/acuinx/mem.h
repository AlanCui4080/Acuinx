#ifndef _MEM_H_
#define _MEM_H_

#include<types.h>
//内存描述符最大数量
#define NR_MEMDES 256
//内存段描述符
struct mem_des_t{
    unsigned long long base_addr,lenth,type;
}
//添加一个表项到内存描述符表中
extern int add_memdes(unsigned long long addr,unsigned long long lenth,unsigned long long type);
//内存描述符表
extern struct mem_des_t g_memdesa[NR_MEMDES];
extern get_pages(size_t cnt);
#endif