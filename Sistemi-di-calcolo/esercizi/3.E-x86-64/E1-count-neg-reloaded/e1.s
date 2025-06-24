.globl f

f: # unsigned f(int *v, unsigned n)

	pushq %r12
	pushq %r13
	pushq %r14
	pushq %rbx

	movq %rdi, %r12         # int* r12 = v;       // e12 <-> v
	movl %esi, %r13d        # unsigned r13d = n;  // r13d <-> n
    movl $0, %r14d          # unsigned r14d = 0;  // r14d <-> cnt
	movl $0, %ebx           # unsigned ebx = 0;   // ebx <-> i
L:  cmpl %r13d, %ebx        # if (ebx >= r13d) 
	jae E                   #      goto E;
	movl (%r12,%rbx,4),%edi # int edi = r12[ebx];	
    call is_negative        # unsigned eax = is_negative(edi);
    addl %eax, %r14d        # r14d += eax;
	incl %ebx               # ebx++;
    jmp L                   # goto L;
E:  movl %r14d, %eax        # eax = r14d;

	popq %rbx
	popq %r14
	popq %r13    
	popq %r12
    
    ret                     # return eax;
