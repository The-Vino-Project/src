/*
 * Copyright (c) 2026, pinrip, rixel, et al.
 *
 * Abstract:
 *      MI boot manager entrypoint
 * Author:
 *      Chloe Pinrip
 */

#include <efi/efi.h>
#include <boot/bootlib.h>

/* Globals */
EFI_BOOT_SERVICES *gBS;
EFI_SYSTEM_TABLE *gST;
EFI_HANDLE gImageHandle;

/*
 * Main EFI application entrypoint
 */
EFI_STATUS
EFIAPI
BmMain(IN EFI_HANDLE ImageHandle, IN EFI_SYSTEM_TABLE *SystemTable)
{
    gImageHandle = ImageHandle;
    gST = SystemTable;
    gBS = SystemTable->BootServices;

    /* Disable the watchdog timer */
    gBS->SetWatchdogTimer(
        0,
        0,
        0,
        NULL
    );

    /* Reset the console */
    gST->ConOut->Reset(
        gST->ConOut,
        FALSE
    );

    PrintRaw(L"bootmgr - " BOOTMGR_VERSION "\r\n");
    for (;;);
}
