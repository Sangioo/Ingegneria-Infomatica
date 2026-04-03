.globl f
f:
    movw 4(%esp), %ax
    xorw %cx, %cx
    movl 8(%esp), %edx  # ERRORE nel codice originale: stiamo leggendo un puntatore!
    movw $0, (%edx)     # ERRORE nel codice originale: dobbiamo scrivere in memoria!
    movl 12(%esp), %edx # ERRORE nel codice originale: stiamo leggendo un puntatore!
    movw $0, (%edx)     # ERRORE nel codice originale: dobbiamo scrivere in memoria!
L:  cmpw %ax, %cx       # ERRORE nel codice originale: sorgente e destinazione invertiti!
    ja E                # ERRORE nel codice originale: condition code per valori con segno!
    testw $1, %cx
    jne F
    movl 8(%esp), %edx  # ERRORE nel codice originale: stiamo leggendo un puntatore!
    addw %cx, (%edx)    # ERRORE nel codice originale: dobbiamo scrivere in memoria!
    jmp C
F:
    movl 12(%esp), %edx # ERRORE nel codice originale: stiamo leggendo un puntatore!
    addw %cx, (%edx)    # ERRORE nel codice originale: dobbiamo scrivere in memoria!
C:
    incw %cx
    jmp L               # ERRORE nel codice originale: serve ripetere il loop!
E:
    ret                 # ERRORE nel codice originale: occorre sempre inserire la ret!
