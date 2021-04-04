#include <acuinx/mem.h>
struct mem_des_t g_memdesa[NR_MEMDES];
int memdes_ptr;
int add_memdes(unsigned long long addr,unsigned long long lenth,unsigned long long type)
{
    if(memdes_ptr = NR_MEMDES)
        painc("kernel memory description overflow");
    g_memdesa[memdes_ptr].base_addr = addr;
    g_memdesa[memdes_ptr].lenth = lenth;
    g_memdesa[memdes_ptr].type = type;
    return 0;
}