section .multiboot
    dd 0x1BADB002            ; magic number
    dd 0x00                 ; flags
    dd -(0x1BADB002 + 0x00) ; checksum

section .text
global start
extern kernel_main

start:
    mov esp, stack_space

    call kernel_main

    cli
    hlt

section .bss
stack_space resb 4096

