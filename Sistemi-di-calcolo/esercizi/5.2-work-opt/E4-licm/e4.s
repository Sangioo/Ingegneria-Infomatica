	.file	"e4.c"
	.text
	.globl	f
	.type	f, @function
f:
.LFB0:
	.cfi_startproc
	testl	%esi, %esi
	jle	.L4
	movl	$1, %eax
	addl	$7, %edi
	.p2align 3
.L3:
	imull	%edi, %eax
	subl	$1, %esi
	jne	.L3
	ret
.L4:
	movl	$1, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	f, .-f
	.ident	"GCC: (GNU) 15.1.1 20250521 (Red Hat 15.1.1-2)"
	.section	.note.GNU-stack,"",@progbits
