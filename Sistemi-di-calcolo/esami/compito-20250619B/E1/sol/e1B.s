.globl check
check:
	pushl %ebx
	pushl %esi
	subl $4, %esp

	xorl %ebx, %ebx 	# unsigned char bl = 0; //count
						# unsigned char bh = 0; //correct
	movl 16(%esp), %esi # mossa * si = head;  

L:
	testl %esi, %esi	# if (si==0) 
	jz E				# goto E;
	incb %bl			# bl++;
	movl %esi, (%esp)
	call is_valid_move	# unsigned char al = is_valid_move(si);
	testb %al, %al		# if (al==0)
	jz A				# goto A;
	incb %bh			# bh++;
A:
	movl 12(%esi), %esi # si = si->next;
	jmp L				# goto L;
E:
	cmpb %bh, %bl		# if (bl != bh)
	jnz B				# goto B;
	movb $1, %al		# al = 1;
	jmp C				# goto C
B:
	movb $0, %al		# al = 0;
C:

	addl $4, %esp
	popl %esi
	popl %ebx
	ret					# return al;
