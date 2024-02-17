#include "kernel.h"
#include "../cpu/isr.h"
#include "../drivers/screen.h"
#include "../libc/string.h"

void kernel_main() {
  isr_install();
  irq_install();
  kprint("\n> ");
}

void user_input(char *input) {
  if (strcmp(input, "CLEAR") == 0) {
    clear_screen();
  }

  if (strcmp(input, "EXIT") == 0) {
    asm volatile("cli");
    asm volatile("hlt");
  }

  kprint("\n> ");
}
