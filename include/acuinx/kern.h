#ifndef _KERN_H_
#define _KERN_H_
#include<acuinx/spinlock.h>
typedef struct{
    spinlock_t lock;
    unsigned long long flag[4]
}kstat_t;
//内核状态
extern kstat_t g_kstat;
#define KS_SMP 0 //多处理器模式 STAT0
#define KS_KLOG 1 //内核日志是否打印至屏幕 STAT0
#endif