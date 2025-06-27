.globl fill

# typedef struct {
#    char age;        |x---| 0(%eax)
#	 char* name;      |xxxx| 4(%eax)
#    char gender;     |x---| 8(%eax)
#} person_t; => sizeof(person_t) == 12

#                           4       8          12         16
fill: # void fill(person_t* p, char age, char* name, char gender)
	movl 4(%esp), %eax       # person_t* a = p;
	
	movl 8(%esp), %ecx       # char c = age;
    movb %cl, (%eax)         # p->age = c;
 
	movl 12(%esp), %ecx      # char* d = name;
    movl %ecx, 4(%eax)       # p->name = d;
    
    movl 16(%esp), %ecx      # c = gender;
    movb %cl, 8(%eax)        # p->gender = c;

	ret
