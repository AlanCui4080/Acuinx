#ifndef _RTC_H_
#define _RTC_H_

#include<asm/io.h>
//初始化RTC并输出时间
extern void init_rtc(void);
//BCD码模式下真实时间格式
typedef struct
{
    uint32_t yr,mo,dy,hr,min,sec;
}rtime_t;
//获取RTC时间
extern int get_rtc_time(rtime_t *time);
#endif