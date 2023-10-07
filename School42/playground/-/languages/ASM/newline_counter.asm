section .rodata
    input db "Hello\nWorld\nThis\nIs\nA\nTest",0   ; Input string terminated with null byte
    newline db 10                              ; Newline character '\n'

section .text
    global _start

_start:
    lea rsi, [input]   ; Load the address of the input string into rsi
    xor rcx, rcx       ; Initialize a counter in rcx to store the newline count

count_loop:
    mov al, byte [rsi + rcx] ; Load a byte from the input string into al
    cmp al, 0          ; Compare the loaded byte with null terminator
    je done            ; If null terminator is reached, exit loop

    cmp al, newline    ; Compare the loaded byte with newline character
    jne not_newline    ; If not a newline, jump to not_newline label

    inc rcx            ; Increment newline count in rcx

not_newline:
    inc rcx            ; Increment input string offset
    jmp count_loop     ; Continue loop

done:
    ; At this point, rcx contains the count of newlines

    ; You can add code here to do something with the newline count, like printing it or storing it.

    mov rax, 60        ; Exit syscall number for x86_64
    xor edi, edi       ; Return code 0
    syscall
