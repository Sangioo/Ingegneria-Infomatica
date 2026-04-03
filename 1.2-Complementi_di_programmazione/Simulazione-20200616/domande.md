# domanda a risposta aperta
Un albero n-ario è una struttura collegata di tipo albero, ma a differenza di un albero binario ogni nodo può avere più di due nodi discendenti, che in questo caso non si chiameranno più figlio destro e figlio sinistro ma li chiameremo primo figlio, secondo figlio, ecc...
In C possiamo rappresentare un albero n-ario, nell'esempio un'albero con valori interi, attraverso la seguente rappresentazione:
```h
typedef int TipoInfoAlbero;
struct StructFiglio;
struct StructAlbero {
    TipoInfoAlbero info;
    struct StructFiglio* figli;
};
struct StructFiglio {
    struct StructAlbero* albero;
    struct StructFiglio* next;
};
typedef struct StructAlbero* TipoAlbero;
typedef struct StructFiglio* TipoFigli;
```

# domande a risposta multipla
domanda 1: B
domanda 2: B
domanda 3: D