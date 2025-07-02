	.file	"e3.c"
	.text
	.globl	expr
	.type	expr, @function
expr:
.LFB0:
	.cfi_startproc
	leal	(%rdi,%rsi), %eax
	imull	%eax, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	expr, .-expr
	.ident	"GCC: (GNU) 15.1.1 20250521 (Red Hat 15.1.1-2)"
	.section	.note.GNU-stack,"",@progbits
