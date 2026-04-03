## Domanda 1
In GDB, quale comando viene utilizzato per impostare un breakpoint all’inizio della funzione main di un programma?

- [ ] A. break start
- [x] B. break main
- [ ] C. set breakpoint main
- [ ] D. bp main

## Domanda 2
Qual è la principale differenza tra i comandi print e x in GDB?

- [ ] A. print viene utilizzato per visualizzare il contenuto della memoria, mentre x stampa il valore delle variabili in formato leggibile
- [ ] B. print può essere usato solo con variabili locali, mentre x può accedere a variabili globali
- [x] C. print esegue l’interpretazione dei tipi di dati e visualizza il valore di una variabile, mentre x mostra il contenuto della memoria senza interpretazione
- [ ] D. print è usato per eseguire codice in tempo reale, mentre x è un comando per esaminare la memoria in fase di esecuzione

## Domanda 3
Supponiamo di eseguire un programma con Valgrind e di ottenere il seguente output:
```
==12345== Invalid write of size 4  
==12345==    at 0x4005A3: main (example.c:10)  
==12345==  Address 0x0 is not stack'd, malloc'd or (recently) free'd  
```
Cosa indica questo messaggio di errore?

- [x] A. Il programma ha tentato di scrivere 4 byte in un’area di memoria non allocata, probabilmente dereferenziando un puntatore NULL
- [ ] B. Il programma ha esaurito la memoria disponibile, causando un errore di allocazione
- [ ] C. Il programma ha tentato di scrivere in un’area della memoria già liberata con free()
- [ ] D. Il programma ha effettuato un accesso a memoria non inizializzata, causando un comportamento indefinito

## Domanda 4
Dopo aver eseguito un programma con Valgrind, otteniamo il seguente messaggio di errore:
```
==56789== Conditional jump or move depends on uninitialized value(s)  
==56789==    at 0x4012BC: process_data (program.c:25)  
==56789==    by 0x4013F1: main (program.c:40)  
```
Cosa indica questo messaggio?

- [x] A. Il programma sta utilizzando una variabile non inizializzata in un’operazione logica o di salto condizionale, il che può causare un comportamento imprevedibile
- [ ] B. Il programma ha tentato di accedere a una variabile dopo averla liberata con free()
- [ ] C. Il programma sta tentando di leggere da un puntatore NULL
- [ ] D. Il programma ha superato i limiti di un array, causando un accesso a memoria non valido
