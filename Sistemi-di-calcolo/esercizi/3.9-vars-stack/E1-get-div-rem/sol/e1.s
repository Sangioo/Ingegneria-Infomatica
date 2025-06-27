.globl f

f:
    subl $24, %esp

    leal 16(%esp), %eax  
    movl %eax, (%esp)    # passa parametro &d

    leal 20(%esp), %eax  
    movl %eax, 4(%esp)   # passa parametro &r

    movl 28(%esp), %eax
    movl %eax, 8(%esp)   # passa parametro x

    movl 32(%esp), %eax
    movl %eax, 12(%esp)  # passa parametro y

    call get_div_rem     # get_div_rem(&d, &r, x, y);

    movl 16(%esp), %eax

    addl $24, %esp
    ret                  # return d;
