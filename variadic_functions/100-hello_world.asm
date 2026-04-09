section .text
    global main

main:
    mov rax, 1          ; syscall number for write
    mov rdi, 1          ; file descriptor 1 is stdout
    mov rsi, message    ; pointer to the string
    mov rdx, 13         ; length of the string
    syscall             ; call the kernel

    mov rax, 60         ; syscall number for exit
    xor rdi, rdi        ; exit status 0
    syscall             ; call the kernel

section .data
    message: db "Hello, World", 10
