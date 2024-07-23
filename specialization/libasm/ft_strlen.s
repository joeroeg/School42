section .text
    global _ft_strlen

_ft_strlen:
    push  rcx             ; Save rcx to preserve its original value
    xor   rcx, rcx        ; Clear rcx to use it as the counter

_strlen_next:
    cmp   byte [rdi], 0   ; Compare current byte to null byte
    jz    _strlen_null    ; If null byte, jump to _strlen_null

    inc   rcx             ; Increment counter
    inc   rdi             ; Move to next byte
    jmp   _strlen_next    ; Repeat the loop

_strlen_null:
    mov   rax, rcx        ; Move the length from rcx to rax

    pop   rcx             ; Restore original rcx value
    ret                   ; Return
