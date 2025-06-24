.globl deleetify

deleetify:
    # prologo
    pushl   %edi
    pushl   %esi
    pushl   %ebp
    subl    $12, %esp

    movl    28(%esp), %esi          # esi = v
    movl    36(%esp), %edi          # edi = res
    xorl    %ebp, %ebp              # ebp = 0

L:
    cmpl    32(%esp), %ebp          # if (ebp >= len)
    jae     E                       # goto E

    movb    (%esi, %ebp, 1), %cl    # cl = esi[ebp]
    cmpb    $57, %cl                # if (cl <= 57)
    jbe     C                       # goto C

    movb    %cl, (%edi, %ebp, 1)    # edi[ebp] = cl
    jmp     N                       # goto N

C:
    movzbl  %cl, %ecx               # ecx = (unsigned)cl
    movl    %ecx, (%esp)
    leal    8(%esp), %eax
    movl    %eax, 4(%esp)            
    call    deleetify_helper        # al = deleetify_helper(cl, &chr)
    movb    8(%esp), %al
    movb    %al, (%edi, %ebp, 1)    # edi[ebp] = al

N:
    incl    %ebp                    # ebp += 1
    jmp     L                       # goto L

E:
    # epilogo
    addl    $12, %esp
    popl    %ebp
    popl    %esi
    popl    %edi
    ret
