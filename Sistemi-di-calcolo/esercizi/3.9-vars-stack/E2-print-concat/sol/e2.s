.global print_concat

print_concat:  # void print_concat(const char* s[], int n){
    pushl %ebx
    pushl %edi
    pushl %esi
    pushl %ebp
    subl $520, %esp

    # char buf[512];
    leal 8(%esp), %edi           # char* edi = buf;
    movl 540(%esp), %esi         # char* esi = s;
    movl 544(%esp), %ebx         # int ebx = n
    xorl %ebp, %ebp              # int ebp = 0;

    movb $0, (%edi)              # *edi=0;
L:  cmpl %ebx, %ebp              # if (ebp>=ebx)
    jge E                        #    goto E;
    movl %edi, (%esp)            #        edi
    movl (%esi, %ebp, 4), %ecx   #         |
    movl %ecx, 4(%esp)           #         |   esi[ebp]
    call strcat                  # strcat( | ,    |    );
    incl %ebp                    # ebp++;
    jmp L                        # goto L;
E:  movl %edi, (%esp)            #      edi
    call puts                    # puts( | );

    addl $520, %esp
    popl %ebp
    popl %esi
    popl %edi
    popl %ebx
    ret

