	.file	"e1.c"
	.text
	.globl	f
	.type	f, @function
f:
.LFB0:
	.cfi_startproc
	testl	%edi, %edi
	je	.L6
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	%edi, %ebx
.L3:
	movl	$0, %eax
	call	g
	subl	$1, %ebx
	jne	.L3
	popq	%rbx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
.L6:
	rep ret
	.cfi_endproc
.LFE0:
	.size	f, .-f
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.3) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
