## Domanda 1
Si consideri il seguente programma C:
```c
#include <stdio.h>
#include <stdlib.h>

void f(int* x){
	*x=10;
}

int main() {
	int x = 0;
	f(&x);
	printf("%d\n",x);
	return 0;
}
```

Una sola delle seguenti affermazioni è vera. Quale?

- [ ] Il programma genera la stampa del valore 0.
- [ ] Il programma genera un errore a tempo di esecuzione.
- [X] Il programma genera la stampa del valore 10.
- [ ] Il programma genera un errore a tempo di compilazione.

## Domanda 2
Si considerino la seguente definizione di SCL:
```c
#include <stdio.h>
#include <stdlib.h>

typedef int TipoInfoSCL;

struct ElemSCL {
	TipoInfoSCL info;
	struct ElemSCL* next;
};

typedef struct ElemSCL TipoNodoSCL;

typedef TipoNodoSCL* TipoSCL;
```
e la seguente funzione:
```c
void aggiungi(TipoSCL* scl, TipoInfoSCL info){
	TipoNodoSCL* primo = (TipoNodoSCL*) malloc(sizeof(TipoNodoSCL));
	primo -> info = info;
	primo -> next = *scl;
	*scl = primo;
}
```

Una sola delle seguenti affermazioni è corretta. Quale?

- [X] La funzione aggiungi modifica la SCL di input inserendovi correttamente in testa un nodo contenente il valore info.
- [ ] La funzione aggiungi effettua correttamente l'inserimento in testa alla SCL di input di un nodo contenente il valore info, esclusivamente nel caso in cui la SCL sia non vuota.
- [ ] La funzione aggiungi effettua correttamente l'inserimento in testa alla SCL di input di un nodo contenente il valore info, esclusivamente nel caso in cui la SCL sia vuota.
- [ ] La funzione aggiungi genera un errore a tempo di esecuzione.

## Domanda 3
Si considerino la seguente rappresentazione collegata di alberi binari:
```c
#include <stdio.h>
#include <stdlib.h>

typedef char TipoInfoAlbero;

struct StructAlbero {
  TipoInfoAlbero info;
  struct StructAlbero *sinistro, *destro;
};

typedef struct StructAlbero TipoNodoAlbero;

typedef TipoNodoAlbero * TipoAlbero;
e la seguente funzione:
void mistero(TipoAlbero alb){
	TipoAlbero aux = alb;
	if (aux != NULL){
		alb = alb -> sinistro;
		mistero(alb);
		alb = aux -> destro;
		mistero(alb);
		printf("%c", aux -> info);
	}
}
```


Una sola delle seguenti affermazioni è vera. Quale?

- [ ] La funzione mistero stampa il contenuto dei nodi dell'albero di input alb secondo una visita in profondità in preordine.
- [X] La funzione mistero stampa il contenuto dei nodi dell'albero di input alb secondo una visita in profondità in postordine.
- [ ] La funzione mistero stampa il contenuto dei nodi dell'albero di input alb secondo una visita in ampiezza.
- [ ] La funzione mistero non effettua una visita dell'albero di input alb.