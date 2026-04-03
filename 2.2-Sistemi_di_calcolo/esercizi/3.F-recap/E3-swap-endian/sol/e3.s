.globl swap_endianness

swap_endianness: #unsigned swap_endianness(unsigned C) {
    movl 4(%esp), %eax              # unsigned a = C;
    movl %eax, %ecx                 # unsigned c = a;
    movl %eax, %edx                 # unsigned d = a;
    andl $0x000000FF, %eax           # a = a & 0x000000FF;
    shll $24, %eax                  # a = a << 24;
    andl $0x0000FF00, %ecx           # c = c & 0x0000FF00;
    shll $8, %ecx                   # c = c << 8;
    orl %ecx, %eax                  # a = a | c
    movl %edx, %ecx                 # c = d
    andl $0x00FF0000, %ecx           # c = c & 0x00FF0000;
    shrl $8, %ecx                   # c = c >> 8;
    orl %ecx, %eax                  # a = a | c
    movl %edx, %ecx                 # c = d
    andl $0xFF000000, %ecx           # c = c & 0xFF000000;
    shrl $24, %ecx                  # c = c >> 24;
    orl %ecx, %eax                  # a = a | c;
    ret                             # return a;
