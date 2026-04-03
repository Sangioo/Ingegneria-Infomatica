## domanda

## risposta
L'algoritmo merge sort sfrutta un approccio dividi e conquista, procedendo ricorsivamente a dividere l'array in input in sottoarray grandi ogni passo la metà del passo precedente, fino a che ogni sotto array non abbia grandezza 1, a questo punto ritornando indietro si fondono i sottoarray in maniera ordinata, di seguito la schematizzazione dell'algoritmo:

Se la dimensione n<2 allora è già ordinato. Fine. \
​Altrimenti:
* ordina la metà sinistra
* ordina la metà destra
* fondi le due metà ordinate

Il costo asintotico del merge sort è nlogn, questo perchè a ogni passo facciamo n operazioni per unire i sottoarray e i passi in totale sono logn, perchè a ogni passo si procede a dividere la lunghezza a metà dunque si arriverà a sottoarray di lunghezza 1 dopo logn passi.
 
$$\frac{n}{2^k} \geq 2 ⇔ k \leq \frac{log(n)}{2}$$

​Per il merge sort non esiste caso peggiore in quanto in ogni caso utilizzeremo n operazioni a ogni passaggio per fondere le due metà e i passaggi saranno in ogni caso logn.

Esempio di esecuzione:
passaggio 0:
    array considerato: [ 9 3 4 6 7 1 8 5 ]
    start = 0, med = 3, end = 7
    la dimensione è maggiore di 2 dunque procedo a ordinare la metà sinistra e la destra.

passaggio 1:
    array considerato: [ 9 3 4 6 ]
    start = 0, med = 1, end = 3
    la dimensione è maggiore di 2 dunque procedo a ordinare la metà sinistra e destra.

    array considerato: [ 7 1 8 5 ]
    start = 4, med = 5, end = 7
    la dimensione è maggiore di 2 dunque procedo a ordinare la metà sinistra e destra.

passaggio 2:
    array considerato: [ 9 3 ]
    start = 0, med = 0, end = 1
    la dimensione è uguale a 2 dunque procedo a ordinare la metà sinistra e destra.

    array considerato: [ 4 6 ]
    start = 2, med = 2, end = 3
    la dimensione è uguale a 2 dunque procedo a ordinare la metà sinistra e destra.

    array considerato: [ 7 1 ]
    start = 4, med = 4, end = 5
    la dimensione è uguale a 2 dunque procedo a ordinare la metà sinistra e destra.

    array considerato: [ 8 5 ]
    start = 6, med = 6, end = 7
    la dimensione è uguale a 2 dunque procedo a ordinare la metà sinistra e destra.

passaggio 3:
    array considerato: [ 9 ]
    start = 0, med = 0, end = 0

    array considerato: [ 3 ]
    start = 1, med = 1, end = 1
    la dimensione è minore di 2 dunque fondo in maniera ordinata le due metà
    risultato: [ 3 9 ]

    array considerato: [ 4 ]
    start = 2, med = 2, end = 2

    array considerato: [ 6 ]
    start = 3, med = 3, end = 3
    la dimensione è minore di 2 dunque fondo in maniera ordinata le due metà
    risultato: [ 4 6 ]

    array considerato: [ 7 ]
    start = 4, med = 4, end = 4

    array considerato: [ 1 ]
    start = 5, med = 5, end = 5
    la dimensione è minore di 2 dunque fondo in maniera ordinata le due metà
    risultato: [ 1 7 ]

    array considerato: [ 8 ]
    start = 6, med = 6, end = 6

    array considerato: [ 5 ]
    start = 7, med = 7, end = 7
    la dimensione è minore di 2 dunque fondo in maniera ordinata le due metà
    risultato: [ 5 8 ]

passaggio 4:
    fondo le prime due parti in maniera ordinata ovvero
    [ 3 9 ]  [ 4 6 ]  --->  [ 3 4 6 9 ]

    fondo le seconde due parti in maniera ordinata ovvero
    [ 1 7 ]  [ 5 8 ]  --->  [ 1 5 7 8 ]

passaggio 5:
    fondo le due metà dell'array
    [ 3 4 6 9 ]  [ 1 5 7 8 ]  --->   [ 1 3 4 5 6 7 8 9 ]
