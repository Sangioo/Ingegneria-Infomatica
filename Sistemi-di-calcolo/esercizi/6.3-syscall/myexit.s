.globl myexit

myexit:
    pushl %ebx              # salva ebx
    movl $1, %eax           # numero system call exit = 1
    movl 8(%esp), %ebx      # primo argomento della system call
    int $0x80               # invocazione system call
    popl %ebx               # ripristina ebx
    ret
    