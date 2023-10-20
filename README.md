## BukefalOS

This is a side project in which I get more into the details on how an operating system works. I have mainly used the following resources:
- https://wiki.osdev.org/Bare_Bones

The Wiki for OSDev is quite good and I can recommend it to anyone who wants to get into this topic.

### How to build
To build the project you need to have the following tools installed:
- nasm
- gcc
- ld
- qemu

Then you can run the following command to build the project:
```bash
nasm -f elf32 ~/projects/bukefal/src/boot/start.asm -o ~/projects/bukefal/build/start.o

i686-elf-gcc -c ~/projects/bukefal/src/kernel/kernel.c -o ~/projects/bukefal/build/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

i686-elf-gcc -T ~/projects/bukefal/linker.ld -o ~/projects/bukefal/build/mykernel.bin -ffreestanding -O2 -nostdlib
```

Next up, you will need to build the ISO file:

```bash
mkdir -p ./isofiles/boot/grub
cp ./build/mykernel.bin ./isofiles/boot/
cp ./boot/grub.cfg ./isofiles/boot/grub/
grub-mkrescue -o ./bukefal.iso ./isofiles
```

And to run the ISO file, you can use qemu:
```bash
qemu-system-i386 -cdrom bukefal.iso
```


### Future goals:
- [ ] Shell
- [ ] File system
- [ ] Text editor
- [ ] Calculator
- [ ] Small game