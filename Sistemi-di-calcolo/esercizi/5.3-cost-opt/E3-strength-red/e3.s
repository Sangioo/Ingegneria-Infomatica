	.file	"e3.c"
	.text
	.globl	f
	.type	f, @function
f:
.LFB0:
	.cfi_startproc
	testl	%esi, %esi
	jle	.L1
	movq	%rdi, %rax
	movslq	%esi, %rsi
	leaq	(%rdi,%rsi,4), %rsi
	movl	$0, %ecx
	.p2align 4
.L3:
	movl	%ecx, (%rax)
	addl	%edx, %ecx
	addq	$4, %rax
	cmpq	%rsi, %rax
	jne	.L3
.L1:
	ret
	.cfi_endproc
.LFE0:
	.size	f, .-f
	.ident	"GCC: (GNU) 15.1.1 20250521 (Red Hat 15.1.1-2)"
	.section	.note.GNU-stack,"",@progbits
