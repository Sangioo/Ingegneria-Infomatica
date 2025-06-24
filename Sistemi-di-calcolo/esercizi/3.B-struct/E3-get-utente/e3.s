.globl get_utente
# typedef struct {         // base
#     char privilegi;      // offset: 0 |x.|    (base)
#     short user_id;       // offset: 2 |xx|   2(base)
# } stud_t;                // sizeof: 4
get_utente: # void get_utente(char* privilegi, short* user_id) {
    pushl %ebx
    pushl %edi
    pushl %esi
    subl $8, %esp
    movl 24(%esp), %ebx     # char* b = privilegi;
    movl 28(%esp), %edi     # short* di = user_id;
    # stud_t utente;
    leal 4(%esp), %esi      # stud_t* si = &utente;
    movl %esi, (%esp)
    call curr_user          # curr_user(si);  //
    movb (%esi), %al 
    movb %al, (%ebx)      # *b = si->privilegi;
    movw 2(%esi), %ax       # short ax = si->user_id;
    movw %ax, (%edi)        # *di = ax;
    addl $8, %esp
    popl %esi
    popl %edi
    popl %ebx
    ret #
