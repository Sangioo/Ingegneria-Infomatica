.globl swap_endianness

swap_endianness:
    movl 4(%esp), %ecx

    movl %ecx, %edx
    andl $0x000000FF, %edx
    shll $24, %edx
    movl %edx, %eax

    movl %ecx, %edx
    andl $0x0000FF00, %edx
    shll $8, %edx
    orl %edx, %eax

    movl %ecx, %edx
    andl $0x00FF0000, %edx
    shrl $8, %edx
    orl %edx, %eax

    movl %ecx, %edx
    andl $0xFF000000, %edx
    shrl $24, %edx
    orl %edx, %eax

    ret
