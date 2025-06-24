.globl f

f: movl 4(%esp), %eax  # a = x
   imull %eax, %eax    # a = a * a
   ret                 # return a
