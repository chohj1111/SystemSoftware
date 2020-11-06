    .globl doubleWeight
    .text
doubleWeight:
    mov %rdi, %rax
    imul $0x2, %rax
    ret
