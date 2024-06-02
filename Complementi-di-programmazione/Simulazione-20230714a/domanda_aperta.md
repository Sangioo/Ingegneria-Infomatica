## domanda
Fornire la specifica del tipo di dato astratto Pila, l'implementazione (in pseudocodice) della specifica con condivisione della memoria. Per ogni funzione implementata descriverne anche il costo asintotico.

## risposta
Una pila è una collezione di elementi dello stesso tipo dove viene utilizzato l'approccio "last in first out", ovvero l'ultimo elemento inserito è il primo che viene estratto, una specifica del tipo astratto pila è la seguente:

### TipoAstratto Pila
#### Domini
* `Pila`: dominio di interesse

* `T`: dominio dei valori della pila
#### Funzioni
* `pilaVuota()` -> Pila \
**pre**: nessuna \
**post**: RESULT è una pila vuota

* `estVuota(Pila p)` -> bool \
**pre**: nessuna \
**post**: RESULT è vero se la pila è vuota, false altrimenti

* `push(Pila p, T e)` -> Pila \
**pre**: nessuna \
**post**: RESULT è una pila identica alla pila in input, ma con un'elemento aggiunto in testa

* `pop(Pila p)` -> Pila \
**pre**: la pila non deve essere vuota \
**post**: RESULT la pila in input con l'ultimo elemento aggiunto eliminato

* `top(Pila p)` -> T \
**pre**: la pila non deve essere vuota \
**post**: RESULT è l'ultimo elemento aggiunto alla pila
### FineTipoAstratto

Definiamo il tipo Pila come il puntatore al primo elemento della pila, ogni elemento della pila ha il proprio valore e il puntatore al prossimo elemento.
Implementazione (in pseudocodice) con condivisione della memoria:

* `pilaVuota()`
    ```
    return NULL
    ```
    il costo asintotico della funzione è O(1).

* `estVuota(Pila p)`
    ```
    if p == NULL:
        return true
    else:
        return false
    ```
    il costo asintotico della funzione è O(1).

* `push(Pila p, T e)`
    ```
    out = <puntatore a nuovo nodo>
    out.info = e
    out.next = p
    return out
    ```
    il costo asintotico della funzione è O(1).

* `pop(Pila p)`
    ```
    if p == NULL:
        errore
    else:
        return p.next
    ```
    il costo asintotico della funzione è O(1).

* `top(Pila p)`
    ```
    if p == NULL:
        errore
    else:
        return p.info
    ```
    il costo asintotico della funzione è O(1).