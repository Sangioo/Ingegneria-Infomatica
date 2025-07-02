.globl div_mod

div_mod:
    pushl %edi
    pushl %esi

    movl 12(%esp), %eax
    movl 16(%esp), %ecx
    movl 20(%esp), %edi
    movl 24(%esp), %esi
    movl %eax, %edx
    sarl $31, %edx
    idiv %ecx
    movl %eax, (%edi)
    movl %edx, (%esi)

    popl %esi
    popl %edi
    ret
