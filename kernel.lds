ENTRY(_ksetup)
SECTIONS
{
    . = 1M;
    .intpg1M ALIGN(4K):
    {
        *(.intpg1M)
    }
    .intpg2M ALIGN(4K):
    {
        *(.intpg2M)
    }
    .text ALIGN(8):
    {
        *(.mbt2std)
        *(.text)
    }
    .rodata :
    {
        *(.rodata)
    }
    __bss = .;
    .bss :
    {
        *(.bss)
    }
    __ebss = .;
}