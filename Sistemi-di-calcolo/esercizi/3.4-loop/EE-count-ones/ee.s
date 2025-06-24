.globl count1

count1:
    movl 4(%esp), %ecx      # unsigned c = n;
    movl $0, %eax           # unsigned a = 0;
L:  cmpl $0, %ecx           # if (c<=0) 
	jbe E     				#	goto E;
	movl %ecx, %edx
	andl $1, %edx  			# unsigned d = c & 1;
    testl %edx, %edx        # if (d==0) 
	je T					# 	goto T;
    incl %eax               # a++;
T:  shr %ecx                # c = c >> 1;
    jmp L					# goto L;
E:  ret                     # return a;
