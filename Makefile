MKDIR = $(AINX_ENV)/build
GAS = as
LD = ld
CC = gcc
CINC = -I $(AINX_ENV)/include
CMKFLG = -mcmodel=large -fno-builtin $(CINC) -m64 -c -Wall -nostdinc -nostdlib
$(MKDIR)/ainxk:$(MKDIR)/kheader.o $(MKDIR)/kstart.o
	ld -z max-page-size=0x1000 -m elf_i386 -T kernel.lds --build-id=none $(MKDIR)/*.o  -o $(MKDIR)/ainxk
$(MKDIR)/kheader.o:kheader.S
	$(GAS) --32 -o $(MKDIR)/kheader.o kheader.S
$(MKDIR)/kstart.o:kstart.c
	$(CC) $(CMKFLG) -o $(MKDIR)/kstart.o kstart.c
	