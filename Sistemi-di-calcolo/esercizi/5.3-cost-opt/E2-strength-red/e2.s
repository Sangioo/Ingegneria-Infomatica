	.file	"e2.c"
	.text
	.globl	f
	.type	f, @function
f:
.LFB0:
	.cfi_startproc
	movl	%edi, %eax
	sall	$4, %eax
	leal	(%rax,%rdi), %eax
	ret
	.cfi_endproc
.LFE0:
	.size	f, .-f
	.ident	"GCC: (GNU) 15.1.1 20250521 (Red Hat 15.1.1-2)"
	.section	.note.GNU-stack,"",@progbits
