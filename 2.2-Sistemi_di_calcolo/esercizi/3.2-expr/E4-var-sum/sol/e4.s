.globl f

f: movl 4(%esp), %eax  # a = x
   movl 8(%esp), %ecx  # c = y
   addl %ecx, %eax     # a = a + c
   ret                 # return a;
