.globl fib

fib:
    movl 4(%esp), %ecx
    movl $0, %edx
    movl $1, %eax

    cmpl $0, %ecx
    jne R1

    movl %edx, %eax
    ret

R1:
    cmpl $1, %ecx
    jne FOR

    ret

FOR:
    cmpl $1, %ecx
    jbe END

    addl %eax, %edx
    addl %eax, %edx
    negl %eax
    addl %edx, %eax
    subl %eax, %edx

    decl %ecx
    jmp FOR

END:
    ret
