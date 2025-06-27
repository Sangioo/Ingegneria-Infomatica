.globl f

f: movl 4(%esp), %eax  # a = x
   movl 8(%esp), %ecx  # c = y
   movl %eax, %edx     # d = a
   sarl $31, %edx      # d = d >> 31
   idivl %ecx          # a = d:a / c
   ret                 # return a
