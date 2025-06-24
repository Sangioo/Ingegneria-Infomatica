.globl swap

swap:
    movl 4(%esp), %eax  # short* a = x;
    movw (%eax), %ax    # short ax = *a;
    movl 8(%esp), %ecx  # short* c = y;
    movw (%ecx), %cx    # short cx = *c;
    movl 4(%esp), %edx  # short* d = x;
    movw %cx, (%edx)    # *d = cx;
    movl 8(%esp), %edx  # d = y;
    movw %ax, (%edx)    # *d = ax;
    ret