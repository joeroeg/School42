section .data
    message db 'abcdefghjklomnqrstuvwxyz', 0   ; Null-terminated message to write

section .text
    global _start

_start:
    ; File descriptor for STDOUT (standard output)
    mov  rdi, 1

    ; Pointer to the message
    lea  rsi, [message]

    ; Length of the message
    mov  rdx, 26

    ; Invoke the write system call
    mov  rax, 1       ; 1 is the syscall number for write
    syscall

    ; Exit the program
    mov  rax, 60      ; 60 is the syscall number for exit
    xor  rdi, rdi     ; Return code 0
    syscall
