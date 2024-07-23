section .data
    newline db 0x0A

section .bss
    buffer resb 1024   ; Reserve space for a buffer (not used in this example but could be)

section .text
    global _start

_start:
    ; Get command-line arguments
    mov rdi, [rsp + 8]  ; argc (arg count)
    mov rsi, [rsp + 16] ; argv (pointer to arguments array)

    ; Check if at least one argument is provided
    cmp rdi, 1
    jbe _exit           ; Exit if no arguments

    ; argv[1] is the first argument
    mov rsi, [rsi + 8]  ; argv[1]

    ; Calculate the length of the argument string
    mov rdx, 0          ; Initialize length
_calculate_length:
    cmp byte [rsi + rdx], 0
    je _write_message   ; Jump to write message if null terminator is found
    inc rdx             ; Increment length
    jmp _calculate_length

_write_message:
    ; Write the argument to stdout
    mov rax, 0x2000004  ; syscall number for write
    mov rdi, 1          ; file descriptor (stdout)
    syscall

    ; Write a newline character
    mov rax, 0x2000004  ; syscall number for write
    mov rdi, 1          ; file descriptor (stdout)
    mov rsi, newline    ; pointer to newline
    mov rdx, 1          ; length of newline
    syscall

_exit:
    ; Exit the program
    mov rax, 0x2000001  ; syscall number for exit
    xor rdi, rdi        ; exit status (0)
    syscall
