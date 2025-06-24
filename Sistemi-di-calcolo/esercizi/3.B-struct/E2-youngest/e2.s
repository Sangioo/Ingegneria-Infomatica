.globl find_youngest

#  typedef struct {   // base
#     char gender;    // offset: 0 |x...|    (base)
#     char* name;     // offset: 4 |xxxx|   4(base)
#     char age;       // offset: 8 |x...|   8(base)
# } person_t;         // sizeof: 12

find_youngest: # person_t *find_youngest(person_t *v, int n) {
    pushl %ebx
    xorl %eax, %eax     # person_t *a = NULL;
    xorl %ecx, %ecx     # int c = 0;
    movl 8(%esp), %ebx  # person_t* b = v;
L:
    cmpl 12(%esp), %ecx # if(c>=n) 
    jge E               # goto E;
    testl %eax, %eax    # if (a==NULL) 
    jz A                # goto A;
    movb 8(%ebx), %dl   # char dl = b.age; 
    cmpb 8(%eax), %dl   # if (dl >= a->age) 
    jge A2              # goto A2;
A:
    movl %ebx, %eax     # a = b;
A2:
    incl %ecx           # ++c;
    addl $12, %ebx      # b++; // aritmetica dei puntatori
    jmp L               # goto L;
E:
    popl %ebx
    ret     # return a;
