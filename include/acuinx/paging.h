#ifndef _PAGING_H_
#define _PAGING_H_
struct pg4l_4g_t{
    unsigned long long pml4[4];
    unsigned long long pg[512][512];
}
#endif