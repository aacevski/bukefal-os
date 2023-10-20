ENTRY(start)

SECTIONS
{
    . = 0x00100000; /* Setting the location counter to 1MB */

    .multiboot ALIGN(4) :
    {
        KEEP(*(.multiboot)) /* Multiboot header */
    }

    .text ALIGN(4096) :
    {
        *(.text) /* Our kernel's text segment (code) */
    }

    .data ALIGN(4096) :
    {
        *(.data) /* Our kernel's data segment */
    }

    .bss ALIGN(4096) :
    {
        *(.bss) /* Our kernel's bss segment */
    }
}

