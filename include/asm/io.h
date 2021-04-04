#ifndef _IO_H_
#define _IO_H_
__attribute__((always_inline)) inline static uint32_t in_port32(uint16_t port)
{
    uint32_t tmp = 0;
    __asm__ __volatile__("inl %%dx,%%eax"
                         : "=a"(tmp)
                         : "d"(port)
                         :);
    return tmp;
}
__attribute__((always_inline)) inline static uint16_t in_port16(uint16_t port)
{
    uint16_t tmp = 0;
    __asm__ __volatile__("inw %%dx,%%ax"
                         : "=a"(tmp)
                         : "d"(port)
                         :);
    return tmp;
}
__attribute__((always_inline)) inline static uint8_t in_port8(uint16_t port)
{
    uint8_t tmp = 0;
    __asm__ __volatile__("inb %%dx,%%al"
                         : "=a"(tmp)
                         : "d"(port)
                         :);
    return tmp;
}
__attribute__((always_inline)) inline static void out_port32(uint16_t port, uint32_t valve)
{
    __asm__ __volatile__("outl %%eax,%%dx" ::"d"(port), "a"(valve)
                         :);
}
__attribute__((always_inline)) inline static void out_port16(uint16_t port, uint16_t valve)
{
    __asm__ __volatile__("outw %%ax,%%dx" ::"d"(port), "a"(valve)
                         :);
}
__attribute__((always_inline)) inline static void out_port8(uint16_t port, uint8_t valve)
{
    __asm__ __volatile__("outb %%al,%%dx" ::"d"(port), "a"(valve)
                         :);
}

#endif