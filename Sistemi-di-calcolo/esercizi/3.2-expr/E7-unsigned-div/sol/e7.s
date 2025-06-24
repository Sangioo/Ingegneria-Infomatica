.globl f

f: movl 4(%esp), %eax  # a = x
   movl 8(%esp), %ecx  # c = y
   xorl %edx, %edx     # d = 0
   divl %ecx           # a = d:a / c
   ret                 # return a
