.global swap

swap: # void swap(short* x, short* y) {
    movl 4(%esp), %ecx  # short* ecx = x;
    movl 8(%esp), %edx  # short* edx = y;
    movw (%ecx), %cx    # short cx = *ecx;
    movw (%edx), %dx    # short dx = *edx;
    movl 4(%esp), %eax  # short* eax = x;
    movw %dx, (%eax)    # *eax = dx;
    movl 8(%esp), %eax  # eax = y;
    movw %cx, (%eax)    # *eax = cx;
    ret
