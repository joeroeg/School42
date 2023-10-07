assemble the code:
nasm -f elf64 hello_world.asm -o hello_world.o

create an executable:
ld -m elf_x86_64 -s -o hello_world hello_world.o


debug:
lldb hello_world
run
disassemble -n _start