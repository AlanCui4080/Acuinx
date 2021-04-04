#include<device/rtc.h>
//获取CMOS-RTC时间的封装
#define __get_rtc(addr) ({\
    out_port8(0x70,0x80 | addr);\
    in_port8(0x71);\
})
//获取RTC时间
int get_rtc_time(rtime_t *time)
{
    do
    {
        time->yr = __get_rtc(0x09) + __get_rtc(0x32) * 0x100;
        time->mo = __get_rtc(0x08);
        time->dy = __get_rtc(0x07);
        time->hr = __get_rtc(0x04);
        time->min = __get_rtc(0x02);
        time->sec = __get_rtc(0x00);
    } while (time->sec != __get_rtc(0x00));//防止Second跳变
    return 0;
}
//初始化RTC
void init_rtc(void)
{
    rtime_t tmp;
    get_rtc_time(&tmp);
}