.globl f

f:
    pushq %r12                  # prologo
    pushq %r13
    pushq %r14
    pushq %rbx
    subq $4, %rsp

    movq %rdi, %r12             # r12 <-> v
    movq %rsi, %r13             # r13 <-> n
    xorq %r14, %r14             # r14 <-> cnt
    xorq %rbx, %rbx             # b <-> i

L:  cmpq %r13, %rbx             # if (b >= r13)
    jge E                       #     goto E;
    movl (%r12, %rbx, 4), %edi  # int di = r12[b];
    call is_negative            # unsigned a = is_negative(c);
    addl %eax, %r14d            # r14 = r14 + a;
    incq %rbx                   # b++;
    jmp L                       # goto L;

E:  movl %r14d, %eax;           # a = r14;

    addq $4, %rsp               # epilogo
    popq %rbx
    popq %r14
    popq %r13
    popq %r12

    ret                         # return a;

