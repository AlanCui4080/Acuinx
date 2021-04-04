#ifndef _SPINLOCK_H_
#define _SPINLOCK_H_

typedef struct {
    volatile unsigned int lock;
}spinlock_t;

//获得自旋锁,sp是*spinlock_t
#define spin_lock(sp) do{\
asm volatile("movq $1,%%rax         \n\t" \
            "1:                     \n\t" \
            "lock xchgq %%rax,(%%rbx)    \n\t" \
            "cmpq $0,%%rax          \n\t" \
            "jne 1b                 \n\t" \
            ::"b"(&(sp->lock)):"rax"\
            )\
}while(0)\
//非堵塞获得自旋锁,成功返回0
__attribute__((always_inline)) static inline int spin_try_lock(spin_lock_t* sp){
    unsigned long long v;
    _spin_try_lock(sp,v);
    return v;
}
//非堵塞获得自旋锁,sp是*spinlock_t,va是完成后的锁值变量,成功返回0
#define _spin_try_lock(sp,va) do{\
asm volatile("movq $1,%%rax         \n\t" \
            "lock xchgq %%rax,(%%rbx)    \n\t" \
            "cmpq $0,%%rax          \n\t" \
            :"=a"(va):"b"(&(sp->lock)):\
            )\
}while(0)\
//解自旋锁,sp是*spinlock_t,未拥有锁而执行的行为是未知的
#define spin_unlock(sp) asm volatile ("lock movq $0,(%%rax)"::"a"(&(sp->lock)):)

#endif 