.globl f

f: movl 4(%esp), %eax # a = x
   incl %eax          # a++
   ret                # return a
