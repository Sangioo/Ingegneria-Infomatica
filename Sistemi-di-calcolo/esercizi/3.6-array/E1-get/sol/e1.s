.globl get

get:
    movl 4(%esp), %ecx      #    short* c = v;
    movl 12(%esp), %edx     #    unsigned d = i;
    cmpl 8(%esp), %edx      #    if (d<n)
    jb L                    #       goto L;
    movw $-1, %ax           #    short ax = -1;
    jmp E                   #    goto E;
L:  movw (%ecx,%edx,2),%ax  # L: ax = c[d];
E:  ret                     # E: return ax;
