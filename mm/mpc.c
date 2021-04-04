#include<acuinx/mpc.h>
#include<errno.h>
struct mpc_obj main_mpc{ //8Mib基础池----完全初始化
    .name="system deafult memory pool";
    .size={4,8,16,32,64,128,256,512,1024};
}
int init_mpc(){
    size_t i =0;
    while (main_mpc.size[i])
    {
        for (size_t l = 0; l < count; l++)
        {
            main_mpc.cachea[i].poola[l].addr = get_pages(NR_PAGE_PER_POOL);//完全初始化
        }
        i++;
    }
    main_mpc.nr_cnt = i;
}
void* mpc_alloc(struct mpc_obj* obj,size_t size)
{
    for (size_t i = 0; i < obj.nr_cnt; i++)
    {
        if(obj.size[i] <= size && obj.cachea[i].free_cnt)//检查大小与可用性
            for (size_t j = 0; j < obj.cachea[i].nr_cnt; j++)//挨个扫每个pool的可用计数
                if(obj.cachea[i].poola[j].free_cnt)
                    for (size_t i = 0; i < NR_ALLOCABLE_PER_POOL/64; i++)//扫位图
                        if(obj.cachea[i].poola[j].map != ULLONG_MAX)
                    
            
    }
    return -ENOMEM;
}