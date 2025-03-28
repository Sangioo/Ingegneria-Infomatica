## Domanda 1
Se una funzione foo ha un prologo in cui vengono salvati due registri callee-save e vengono riservati 12 byte per ospitare variabili locali, argomenti ed eventuale padding, quale di questi operandi permette di accedere al secondo argomento di foo?
A. (%esp)
B. 4(%esp)
C. 8(%esp)
D. 12(%esp)
E. 20(%esp)
F. 24(%esp)
G. 28(%esp)
H. 32(%esp)

Domanda 2
Assumendo %al = 5, eseguire movsbl %al, %eax porta allo stesso risultato in %eax rispetto eseguire movzbl %al, %eax?
A. Sì
B. No

Domanda 3
Assumendo di avere una funzione foo che chiama una funzione baz. Quale tra le seguenti affermazioni risulta essere vera:
A. foo non può utilizzare il registro %eax
B. foo non può utilizzare il registro %ebx
C. baz non può utilizzare il registro %eax
D. baz non può utilizzare il registro %ebx
E. Nessuna delle precedenti affermazioni è vera

Domanda 4
Se una funzione baz viene chiamata da una funzione foo, quale delle seguenti affermazioni risulta essere falsa:
A. baz prima di poter utilizzare %edi deve salvare il suo contenuto e ripristinarlo prima di effettuare la ret
B. baz può utilizzare %edx senza dover preservare il suo contenuto iniziale
C. foo deve salvare il contenuto di %ecx se vuole preservarne il contenuto prima di chiamare baz
D. foo deve salvare il contenuto di %esi se vuole presevarne il valore prima di chiamare baz

Domanda 5
Quale fra le seguenti istruzioni risulta essere valida:
A. leal (%eax, %edx, 6), %ecx
B. movl (%eax), 4(%esp)
C. leal -1(%ecx), %eax
D. addl %eax, $4

Domanda 6
Assumendo che %eax=0x0000BEEF e %ecx=0, quanto vale %ecx dopo aver eseguito l’istruzione movsbw %al, %cx?
A. 0x000000EF
B. 0xFFFFFFEF
C. 0x0000FFEF
D. 0x0000EFEF