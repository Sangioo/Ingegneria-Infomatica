// Scrivi la soluzione qui...

.global stringa_vuota

stringa_vuota:                 # int stringa_vuota(const char *s) {
    movl 4(%esp), %ecx         # const char *c = s;
    xorl %eax, %eax            # int a = 0;
    testl %ecx, %ecx           # if (c == 0) // cortocircuitazione
    je E                       #    goto E;
    cmpb $0, (%ecx)            # if (*c != 0) 
    jne E                      #    goto E;
    movl $1, %eax              # a = 1;
E:  ret                        # return a;  
