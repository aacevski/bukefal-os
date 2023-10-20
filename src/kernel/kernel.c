char *video_memory = (char *)0xB8000; //  VGA text mode memory starts at 0xB8000.

void print_string(const char *str) {
    int index = 0;
    while (str[index] != '\0') {
        video_memory[index * 2] = str[index];       // Character byte
        video_memory[index * 2 + 1] = 0x07;  // Attribute byte: light gray on black background
        index++;
    }
}

void kernel_main(void) {
    print_string("Welcome to BukefalOS");
    while (1) {};
}

