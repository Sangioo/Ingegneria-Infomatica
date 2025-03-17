.globl min

min:
    movl 4(%esp), %eax
    movl 8(%esp), %ecx
    movl 12(%esp), %edx

    cmpl %ecx, %eax
    jge E

    cmpl %edx, %eax
    jge G

    jmp F

E:
    cmpl %edx, %ecx
    jge G

    movl %ecx, %eax
    jmp F

G:
    movl %edx, %eax
    # jmp F

F:
    ret
