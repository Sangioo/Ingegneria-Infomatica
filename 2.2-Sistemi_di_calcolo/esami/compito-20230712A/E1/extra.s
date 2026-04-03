.globl get_adler_constant

get_adler_constant:
    movl 4(%esp), %eax
    movl $65521, (%eax)
    movl $0xBADCAFE, %ecx
    movl $0xBADCAFE, %edx
    ret
