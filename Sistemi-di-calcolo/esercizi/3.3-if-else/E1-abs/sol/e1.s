.globl myabs

myabs:
     movl 4(%esp), %eax
     cmpl $0, %eax
     jge End
     negl %eax
End: ret
