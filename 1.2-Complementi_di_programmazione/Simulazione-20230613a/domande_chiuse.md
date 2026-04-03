## Domanda 1
Si consideri la seguente funzione C:
```c
int main(int argc, char** argv){
    int v[]={1,2,3};
    unsigned const int n = 3;
    int i = 0;
    short y = 0;
    while (i < n) {
        i++;
        *(v+i) = y;
    }
}
```
Una sola delle seguenti affermazioni è vera. Quale?

- [X] La funzione scrive oltre i limiti dell'array.
- [ ] La funzione scrive il valore 0 in tutte le celle dell'array.
- [ ] La funzione genera un errore a tempo di esecuzione poiché non è possibile assegnare un valore di tipo short alle componenti di un array di tipo int.
- [ ] La funzione scrive 0 solo nell'ultima posizione dell'array.

## Domanda 2
Si considerino le seguenti definizioni:
```c
typedef int TipoInfoSCL;

struct ElemSCL{
    TipoInfoSCL info;
    struct ElemSCL* next;
};

typedef struct ElemSCL TipoNodoSCL;
typedef TipoNodoSCL * TipoSCL;

void doSCL(TipoSCL *l, TipoInfoSCL e){
    TipoSCL temp = *l;
    *l = (TipoNodoSCL*) malloc(sizeof(TipoNodoSCL));
    (*l)->info = e;
    if (temp!=NULL && temp->next!=NULL)
        (*l)->next = temp->next;
    else
        (*l)->next = temp;
}
```
ed il seguente frammento di programma:
```c
TipoSCL l1 = NULL;
doSCL(&l1,9);
doSCL(&l1,5);
doSCL(&l1,3);
doSCL(&l1,1);

for (TipoSCL p=l1; p!=NULL; p=p->next)
    printf("%d ", p->info);
printf("\n");
```
Una sola delle seguenti affermazioni è corretta. Quale?

- [X] Il programma stampa i valori 1 9.
- [ ] Il programma stampa i valori 1 3 5 9.
- [ ] Il programma non stampa alcun valore (la lista è vuota).
- [ ] Il programma provoca un errore a tempo di esecuzione in quanto si accede ad aree di memoria non allocate.

## Domanda 3
Si assuma che il tipo float abbia una rappresentazione a 32 bit, mentre il tipo double a 64 bit.

Una sola delle seguenti affermazioni è vera. Quale?

- [X] Il numero di valori double distinti rappresentabili è maggiore del numero di valori float distinti rappresentabili.
- [ ] Il numero di valori float distinti rappresentabili è maggiore del numero di valori double distinti rappresentabili.
- [ ] Il numero di valori float distinti rappresentabili è uguale al numero di valori double distinti rappresentabili, ma le operazioni sui valori double vengono eseguite con maggiore precisione.
- [ ] Il numero di valori float distinti rappresentabili è uguale al numero di valori double distinti rappresentabili, ma le operazioni sui valori float vengono eseguite con maggiore precisione. 