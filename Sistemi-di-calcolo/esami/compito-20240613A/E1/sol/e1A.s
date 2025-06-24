.globl deleetify

deleetify:
    # prologo
    pushl   %edi
    pushl   %esi
    pushl   %ebp
    subl    $4, %esp

    movl    24(%esp), %eax          # eax = len
    movl    %eax, (%esp)
    call    malloc                  # malloc(eax)
    movl    %eax, %edi              # edi = malloc(eax)
    movl    20(%esp), %esi          # esi = v
    xorl    %ebp, %ebp              # ebp = 0

L:
    cmpl    24(%esp), %ebp          # if (ebp >= len)
    jae     E                       # goto E

    movb    (%esi, %ebp, 1), %cl    # cl = esi[ebp]
    cmpb    $57, %cl                # if (cl <= 57)
    jbe     C                       # goto C

    movb    %cl, (%edi, %ebp, 1)    # edi[ebp] = cl
    jmp     N                       # goto N

C:
    movzbl  %cl, %ecx               # ecx = (unsigned)cl
    movl    %ecx, (%esp)            
    call    deleetify_helper        # al = deleetify_helper(cl)
    movb    %al, (%edi, %ebp, 1)    # edi[ebp] = al

N:
    incl    %ebp                    # ebp += 1
    jmp     L                       # goto L

E:
    movl    %edi, %eax

    # epilogo
    addl    $4, %esp
    popl    %ebp
    popl    %esi
    popl    %edi
    ret
