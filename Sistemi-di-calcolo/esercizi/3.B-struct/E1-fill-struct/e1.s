# typedef struct {
#     char age;       // 0 age    |x---|
#     char* name;     // 4 name   |xxxx|
#     char gender;    // 8 gender |x---|
# } person_t;         // sizeof == 12
.globl fill
fill:   # void fill(person_t* p, char age, char* name, char gender) {
    pushl %ebx
    movl 8(%esp), %eax  #     person_t* a = p;
    movb 12(%esp), %cl  #     char c  = age;
    movl 16(%esp), %edx #     char* d = name;
    movb 20(%esp), %bl  #     char b  = gender;
    movb %cl, (%eax)    #     a->age = c;
    movl %edx, 4(%eax)  #     a->name = d;
    movb %bl, 8(%eax)   #     a->gender = b;
    popl %ebx
    ret
