typedef struct 
{
    unsigned long long rax,rbx,rcx,rdx,
}regs_t;
#include"tstat.h"
struct task_struct
{
volatile unsigned long long state;
unsigned long long flags;
}