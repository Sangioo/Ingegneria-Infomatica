.globl times2
times2:
    movl 4(%esp), %eax  # short* a = p;
    movw (%edx), %cx    # short cx = *a;
    imulw $2, %cx       # cx = cx * 2;
    movw %cx, (%eax)    # *a = cx;
    ret
