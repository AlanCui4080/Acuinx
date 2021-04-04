.code32
.section .mbt2_header
tag_start:
.long 0xE85250D6
.long 0
.long tag_end-tag_start
.long -1*(tag_end-tag_start + 0 +  0xE85250D6)
.vbe:
.short 5
.short 0
.long 20
.long 1024
.long 768
.long 32
.vbe_e:
.long 0 #align
tag_end:
.long 0xffffffffffffffff
#----setup kernel----
.section .ksetup_text
_ksetup:
.globl _ksetup
cmpl %eax,0x36d76289
je .mbt2_vaild #check that OS has been booted by multiboot2 
cli
hlt
.mbt2_vaild:
movl %ebx,(__mbt_ptr)
#get cpu infomation
movl $0x80000002,%eax
cpuid
movl %eax,(__logo_cpu)
movl %ebx,(4+__logo_cpu)
movl %ecx,(8+__logo_cpu)
movl %edx,(16+__logo_cpu)
movl $0x80000003,%eax
cpuid
movl %eax,(20+__logo_cpu)
movl %ebx,(24+__logo_cpu)
movl %ecx,(28+__logo_cpu)
movl %edx,(32+__logo_cpu)
movl $0x80000004,%eax
cpuid
movl %eax,(36+__logo_cpu)
movl %ebx,(40+__logo_cpu)
movl %ecx,(44+__logo_cpu)
movl %edx,(48+__logo_cpu)

#init pgd
movl $.pde,%eax
orl %eax,1
movl %eax,(.pdpte)
movl $0,%ecx
movl $.pde,%eax
addl 4,%eax
.lop_setgde:#map the first 32mib to linear address aera
    andl %ecx,(%eax)
    addl $0x200000,%ecx
    addl $8,%eax
    cmpl $.pde_e, %eax
    jl .lop_setgde

#into long mode
.byte 0x66
lgdt (__TEMP_PTR64) #load gdt
movw $0x10,%ax
movw %ax,%ds #load segment reg
movw %ax,%es
movw %ax,%fs
movw %ax,%ss
movl $__TEMP_STACK,%esp #load temp stack
movl $__TEMP_STACK,%ebp

movl %cr4,%eax #enable PAE
orl $0x20,%eax
movl %eax,%cr4

movl $.pdpte,%eax #set CR3
movl %eax,%cr4

movl $0xc0000080,%ecx #enable long mode
rdmsr
orl $0x100,%eax
wrmsr

movl %cr0,%eax #enable PE&PG
orl $0x80000001,%eax
movl %eax,%cr0

pushl $0x10
pushl $__TEMP_STACK
pushl $0x10
pushl $kstart
iret
nop
nop
nop
hlt

__logo_cpu:.fill 53,8,0 
.globl __logo_cpu
__mbt_ptr: .fill 4,8,0
.globl __mbt_ptr
__TEMP_STACK: .fill 4096,8,0 #4kb temp stack

.align 4096
.pdpte:
.quad 0x0
.align 4096
.pde:
.fill 64,8,0x0083
.pde_e:

.gdt:
__TEMP_KERN_NULL: 
                .long 0x00
                .long 0x000000
__TEMP_KERN_CS64: 
                .long 0x00
                .long 0x002098
__TEMP_KERN_DS64: 
                .long 0x00
                .long 0x000092
.gdt_e:

__TEMP_PTR64: .word .gdt_e-.gdt-1
              .long .gdt
