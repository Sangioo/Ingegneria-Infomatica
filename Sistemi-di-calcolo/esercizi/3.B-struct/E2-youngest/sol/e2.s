# Scrivere soluzione qui...

// typedef struct {    // base
//   char gender;      // offset: 0 |x...|    (base)
//   char* name;       // offset: 4 |xxxx|   4(base)
//   char age;         // offset: 8 |x...|   8(base)
// } person_t;         // sizeof: 12

.globl find_youngest

find_youngest:              # person_t *find_youngest(person_t *v, int n) {
	pushl %ebx

	movl 8(%esp), %ecx      # person_t *c = v;
    movl $0, %eax           # person_t *a = NULL;
    movl $0, %ebx           # int b=0;
L:  cmpl 12(%esp), %ebx     # if (b>=n) 
	jge E                   #     goto E;
    testl %eax, %eax        # if (a==NULL) 
	je A                    #     goto A; 
    movb 8(%ecx), %dl       # char d = c->age;
    cmpb 8(%eax), %dl       # if (d >= a->age) 
	jge F                   #     goto F;
A:  movl %ecx, %eax         # a = c;
F:  addl $12, %ecx          # c++;      // c += 12 aritmetica dei puntatori
    incl %ebx               # b++;
    jmp L                   # goto L;

E:  popl %ebx
    ret                     # return a;
