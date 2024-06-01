## Domanda 1
Si consideri il seguente programma C:
```c
#include <stdio.h>
#include <stdlib.h>
int* g(){
	int a = 10;
	return &a;
}

int main() {
	int* x = g();
	printf("%d\n",*x);
	free(x);
}
```
Una sola delle seguenti affermazioni è vera. Quale?

- [ ] La funzione g() causa un errore a tempo di compilazione.
- [ ] La funzione main() causa un errore a tempo di esecuzione.
- [ ] L'esecuzione della funzione main() termina correttamente.
- [X] La funzione g() viene compilata correttamente ma la funzione main() causa un errore a tempo di compilazione.

## Domanda 2
Si considerino la seguente definizione di SCL:
```c
#include <stdlib.h>

typedef int TipoInfoSCL;

struct ElemSCL {
	TipoInfoSCL info;
	struct ElemSCL* next;
};

typedef struct ElemSCL TipoNodoSCL;
typedef TipoNodoSCL* TipoSCL;
e la seguente funzione:
void addSCL(TipoSCL scl, TipoInfoSCL v){
	TipoSCL new_scl = (ElemSCL*) malloc(sizeof(struct ElemSCL));
	new_scl -> info = v;
	new_scl -> next = NULL;

	if (scl == NULL){
		scl = new_scl;
	}
	else{
		while (scl -> next != NULL){
			scl = scl -> next;
		}
		scl -> next = new_scl;
	}
}
```
Una sola delle seguenti affermazioni è vera. Quale?

- [ ] La funzione addSCL effettua correttamente l'inserimento dell'elemento v in testa alla SCL di input.
- [ ] La funzione addSCL effettua correttamente l'inserimento dell'elemento v in coda alla SCL di input.
- [X] La funzione addSCL effettua correttamente l'inserimento dell'elemento v in coda alla SCL di input, solo se questa è non vuota.
- [ ] La funzione addSCL non può modificare in alcun modo la SCL di input.

## Domanda 3
Si considerino la seguente rappresentazione collegata di alberi binari:
```c
#include <stdio.h>
#include <stdlib.h>

typedef int TipoInfoAlbero;

struct StructAlbero {
  TipoInfoAlbero info;
  struct StructAlbero *sinistro, *destro;
};

typedef struct StructAlbero TipoNodoAlbero;

typedef TipoNodoAlbero* TipoAlbero;
e la seguente funzione:
void stampaPari(TipoAlbero a){
	if (a == NULL){
		return;
	}
	if (a -> info % 2 == 0){
		printf("%d ", a -> info);
		return;
	}
	if (a -> sinistro != NULL){
		stampaPari(&(a.sinistro));
	}
	if (a -> destro != NULL){
		stampaPari(&(a.destro));
	}
}
```
Una sola delle seguenti affermazioni è vera. Quale?

- [ ] La funzione stampaPari genera un errore a tempo di esecuzione.
- [ ] La funzione stampaPari stampa correttamente il contenuto dei nodi di a aventi valore pari.
- [ ] Se l'albero a è non vuoto ed il nodo radice contiene un valore pari, la funzione stampaPari stampa esclusivamente il contenuto del nodo radice.
- [X] La funzione stampaPari causa un errore a tempo di compilazione.