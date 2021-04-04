#ifndef _BOPS_H_
#define _BOPS_H_
#define _find_non_zerof(va,fb) asm volatile("bsfl %%eax,%%ebx":"=b"(fb):"a"(va):)
static inline size_t find_non_zerof(unsigned long long va)
{
    size_t tmp = 0;
    _find_non_zerof(va,tmp)
    return tmp;
}

#endif