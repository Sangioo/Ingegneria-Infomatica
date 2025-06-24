// Scrivi la soluzione qui...
.globl count_spaces

count_spaces:
	movl 4(%esp), %ecx     # const char *ecx = s;
    movl $0, %eax          # int eax = 0;
L:  movb (%ecx), %dl       # char dl = *ecx;
	testb %dl, %dl         # if (dl==0) 
	je E				   #	goto E;
	cmpb $32, %dl
	sete %dl               # dl = dl == 32; // ' ' ha codice 32 in ASCII
    movsbl %dl, %edx
    addl %edx, %eax        # eax += dl;
    incl %ecx 			   # ecx++;
	jmp L				   # goto L;
E:  ret                    # return eax;
