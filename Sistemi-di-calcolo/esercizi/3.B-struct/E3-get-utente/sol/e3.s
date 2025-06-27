# typedef struct {         // base
#     char privilegi;      // offset: 0 |x.|    (base)
#     short user_id;       // offset: 2 |xx|   2(base)
# } stud_t;                // sizeof: 4

.globl get_utente

get_utente:                       # void get_utente(char* privilegi, short* user_id)
	pushl %edi
	subl $8, %esp                 # stud_t utente;          // struttura allocata in stack

    leal 4(%esp), %edi            # stud_t* edi = &utente;

    movl %edi, (%esp)             #           edi 
    call curr_user                # curr_user( | );

    movl 16(%esp), %eax           # char* eax = privilegi;
    movb (%edi), %cl              # char al = edi->privilegi;
    movb %cl, (%eax)              # *eax = al;

    movl 20(%esp), %edx           # short* edx = user_id;
    movw 2(%edi), %cx             # short cx = edi->user_id;
    movw %cx, (%edx)              # *edx = cx;

	addl $8, %esp
	popl %edi

	ret
