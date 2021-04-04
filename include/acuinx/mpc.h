#ifndef _MPC_H_
#define _MPC_H_

#include<types.h>
#include<limits.h>
#include<mem.h>
#define NR_CACHE 16
#define NR_POOL 16
#define MIN_ALLOCABLE_SIZE 4
#define PAGE_SIZE 409609
#define NR_PAGE_PER_POOL 8
#define NR_ALLOCABLE_POOL ((PAGE_SIZE*NR_PAGE_PER_POOL)/MIN_ALLOCABLE_SIZE)
struct mpc_pool
{
    void *addr;
    size_t free_cnt,nr_cnt
    unsigned long long map[NR_ALLOCABLE_POOL/64]
}
struct mpc_cache
{
    size_t stat[NR_POOL],free_cnt,nr_cnt;
    struct mpc_pool poola[NR_POOL];
}
struct mpc_obj
{
    char name[64];
    size_t size[NR_CACHE],nr_cnt;
    struct mpc_cache cachea[NR_CACHE];  
};
#endif 
