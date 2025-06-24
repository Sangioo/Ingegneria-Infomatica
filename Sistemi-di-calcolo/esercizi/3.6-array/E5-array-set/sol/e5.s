.globl array_set

array_set:              # void array_set(short* v, int n, short x)
    movl 4(%esp), %eax  # char* a = (char*)v;
    movw 12(%esp), %cx  # short c = x;
    movl 8(%esp), %edx  # int d = n;
    imull $2, %edx      # d = d * 2; // NOTA: imull imm, %reg == imull imm, %reg, %reg
    addl %edx, %eax     # a = a + d;
    subl $2, %eax       # a = a - 2;
L:  cmpl 4(%esp), %eax  # if ((short*)a < v) 
	jl E                # goto E;
    movw %cx, (%eax)    # *(short*)a = c;
    subl $2, %eax       # a = a - 2;
    jmp L               # goto L;
E:  ret                 # ;

