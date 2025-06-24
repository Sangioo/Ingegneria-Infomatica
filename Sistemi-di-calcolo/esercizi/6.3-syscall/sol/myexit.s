.globl myexit

myexit:
    pushl %ebx 
    movl $1, %eax 
    movl 8(%esp), %ebx 
    int $0x80 
    popl %ebx 
    ret
    