extern uint8_t unifont[65534][32];
struct grap_info g_sysgrap;
void kputchar(unsigned long x, unsigned long y, char chr, unsigned long fcolor, unsigned long bcolor)
{
    addr_t *target_addr = (void *)(g_sysgrap.base_addr + (y * g_sysgrap.res_x * 32 * 2 + x * 32));
    if (chr == 0x00)
        chr = ' ';
    for (size_t i = 0; i < 16; i++)
    {
        for (size_t l = 1; l <= 8; l++)
        {
            if (((unifont[(uint32_t)chr][i] >> (8 - l)) & 1UL) == 1)
                *(unsigned long *)target_addr = fcolor;
            else
                *(unsigned long *)target_addr = bcolor;
            target_addr += 4;
        }
        target_addr -= 32;
        target_addr += g_sysgrap.res_x * 4;
    }
}
void kputwchar(unsigned long x,unsigned long y,wchar_t wchr,unsigned long fcolor,unsigned long bcolor) //Exp
{
    if (wchr == 0x00)
        wchr = L' ';   
    addr_t * target_addr = (void *)(g_sysgrap.base_addr + (y*g_sysgrap.res_x*32*2 + x*32));
    for (size_t i = 0; i < 32; i+=2)
    {
        for (size_t l = 1; l <=16; l++)
        {
            if  (((uint16_t)((uint16_t)unifont[wchr][i]<<8)+unifont[wchr][i+1] >> (16-l) )& 1UL)
                *(unsigned long *)target_addr = fcolor;
            else
                *(unsigned long *)target_addr = bcolor;
            target_addr += 4;
        
        }
        target_addr -=64 ;
        target_addr += g_sysgrap.res_x*4;
    }
    
}
void kputstr(unsigned long x, unsigned long y, char *chr, unsigned long fcolor, unsigned long bcolor)
{
    unsigned long lr = y;
    for (size_t i = 0; *chr != '\0'; i++)
    {
        switch (*chr)
        {
        case '\n':
            lr++;
            break;
        default:
            kputchar(x + i, lr, *chr, fcolor, bcolor);
            break;
        }w
        chr++;
    }
}
void kputwstr(unsigned long x, unsigned long y, wchar_t *chr, unsigned long fcolor, unsigned long bcolor)
{
    unsigned long lr = y;
    for (size_t i = 0; *chr != 0; i++)
    {
        switch (*chr)
        {
        case '\n':
            lr++;
            break;
        default:
            if (*chr < 128 && *chr > 32)
            {
                kputchar(x, lr, *chr, fcolor, bcolor);
                x += 2;
            }
            else
            {
                kputwchar(x, lr, *chr, fcolor, bcolor);
                x += 1;
            }
            break;
        }
        chr++;
    }
}
void kputwstrc(unsigned long x, unsigned long y, wchar_t *chr, unsigned long fcolor, unsigned long bcolor, unsigned long l)
{
    unsigned long lr = y;
    for (size_t i = 0; i < l; i++)
    {
        switch (*chr)
        {
        case '\n':
            lr++;
            break;
        default:
            kputwchar(x + 2*i, lr, *chr, fcolor, bcolor);
            break;
        }
        chr++;
    }
}
void kputstrc(unsigned long x, unsigned long y, char *chr, unsigned long fcolor, unsigned long bcolor, unsigned long l)
{
    unsigned long lr = y;
    for (size_t i = 0; i < l; i++)
    {
        switch (*chr)
        {
        case '\n':
            lr++;
            break;
        default:
            kputchar(x + i, lr, *chr, fcolor, bcolor);
            break;
        }
        chr++;
    }
}