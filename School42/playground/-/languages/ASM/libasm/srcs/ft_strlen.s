addition:
push    rbp
	mov     rbp, rsp
mov     DWORD PTR [rbp-4], edi
mov     DWORD PTR [rbp-8], esi
mov     edx, DWORD PTR [rbp-4]
mov     eax, DWORD PTR [rbp-8]
add     eax, edx
pop     rbp
ret
.LC0:
        .string "%d \n"
main:
push    rbp
mov     rbp, rsp
mov     esi, 3
mov     edi, 2
call    add
mov     esi, eax
mov     edi, OFFSET FLAT:.LC0
mov     eax, 0
call    printf
mov     eax, 0
pop     rbp
ret