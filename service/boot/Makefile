#
# Copyright (c) 2026, pinrip, rixel, et al.
#
# Abstract:
# 	Bootloader build script
# Author:
# 	Chloe Pinrip
#

CC = clang

CFLAGS =							\
	-target x86_64-windows-unknown 	\
	-ffreestanding 					\
	-nostdlib 						\
	-MMD							\
	-I$(NT_PROJECT_ROOT)/sdk/head

LINK_FLAGS = 						\
	-target x86_64-windows-unknown 	\
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
		-o BOOTX64.EFI

-include $(DFILES)
%.o: %.c
	$(CC) -c $< $(CFLAGS) -o $@
