# domanda a risposta aperta
Il passaggio di un parametro nel linguaggio C può avvenire in due modi:

* Per valore, ovvero quando viene effettuata la chiamata alla funzione inseriamo come parametro formale un valore e dunque viene passato come parametro un int, char o altro. In questo caso qualsiasi operazione svolta all'interno della funzione chiamata non avrà effetto sulla variabile all'interno della funzione chiamante, perchè il parametro attuale contiene il valore con cui è stata chiamata la funzione ma non può essere usato per modificare la variabile passata come parametro.
Ad esempio se ho una funzione
    ```c
    void differenza(int x, int y) {
        x = x - y;
    }
    ```
    E la chiamo all'interno del main in questo modo
    ```c
    int x = 10, y = 5;
    differenza(x, y);
    printf("%d %d\n", x, y);
    ```
    Verrà stampato `10 5` perchè le variabili all'interno del main non sono state modificate mentre se la printf fosse stata nella funzione differenza, allora l'output sarebbe stato `5 5`.

* Per riferimento, in questo caso quando la funzione viene chiamata viene posto come parametro formale il riferimento all'indirizzo di memoria in cui si trova la variabile passata e all'interno della funzione chiamata questo valore è assegnato al parametro attuale che è di tipo puntatore, in tal modo possiamo andare a modificare il contenuto di quel segmento di memoria e tale modifica si ripercuote anche nella funzione chiamante.
Se ad esempio avessimo la funzione
    ```c
    void incrementa(int *x) {
        *x = *x + 1;
    }
    ```
    E venisse chiamata in questo modo
    ```c
    int x = 1;
    incrementa(&x);
    printf("%d\n", x);
    ```
    L'output sarebbe `2`, anche se la printf fosse all'interno della funzione incrementa, questo perchè mettendo il simbolo "&" davanti a una variabile che viene passata come parametro intendiamo che viene passato il suo indirizzo di memoria e quindi nella funzione noi stiamo incrementando effettivamente l'x della funzione chiamante

# domande a risposta multipla
domanda 1: A
domanda 2: D
domanda 3: D