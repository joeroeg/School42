section .data
    hello db 'Hello, World!',0x0A    ; The string to be printed (0x0A is newline)
    hello_len equ $ - hello         ; Calculate the length of the string

section .text
    global _start                   ; Entry point for the program

_start:
    ; Write "Hello, World!" to the console
    mov rax, 1                      ; syscall number 1 (sys_write)
    mov rdi, 1                      ; file descriptor 1 (stdout)
    mov rsi, hello                  ; pointer to the string
    mov rdx, hello_len              ; length of the string
    syscall                         ; make the system call

    ; Exit the program
    mov rax, 60                     ; syscall number 60 (sys_exit)
    xor rdi, rdi                    ; exit code 0
    syscall                         ; make the system call