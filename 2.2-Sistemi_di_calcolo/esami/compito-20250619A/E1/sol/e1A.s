.globl fight
fight:
	pushl %ebx				# PROLOGO
	pushl %ebp
	pushl %esi
	pushl %edi
	subl $12, %esp

	movl 32(%esp), %esi		# esi = p1
	movw (%esi), %si		# si = esi->pf
	movl 36(%esp), %edi		# edi = p2
	movw (%edi), %di		# di = edi->pf
	movb $1, %bl			# unsigned char bl = 1;
L:
	cmpb $10, %bl			# if (bl>10)
	ja E					# goto E;
	movb %bl, (%esp)		#
	movl 32(%esp), %ebp		#
	movl %ebp, 4(%esp)		#
	movw %di, 8(%esp)		#
	call update				#
	movw %ax, %di  			# di = update(bl,p1,di);
	movl 36(%esp), %ebp
	movl %ebp, 4(%esp)
	movw %si, 8(%esp)
	call update
	movw %ax, %si 			# si = update(bl,p2,si);
	movw %si, (%esp)
	movw %di, 4(%esp)
	call winner				# al = winner(si,di);
	cmpb $0, %al			# if (al>=0)
	jge E					# goto E;
	xorb %al, %al			# al = 0;
	incb %bl				# bl++;
	jmp L					# goto L ;   
E:
	addl $12, %esp			# EPILOGO
	popl %edi
	popl %esi
	popl %ebp
	popl %ebx
	ret
