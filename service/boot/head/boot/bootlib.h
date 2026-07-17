/*
 * Copyright (c) 2026, pinrip, rixel, et al.
 *
 * Abstract:
 *      Boot library defs
 * Author:
 *      Chloe Pinrip
 */

#ifndef _BOOT_BOOTLIB_H_
#define _BOOT_BOOTLIB_H_ 1

/* Boot manager version */
#define BOOTMGR_VERSION "v0.0.1"

/*
 * Print a raw string to the console, unformatted.
 */
#define PrintRaw(Str)               \
    gST->ConOut->OutputString(      \
        gST->ConOut,                \
        (Str)                       \
    )

#endif  /* !_BOOT_BOOTLIB_H_ */
