/*copyright (c) 2021 AlanCui*/
#include <asm/sys.h>
#include <acuinx/mem.h>
#include <acuinx/multiboot.h>
extern unsigned long * __mbt_ptr = 0;
unsigned long long g_fbaddr = 0;
void kstart(void)
{
    struct mbinfo_t * iptr = __mbt_ptr;
    while(1)
    {
        if(iptr->type == 8)
            g_fbaddr = ((struct mb_fb_t *)iptr)->fbuf_addr;
        else if(iptr->type == 6)
            if(((struct mb_mmap_t *)iptr)->ent_ver != 0)
                painc("do not support this mmap info");
            else
                #define mmaptr ((struct mb_mmap_t *)iptr) 
                #define mmdesa(nr) ((&(mmaptr->ent_header))+nr)
                for (size_t i = 0; i < (mmaptr->header.size - 8) /mmaptr->ent_size ; i++)
                {
                    add_memdes(mmdesa(i).base_addr,mmdesa(i).(unsigned long long)lenth,mmdesa(i).type);
                }
                #undef mmaptr
                #undef mmdesa(nr)
                

    }
    hlt();
}