## Domanda 1
Si consideri il seguente programma C:
```c
#include <stdio.h>
#include <stdlib.h>

void f(int* x){
	x = (int*) malloc(sizeof(int));
	x = 0;
}

int main() {
	int x = 10;
	f(&x);
	printf("%d\n",x);
	return 0;
}
```

Una sola delle seguenti affermazioni è vera. Quale?

- [ ] Il programma genera la stampa del valore 0.
- [ ] Il programma genera un errore a tempo di esecuzione.
- [ ] Il programma genera la stampa del valore 10.
- [ ] Il programma genera un errore a tempo di compilazione.

## Domanda 2
Si considerino la definizione usuale di SCL:
```c
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
TipoSCL costruisciSCL(int n){
	if (n<=0){
		return NULL;
	}
	else{
		TipoNodoSCL nuovo;
		nuovo.info = n;
		nuovo.next = costruisciSCL(n-1);
		return &nuovo;
	}
}
```

Una sola delle seguenti affermazioni è corretta. Quale?

- [ ] La funzione costruisciSCL crea correttamente e restituisce una SCL contenente tutti e soli i valori nell'intervallo [0, n], in ordine crescente.
- [ ] La funzione costruisciSCL crea correttamente e restituisce una SCL contenente tutti e soli i valori nell'intervallo [0, n], in ordine decrescente.
- [ ] Se n è positivo, la funzione costruisciSCL restituisce una SCL non allocata correttamente.
- [ ] La funzione costruisciSCL genera un errore a tempo di compilazione.

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

typedef TipoNodoAlbero* TipoAlbero;
```
e le seguenti funzioni:
```c
int mistero(TipoAlbero alb){
	if (alb == NULL)
		return 0;
	if (alb -> sinistro == NULL && alb -> destro == NULL){
		return 1;
	}
	return mistero(alb->sinistro)+mistero(alb->destro);
}

int main(){
	TipoNodoAlbero a,b,c,d,e;

	a.info = 'a';
	a.sinistro = &b;
	a.destro = &c;

	b.info = 'b';
	b.sinistro = &d;
	b.destro = &e;

	c.info = 'c';
	c.sinistro = NULL;
	c.destro = NULL;

	d.info = 'd';
	d.sinistro = NULL;
	d.destro = NULL;

	e.info = 'e';
	e.sinistro = NULL;
	e.destro = NULL;

	printf("%d \n", mistero(&a));
}
```

Una sola delle seguenti affermazioni è vera. Quale?

- [ ] L'esecuzione della funzione main stampa il valore 1.
- [ ] L'esecuzione della funzione main stampa il valore 2.
- [ ] L'esecuzione della funzione main stampa il valore 3.
- [ ] L'esecuzione della funzione main genera un errore a tempo di esecuzione.