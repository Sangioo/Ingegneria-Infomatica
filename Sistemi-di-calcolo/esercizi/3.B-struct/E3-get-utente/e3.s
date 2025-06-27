.globl get_utente

get_utente:
    subl $8, %esp
    movl 12(%esp), %ecx
    movl 16(%esp), %edx
    leal 4(%esp), %eax
    movl %eax, (%esp)
    call curr_user
    movb 4(%esp), %al
    movb %al, (%ecx)
    movw 6(%esp), %ax
    movw %ax, (%edx)
    addl $8, %esp
    ret
