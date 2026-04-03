.globl times2
times2:
    movl 4(%esp), %eax
    movl (%eax), %ecx
    imull $2, %ecx
    movl %ecx, (%eax)
    ret
