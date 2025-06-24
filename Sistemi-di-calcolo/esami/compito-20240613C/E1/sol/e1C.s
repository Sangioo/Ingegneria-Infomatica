.globl hextodec_sum

hextodec_sum:
    # prologo
    pushl   %ebx
    pushl   %esi
    pushl   %edi
    pushl   %ebp
    subl    $12, %esp

    xorl    %ebx, %ebx                  # ebx = 0
    xorl    %esi, %esi                  # esi = 0
    movl    32(%esp), %edi              # edi = in
    movl    36(%esp), %ebp              # ebp = out

L:
    cmpb    $0, (%edi)                  # if (*edi == 0)
    je      E                           # goto E

    movl    %edi, (%esp)                
    leal    8(%esp), %ecx
    movl    %ecx, 4(%esp)               # ecx = &mem
    call    hextodec_helper             # hextodec_helper(edi, ecx)

    movl    8(%esp), %eax               # eax = mem
    cmpl    $0, %eax                    # if (eax <= 0)
    jle     F                           # goto F

    addl    %eax, %ebx                  # ebx += eax

F:
    movl    %eax, (%ebp, %esi, 4)       # ebp[esi] = eax
    incl    %esi                        # esi += 1
    addl    $2, %edi                    # edi += 2
    jmp     L                           # goto L

E:
    movl    %ebx, %eax                  # eax = ebx

    # epilogo
    addl    $12, %esp
    popl    %ebp
    popl    %edi
    popl    %esi
    popl    %ebx
    ret
