#
# Copyright (c) 2026, pinrip, rixel, et al.
#
# Abstract:
# 	Bootloader build script
# Author:
# 	Chloe Pinrip
#

include ../mk/ntos.mk

CC = clang

CFLAGS =							\
	$(NTOS_CFLAGS)

LINK_FLAGS = 						\
	-target $(CC_TARGET)			\
	-ffreestanding 					\
	-nostdlib 						\
	-fuse-ld=lld 					\
	-Wl,-entry:BmMain 				\
	-Wl,-subsystem:efi_application

CFILES = $(shell find . -name "*.c")
OFILES = $(CFILES:.c=.o)
DFILES = $(CFILES:.c=.d)

.PHONY: all
all: bootmgr
.PHONY: bootmgr
bootmgr: $(OFILES)
	$(CC) 								\
		$(LINK_FLAGS)					\
		$(OFILES)						\
		-o $(NT_PROJECT_ROOT)/artifacts/BOOTX64.EFI

-include $(DFILES)
%.o: %.c
	$(CC) -c $< $(CFLAGS) -o $@
